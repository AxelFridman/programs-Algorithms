#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;


template<class tipo1>
class Heap {

private:

    int longi;
    vector<tipo1> heap;
    map<tipo1,int> mapaNodoIndices;
public:

    /**
     * Constructor por defecto de la clase Heap.
     */
    Heap();
     // Agrega un elemento al heap
    void agregarElemento(const tipo1& elem);

    void bajar(vector<tipo1> &v, int i); // Reacomoda heap desde la pos i.
    void subir(vector<tipo1> &v, int i);
    // Funcion interna para reacomdor heap cuando recibe vector
    void swap(vector<tipo1> &v, int i, int j);
    /**
     * Saca el elemento minimo del heap.
     * @param elem elemento a agregar
     */
    tipo1 desencolar();

    int longitud() const;
    vector<tipo1> verHeap();
    // funcion que permite recibir un vector y pasarlo a heap.
    void makeHeapFromVector(vector<tipo1> v);
    int dameIndiceDeElemento(tipo1 elem);
    void modificarElemento(tipo1 viejoElem, tipo1 nuevoElem);
};

template<class tipo1>
int Heap<tipo1>::longitud() const {
    return longi;
}

template<class tipo1>
Heap<tipo1>::Heap() {
    heap = vector<tipo1>(0);
    longi=0;
}


template<class tipo1>
void Heap<tipo1>::makeHeapFromVector(vector<tipo1> v) {
    for(int i=v.size()-1; i>=0; i--){
        bajar(v, i);
    }
    heap = v;
    longi = heap.size();
    for(int j=0; j<longi;j++){
        mapaNodoIndices[heap[j]]=j;
    }
    return;
}

template<class tipo1>
tipo1 Heap<tipo1>::desencolar() {
    tipo1 valor = heap[0];
    tipo1 ult = heap[longi-1];
    heap.erase(heap.end()-1);
    mapaNodoIndices.erase(valor);
    longi = longi-1;
    heap[0] = ult;
    bajar(heap, 0);

    return valor;
}

template<class tipo1>
void Heap<tipo1>::bajar(vector<tipo1> &v, int i) {
    bool a = (2*i+1 < v.size() and v[i]>v[2*i+1]);
    bool b = (2*i+2 < v.size() and v[i]>v[2*i+2]);
    while(a or b ) {
        if ( v[2 * i + 1] < v[2 * i + 2]) {
            swap(v, i, 2 * i + 1);
            i = 2*i+1;
        }
        else {
            swap(v, i, 2 * i + 2);
            i = 2*i+2;
        }
        a = (2*i+1 < v.size() and v[i]>v[2*i+1]);
        b = (2*i+2 < v.size() and v[i]>v[2*i+2]);
    }
}


template<class tipo1>
void Heap<tipo1>::swap(vector<tipo1> &v, int i, int j) {
    mapaNodoIndices[v[i]] = j;
    mapaNodoIndices[v[j]] = i;
    tipo1 aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

template<class tipo1>
void Heap<tipo1>::subir(vector<tipo1> &v, int i) {
    int posicion = i;
    if(posicion==0){
        return;
    }
    bool esPosicionPar = true;
    if(posicion%2==0){
        esPosicionPar = true;
    }
    else{
        esPosicionPar = false;
    }
    while (posicion!=0 and ((esPosicionPar and heap[posicion]<heap[(posicion-2)/2]) or ((not esPosicionPar and heap[posicion]<heap[(posicion-1)/2])))){
        if(esPosicionPar){
            swap(heap, posicion, (posicion-2)/2);
            posicion = (posicion-2)/2;
        }
        else{
            swap(heap, posicion, (posicion-1)/2);
            posicion = (posicion-1)/2;
        }
        if(posicion%2==0){
            esPosicionPar = true;
        }
        else{
            esPosicionPar = false;
        }
    }
}

template<class tipo1>
void Heap<tipo1>::agregarElemento(const tipo1 &elem) {
    heap.push_back(elem);
    longi = longi + 1;
    mapaNodoIndices[elem] = longi-1;
    subir(heap, longi-1);
}

template<class tipo1>
vector<tipo1> Heap<tipo1>::verHeap() {
    for(int i=0;i<heap.size();i++){
        std :: cout << " "<<heap[i] ;
    }
    std :: cout << " "<< endl ;
    return (heap);
}

template<class tipo1>
int Heap<tipo1>::dameIndiceDeElemento(tipo1 elem) {
    return mapaNodoIndices[elem];
}

template<class tipo1>
void Heap<tipo1>::modificarElemento(tipo1 viejoElem, tipo1 nuevoElem) {
    int ind = dameIndiceDeElemento(viejoElem);
    heap[ind] = nuevoElem;
    mapaNodoIndices.erase(viejoElem);
    mapaNodoIndices[nuevoElem] = ind;
    if(nuevoElem>viejoElem){
        bajar(heap, ind);
    }
    else{
        subir(heap, ind);
    }
}


int main() {


    Heap<int> h2 = Heap<int>();
    h2.verHeap();
    vector<int> v2 = {1,2,0,4};
    h2.makeHeapFromVector(v2);
    h2.verHeap();
    h2.agregarElemento(3);
    h2.agregarElemento(6);
    h2.agregarElemento(5);
    h2.agregarElemento(7);
    h2.verHeap();



    vector<pair<int,int>> p = {make_pair(2,4), make_pair(1,5)};
    bool mayor = p[0]>p[1];
    std::cout << mayor << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
