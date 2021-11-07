
#include "string_map.h"

bool esSubsecuencia(string a, string b){
    // devuelve verdadero si b es una subsecuencia de a
    if (b.size()>a.size()){
        return false;
    }
    bool res = true;
    for(int i = 0; i<b.size(); i++){
        res = res and b[i] == a[i];
    }
    return res;
}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR
    return _size == 0;
}

template <typename T>
string_map<T>::string_map(){
    // COMPLETAR
    _size = 0;
    Nodo* nodoRaiz = new Nodo;
    nodoRaiz->definicion= nullptr;
    nodoRaiz->clave = "";

    vector<Nodo*> siguientes = vector<Nodo*>(255);
    for(int j=0; j<siguientes.size(); j++){
        siguientes[j] = nullptr;
    }

    nodoRaiz->siguientes = siguientes;
    raiz = nodoRaiz;

}
template<typename T>
void string_map<T>::insert(const pair<string, T> & claveValor) {
    Nodo* base = raiz;
    string claveTemp = "";
    for(int i=0; i<claveValor.first.size(); i++){

        int caracterPasadoaEntero = claveValor.first[i] % 255;
        claveTemp.push_back(claveValor.first[i]);
        if(base->siguientes[caracterPasadoaEntero] == nullptr){
            Nodo* nuevoNodo = new Nodo;
            nuevoNodo->definicion= nullptr;
            nuevoNodo->clave= claveTemp;
            vector<Nodo*> siguientes = vector<Nodo*>(255);
            for(int j=0; j<siguientes.size(); j++){
                siguientes[j] = nullptr;
            }
            nuevoNodo->siguientes = siguientes;
            base->siguientes[caracterPasadoaEntero] = nuevoNodo;
        }
        base = base->siguientes[caracterPasadoaEntero];

    }
    T* def = new T;
    *def = claveValor.second;
    base->definicion = def;

    base->clave = claveValor.first;
    _size++;
}

template<typename T>
bool sonTodosNullptr(vector<T> v1){
    bool res = true;
    for(int i = 0; i<v1.size(); i++){
        res = res and v1[i]== nullptr;
    }
    return res;
}

template<typename T>
typename string_map<T>::Nodo* string_map<T>::Nodo::copiarNodo() {
    Nodo* copia = new Nodo;

    if(definicion!= nullptr){
        copia->definicion = new T(*definicion);
    }
    else{
        copia->definicion= nullptr;
    }

    copia->clave = clave;

    vector<Nodo*> siguientes1 = vector<Nodo*>(255);
    for(int j=0; j<siguientes1.size(); j++){
        siguientes1[j] = nullptr;
    }
    copia->siguientes = siguientes1;

    if(sonTodosNullptr(siguientes)){
        return copia;
    }
    else{
        for(int i = 0; i<siguientes.size(); i++){
            if(siguientes[i] != nullptr){
                copia->siguientes[i] = siguientes[i]->copiarNodo();
            }
        }
    }
    return copia;

}

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& copiado) {

    this->_size = copiado._size;


    Nodo* baseCopiado = copiado.raiz;

    //baseCopia = string_map<T>::Nodo::copiarNodo(baseCopiado);
    Nodo* baseCopia = baseCopiado->copiarNodo();
    this->raiz = baseCopia;


    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    if(_size == 0){
        return 0;
    }
    Nodo* base = raiz;
    bool hayMas = true;
    for(int i=0; i<clave.size() and hayMas; i++){
        if(base != nullptr and base->siguientes[clave[i]] != nullptr){
            base = base->siguientes[clave[i]];
        }
        else{
            hayMas = false;
        }
    }
    return (base->definicion!= nullptr and hayMas);
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* base = raiz;
    // COMPLETAR
    for(int i=0; i<clave.size(); i++) {

        int caracterPasadoaEntero = clave[i] % 255;
        base = base->siguientes[caracterPasadoaEntero];
    }
    string s = base->clave;
    return base->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
    Nodo* base = raiz;

    for(int i=0; i<clave.size(); i++) {

        int caracterPasadoaEntero = clave[i] % 255;
        base = base->siguientes[caracterPasadoaEntero];
    }
    string s = base->clave;
    return * base->definicion;
}

template<typename T>
bool string_map<T>::Nodo::esNodoValido(string claveABuscar, int i) {
    bool res = false;
    res = res or definicion!= nullptr;
    int ia = claveABuscar[i];
    for(int j=0; j<siguientes.size(); j++){

        if((siguientes[j]!= nullptr and j != ia)){
            res = true;
        }
        //res = res or (siguientes[j]!= nullptr and j != ia);
    }
    return (res);
}

template<typename T>
void string_map<T>::buscarYasignarComoNull(string clave) {
    Nodo* base = raiz;
    for(int i=0; i<clave.size()-1; i++){
        base = base->siguientes[clave[i]];
    }
    base->siguientes[clave[clave.size()-1]] = nullptr;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
    vector<Nodo*> ultimoNodoEnSuCamino = {};
    Nodo* base = raiz; //->siguientes[clave[0]];
    //La idea va a ser llegar hasta el nodo a borrar, recorriendo y guardando todos los nodos en su camino desde el ultimo valido hasta el que queremos borrar.
    // osea, en cuanto llego a uno valido, se resetea a al vector nulo.
    // un nodo "valido" es aquel que o tiene definicion para el o tiene algun otro siguiente que no sea el camino del que estoy buscando.
    for(int i=0; i<clave.size(); i++){
        if(base->esNodoValido(clave, i) or base==raiz){
            ultimoNodoEnSuCamino = {};
        }
        else{
            ultimoNodoEnSuCamino.push_back(base);
        }
        base = base->siguientes[clave[i]];
    }

    // delete base->definicion;
    base->definicion = nullptr;
    _size--;

    if(sonTodosNullptr(base->siguientes)) {
        delete base;
        for (int j = 0; j < ultimoNodoEnSuCamino.size(); j++) {
            if (ultimoNodoEnSuCamino[j]->definicion != nullptr) {
                delete ultimoNodoEnSuCamino[j]->definicion;
                _size--;
            }
            delete ultimoNodoEnSuCamino[j];
        }
        buscarYasignarComoNull(ultimoNodoEnSuCamino[0]->clave);
    }

}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
    return _size;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; }



// Provisto por la catedra: utiliza el operador asignacion para realizar la copia.
