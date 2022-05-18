#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

template<typename tipo>
void visualizarVector(const vector<tipo> v){
    for(int i=0;i<v.size();i++){
        std :: cout << " ("<<v[i].first << " " << v[i].second << ") ;" ;
    }
    std :: cout << " "<< endl ;
}
template<typename tipo>
void visualizarMatrizPares(const vector<vector<tipo>> m){
    for(int i=0;i<m.size();i++){
        visualizarVector(m[i]);
    }
    std :: cout << " "<< endl ;
}

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



void inicializarFuenteUnica(map<pair<int, int>, int> &grafo, int tamanioGrafo, vector<pair<int, int>> &s, int nodoInicial){
    for (int i = 0; i < tamanioGrafo; ++i) {
        s[i] = make_pair(1147483647, -1); // todos los nodos al empezar tienen dis infinita al inicial y no tienen padre
    }
    s[nodoInicial] = make_pair(0, -1); // mienteas que el inicial tiene distancia 0, y tampoco tiene padre
}

void inicializarFuenteUnicaGrafoListaAdyacencia(vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s, int nodoInicial){
    for (int i = 0; i < grafo.size(); ++i) {
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

void relajarAristaListaAdyacencia(int u, int v, int k, vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s){
    if(s[v].first>s[u].first+k){ // si el costo en disancia de llegar a v es MAYOR que el de ir a u mas el de la arista UV.
        s[v]= make_pair(s[u].first +k, u); // actualizo nuevo camino para ir a V
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
bool bellmanFordListaAdyacencia(vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s, int nodoInicial) {
    inicializarFuenteUnicaGrafoListaAdyacencia(grafo, s, nodoInicial);
    for (int veces = 0; veces < grafo.size(); ++veces) {
        for (int i = 0; i < grafo.size(); ++i) {
            for (int j = 0; j < grafo[j].size(); ++j) {
                int u = grafo[i][j][0];
                int v = grafo[i][j][1];
                int k = grafo[i][j][2];
                relajarAristaListaAdyacencia(u, v, k, grafo, s);
            }
        }
    }
    // fijarme si tiene ciclos negativos:
    for (int i = 0; i < grafo.size(); ++i) {
        for (int j = 0; j < grafo[j].size(); ++j) {
            int u = grafo[i][j][0];
            int v = grafo[i][j][1];
            int k = grafo[i][j][2];
            if (s[v].first > s[u].first + k) {
                return false;
            }
        }
    }
    return true;
}


void dijkstra(vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s, int nodoInicial) {
    inicializarFuenteUnicaGrafoListaAdyacencia(grafo, s, nodoInicial);
    Heap<pair<int,int>> priorityQnodos = Heap<pair<int,int>>();
    for (int i = 0; i <s.size() ; ++i) {
        priorityQnodos.agregarElemento(make_pair(s[i].first, i));
    }
    vector<int> definitivos(0);
    while (priorityQnodos.longitud()>0){
        pair<int,int> v = priorityQnodos.desencolar();
        int nodo = v.second;
        for(int i=0; i<grafo[nodo].size(); i++){
            vector<int> arista = grafo[nodo][i];
            relajarAristaListaAdyacencia(arista[0],arista[1], arista[2], grafo, s);
        }
    }
}
bool johnson(vector<vector<vector<int>>> &grafo, vector<vector<pair<int, int>>> &M){
    int l = grafo.size();
    vector<vector<vector<int>>> gmod = grafo;
    vector<vector<int>> aristasNuevoNodo(0);
    for (int i = 0; i < grafo.size(); ++i) {
        vector<int> arista = {l,i,0};
        aristasNuevoNodo.push_back(arista);
    }
    gmod.push_back(aristasNuevoNodo);
    vector<pair<int, int>> s(gmod.size());
    bool noTieneCiclosNegativos = bellmanFordListaAdyacencia(gmod, s, gmod.size()-1);
    if(not noTieneCiclosNegativos){
        return false;
    }
    gmod.erase(gmod.end()-1);
    for (int i = 0; i < gmod.size(); ++i) {
        for (int arista = 0; arista < gmod[i].size(); ++arista) {
            gmod[i][arista][2] = gmod[i][arista][2] + s[gmod[i][arista][0]].first - s[gmod[i][arista][1]].first;
        }
    }
    for (int i = 0; i < gmod.size(); ++i) {
        vector<pair<int, int>> s2(gmod.size());
        dijkstra(gmod,s2, i);
        M[i] = s2;
    }

    for (int i = 0; i < M.size(); ++i) {
        for (int j = 0; j < M[i].size(); ++j) {
            M[i][j].first = M[i][j].first - s[i].first + s[j].first;
        }
    }
    return true;
}
    int main() {
    vector<int> v = {1,2,34};
        vector<vector<vector<int>>> grafoListaAdyacencia = {
                {{0, 1, 4},  {0, 2, 3}},
                {{1, 0, 1}, {1, 2, 1}},
                {{2, 1, 2},  {2, 0, 5}}
        };

        /*
        vector<pair<int, int>> s(grafoListaAdyacencia.size());
        int nodoInicial = 2;
        bellmanFordListaAdyacencia(grafoListaAdyacencia, s, nodoInicial);
        visualizarVector(s);
        dijkstra(grafoListaAdyacencia, s, nodoInicial);
        visualizarVector(s);
        std::cout << "Hello, World!" << std::endl;
        return 0;
        */
        vector<vector<pair<int, int>>> M(grafoListaAdyacencia.size());
        johnson(grafoListaAdyacencia, M);
        visualizarMatrizPares(M);
    }