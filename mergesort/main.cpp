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

template<typename tipo>
tipo mergeOrdenado(tipo tA, tipo tB){
    tipo tC;
    int indA= 0;
    int indB= 0;
    while( indA< tA.size() and  indB< tB.size() ){
        if(tA[indA]<tB[indB]){
            tC.push_back(tA[indA]);
            indA ++;
        }
        else{
            tC.push_back(tB[indB]);
            indB ++;
        }
    }
    while( indA< tA.size()){
        tC.push_back(tA[indA]);
        indA ++;
    }

    while( indB< tB.size()){
        tC.push_back(tB[indB]);
        indB ++;
    }
    return tC;
}

template<typename tipo>
void mergeSort(tipo &tA){
    if(tA.size()<2){
        return;
    }
    else{
        if(tA.size() == 2){
            if(tA[0]>tA[1]){
                float aux = tA[0];
                tA[0] = tA[1];
                tA[1] = aux;
            }
        }
        else {
            int mitad = int(tA.size() / 2);
            tipo primeraParte;
            tipo segundaParte;
            for(int i=0; i<tA.size(); i++){
                if(i<mitad){
                    primeraParte.push_back(tA[i]);
                }
                else{
                    segundaParte.push_back(tA[i]);
                }
            }
            mergeSort(primeraParte);
            mergeSort(segundaParte);
            tA = mergeOrdenado( primeraParte, segundaParte);
        }
    }
}
template<class tipo1>
bool estaOrdenado(vector<tipo1> v){
    bool res = true;
    for(int i=0; i<v.size()-1; i++){
        res = res and v[i] <= v[i+1];
    }
    return res;
}

template<typename tipo>
void swap(tipo &tA, int i, int j){
    auto old = tA[i];
    tA[i] = tA[j];
    tA[j] = old;
}

template<typename tipo>
void revertirOrden(tipo &tA){
    for(int i=0; i<int(tA.size()/2); i++){
        swap(tA, i, tA.size()-i-1);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<float> v1 = {-1.1, 1.1 ,21.1,32.1, 139.1,0};
    vector<float> v2 = {-2.1, 2.1 ,4.1,13.1, 16.1, 90, 150};
    vector<float> v4 = {52.1, 2.1 ,14.1,13.1, 16.1, 90, 1};

    int largo = 10000;
    vector<float> v={};
    for(int j=0; j<largo; j++){
        float q = j;
        float p = 0.1 + q/(q+1) + (rand()%largo) ;
        v.push_back(p);
        //v.push_back(j);
    }


    //visualizarVector(v);
    cout << endl;

    //visualizarVector(v);
    //cout << estaOrdenado(v);
    cout << endl;

    mergeSort(v1);
    visualizarVector(v1);
    revertirOrden(v1);
    visualizarVector(v1);

    //cout << estaOrdenado(v);


    return 0;
}
