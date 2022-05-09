#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
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
    while (posicion!=0 and ((esPosicionPar and heap[posicion]>heap[(posicion-2)/2]) or ((not esPosicionPar and heap[posicion]>heap[(posicion-1)/2])))){
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

void inicializarFuenteUnica(map<pair<int, int>, int> &grafo, int tamanioGrafo, vector<pair<int, int>> &s, int nodoInicial){
    for (int i = 0; i < tamanioGrafo; ++i) {
        s[i] = make_pair(1147483647, -1); // todos los nodos al empezar tienen dis infinita al inicial y no tienen padre
    }
    s[nodoInicial] = make_pair(0, -1); // mienteas que el inicial tiene distancia 0, y tampoco tiene padre
}

void relajarArista(int u, int v, map<pair<int, int>, int> &grafo, vector<pair<int, int>> &s){
    if(grafo.count(make_pair(u,v))>0){
        if(s[v].first>s[u].first+grafo[make_pair(u,v)]){ // si el costo en disancia de llegar a v es MAYOR que el de ir a u mas el de la arista UV.
            s[v]= make_pair(s[u].first +grafo[make_pair(u,v)], u); // actualizo nuevo camino para ir a V
        }
    }
}

bool bellmanFord(map<pair<int, int>, int> &grafo, int tamanioGrafo, vector<pair<int, int>> &s, int nodoInicial){
    inicializarFuenteUnica(grafo,  tamanioGrafo, s,  nodoInicial);
    for (int i = 0; i < tamanioGrafo; ++i) {
        for( auto k : grafo){
            int u = k.first.first;
            int v = k.first.second;
            relajarArista(u,v, grafo, s);
        }
    }
    // fijarme si tiene ciclos negativos:
    for( auto k : grafo){
        int u = k.first.first;
        int v = k.first.second;
        if(s[v].first > s[u].first + k.second){
            return false;
        }
    }
    return true;

}

void dijkstra(map<pair<int, int>, int> &grafo, int tamanioGrafo, vector<pair<int, int>> &s, int nodoInicial){
    inicializarFuenteUnica(grafo,  tamanioGrafo, s,  nodoInicial);
    vector<int> definitivos(0);

}
int main() {
    Heap<int> h1 = Heap<int>();
    vector<int> v = {1,2,3,4,5,6,7};
    h1.makeHeapFromVector(v);
    h1.agregarElemento(8);
    h1.agregarElemento(9);
    h1.agregarElemento(10);

    h1.desencolar();
    h1.desencolar();
    h1.desencolar();

    map<pair<int, int>, int> grafo = {
            {make_pair(0,1), -10},
            {make_pair(1,2), 5},
            {make_pair(2,3), 15},
            {make_pair(3,0), 10},
            {make_pair(2,0), 7},
            {make_pair(0,5), -3},
            {make_pair(5,4), -1},
            {make_pair(4,3), -5}

    };
    int tamanioGrafo = 8;
    vector<pair<int,int>> s(tamanioGrafo);
    int nodoInicial = 5;

    cout << bellmanFord(grafo, tamanioGrafo, s, nodoInicial);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
