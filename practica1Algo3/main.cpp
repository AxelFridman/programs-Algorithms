#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template<typename tipo>
void visualizarVector(const vector<tipo> v){
    for(int i=0;i<v.size();i++){
        std :: cout << " "<<v[i] ;
    }
    std :: cout << " "<< endl ;
}


void visualizarMatriz(vector<vector<int> > v){
    std :: cout << "--------"<<endl ;
    for(int i=0;i<v.size();i++){
        visualizarVector(v[i]) ;
    }
    std :: cout << "--------"<<endl ;
}

void swapMio(vector<int>&v, int i, int j){
    int old = v[i];
    v[i] = v[j];
    v[j] = old;
}

bool matrizCumpleCondicion(vector<vector<int>> mat, int numMagico){
    for (int i = 0; i < mat.size(); i++) {
        int sumaFilas = 0;
        int sumaColumnas = 0;
        for(int j=0; j<mat.size(); j++) {
            sumaFilas = sumaFilas + mat[j][i];
            sumaColumnas = sumaColumnas + mat[i][j];
        }
        if(sumaFilas!=numMagico or sumaColumnas!= numMagico){
            return false;
        }
    }
    return true;
}

bool  sigueSiendoCuadradoPosible(vector<vector<int>> mat, int numMagico){
    for (int i = 0; i < mat.size(); i++) {
        int sumaFilas = 0;
        int sumaColumnas = 0;
        for(int j=0; j<mat.size(); j++) {
            sumaFilas = sumaFilas + mat[j][i];
            sumaColumnas = sumaColumnas + mat[i][j];
        }
        if(sumaFilas > numMagico or sumaColumnas > numMagico){
            //visualizarMatriz(mat);
            return false;
        }
    }
    return true;
}

void solucionesCuadradoMagico(int i, int j, vector<vector<int>> &cuadradoMagico, vector<int> numerosFaltantes, int numMagico, vector<vector<vector<int>>> &soluciones){
        if (numerosFaltantes.size() == 0) {
            // Caso en donde llegue al final.
            if (matrizCumpleCondicion(cuadradoMagico, numMagico)) {
                soluciones.push_back(cuadradoMagico);
            }
        } else {
            // Parte recursiva
            int nuevoI;
            int nuevoJ;
            if (i == cuadradoMagico.size() - 1) {
                nuevoI = 0;
                nuevoJ = j + 1;
            } else {
                nuevoI = i + 1;
                nuevoJ = j;
            }
            for (int k = 0; k < numerosFaltantes.size(); k++) {
                    cuadradoMagico[j][i] = numerosFaltantes[k];
                    int viejo = numerosFaltantes[k];
                    numerosFaltantes.erase(numerosFaltantes.begin() + k); //  sacar de numeros faltantes a la posicion k
                    if(sigueSiendoCuadradoPosible(cuadradoMagico, numMagico)) {
                        solucionesCuadradoMagico(nuevoI, nuevoJ, cuadradoMagico, numerosFaltantes, numMagico, soluciones);
                    }
                    cuadradoMagico[j][i] = 0;
                    numerosFaltantes.push_back(viejo);
                    swapMio(numerosFaltantes, numerosFaltantes.size() - 1, k);

                // agregar devuelt a numeros faltantes lo que era la posicion k anteriormente

            }
        }
}

vector<vector<vector<int>>> cuadradoMagico(int n, int numMagico){
    vector<vector<vector<int>>> res = {};
    vector<vector<int>> m = {};
    vector<int> v(n);
    for (int j = 0; j<n; j++){
        m.push_back(v);
    }
    vector<int> numerosFaltantes = {};
    for(int k=1; k<=pow(n,2); k++){
        numerosFaltantes.push_back(k);
    }
    solucionesCuadradoMagico(0,0, m, numerosFaltantes, numMagico, res);
    return res;
}
int maxi(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int mini(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
int sumaDesdeHasta(vector<int> v, int i, int j){
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum = sum + v[k];
    }
    return sum;
}
int numeroJugadorEjPracticoClase(vector<int> v, int i, int j, int sumaT, vector<vector<int>> &mat){
    if(j-i<=1){
        return maxi(v[i], v[j]);
    }
    if(mat[i][j]==0) {
        mat[i][j] = maxi(sumaT - numeroJugadorEjPracticoClase(v, i + 1, j, sumaT - v[i], mat),
                    sumaT - numeroJugadorEjPracticoClase(v, i, j - 1, sumaT - v[j], mat));
    }
    return mat[i][j];
}
int sumaDeMonedas(vector<int> &solucionParcial){
    int suma = 0;
    for (int i = 0; i < solucionParcial.size(); ++i) {
        suma = suma + solucionParcial[i];
    }
    return suma;
}

int maximaGananciaAstroVoid(int c, int j, vector<int> precios, vector<vector<int>> &estructuraMemoizacion){
    if(j==-1){
        return 0;
    }
    if(c<0 or c>j){
        return -99999999;
    }
    if(estructuraMemoizacion[c][j]==0){
        estructuraMemoizacion[c][j] = maximaGananciaAstroVoid(c-1, j-1, precios, estructuraMemoizacion);
    }
    if(estructuraMemoizacion[c+2][j]==0){
        estructuraMemoizacion[c+2][j] = maximaGananciaAstroVoid(c+1, j-1, precios, estructuraMemoizacion) ;
    }
    if(estructuraMemoizacion[c+1][j]==0){
        estructuraMemoizacion[c+1][j] = maximaGananciaAstroVoid(c, j-1, precios, estructuraMemoizacion);
    }
    int siComp = estructuraMemoizacion[c][j] - precios[j];
    int siVend = estructuraMemoizacion[c+2][j]+ precios[j];
    int SiNada = estructuraMemoizacion[c+1][j];
    estructuraMemoizacion[c+1][j+1] = maxi(siComp, maxi(siVend, SiNada));
    return estructuraMemoizacion[c+1][j+1];
}
vector<vector<int>> minimaVidaJuego(vector<vector<int>> juego){
    vector<vector<int>> estructuraMemoizacion={};
    vector<int> js(juego[0].size());
    for (int i = 0; i < juego.size(); ++i) {
        estructuraMemoizacion.push_back(js);
    }
    estructuraMemoizacion[0][0] = maxi(1, - juego[0][0] + 1);
    for (int i = 0; i < juego[0].size(); ++i) {
        for (int j = 0; j < juego.size(); ++j) {
            if(i==0 and j!=0){
                estructuraMemoizacion[j][i] = maxi(estructuraMemoizacion[j-1][i]-juego[j][i], 1);
            }
            if(j==0 and i!=0) {
                estructuraMemoizacion[j][i] = maxi(estructuraMemoizacion[j][i - 1] - juego[j][i], 1);
            }
            else{
                if(i!=0 and j!=0){
                    int mins = mini(estructuraMemoizacion[j][i-1], estructuraMemoizacion[j-1][i]);
                    estructuraMemoizacion[j][i] = maxi(mins- juego[j][i], maxi(1, mins));
                }
            }
        }
    }
    return estructuraMemoizacion;
}
int main() {
    /*
    vector<vector<int>> estructuraMemoizacion={};
    vector<int> monedas = {1,2,4,8,1,0,10};
    vector<int> js(monedas.size()+1);
    for (int i = 0; i < js.size()+1; ++i) {
        estructuraMemoizacion.push_back(js);
    }
    visualizarMatriz(estructuraMemoizacion);
    std :: cout <<  maximaGananciaAstroVoid(0, monedas.size()-1, monedas, estructuraMemoizacion) ;
    */
    vector<vector<int>> juego = {{-11,-1,2},{-4,2,-1},{-1,1,30}};
    vector<vector<int>> res = minimaVidaJuego(juego);
    visualizarMatriz(juego);
    visualizarMatriz(res);
    return 0;
}
