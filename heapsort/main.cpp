#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
template<class tipo1>
void visualizarVector(const vector<tipo1> v){
    std :: cout << " "<<endl ;
    for(int i=0;i<v.size();i++){
        std :: cout << " "<<v[i] ;
    }
    std :: cout << " "<<endl ;

}

template<class tipo1>
void swap(vector<tipo1> &v, int i, int j){
    tipo1 aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

template<class tipo1>
void bajar(vector<tipo1> &v, int i){
    while(2*i+1 < v.size() and (v[i]<v[2*i+1] or  v[i]<v[2*i+2]) ) {
        if (v[2 * i + 1] > v[2 * i + 2]) {
            swap(v, i, 2 * i + 1);
            i = 2*i+1;
        }
        else {
            swap(v, i, 2 * i + 2);
            i = 2*i+2;
        }

    }
}
template<class tipo1>
void array2heap(vector<tipo1> &v){
    for(int i=v.size()-1; i>=0; i--){
        bajar(v, i);
    }
}
template<class tipo1>
tipo1 desencolar(vector<tipo1> &v){
    tipo1 valor = v[0];
    tipo1 ult = v[v.size()-1];
    v.erase(v.end()-1);
    v[0] = ult;
    bajar(v, 0);
    return valor;
}

template<class tipo1>
void heapsort(vector<tipo1> &v){
    array2heap(v);
    vector<tipo1> ordenado(v.size());
    for(int i=0; i<ordenado.size(); i++){
        ordenado[i] = desencolar(v);
    }
    v = ordenado;
}

template<class tipo1>
bool estaOrdenado(vector<tipo1> v){
    bool res = true;
    for(int i=0; i<v.size()-1; i++){
        res = res and v[i] >= v[i+1];
    }
    return res;
}
int main() {
    int largo = 10000000;
    vector<float> v={};
    for(int j=0; j<largo; j++){
        float q = j;
        float p = 0.1 + q/(q+1) + (rand()%largo) ;
        v.push_back(p);
        //v.push_back(j);
    }


    //visualizarVector(v);
    cout << endl;

    array2heap(v);
    //visualizarVector(v);
    cout << estaOrdenado(v);
    cout << endl;

    heapsort(v);
    //visualizarVector(v);
    cout << estaOrdenado(v);
    return 0;
}
