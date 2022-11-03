### A Pluto.jl notebook ###
# v0.19.9

using Markdown
using InteractiveUtils

# ╔═╡ 8c8a2fa8-e7cb-40e6-9c98-227237e91149
begin
	import Pkg
	Pkg.add("Plots")
end

# ╔═╡ fb455544-5608-11ed-2a0d-358c49ef59c5
begin
	using Random
	using LinearAlgebra
	using Plots
end

# ╔═╡ 3f968bb1-33fb-4577-b108-0a1e11f3f7dd
begin
	h = 0.1
	comienzo = -2
	fin = - comienzo
end

# ╔═╡ 53cc690f-6aaf-4c33-82b6-1a8fc7ff0a0e
tspan = comienzo:h:fin

# ╔═╡ fbee766e-f3f2-446b-b854-5f6b19be540e
begin
	f(x) = x^4
	fder(x) = x^3 *4
	fderSeg(x) = x^2 *12
	derReal = fder.(tspan)
	dersegReal = fderSeg.(tspan)
	
	u = f.(tspan)
	d = 2*ones(length(tspan))
	dl = -1*ones(length(tspan)-1)
	du = -1*ones(length(tspan)-1)
	A = Tridiagonal(dl ,d , du )
	
	d2 = 0*ones(length(tspan))
	dl2 = -1*ones(length(tspan)-1)
	du2 = 1*ones(length(tspan)-1)
	A2 = Tridiagonal(dl2 ,d2 , du2 )
end

# ╔═╡ 8fc60920-65bf-4b66-8339-e4bd4610472d
begin
	uprimaCentrada = 1/(h*2) * (A2 * u)
	uprimaSeg = -1/(h^2) * (A * u) #.+ u)
end

# ╔═╡ 08a00cc9-f2bd-4d67-92e8-997843a14a20
begin
	plot(tspan, u, label="original")
	plot!(tspan[2:end-1], uprimaCentrada[2:end-1], label="derivadaEstimada")
	plot!(tspan, derReal, label = "derivadaReal")
	
	errorDerivadaPromedioPorPunto = sum(abs.(uprimaCentrada[2:end-1] - derReal[2:end-1]))/(length(derReal)-2)
end

# ╔═╡ 2a9918bd-77cf-48fe-8332-a48d50fe0bbe
begin
	plot(tspan, u, label="original")
	plot!(tspan[2:end-1], uprimaSeg[2:end-1], label="derivadaSegEstimada")
	plot!(tspan, dersegReal, label = "derivadaSegReal")

	errorDerivadaSegPromedioPorPunto = sum(abs.(uprimaSeg[2:end-1] - dersegReal[2:end-1]))/(length(dersegReal)-2)
end

# ╔═╡ 56f84b43-ba7d-47b6-9a89-6276235d372b
begin
	e = 2.7182
	f3(x) = e^(cos(2*pi*x)) + cos(sin(5/(0.1+x^2)))
	u3 = f3.(tspan)
	uprimaCentrada3 = 1/(h*2) * (A2 * u3)
end

# ╔═╡ ab0894af-418c-4b74-acd4-580d82ff5233
begin
	plot(tspan, u3, label="original")
	plot!(tspan[2:end-1], uprimaCentrada3[2:end-1], label="derivadaEstimada")
end

# ╔═╡ f5334f2c-7555-4e91-9261-dee8e8ee2ff0
	

# ╔═╡ Cell order:
# ╠═8c8a2fa8-e7cb-40e6-9c98-227237e91149
# ╠═fb455544-5608-11ed-2a0d-358c49ef59c5
# ╠═3f968bb1-33fb-4577-b108-0a1e11f3f7dd
# ╠═53cc690f-6aaf-4c33-82b6-1a8fc7ff0a0e
# ╠═fbee766e-f3f2-446b-b854-5f6b19be540e
# ╠═8fc60920-65bf-4b66-8339-e4bd4610472d
# ╠═08a00cc9-f2bd-4d67-92e8-997843a14a20
# ╠═2a9918bd-77cf-48fe-8332-a48d50fe0bbe
# ╠═56f84b43-ba7d-47b6-9a89-6276235d372b
# ╠═ab0894af-418c-4b74-acd4-580d82ff5233
# ╠═f5334f2c-7555-4e91-9261-dee8e8ee2ff0
