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

int main() {
    //int m = combinatorio(12,4);
    //vector<vector<vector<int>>> res = cuadradoMagico(3, 15);
    //for(int k=0; k<res.size(); k++){
    //    visualizarMatriz(res[k]);
    //}
    //std :: cout << res.size()<< endl ;
    vector<int> v= {1,20,30,400,5,60,7,8,9};
    //numeroJugadorEjPracticoClase(v, 0, v.size()-1);
    int a = 0;
    int b = v.size()-1;
    int sumaT = sumaDesdeHasta(v, a, b);
    vector<vector<int>> valores = {};
    vector<int> val(b+1);
    for (int j = 0; j<=b; j++){
        valores.push_back(val);
    }
    std :: cout << numeroJugadorEjPracticoClase(v, a, b, sumaT, valores)  << endl ;
    visualizarMatriz(valores);
    return 0;
}
