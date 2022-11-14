### A Pluto.jl notebook ###
# v0.19.9

using Markdown
using InteractiveUtils

# ╔═╡ 497ee1fc-bbcc-4e66-a8f4-5028556a5ed9
import Pkg

# ╔═╡ 9c03ac7e-fa35-48f7-bc42-0baf8c51dd0e
Pkg.add("Images")

# ╔═╡ 7461b836-642e-11ed-1b02-eb8ede338e92
begin
	using Plots, LinearAlgebra, SparseArrays, DifferentialEquations
end

# ╔═╡ 013a4b3d-45d6-4b86-b9a9-293ff38ed7ec
begin
using Markdown
using InteractiveUtils
end

# ╔═╡ 2b8b45ef-43d3-49c5-9187-edb0cc15444f
# ╠═╡ show_logs = false
using Images

# ╔═╡ 9164b8ab-f60b-44bd-9386-d24cf2ab0b16
function calor2d(x₀, xf, y₀, yf, t₀, tf, u₀, Δx, Δy, Δt, α)
	# Preprocesamiento
	rₓ = α*Δt/(Δx)^2
	ry = α*Δt/(Δy)^2
	I = length(x₀:Δx:xf)
	J = length(y₀:Δy:yf)
	lado = I*J
	u = [] 
	ures = fill(0.0, lado, length(t₀:Δt:tf))
	drx = ones(lado)

	# Armo la grilla
	xExtendido = []
	for i in 1:I
		append!(xExtendido, x₀:Δx:xf)
	end
	yExtendido = []
	posiblesy = y₀:Δy:yf
	for i in 1:J
		append!(yExtendido, posiblesy[i]*ones(I))
	end

	# Evaluamos u₀ en x, y
	for i in 1:lado
		x = xExtendido[i]
		y = yExtendido[i]
		push!(u, u₀(x, y, t₀))
	end
	
	# Construyo la matriz :)
	matriz = diagm(0 => (1 + 2rₓ + 2ry)*ones(lado), 1=> (-rₓ)*ones(lado-1), -1=> (-rₓ)*ones(lado-1), I => (-ry)*ones(lado-I), -I => (-ry)*ones(lado-I))
	for λ in 1:(I-1)
		matriz[λ*J + 1, λ*I] = 0
		matriz[λ*J, λ*I + 1] = 0
	end

	# help
	ures[:, 1] = u
	tiempos = t₀:Δt:tf-1
	for j in 1:length(tiempos)
		ures[:, j + 1] = inv(matriz)*ures[:, j]
	end
	return xExtendido, yExtendido, ures
	# devuelvo la solución (matriz de para cada tiempo los valores calculados), yExtendido : valores de y en un vector columna donde los primeros M-1 son y[1], los siguientes M-1 son y[2],... así hasta y[N-1]. xExtendido: en cada bloque de M-1 pones x[1],...,x[M-1] y repetis para todos los bloques
end

# ╔═╡ 06993bfb-c342-4d0c-8307-710b8cb51952
# ╠═╡ disabled = true
#=╠═╡
im = load("ima.jpg") 
  ╠═╡ =#

# ╔═╡ 443da61a-eb49-4ac2-b3cf-7158b6f551e3
im2 = calor2d(-1.0, 1.0, -1.0, 1.0, 0.0, 0.8, u₀, 0.05, 0.05, 0.002, 0.2)

# ╔═╡ Cell order:
# ╠═7461b836-642e-11ed-1b02-eb8ede338e92
# ╠═9164b8ab-f60b-44bd-9386-d24cf2ab0b16
# ╠═013a4b3d-45d6-4b86-b9a9-293ff38ed7ec
# ╠═497ee1fc-bbcc-4e66-a8f4-5028556a5ed9
# ╠═9c03ac7e-fa35-48f7-bc42-0baf8c51dd0e
# ╠═2b8b45ef-43d3-49c5-9187-edb0cc15444f
# ╠═06993bfb-c342-4d0c-8307-710b8cb51952
# ╠═443da61a-eb49-4ac2-b3cf-7158b6f551e3
