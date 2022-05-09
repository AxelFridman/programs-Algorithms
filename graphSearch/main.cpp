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
     * Constructor por defecto de la clase Lista.
     */
    Heap();
    /**
     Heap makeHeapFromVector(vector<tipo1>);

    /**
     * Agrega un elemento al principio de la Lista.
     * @param elem elemento a agregar
     */
    void agregar(const tipo1& elem);

    void bajar(vector<tipo1> &v, int i); // Reacomoda heap desde la pos i.
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


    Heap<tipo1> makeHeapFromVector(vector<tipo1> v);
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
Heap<tipo1> Heap<tipo1>::makeHeapFromVector(vector<tipo1> v) {
    Heap nuevo = Heap();
    array2heap(v);
    nuevo.heap = v;
    nuevo.longi = nuevo.heap.size();
    return nuevo;
}

template<class tipo1>
tipo1 Heap<tipo1>::desencolar() {
    tipo1 valor = heap[0];
    tipo1 ult = heap[longi-1];
    heap.erase(heap.end()-1);
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
