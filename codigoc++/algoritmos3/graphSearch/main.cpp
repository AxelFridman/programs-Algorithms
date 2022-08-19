#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void revertirVector(vector<int> &v){
    vector<int> w = {};
    for (int i = v.size()-1; i >= 0; --i) {
        w.push_back(v[i]);
    }
    v= w;
}
void visualizarVectorAristasMalas(const vector<pair<int,int>> s, int u, int v){
    vector<int> nodos={};
    int nodoActual = u;
    while(nodoActual!=v){
        //std::cout << nodoActual << " ";
        nodos.push_back(nodoActual);
        nodoActual = s[nodoActual].second;
    }
    nodos.push_back(v);
    nodos.push_back(u);
    revertirVector(nodos);
    cout << "0"<< endl;
    for (int i = 0; i < nodos.size(); ++i) {
        cout << nodos[i] << " ";
    }
    cout << " "<< endl;
}

template<typename tipo>
void visualizarVector(const vector<tipo> v){
    for(int i=0;i<v.size();i++){
        if(v[i].first<114748364) {
            std::cout << v[i].first << " ";//<< " " << v[i].second << ") ;" ;
        }
        else{
            std::cout << "INF " ;
        }
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
    if(mapaNodoIndices.count(viejoElem)==0){
        return;
    }
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


void inicializarFuenteUnicaGrafoListaAdyacencia(vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s, int nodoInicial){
    for (int i = 0; i < grafo.size(); ++i) {
        s[i] = make_pair(1147483647, -1); // todos los nodos al empezar tienen dis infinita al inicial y no tienen padre
    }
    s[nodoInicial] = make_pair(0, -1); // mienteas que el inicial tiene distancia 0, y tampoco tiene padre
}



void relajarAristaListaAdyacencia(int u, int v, int k, vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s){
    if(s[v].first>s[u].first+k){ // si el costo en disancia de llegar a v es MAYOR que el de ir a u mas el de la arista UV.
        s[v]= make_pair(s[u].first +k, u); // actualizo nuevo camino para ir a V
    }
}

bool bellmanFordListaAdyacencia(vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s, int nodoInicial) {
    inicializarFuenteUnicaGrafoListaAdyacencia(grafo, s, nodoInicial);
    for (int veces = 0; veces < grafo.size(); ++veces) {
        for (int i = 0; i < grafo.size(); ++i) {
            for (int j = 0; j < grafo[i].size(); ++j) {
                int u = grafo[i][j][0];
                int v = grafo[i][j][1];
                int k = grafo[i][j][2];
                relajarAristaListaAdyacencia(u, v, k, grafo, s);
            }
        }
    }

    // fijarme si tiene ciclos negativos:
    for (int i = 0; i < grafo.size(); ++i) {
        for (int j = 0; j < grafo[i].size(); ++j) {
            int u = grafo[i][j][0];
            int v = grafo[i][j][1];
            int k = grafo[i][j][2];
            if (s[v].first > s[u].first + k) {
                visualizarVectorAristasMalas(s, u, v);
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
    //vector<int> definitivos(0);
    while (priorityQnodos.longitud()>0){
        pair<int,int> vmin = priorityQnodos.desencolar();
        int nodo = vmin.second;
        for(int i=0; i<grafo[nodo].size(); i++){
            vector<int> arista = grafo[nodo][i];
            int u = arista[0];
            int v = arista[1];
            int disVieja = s[v].first;
            relajarAristaListaAdyacencia(u,v,arista[2], grafo, s);
            priorityQnodos.modificarElemento(make_pair(disVieja, v), make_pair(s[v].first, v));
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
        vector<vector<vector<int>>> grafoEjtp = {
                {{0, 1, 3}},
                {{1, 2, 2}, {1, 3, -1}},
                { {2, 3, 6}},
                {{3, 0, -1}},

        };
        vector<vector<vector<int>>> grafoEjtp2 = {
                {{0, 1, -3}},
                {{1, 2, -2}, {1, 0, 5}},
                { {2, 3, 0}, {2,0,2}},
                {{3, 0, 5}},

        };
        vector<vector<vector<int>>> grafoListaAdyacencia = {
                {{0, 1, 1},  {0, 4, 1}},
                {{1, 2, 1}, {1, 5, 1}},
                { {2, 3, 1}},
                {{3, 0, 1}, {3, 5, 1}},
                {{4, 2, 1},  {4, 3, 1}},
                {{5, 0, 1},  {5, 4, 1}}
        };
        vector<vector<vector<int>>> falloDijkstra = {
                {{0, 1, 0}},
                {{1, 2, 0}, {1, 0, 2}},
                { {2, 3, 0}, {2, 1, 1}},
                {{3, 0, 0}},

        };

        vector<vector<pair<int, int>>> M(grafoEjtp2.size());
        if(johnson(grafoEjtp2, M)){
            cout << "1" << endl;
            visualizarMatrizPares(M);
        }

        /*
        vector<pair<int, int>> s(falloDijkstra.size());
        bellmanFordListaAdyacencia(falloDijkstra, s, 0);
        visualizarVector(s);
        dijkstra(falloDijkstra, s, 0);
        visualizarVector(s);
        /*
        bellmanFordListaAdyacencia(grafoListaAdyacencia, s, 4);
        visualizarVector(s);
        */
    }