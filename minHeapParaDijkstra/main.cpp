#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


template<class tipo1>
class Heap {

private:

    int longi;
    vector<tipo1> heap;
public:

    /**
     * Constructor por defecto de la clase Heap.
     */
    Heap();


     // Agrega un elemento al heap
    void agregarElemento(const tipo1& elem);

    void bajar(vector<tipo1> &v, int i); // Reacomoda heap desde la pos i.

    // Funcion interna para reacomdor heap cuando recibe vector
    void array2heap(vector<tipo1> &v);

    void swap(vector<tipo1> &v, int i, int j);
    /**
     * Saca el elemento minimo del heap.
     * @param elem elemento a agregar
     */
    tipo1 desencolar();
    /**

    /**
     * Devuelve la cantidad de elementos que contiene la Lista.
     * @return
     */
    int longitud() const;
    vector<tipo1> verHeap();
    // funcion que permite recibir un vector y pasarlo a heap.
    void makeHeapFromVector(vector<tipo1> v);
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
void Heap<tipo1>::array2heap(vector<tipo1> &v) {
    for(int i=v.size()-1; i>=0; i--){
        bajar(v, i);
    }
}

template<class tipo1>
void Heap<tipo1>::makeHeapFromVector(vector<tipo1> v) {
    array2heap(v);
    heap = v;
    longi = heap.size();
    return;
}

template<class tipo1>
tipo1 Heap<tipo1>::desencolar() {
    tipo1 valor = heap[0];
    tipo1 ult = heap[longi-1];
    heap.erase(heap.end()-1);
    longi = longi-1;
    heap[0] = ult;
    bajar(heap, 0);

    return valor;
}

template<class tipo1>
void Heap<tipo1>::bajar(vector<tipo1> &v, int i) {
    while(2*i+1 < v.size() and (v[i]>v[2*i+1] or  v[i]>v[2*i+2]) ) {
        if (v[2 * i + 1] < v[2 * i + 2]) {
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
void Heap<tipo1>::swap(vector<tipo1> &v, int i, int j) {
    tipo1 aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

template<class tipo1>
void Heap<tipo1>::agregarElemento(const tipo1 &elem) {
    heap.push_back(elem);
    longi = longi + 1;
    int posicion = longi-1;
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
vector<tipo1> Heap<tipo1>::verHeap() {
    for(int i=0;i<heap.size();i++){
        std :: cout << " "<<heap[i] ;
    }
    std :: cout << " "<< endl ;
    return (heap);
}

int main() {
    Heap<int> h1 = Heap<int>();
    vector<int> v = {110, 12, 3, 1, -15, -60, -70};
    h1.makeHeapFromVector(v);
    h1.verHeap();
    h1.agregarElemento(8);
    h1.agregarElemento(9);
    h1.agregarElemento(10);

    h1.verHeap();

    h1.desencolar();
    h1.desencolar();
    h1.desencolar();

    h1.verHeap();

    vector<pair<int,int>> p = {make_pair(2,4), make_pair(1,5)};
    bool mayor = p[0]>p[1];
    std::cout << mayor << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
