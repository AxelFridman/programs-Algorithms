//
// Created by Axel on 10/11/2021.
//

#include "aed2_mapa.h"
#include "mapa.h"

Mapa::Mapa() {

}


Coordenada Mapa::receptaculo(Color c) {
    return _receptaculos[c];
}

const map<Color, Coordenada> &Mapa::receptaculos() const {
    return _receptaculos;
}

Mapa::Mapa(Nat ancho, Nat alto, set<Coordenada> elevaciones, map<Color, Coordenada> receptaculos) {
    _ancho = ancho;
    _alto = alto;
    _receptaculos = receptaculos;
    vector<TipoCasillero> filas(ancho);
    for(int i = 0; i < alto; i++){
        filas[i]= PISO;
    }
    vector<vector<TipoCasillero>> columnas;
    for(int i = 0; i < alto; i++){
        columnas.push_back(filas);
    }
    _mapa = columnas;
}

void Mapa::agregarRampa(Coordenada c) {
    _mapa[c.first][c.second] = RAMPA ;
}
void Mapa::agregarElevacion(Coordenada c) {
    _mapa[c.first][c.second] = ELEVACION ;
}


Nat Mapa::ancho() const {
    return _ancho;
}

Nat Mapa::alto() const {
    return _alto;
}

TipoCasillero Mapa::tipoCasillero(Coordenada c) const {
    TipoCasillero casillero = PISO;
    if (_mapa[c.first][c.second] == RAMPA){
        casillero = RAMPA;
    }
    else if (_mapa[c.first][c.second] == ELEVACION){
        casillero = ELEVACION;
    }
    return casillero;
}

bool Mapa::esElevacion(Coordenada c) const {
    return tipoCasillero(c)==ELEVACION;
}

bool Mapa::esRampa(Coordenada c) const {
    return tipoCasillero(c)==RAMPA;
}

bool Mapa::esPiso(Coordenada c) const {
    return tipoCasillero(c)==PISO;
}

bool Mapa::enRango(Coordenada c) {
    bool res = 0 <= c.first;
    res = res and 0 <= c.second;
    res = res and ancho() >= c.first;
    res = res and alto() <= c.second;
    return res;
}

Nat Mapa::dist(Coordenada c1, Coordenada c2) {
    Nat a;
    Nat b;
    if(c1.first> c2.first){
        a = (c1.first - c2.first);
    }
    else{
        a = (c2.first - c1.first);
    }
    if(c1.second> c2.second){
        b = (c1.second - c2.second);
    }
    else{
        b = (c2.second - c1.second);
    }
    return (a+b);
}




