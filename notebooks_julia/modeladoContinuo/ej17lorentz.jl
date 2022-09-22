### A Pluto.jl notebook ###
# v0.19.9

using Markdown
using InteractiveUtils

# ╔═╡ 3ab06fef-1313-4d8a-9855-d2b835118523
import Pkg; Pkg.add("Plots")

# ╔═╡ 0ee9e42e-deea-43a3-9b1d-1911a07e7599
begin 
	using Plots, DifferentialEquations
end

# ╔═╡ 6dea5ecf-6a70-4bcf-8786-ca11a0309913
begin
	xIni,yIni,zIni = 0,0,0.0
	v = -0.1
	xVelIni, yVelIni, zVelIni = v,0, 0
	
	m = 0.5
	B = [0,0, 0.11]
	q = 1
	
	datoInicialEspacial = [xIni, yIni, zIni, xVelIni, yVelIni, zVelIni]
	pInfo = [m, B, q]
end

# ╔═╡ 4aaeecff-317f-4d73-a382-7023adb10318
function atractorLorentz(du,u,pInfo,t)
	m, B, q = pInfo
	
	du[1] = u[4]
	du[2] = u[5] 	
	du[3] = u[6]
	du[4] = (q/m) * (u[5] * B[3] − u[6] * B[2])
	du[5] = (q/m) * (u[6] * B[1] − u[4] * B[3])
	du[6] = (q/m) * (u[4] * B[2] − u[5] * B[1])

end

# ╔═╡ 2eab02c8-4855-4d83-8c59-10399614c889
begin
	tspanLorentz = [0,60]
	Plorentz  = ODEProblem(atractorLorentz,datoInicialEspacial,tspanLorentz,pInfo)
	solLorentz = solve(Plorentz)
	
end

# ╔═╡ e67fa961-f03b-4848-954c-8aa216146136
plot(solLorentz, idxs=(1,2))

# ╔═╡ 53ec4523-6322-463f-a371-9c6c2fc2e5ec
animate(solLorentz, idxs=(1,2))

# ╔═╡ Cell order:
# ╠═0ee9e42e-deea-43a3-9b1d-1911a07e7599
# ╠═3ab06fef-1313-4d8a-9855-d2b835118523
# ╠═6dea5ecf-6a70-4bcf-8786-ca11a0309913
# ╠═4aaeecff-317f-4d73-a382-7023adb10318
# ╠═2eab02c8-4855-4d83-8c59-10399614c889
# ╠═e67fa961-f03b-4848-954c-8aa216146136
# ╠═53ec4523-6322-463f-a371-9c6c2fc2e5ec
