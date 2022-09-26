### A Pluto.jl notebook ###
# v0.19.9

using Markdown
using InteractiveUtils

# ╔═╡ 41d6c073-8ad6-40b7-83f1-6f6baac4319d
begin
import Pkg
Pkg.add("Plots")
end

# ╔═╡ 9469a954-2897-11ed-26bc-a3c77af2e487
begin
	using Plots,DifferentialEquations,OrdinaryDiffEq, BenchmarkTools,PlutoUI
	
end

# ╔═╡ 3df55fa6-b6ee-4ecd-9dff-095f9aefab69
md"""### Mejorando la eficiciencia de los solvers"""

# ╔═╡ a813ae0d-4770-4486-956e-bde0b07a36b1
md"""Comencemos por fabricar un problema _arbitrariamente grande_. Supongamos que queremos hacer algo similar a un `streamplot` aprovechando las herramientas para resolver un sistema. Consideremos, por ejemplo, el sistema de Lotka-Volterra:

$\left\{\begin{array}{rcl}\dot{x} &=& -\alpha x + \beta xy \\
  							\dot{y} &=& \gamma y - \delta xy \end{array}\right.$

Lo que hace un `streamplot` es esencialmente graficar varias trayectorias, que corresponden a resolver el sistema con distintos datos iniciales. 

Podríamos diseñar una función que represente el sistema y luego correrla muchas veces con distintos datos iniciales y graficar todas las trayectorias juntas. Eso estaría bien. Pero vamos a hacer algo un poco más compacto.
"""



# ╔═╡ 8d4f1314-9e42-42b4-a270-fd16d11f8ecc
md"""Implementamos una función que resuelva _muchas copias_ del sistema de Lotka-Volterra:"""

# ╔═╡ 243157aa-10b2-4d72-bfaf-4020de98df1e
function lotka_volterra(u,p,t)
	α,β,γ,δ = p
	n       = Int(length(u)/2) #asumimos que u tiene una cantidad par de casilleros.
	du      = zeros(2n)
	for i in 1:2:2n-1
		du[i]   = -α*u[i]+β*u[i]*u[i+1]
		du[i+1] = γ*u[i+1]-δ*u[i]*u[i+1]
	end
	return du
end

# ╔═╡ eaf19668-37c8-4085-8ae2-ec1ffa1107d8
md"""La idea de esta función es que cada pareja `[u[i],u[i+1]]` (con `i` impar) será un sistemita de Lotka-Volterra. Nuestra función maneja un sistema de `2n` variables, pero en realidad son `n` sistemas de 2 variables, dado que las variables sólo interactúan por parejas. Ahora podemos definir muchos datos iniciales y resolver."""

# ╔═╡ e5775bed-5227-49e3-886c-6fbd2c491f9d
begin
	n     = 100 # Calculamos 100 trayectorias
	p     = (0.5,0.5,0.5,0.5)
	u₀    = 3*rand(2n)
	tspan = (0.0,50.0)
	prob₁ = ODEProblem(lotka_volterra,u₀,tspan,p)
end

# ╔═╡ 0e2648eb-70d2-4a5a-a733-b11ef8d716a3
md"""Para estimar el tiempo que se demora en resolver el problema podemos usar el macro `@time`:"""

# ╔═╡ b515d530-3af0-4c86-bd71-a0b4b575decd
@time sol₁ = solve(prob₁)

# ╔═╡ 4ec28ba0-886e-4277-9649-61ffc994330c
md"""Es importante prestarle atención no sólo al tiempo de ejecución sino también a la **memoria** utilizada. El acceso a memoria suele ser bastante costoso. Al resolver problemas grandes con métodos iterativos se repiten pasos de acceso a memoria muchísimas veces y eso puede deteriorar seriamente el tiempo (además el consumo de memoria en sí mismo)."""

# ╔═╡ f3adf923-8950-4562-9bbc-fada87a82e15
md"""Un detalle es que `@time` computa el tiempo de una corrida, que puede verse afectado por innumerables factores. Para tener una estimación más confiable puede usarse el macro `@benchmark`, de la librería `BenchmarkTools`."""

# ╔═╡ 5c8da6ff-8afc-44fb-9ef3-ca95722453fe
@benchmark  solve(prob₁)

# ╔═╡ 5654c02b-d335-4575-a9fc-07fdfa7d1d87
md"""Una vez que tenemos nuestras soluciones las podemos graficar por pares en el plano de fases: """


# ╔═╡ 4d8852d5-2d63-4eea-8066-9085dac86abc
plot(sol₁,idxs=[(i,i+1) for i in 1:2:2n-1],arrow=true,legend=:none)

# ╔═╡ 3d3f2f6b-1201-4941-940d-f9f75771376b
md"""Ahora repitamos el experimento, pero definiendo la función del sistema en formato _in place_. Es decir: la función del sistema no genera `du` internamente sino que lo recibe como parámetro y lo modifica:"""


# ╔═╡ 8afa491f-dd1f-41de-a4de-1327b15344bc
function lotka_volterra!(du, u,p,t)
	α,β,γ,δ = p
	n       = Int(length(u)/2) #asumimos que u tiene una cantidad par de casilleros.
	for i in 1:2:2n-1
		du[i]   = -α*u[i]+β*u[i]*u[i+1]
		du[i+1] = γ*u[i+1]-δ*u[i]*u[i+1]
	end
end

# ╔═╡ ed00582e-8552-4296-a093-7250af6021c7
md"""Repetimos nuestro experimento con esta función:"""

# ╔═╡ a3524e64-605d-4717-85bf-d3d44b31d85a
prob₂ = ODEProblem(lotka_volterra!,u₀,tspan,p)

# ╔═╡ 89fef5f1-06bc-48b2-965d-7d8712dd9fea
@benchmark solve(prob₂)

# ╔═╡ aa4be2fa-f48f-4e31-a843-ba8cd534313e
md"""#### Cambiando el solver"""

# ╔═╡ 0ba2d585-dfe0-4d4d-a0be-c020dec0355f
md"""La librería `OrdinaryDiffEq` (es parte de `DifferentialEquations` y no hace falta instalarla aparte) contiene distintos solvers que uno puede utilizar. El solver por defecto es `Tsit5()`, que es método de Runge-Kutta de orden 4(5) propuesto por Tsitouras. Si bien tiene poco sentido en cuanto a la precisión, existe el método `Euler()`. También el método `Heun()`. También existen métodos de orden más alto, como `Vern7`, un RK de orden 6(7) debido a Verner, o `Feagin14()`, un RK de orden 14 debido a Feagin. Para problemas _stiff_ se recomiendan los métodos `Rosenbrock23()` o `Rodas4()`."""

# ╔═╡ 485b011c-cfef-4fb3-8c83-ead6502c4cd7
md"""Para usar un método, sólo hay que especificar su nombre en la función `solve`: """

# ╔═╡ 3963ffd1-5dae-433b-a990-61cfdaee2f3e
sol₃ = solve(prob₂,Tsit5())

# ╔═╡ 27a37aa6-47ef-42f3-9879-2d79150ff705
md"""El método de Euler no tiene capacidad para elegir automáticamente el paso, de modo que es necesario especificarlo con el parámetro `dt`:"""



# ╔═╡ 2b5a847e-5cc3-4c15-947c-9681210ad28d
sol₄ = solve(prob₂,Euler(),dt=0.1)

# ╔═╡ 7e2c1b44-723b-44a4-91f5-a46652e570e1
md"""#### Precisión"""

# ╔═╡ d34536a6-7099-4dc7-a4f0-828c2a7cf38e
md"""Los solvers eligen el tamaño del paso de acuerdo con una tolerancia al error. Hay dos tolerancias: `reltol` es un control del error relativo y determina el número de dígitos correctos de la solución; `abstol` es una tolerancia absoluta. Por el modo en que los solvers utilizan estas tolerancias el efecto es el siguiente: si el error (local) es menor que `abstol`, entonces se considera que la solución es buena con independencia de la cantidad de dígitos correctos, mientras que si el error es mayor se garantiza que haya tantos dígitos correctos como indica `reltol`. Los valores por defecto son `abstol=1e-6` y `reltol=1e-3`, lo que implica que en un paso dado el error es menor que $10^{-6}$ o, en caso contrario, tiene $2$ dígitos correctos.

Si uno desea mejorar la calidad de una solución, puede imponer valores más chicos de estas tolerancias. Esto en general implica que el método seleccionará pasos más chicos y por lo tanto consumirá más memoria y tardará más tiempo. """

# ╔═╡ 2209426d-fbbf-4986-8b23-722e18a51e10
@benchmark solve(prob₁)


# ╔═╡ 5dfc0413-6942-42ef-ab16-7f2c7fc10442
@benchmark solve(prob₁,abstol=1e-10,reltol=1e-10)

# ╔═╡ 7a2b1de6-79aa-4665-a8bd-70b448f40b70
@benchmark solve(prob₂)

# ╔═╡ 3185184e-c72e-4a26-9506-7e42dbce4a0d
@benchmark solve(prob₂,abstol=1e-10,reltol=1e-10)

# ╔═╡ cd8f4567-d05f-4ccd-b18e-c3d72ccb6fd8
md"""### Ecuaciones con Delay"""

# ╔═╡ 612d9207-be03-493e-b54d-a7bd90b8d33b
md"""Para trabajar con ecuaciones con delay utilizamos el constructor:

	prob = DDEProblem(modelo,u0,h,tspan,p; constant_lags=lags)

donde `h` es una función de historia que le indica al modelo los valores de las variables previos al inicio de la simulación. """

# ╔═╡ 5bc3500f-03ef-4ab0-87d6-45f3f85da786
md"""Estudiemos, por ejemplo, un sistema predador presa en el que introducimos cierto delay:

$\left\{\begin{array}{rcl}\dot{x}(t) &=& -\alpha x(t) + \beta x(t-τ)y(t-τ) \\
  							\dot{y}(t) &=& \gamma y(t) - \delta x(t)y(t) \end{array}\right.$

"""

# ╔═╡ c0b5347f-85e4-4634-904d-ccaa8c77a534
function ppd!(du,u,h,p,t)
	α,β,γ,δ,τ = p
	H         = h(p,t-τ)
	du[1]     = -α*u[1] + β*H[1]*H[2]
	du[2]     = γ*u[2] - δ*u[1]*u[2]
end

# ╔═╡ 46b13228-1ccc-4b01-91f9-b1369573eac6
begin
	ud₀    = [2.0,20.0]
	h(p,t) = ud₀
	τ      = 1.0
	tspand = (0.0,50.0)
	pd     = (0.5,0.04,0.5,0.03,τ)
	probd  = DDEProblem(ppd!,ud₀,h,tspand,pd,constant_lags=[τ])
	sold   = solve(probd,MethodOfSteps(Tsit5()))
	plot(sold,label=["Predador" "Presa"],title="τ = $τ")
end
	

# ╔═╡ 27add47f-ca0b-4103-a5bc-e20ab9f2dbf0
begin
	τ₂     = 0.1
	pd₂    = (0.5,0.04,0.5,0.03,τ₂)
	probd₂ = DDEProblem(ppd!,ud₀,h,tspand,pd₂,constant_lags=[τ₂])
	sold₂  = solve(probd₂,MethodOfSteps(Tsit5()))
	plot(sold₂,label=["Predador" "Presa"],title="τ = $τ₂")
end

# ╔═╡ 63a89fbc-ab67-4bc3-875b-97ac5ca3197c
function nutch!(du,u,h,p,t)
	r,τ, K = p
	H         = h(p,t-τ)
	du[1] = r*u[1]*(1-(H[1]/K))
end

# ╔═╡ 19afdd31-aa62-4773-88a3-2b23f30f0303
begin
	ud1    = [6]
	h1(p,t) = ud1
	
	tspand1 = (0.0,50.0)
	
	r = 0.5
	K = 20
	τ1      = 1
	pd1     = (r,τ1, K)
	probd1  = DDEProblem(nutch!,ud1,h1,tspand1,pd1,constant_lags=[τ1])
	sold1  = solve(probd1,MethodOfSteps(Tsit5()))
	
	plot(sold1,title="τ = $τ")
end

# ╔═╡ Cell order:
# ╠═41d6c073-8ad6-40b7-83f1-6f6baac4319d
# ╠═9469a954-2897-11ed-26bc-a3c77af2e487
# ╟─3df55fa6-b6ee-4ecd-9dff-095f9aefab69
# ╟─a813ae0d-4770-4486-956e-bde0b07a36b1
# ╟─8d4f1314-9e42-42b4-a270-fd16d11f8ecc
# ╠═243157aa-10b2-4d72-bfaf-4020de98df1e
# ╟─eaf19668-37c8-4085-8ae2-ec1ffa1107d8
# ╠═e5775bed-5227-49e3-886c-6fbd2c491f9d
# ╟─0e2648eb-70d2-4a5a-a733-b11ef8d716a3
# ╠═b515d530-3af0-4c86-bd71-a0b4b575decd
# ╟─4ec28ba0-886e-4277-9649-61ffc994330c
# ╟─f3adf923-8950-4562-9bbc-fada87a82e15
# ╠═5c8da6ff-8afc-44fb-9ef3-ca95722453fe
# ╟─5654c02b-d335-4575-a9fc-07fdfa7d1d87
# ╠═4d8852d5-2d63-4eea-8066-9085dac86abc
# ╟─3d3f2f6b-1201-4941-940d-f9f75771376b
# ╠═8afa491f-dd1f-41de-a4de-1327b15344bc
# ╟─ed00582e-8552-4296-a093-7250af6021c7
# ╠═a3524e64-605d-4717-85bf-d3d44b31d85a
# ╠═89fef5f1-06bc-48b2-965d-7d8712dd9fea
# ╟─aa4be2fa-f48f-4e31-a843-ba8cd534313e
# ╟─0ba2d585-dfe0-4d4d-a0be-c020dec0355f
# ╟─485b011c-cfef-4fb3-8c83-ead6502c4cd7
# ╠═3963ffd1-5dae-433b-a990-61cfdaee2f3e
# ╟─27a37aa6-47ef-42f3-9879-2d79150ff705
# ╠═2b5a847e-5cc3-4c15-947c-9681210ad28d
# ╟─7e2c1b44-723b-44a4-91f5-a46652e570e1
# ╟─d34536a6-7099-4dc7-a4f0-828c2a7cf38e
# ╠═2209426d-fbbf-4986-8b23-722e18a51e10
# ╠═5dfc0413-6942-42ef-ab16-7f2c7fc10442
# ╠═7a2b1de6-79aa-4665-a8bd-70b448f40b70
# ╠═3185184e-c72e-4a26-9506-7e42dbce4a0d
# ╟─cd8f4567-d05f-4ccd-b18e-c3d72ccb6fd8
# ╟─612d9207-be03-493e-b54d-a7bd90b8d33b
# ╟─5bc3500f-03ef-4ab0-87d6-45f3f85da786
# ╠═c0b5347f-85e4-4634-904d-ccaa8c77a534
# ╠═46b13228-1ccc-4b01-91f9-b1369573eac6
# ╠═27add47f-ca0b-4103-a5bc-e20ab9f2dbf0
# ╠═63a89fbc-ab67-4bc3-875b-97ac5ca3197c
# ╠═19afdd31-aa62-4773-88a3-2b23f30f0303
