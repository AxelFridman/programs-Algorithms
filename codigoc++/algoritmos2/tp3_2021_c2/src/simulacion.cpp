#include "simulacion.h"
#include "aed2_mapa.h"

simulacion :: simulacion(const aed2_Mapa& mapa, const map<Color, Coordenada>& objetos, Coordenada inicio){
    _mapa = mapa;
    _posJug = inicio;
    _cantMov = 0;
    set<Objetivo> _objDisp;
    _cantObjRealizados = 0;
    string_map<Coordenada> _posObjetos;
    vector<Color> filasMapaObjetos(mapa.ancho());
    for (int i = 0; i < mapa.ancho() ; ++i) {
        filasMapaObjetos[i] = "";
    }
    for (int i = 0; i < mapa.alto() ; ++i) {
        _mapaObjetos.push_back(filasMapaObjetos);
    }
    auto it = objetos.begin();
    while(it != objetos.end()){
         _posObjetos.insert(make_pair(it->first,it->second));
         _coloresObjetos.insert(it->first);
         _mapaObjetos[it->second.first][it->second.second] = it->first;
         ++it;
    }
    vector<pair<Color,string_map<iterator<set<Objetivo>,Objetivo,Objetivo>>>> filasMapaCasillas(mapa.ancho());
    for (int i = 0; i < mapa.ancho() ; ++i) {
        string_map<iterator<set<Objetivo>,Objetivo,Objetivo>> arbolVacio;
        filasMapaCasillas[i] = make_pair("",arbolVacio);
    }
    for (int i = 0; i < mapa.alto() ; ++i) {
        _mapaColores.push_back(filasMapaCasillas);
    }
    auto it2 = mapa.receptaculos().begin();
    while(it2 != mapa.receptaculos().end()){
        _posCasillas.insert(make_pair(it->first,it->second));
        _mapaColores[it->second.first][it->second.second].first = it->first;
        ++it;
    }

}

bool simulacion:: mover(Direccion){

}

void simulacion:: agregarObjetivo(Objetivo){

}

const aed2_Mapa simulacion:: mapa() const{
    return _mapa;
}

Coordenada simulacion:: posObjetos(Color o){
    return _posObjetos.at(o);
}

const set<Color> simulacion:: coloresObjetos(Color o){
    return _coloresObjetos;
}

Coordenada simulacion:: posJug() const{
    return _posJug;
}

const ConjObjetivos& simulacion:: objetivosDisponibles() const{
    return _objDisp;
}

Nat simulacion:: cantMovimientos() const{
    return _cantMov;
}

Nat simulacion:: cantObjetivosRealizados() const{
    return _cantObjRealizados;
}

bool simulacion:: hayMovimiento(Direccion d, Coordenada p){
    bool res = false;
    Coordenada destino = siguientePosicion(d,p);
    if(enRango(_mapa,destino) && (not esPared(_mapa,destino) || (esPared(_mapa,destino)&& esPiso(_mapa,p)){
        res = true;
    }
    return res;
}

bool simulacion:: hayObjeto(Coordenada p){
    return _mapaObjetos[p.first][p.second] != "";
}

Coordenada simulacion:: siguientePosicion(Direccion d, Coordenada p){
    int x = 0;
    int y = 0;
    if(d==ARRIBA){
        x=1;
    }
    else if(d==ABAJO){
        x=-1;
    }
    else if(d==IZQUIERDA){
        y=-1;
    }
    else if(d==DERECHA){
        y=1;
    }
    Coordenada res = make_pair(p.first+x,p.second+y);
    return res;
}
