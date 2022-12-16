### A Pluto.jl notebook ###
# v0.19.11

using Markdown
using InteractiveUtils

# ╔═╡ daf6eeae-5eac-11ed-28e5-fd61125c0d04
begin
	using Random
	using LinearAlgebra
	using Plots
end

# ╔═╡ 7b031bac-8aa2-4709-b997-b25193afae63
Int.(round.(abs.(rand(Float64, 10))))

# ╔═╡ 4920981b-1f55-4ca1-9426-03f9120f5b43
function actualizarTemperatura(matriz, tempActual)
	print(length(tempActual))
	print("    ")
	print(length(matriz))
	print("  ---  ")
	return (matriz \ tempActual)
end

# ╔═╡ 07d0783f-3dbc-4fca-b03f-6be85d2483bd


# ╔═╡ 1b9ae998-5492-4148-85c0-2dacaa88901f
function ecuacionesDeCalor(tempInicial, xspan, tspan)
	r = (tspan[2]-tspan[1]) / (xspan[2]-xspan[1])^2
	dlor = (-2*r +1)*ones(length(xspan[2:end-1]))
	dllor = r*ones(length(xspan[2:end-1])-1)
	dulor = r*ones(length(xspan[2:end-1])-1)
	A = Tridiagonal(dllor ,dlor , dulor )
	
	temps = [tempInicial]
	for i in 1:length(tspan)
		push!(temps,(A * temps[i]))
	end
	return temps
end

# ╔═╡ 77dcdaa7-7a62-43c3-b2ab-f8270f4d3cab
function metodoImplicito(xspan, tspan, datoIni, borde1, borde2, alpha)
	r = alpha*(tspan[2]-tspan[1]) / (xspan[2]-xspan[1])^2
	dlor = (2*r +1)*ones(length(xspan[2:end-1]))
	dllor = -r*ones(length(xspan[2:end-1])-1)
	dulor = -r*ones(length(xspan[2:end-1])-1)
	A = Tridiagonal(dllor ,dlor , dulor )
	
	bordes = zeros(length(datoIni))
	bordes[1] = borde1 * r
	bordes[end] = borde2 * r
	
	temps = [datoIni]
	for i in 1:length(tspan)
		push!(temps, A \ (temps[i] + bordes ))
	end
	return temps
end

# ╔═╡ de7eaaeb-5767-42c3-bd79-4653fcc8549d
tspan2 = 0:0.5:60

# ╔═╡ 8ddc77ab-0189-4751-b861-5df3361395a3
xspan = -1000:0.1:1000

# ╔═╡ 35d6b738-bae7-4a31-9273-879c8ea85fac
borde1 = 10

# ╔═╡ 910e9e80-5d67-4855-8c4a-5ab92413ab3a
borde2 = -20

# ╔═╡ 739abc4a-05cd-4715-9881-80e64b50244a
alpha = 98.8 #aluminio con milimiteros cuadrados sobre seg

# ╔═╡ e97e78bf-9d32-415c-80ec-42a15afb7a19
datosIniciales = xspan[2:end-1].*1 .+ sin.(π*xspan[2:end-1])

# ╔═╡ e07fde91-63b4-46bf-9004-23cfefc98563
temperaturas = metodoImplicito(xspan, tspan2, datosIniciales, borde1, borde2, alpha)

# ╔═╡ 11bbc342-f5af-4a93-9d94-dedec039297d
@gif for i in 1:1:length(temperaturas)
	plot(xspan[2: end - 1], temperaturas[i], label="",ylim=(-2000,2000))
end

# ╔═╡ 1cbb8350-de06-4639-bb83-b489db0027c4
# ╠═╡ disabled = true
#=╠═╡
tempec = ecuacionesDeCalor(datosIniciales, xspan, tspan2)
  ╠═╡ =#

# ╔═╡ a5703c70-3f9a-483b-843b-1c4316fd9bb6
# ╠═╡ disabled = true
#=╠═╡
@gif for i in 1:100:length(tempec)
	plot(xspan[2: end - 1], tempec[i], label="",ylim=(-10,10))
end
  ╠═╡ =#

# ╔═╡ 8bb8b29d-cf3c-483b-ad94-708776be49b3
plot(xspan[2: end - 1], temperaturas[1], label="primero")

# ╔═╡ 8f21ea17-da8f-46cb-b232-4aa120c9764d
md"""
Ec de calor 2d
"""

# ╔═╡ 954b985b-f26b-44d7-bde6-3bee88c6fea8
begin
	tsp = 0:0.1:10
	xsp = 0:0.5:10
	ysp = 0:0.5:10
	datosIniMat = zeros(length(xsp)-1, length(ysp)-1)
	datosIniMat[Int(round(length(xsp)/2)), Int(round(length(ysp)/2)) ] = 100
end

# ╔═╡ c3ef61cf-e56b-4b71-b4fe-a3934d3b0807
function ec2dCalor(datosInicialesMatriz, tspan, xspan, yspan, alpha)

end

# ╔═╡ Cell order:
# ╠═daf6eeae-5eac-11ed-28e5-fd61125c0d04
# ╠═7b031bac-8aa2-4709-b997-b25193afae63
# ╠═4920981b-1f55-4ca1-9426-03f9120f5b43
# ╠═07d0783f-3dbc-4fca-b03f-6be85d2483bd
# ╠═1b9ae998-5492-4148-85c0-2dacaa88901f
# ╠═77dcdaa7-7a62-43c3-b2ab-f8270f4d3cab
# ╠═de7eaaeb-5767-42c3-bd79-4653fcc8549d
# ╠═8ddc77ab-0189-4751-b861-5df3361395a3
# ╠═35d6b738-bae7-4a31-9273-879c8ea85fac
# ╠═910e9e80-5d67-4855-8c4a-5ab92413ab3a
# ╠═739abc4a-05cd-4715-9881-80e64b50244a
# ╠═e97e78bf-9d32-415c-80ec-42a15afb7a19
# ╠═e07fde91-63b4-46bf-9004-23cfefc98563
# ╠═11bbc342-f5af-4a93-9d94-dedec039297d
# ╠═1cbb8350-de06-4639-bb83-b489db0027c4
# ╠═a5703c70-3f9a-483b-843b-1c4316fd9bb6
# ╠═8bb8b29d-cf3c-483b-ad94-708776be49b3
# ╠═8f21ea17-da8f-46cb-b232-4aa120c9764d
# ╠═954b985b-f26b-44d7-bde6-3bee88c6fea8
# ╠═c3ef61cf-e56b-4b71-b4fe-a3934d3b0807
