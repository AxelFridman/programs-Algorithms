#include <iostream>
using namespace std;
#include <vector>

int sumaDesdeHasta(vector<int> vector1, int i, int j){
    int suma = 0;
    for(int z=i; z<j; z++){
        suma = suma + vector1[z];
    }
    return suma;
}

pair<int, int> maximaSubCentral(vector<int> vector1, int i, int medio, int j) {
    int maxDer = 0;
    int maxIzq = 0;
    int low = i;
    int high = medio;

    for(int k=i; k<medio ; k++){
        if(sumaDesdeHasta(vector1, low, medio)<sumaDesdeHasta(vector1, k, medio)){
            low = k;
        }
    }
    for(int z=medio; z<j+1 ; z++){
        if(sumaDesdeHasta(vector1, medio, high)<sumaDesdeHasta(vector1, medio, z)){
            high = z;
        }
    }
    return make_pair(low, high);
}

pair<int, int> maximaSubDesdeHasta(vector<int> vector1, int i, int j){
    if(j==i+1){
        return make_pair(i,j);
    }
    int medio = int((i+j)/2);
    pair<int, int> maxIzq = maximaSubDesdeHasta(vector1, i, medio);
    pair<int, int> maxDer = maximaSubDesdeHasta(vector1, medio, j);
    pair<int, int> maxCentral = maximaSubCentral(vector1, i, medio, j);

    if(sumaDesdeHasta(vector1, maxIzq.first, maxIzq.second)> sumaDesdeHasta(vector1, maxDer.first, maxDer.second) and
    sumaDesdeHasta(vector1, maxIzq.first, maxIzq.second)> sumaDesdeHasta(vector1, maxCentral.first, maxCentral.second)){
        return maxIzq;
    }
    else{
        if(sumaDesdeHasta(vector1, maxDer.first, maxDer.second)> sumaDesdeHasta(vector1, maxCentral.first, maxCentral.second)){
            return maxDer;
        } else{
            return maxCentral;
        }
    }

}


pair<int, int> maximaSubsecuenciaContigua(vector<int> v){
    return maximaSubDesdeHasta(v, 0, v.size());
}

int main() {
    vector<int> v = {13,-1,-4, -8, 3, -70, 0, 9, 1, 30};
    pair<int, int> mx = maximaSubsecuenciaContigua(v);
    std::cout << mx.first << " "<< mx.second << std::endl;
    return 0;
}
