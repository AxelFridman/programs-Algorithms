//
// Created by Axel on 27/05/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void revertirVector(vector<int> &v){ // Dado un vector con elementos a1, a2 , ..., an-1, an. devuelve: an, an-1, ... a2, a1.
    vector<int> w = {};
    for (int i = v.size()-1; i >= 0; --i) {
        w.push_back(v[i]);
    }
    v= w;
}
void visualizarVectorAristasMalas(const vector<pair<int,int>> s, int u, int v){ // Esta funcion se corre en caso de haber encontrado un ciclo negativo.
    // Lo que hace es imprimir el cero, lo cual indica en el algoritmo de johnson que hubo ciclo negativo.
    // Luego busca todos los nodos participantes de ese ciclo y los imprime.
    vector<int> nodos={};
    int nodoActual = u;
    while(nodoActual!=v){
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
void visualizarVector(const vector<tipo> v){ // Da una manera facil de ver las distancias desde un nodo. (que es un vector de pares distancia, padre)
    for(int i=0;i<v.size();i++){
        if(v[i].first<114748364) { // Este valor es considerado infinito, con lo cual si es menor se imprime y sino se escribe INF
            std::cout << v[i].first << " ";
        }
        else{
            std::cout << "INF " ;
        }
    }
    std :: cout << " "<< endl ;
}

template<typename tipo>
void visualizarMatrizPares(const vector<vector<tipo>> m){ // Dada una matriz de pares distancia, padre. Te la imprime las distancias al llamar N veces al visualizar fila.
    for(int i=0;i<m.size();i++){
        visualizarVector(m[i]);
    }
    std :: cout << " "<< endl ;
}

template<class tipo1>
class Heap {
private:

    int longi;
    vector<tipo1> heap; // El heap en si implementado sobre vector
    map<tipo1,int> mapaNodoIndices; // El diccionario que me dice donde esta parado cada elemento en el heap, si es que esta.
public:

    Heap(); // Crea heap constructor

    void agregarElemento(const tipo1& elem); // Agrega un elemento al heap

    void bajar(vector<tipo1> &v, int i); // Reacomoda heap desde la pos i. Hasta que ya no puede bajar mas en el heap

    void subir(vector<tipo1> &v, int i);  // Reacomoda heap desde la pos i. Hasta que ya no puede subir mas en el heap

    void swap(vector<tipo1> &v, int i, int j); // Funcion interna para reacomdor heap y su diccionario de donde esta elemento.
    // se usa cuando recibe vector por parametro, cuando se desencola o cualquier operacion que requiera luego restablecer invariante.

    tipo1 desencolar(); // Saca elemento minimo y reacomoda para que siga siendo heap

    int longitud() const; // Devuelve la longitud

    vector<tipo1> verHeap();
    // funcion que permite recibir un vector y pasarlo a heap.

    void makeHeapFromVector(vector<tipo1> v); // Descarta lo que tenia antes guardado como heap, Le pasas un vector, te lo hace heap y es el nuevo heap.

    int dameIndiceDeElemento(tipo1 elem); // Dado un elemento, te dice en que posicion esta guardado en el heap, en que indice

    void modificarElemento(tipo1 viejoElem, tipo1 nuevoElem); // Dado un elemento VIEJO, y un NuEVOeLEMENTO QUE lo reemplazara, actualiza
    //el elemento viejo y ademas lo reacomoda con la nueva prioridad dentro del heap. Para mantener invariante
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
    // Dada una lista de adyacencia, setea en S el vector de pares distancia, padre.
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
    inicializarFuenteUnicaGrafoListaAdyacencia(grafo, s, nodoInicial); // Me pone todas las distancias en inf menos la propia. todos los padres en -1 (nil)
    for (int veces = 0; veces < grafo.size(); ++veces) {
        for (int i = 0; i < grafo.size(); ++i) {
            for (int j = 0; j < grafo[i].size(); ++j) {
                int u = grafo[i][j][0]; // origen
                int v = grafo[i][j][1]; // destino
                int k = grafo[i][j][2]; // peso
                relajarAristaListaAdyacencia(u, v, k, grafo, s); //Por cada arista la relajo N veces
            }
        }
    }

    // fijarme si tiene ciclos negativos:
    for (int i = 0; i < grafo.size(); ++i) {
        for (int j = 0; j < grafo[i].size(); ++j) {
            int u = grafo[i][j][0];
            int v = grafo[i][j][1];
            int k = grafo[i][j][2];
            if (s[v].first > s[u].first + k) { // Si alguna arista no me cumple la desigualdad triangular, hay ciclo negativo seguro, y es "cerrado" por esa arista
                visualizarVectorAristasMalas(s, u, v); // LLamo a la funcion que me da todas las aristas de v a u + u
                return false;
            }
        }
    }
    return true; // no tiene ciclos negativos, lo que se modifico fue s.
}


void dijkstra(vector<vector<vector<int>>> &grafo, vector<pair<int, int>> &s, int nodoInicial) {
    inicializarFuenteUnicaGrafoListaAdyacencia(grafo, s, nodoInicial); // Mismo que bellman ford.
    Heap<pair<int,int>> priorityQnodos = Heap<pair<int,int>>(); // Creo un heap vacio que representa los nodos que todavia no llegue.
    for (int i = 0; i <s.size() ; ++i) {
        // Agrego al heap el par s[i].first (la distancia desde el nodo inicial a i que empieza siendo INF) y como segundo elemento al nodo i-esimo.
        priorityQnodos.agregarElemento(make_pair(s[i].first, i));
    }
    // Ahora que tengo el heap armado completo, voy desencolando.
    while (priorityQnodos.longitud()>0){ // Hasta que se me vacie el heap
        pair<int,int> vmin = priorityQnodos.desencolar(); // Agarro al de distancia minima
        int nodo = vmin.second; // En particual quiero saber cual es ese nodo
        for(int i=0; i<grafo[nodo].size(); i++){ // Y ahora por cada arista que salga desde ese nodo que acabo de desencolar actualizo su nueva distancia.
            vector<int> arista = grafo[nodo][i];
            int u = arista[0];
            int v = arista[1];
            int disVieja = s[v].first;
            relajarAristaListaAdyacencia(u,v,arista[2], grafo, s); // Relajo arista
            priorityQnodos.modificarElemento(make_pair(disVieja, v), make_pair(s[v].first, v)); // Reflejo esta nueva relajada de arista en el heap.
        }
    }
}
bool johnson(vector<vector<vector<int>>> &grafo, vector<vector<pair<int, int>>> &M){
    // Recibo el grafo como lista de adyacencia, y M que es la matriz de pares (distancia, padre en camino minimo),
    // Cada arista es un vector es de 3 posiciones, origen, destino, peso.
    // Devuelve booleano que es si tiene o no ciclos negativos.
    int l = grafo.size();
    vector<vector<vector<int>>> gmod = grafo; //Copio grafo lista de adyacencia en nuevo grafo modificado al cual le agregare un nodo.

    //Ahora como voy al grafo modificado agregarle un nodo mas, cuya distancia a todos sea cero, primero creo todas sus aristas de este nuevo nodo l.
    vector<vector<int>> aristasNuevoNodo(0); // Vector vacio al cual le voy a agregar todas las aristas de l a cada nodo.
    for (int i = 0; i < grafo.size(); ++i) {
        vector<int> arista = {l,i,0}; // Creo arista de nuevo nodo l a cada otro nodo de peso 0.
        aristasNuevoNodo.push_back(arista); // Agrego a vector de aristas
    }
    gmod.push_back(aristasNuevoNodo); // Al nuevo grafo modifiado le agrego el nodo l y sus aristas

    vector<pair<int, int>> s(gmod.size()); // Me creo la estructura donde guardare pares distancia, padre en camino.
    bool noTieneCiclosNegativos = bellmanFordListaAdyacencia(gmod, s, gmod.size()-1); // Corro bellman ford en grafo modificado
    if(not noTieneCiclosNegativos){
        return false; // Si tuviera ciclos negativos, bellman ford me los encuentra y me da cual es su ciclo.
    }
    // En caso de que no tuviera ciclos negativos:

    gmod.erase(gmod.end()-1); //Borro el nodo que habia agregado el l del grafo mod.
    for (int i = 0; i < gmod.size(); ++i) { // Y ahora ajusto pesos para que todas las aristas sean no negativas.
        for (int arista = 0; arista < gmod[i].size(); ++arista) {
            gmod[i][arista][2] = gmod[i][arista][2] + s[gmod[i][arista][0]].first - s[gmod[i][arista][1]].first; // Modifico pesos
        }
    }
    // Ahora que todas las aristas son no negativas en gmod, puedo correr dijkstra para cada nodo.
    for (int i = 0; i < gmod.size(); ++i) {
        vector<pair<int, int>> s2(gmod.size());
        dijkstra(gmod,s2, i); // Corro dijkstra por cada nodo
        M[i] = s2; // Me guardo distancias y padre en camino en matriz de dijkstra por cada fila.
    }

    for (int i = 0; i < M.size(); ++i) {
        for (int j = 0; j < M[i].size(); ++j) {
            M[i][j].first = M[i][j].first - s[i].first + s[j].first; // reacomodo los pesos para tener los originales (revierto la primer modificacion)
        }
    }
    return true; // Devuelvo que no tiene ciclos negativos
}
vector<vector<vector<int>>> leerArchivoGrafoListaAdyacencia(string nombre){
    string archivo = nombre;//"/Users/imac/Documents/GitHub2/programas-algoritmos/graphAlgorithms/";
    //archivo.append(nombre);
    ifstream entradaArchivo(archivo.c_str());
    if(entradaArchivo.fail()){
        cout << "Error en archivo " << archivo << endl;
        exit(0);
    }
    string nada;
    int cantVertices;
    int cantAristas;
    int nodoSalida;
    int nodoEntrada;
    int peso;
    entradaArchivo >> cantVertices >> cantAristas  ;
    vector<vector<vector<int>>> grafoEntrada(cantVertices);
    while(entradaArchivo){
        entradaArchivo >> nodoSalida;
        entradaArchivo >> nodoEntrada;
        entradaArchivo >> peso;
        vector<int> arista = {nodoSalida, nodoEntrada, peso};
        grafoEntrada[nodoSalida].push_back(arista);
    }
    if(cantAristas>0 and cantVertices>0) {
        grafoEntrada[cantVertices - 1].erase(grafoEntrada[cantVertices - 1].end() - 1);
    }
    return grafoEntrada;
}
int main(){
    vector<vector<vector<int>>> grafo = leerArchivoGrafoListaAdyacencia("/Users/imac/Documents/GitHub2/programas-algoritmos/graphAlgorithms/NOMBRE.TXT"); //Debo pasar nombre de archivo y ubicacion
    vector<vector<pair<int, int>>> M(grafo.size()); // Debo antes de llamar a johnson crear la matriz donde guardare distancias y caminos.
    if(johnson(grafo, M)){
        cout << "1" << endl; // Formato en caso positivo
        visualizarMatrizPares(M); // Formato en caso positivo
    }    // formato en caso negativo se hace en otra funcion de manera automatica, despreocuparse.
    return 0;
}
