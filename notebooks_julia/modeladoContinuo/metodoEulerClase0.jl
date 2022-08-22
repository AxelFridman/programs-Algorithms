### A Pluto.jl notebook ###
# v0.19.9

using Markdown
using InteractiveUtils

# This Pluto notebook uses @bind for interactivity. When running this notebook outside of Pluto, the following 'mock version' of @bind gives bound variables a default value (instead of an error).
macro bind(def, element)
    quote
        local iv = try Base.loaded_modules[Base.PkgId(Base.UUID("6e696c72-6542-2067-7265-42206c756150"), "AbstractPlutoDingetjes")].Bonds.initial_value catch; b -> missing; end
        local el = $(esc(element))
        global $(esc(def)) = Core.applicable(Base.get, el) ? Base.get(el) : iv(el)
        el
    end
end

# ╔═╡ 60ccb3c4-8245-4b19-ab3d-246f93190008
import Pkg

# ╔═╡ 26cc5030-0024-4ec5-955d-d9754857a7f2
Pkg.add("PlutoUI")

# ╔═╡ ccab0f4a-1f07-11ed-3fc8-1990dc5b6c44
using Plots

# ╔═╡ 8a06106e-d71f-4c3d-9f3e-7b5da53bc016
using PlutoUI

# ╔═╡ a8565f65-1599-4882-8ce2-c20f4b7cee0f
begin
	function euler(f, tspan, u0, h)
		t = tspan[1]:h:tspan[2]
		n = length(t)
		u = zeros(n)
		u[1] = u0
		for i in 1:(n-1)
			u[i+1] = u[i] + h*f(u[i],t[i])
		end
		return t,u
	end
end

# ╔═╡ 600a35ce-69ab-4d17-944f-c03f70d1f1b9
md"""## Ejercicio 1"""

# ╔═╡ 1c38b673-c122-487f-930d-1fb05262e6aa
tspan = [0,10] #Este es el intervalo del cual quiero inferir como es la funcion

# ╔═╡ ddd41707-d80c-4f43-b737-b2b7ad9a43b5
u0 = 1 #Este es el valor que se que tiene en tspan[0]

# ╔═╡ a8d09198-f27f-4f0c-84a0-c0fca5a09beb
h = 0.01

# ╔═╡ 28fa216c-88c3-4bb4-b240-38a1cb26f07d
@bind c Slider(0.1:0.1:5)

# ╔═╡ a8a67413-2ad6-4dc6-b887-0781c7691135
fun(u,t)=c*u #esta es la derivada de u con respecto a t

# ╔═╡ 7d18f4da-ffb2-4c62-9d3b-5f05c4219fed
funReal(t)=exp(c*t)

# ╔═╡ 15de90ae-b0ba-47fa-bc8f-edbccaa359e9
tPuntual, uPuntual = euler(fun,tspan, u0, h)

# ╔═╡ 292ef27c-b0c6-4546-a15e-be4f83011d52
begin
	plot(tPuntual,uPuntual, label="Estimacion")
	plot!(tPuntual, funReal.(tPuntual),label="Funcion Real")
	plot!(tPuntual, funReal.(tPuntual)-uPuntual,label="Diferencia") 
	#La diferencia aumenta porque es STIFFNES crece tan rapido que a los metodos numericos les cuesta aproximar
	
end

# ╔═╡ b04f60b1-ddd6-4ebe-858d-0b0f7e34b2c4
md"""## Ejercicio 2"""

# ╔═╡ 283cc0ba-0711-4708-85ce-35939b8965ce
tspan2 = [0,120]

# ╔═╡ 9c298f59-b488-49a6-8147-e8572af39618
@bind r Slider(-0.1:0.01:0.1) #Tasa de crecimiento

# ╔═╡ 2d2005fc-06a2-4d9d-b176-d17001cfa41f
@bind K Slider(1:0.1:100) #Capacidad de carga del ambiente

# ╔═╡ 2bee61e0-4a4e-4ba7-bd8a-4cbb5449f615
begin
	@bind uIni Slider(0.1:0.1:2) 
	#Capacidad de carga del ambiente
end

# ╔═╡ 12cfd134-29a9-401d-9cb9-a61fcf810564
@bind h2 Slider(0.1:0.01:2) #Capacidad de carga del ambiente

# ╔═╡ e66b6cb8-69da-48e5-9978-048482cb7ec3
ecuLog(p,t)=r*p*(1-p/K) #esta es la derivada de u con respecto a t

# ╔═╡ 4e756eac-a3f5-4fdb-9dd3-d7fddace16e3
t2, u2 = euler(ecuLog,tspan2, uIni, h2)

# ╔═╡ 317d83de-681d-4e4e-90fd-951a79e73315
funReal2(t)=K/(1+((K-uIni)/uIni)*exp(-r*t))

# ╔═╡ ccfaa591-a08a-47a6-9636-fcfb18ab5168
begin
	
plot(t2,u2, label="Estimacion")
plot!(t2, funReal2.(t2),label="Funcion Real")
end

# ╔═╡ 32947483-6a2c-47bb-86de-438a1dae1416
md"""## Ejercicio 3"""

# ╔═╡ 2b2c120e-3412-476a-b504-2f404f94695d
begin
	q1 = 1
	A=1
end

# ╔═╡ 46ae8641-f402-4689-8c1d-785852f6fbb0
@bind h0 Slider(0.1:0.1:5)

# ╔═╡ f7b3f322-73ad-4a22-a689-fd2ac0be1a07
@bind R Slider(0.1:0.1:1)

# ╔═╡ aa8e824a-7fd9-4995-9b86-0f5bd30bff63
funAlturaTanque(h,t)=(1/A) * (q1- (sqrt(h))/R)

# ╔═╡ 33dbd903-3b3f-424b-a19d-ba23a1fab8bd
tspan3=[1,10]

# ╔═╡ d55eb45f-c89a-4c72-876b-4cd4866092b3
t3, u3 = euler(funAlturaTanque,tspan3, h0, h2)

# ╔═╡ 1a9a9935-c86f-41d3-93ff-a811b7a69051
begin
	
plot(t3,u3, label="Estimacion")
#plot!(t2, funReal2.(t2),label="Funcion Real")
end

# ╔═╡ 767ea75b-ea06-4acd-9a9b-8051e502507b
@bind α Slider(-1:0.1:2)

# ╔═╡ a744dbde-d622-4817-8d39-1237876ca955
@bind kt Slider(0.1:0.1:50)

# ╔═╡ f8950c70-d423-41bb-9182-e0ab8cab5aa2
@bind rr Slider(0.1:0.1:2)

# ╔═╡ b2db0066-d214-4abb-a1ed-48b72d59b6e5
funej5teo(m,t) = m*rr*(kt-m)/(kt+ α*m)

# ╔═╡ fb1f68e5-caa7-462d-b546-a3fd1877fcb8
tspanteo=[0,100]

# ╔═╡ 124550c8-8896-4527-ba2c-966c3e2fa762
t5, u5 = euler(funej5teo,tspanteo, h0, h2)

# ╔═╡ 29015388-2cd4-4e84-87e1-f90718d836a2
plot(t5,u5, label="Estimacion ej 5 teo")


# ╔═╡ 2e038805-4de7-40b0-ad40-e131e1f8ccf4
md"""## Ejercicio 4"""

# ╔═╡ ded3a4c9-e4d9-44cd-9c1d-595808491943
f4(y,t)=-50*(y-cos(t))

# ╔═╡ c21d2040-d6ed-4fef-a3c9-a76add50432f
span4 = [0,1]

# ╔═╡ 5d5cba59-44af-4cbc-9e0c-79483f208335
x04 = 0.15

# ╔═╡ 30ce192b-309c-486e-8085-268f158229a7
@bind h4 Slider(0.01:0.01:0.6)

# ╔═╡ 0e84395e-9286-4012-bd02-e616b0dea73e
t4l, u4l = euler(f4,span4, x04, h4)

# ╔═╡ 2aae0847-1c83-4237-937a-e4c489d6a299
plot(t4l,u4l, label="Estimacion ej 4 euler")


# ╔═╡ 1374e4bc-ac6a-487a-a24e-2342e0244566
md"""## Ejercicio 5"""

# ╔═╡ fbdab0f3-c15c-49ac-a441-3ba0645e81d5
function eulerModificado(f, tspan, u0, h)
		t = tspan[1]:h:tspan[2]
		n = length(t)
		u = zeros(n)
		u[1] = u0
		for i in 1:(n-1)
			u[i+1] = u[i] + h * f(u[i]+(h/2) *f(u[i],t[i]) ,t[i]+ h/2)
		end
		return t,u
	end

# ╔═╡ 88195dca-7325-42dc-811a-1b08ddcb9900
g = 9.81

# ╔═╡ bf6060c4-7bba-41eb-a4c8-849dd7d7ba7d
m = 0.084

# ╔═╡ af083311-c7f7-454d-b74d-883c2b8e330e
cr = 0.028

# ╔═╡ 0b9ecce3-a39b-4150-b76b-f60f2cc2ac07
@bind v0 Slider(5:0.1:6)

# ╔═╡ 4ff1756a-08b5-422d-b63d-c1c951b8ea4c
tspan5 = [0,10]

# ╔═╡ df08721a-6ffb-4bc5-9c39-5380678dfc5e
h55=0.001

# ╔═╡ 90768daf-58f9-44ce-9155-c3e10151caa8
vprima(v,t)=g-(cr/m)*v^2

# ╔═╡ 1d5a0391-e018-4894-8a4d-aaf50f89f177
t5a, u5a = eulerModificado(vprima,tspan5, v0, h55)

# ╔═╡ 6a60c1fe-6d92-4fa6-956b-b2169abc2653
plot(t5a,u5a, label="Estimacion ej 5 euler mod")


# ╔═╡ Cell order:
# ╠═60ccb3c4-8245-4b19-ab3d-246f93190008
# ╠═26cc5030-0024-4ec5-955d-d9754857a7f2
# ╠═ccab0f4a-1f07-11ed-3fc8-1990dc5b6c44
# ╠═8a06106e-d71f-4c3d-9f3e-7b5da53bc016
# ╠═a8565f65-1599-4882-8ce2-c20f4b7cee0f
# ╠═600a35ce-69ab-4d17-944f-c03f70d1f1b9
# ╠═1c38b673-c122-487f-930d-1fb05262e6aa
# ╠═ddd41707-d80c-4f43-b737-b2b7ad9a43b5
# ╠═a8d09198-f27f-4f0c-84a0-c0fca5a09beb
# ╠═28fa216c-88c3-4bb4-b240-38a1cb26f07d
# ╠═a8a67413-2ad6-4dc6-b887-0781c7691135
# ╠═7d18f4da-ffb2-4c62-9d3b-5f05c4219fed
# ╠═15de90ae-b0ba-47fa-bc8f-edbccaa359e9
# ╠═292ef27c-b0c6-4546-a15e-be4f83011d52
# ╠═b04f60b1-ddd6-4ebe-858d-0b0f7e34b2c4
# ╠═283cc0ba-0711-4708-85ce-35939b8965ce
# ╠═9c298f59-b488-49a6-8147-e8572af39618
# ╠═2d2005fc-06a2-4d9d-b176-d17001cfa41f
# ╠═2bee61e0-4a4e-4ba7-bd8a-4cbb5449f615
# ╠═12cfd134-29a9-401d-9cb9-a61fcf810564
# ╠═e66b6cb8-69da-48e5-9978-048482cb7ec3
# ╠═4e756eac-a3f5-4fdb-9dd3-d7fddace16e3
# ╠═317d83de-681d-4e4e-90fd-951a79e73315
# ╠═ccfaa591-a08a-47a6-9636-fcfb18ab5168
# ╠═32947483-6a2c-47bb-86de-438a1dae1416
# ╠═aa8e824a-7fd9-4995-9b86-0f5bd30bff63
# ╠═2b2c120e-3412-476a-b504-2f404f94695d
# ╠═46ae8641-f402-4689-8c1d-785852f6fbb0
# ╠═f7b3f322-73ad-4a22-a689-fd2ac0be1a07
# ╠═33dbd903-3b3f-424b-a19d-ba23a1fab8bd
# ╠═d55eb45f-c89a-4c72-876b-4cd4866092b3
# ╠═1a9a9935-c86f-41d3-93ff-a811b7a69051
# ╠═767ea75b-ea06-4acd-9a9b-8051e502507b
# ╠═a744dbde-d622-4817-8d39-1237876ca955
# ╠═f8950c70-d423-41bb-9182-e0ab8cab5aa2
# ╠═b2db0066-d214-4abb-a1ed-48b72d59b6e5
# ╠═fb1f68e5-caa7-462d-b546-a3fd1877fcb8
# ╠═124550c8-8896-4527-ba2c-966c3e2fa762
# ╠═29015388-2cd4-4e84-87e1-f90718d836a2
# ╠═2e038805-4de7-40b0-ad40-e131e1f8ccf4
# ╠═ded3a4c9-e4d9-44cd-9c1d-595808491943
# ╠═c21d2040-d6ed-4fef-a3c9-a76add50432f
# ╠═5d5cba59-44af-4cbc-9e0c-79483f208335
# ╠═30ce192b-309c-486e-8085-268f158229a7
# ╠═0e84395e-9286-4012-bd02-e616b0dea73e
# ╠═2aae0847-1c83-4237-937a-e4c489d6a299
# ╠═1374e4bc-ac6a-487a-a24e-2342e0244566
# ╠═fbdab0f3-c15c-49ac-a441-3ba0645e81d5
# ╠═88195dca-7325-42dc-811a-1b08ddcb9900
# ╠═bf6060c4-7bba-41eb-a4c8-849dd7d7ba7d
# ╠═af083311-c7f7-454d-b74d-883c2b8e330e
# ╠═0b9ecce3-a39b-4150-b76b-f60f2cc2ac07
# ╠═4ff1756a-08b5-422d-b63d-c1c951b8ea4c
# ╠═df08721a-6ffb-4bc5-9c39-5380678dfc5e
# ╠═90768daf-58f9-44ce-9155-c3e10151caa8
# ╠═1d5a0391-e018-4894-8a4d-aaf50f89f177
# ╠═6a60c1fe-6d92-4fa6-956b-b2169abc2653
