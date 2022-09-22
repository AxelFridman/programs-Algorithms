### A Pluto.jl notebook ###
# v0.19.9

using Markdown
using InteractiveUtils

# ╔═╡ fa37b253-2fed-41f9-8a53-30f255798cf7
import Pkg; Pkg.add("Plots")

# ╔═╡ 31e80c6e-3a88-11ed-0a7b-ebb6e1e98016
begin 
	using Plots, DifferentialEquations
end

# ╔═╡ 2769009a-9629-4678-88a8-31ba198148a2
begin
	xIni,yIni,zIni = 0,0,0.0
	v = -0.1
	xVelIni, yVelIni, zVelIni = v,0, 0
	
	r = 1
	b = 8/3
	σ = 10
	
	datoInicialEspacial = [xIni, yIni, zIni, xVelIni, yVelIni, zVelIni]
	pInfo = [r, b, σ]
end

# ╔═╡ 82d6ab0e-5468-4d14-9a04-98f35cac2653
function atractorLorentz(du,u,pInfo,t)
	r, b, σ = pInfo
	
	du[1] = u[4]
	du[2] = u[5] 	
	du[3] = u[6]
	du[4] = σ*(u[2] − u[1])
	du[5] = r*u[1] − u[2] − u[1]*u[3]
	du[6] = u[1] * u[2] − b*u[3]

end

# ╔═╡ d8b5d01f-1383-4873-8769-3222c0322638
begin
	tIni = 0
	tFin = 30
	tspanLorentz = [tIni,tFin]
	Plorentz  = ODEProblem(atractorLorentz,datoInicialEspacial,tspanLorentz,pInfo)
	solLorentz = solve(Plorentz)
	
end

# ╔═╡ 6bed019c-f41c-4581-9951-08d997e935c1
n = length(solLorentz)

# ╔═╡ 8f869475-2f9d-49a1-b813-57a7b86a0bba
plot(solLorentz, idxs=(1,2,3), color=colormap("Blues", 10*n))

# ╔═╡ 7ced0d71-04ba-4eff-a2a4-fc5708805675


# ╔═╡ 23d0e5e4-b1a6-4142-bfc5-4614f6d8a1ac
function animar(sol, tIni, tFin, cantFrames, k )
	rangoTiempo = tIni: (tFin-tIni)/cantFrames : tFin
	vectorTiempos = zeros(cantFrames)
	for i in 1:cantFrames
		vectorTiempos[i] = rangoTiempo[i]
		
	end
	solCuerpos2 = sol(vectorTiempos)
	animacion = @animate for i in 1:length(solCuerpos2[1,:])
		
		plot(xlims=(-k, k),ylims=(-k, k),zlims=(-k, k))#xlims=xl,ylims=yl

		scatter!([solCuerpos2[1,i]], [solCuerpos2[2,i]], [solCuerpos2[3,i]],legend=:none)

	end
	return animacion
end

# ╔═╡ 0ae991d8-176a-4b85-b7f9-6b1ed12f2b18
an = animar(solLorentz, tIni, tFin, 800, 0.05 )

# ╔═╡ 2661d8a4-2af3-4648-bd98-ea5dea76a928
mp4(an)

# ╔═╡ 4aaa753e-864e-4822-a529-abef1b46be9d
animate(solLorentz,idxs=(1,2,3))

# ╔═╡ Cell order:
# ╠═31e80c6e-3a88-11ed-0a7b-ebb6e1e98016
# ╠═fa37b253-2fed-41f9-8a53-30f255798cf7
# ╠═2769009a-9629-4678-88a8-31ba198148a2
# ╠═82d6ab0e-5468-4d14-9a04-98f35cac2653
# ╠═d8b5d01f-1383-4873-8769-3222c0322638
# ╠═6bed019c-f41c-4581-9951-08d997e935c1
# ╠═8f869475-2f9d-49a1-b813-57a7b86a0bba
# ╠═7ced0d71-04ba-4eff-a2a4-fc5708805675
# ╠═23d0e5e4-b1a6-4142-bfc5-4614f6d8a1ac
# ╠═0ae991d8-176a-4b85-b7f9-6b1ed12f2b18
# ╠═2661d8a4-2af3-4648-bd98-ea5dea76a928
# ╠═4aaa753e-864e-4822-a529-abef1b46be9d
