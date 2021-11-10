//
// Created by Axel on 10/11/2021.
//

#include "aed2_mapa.h"
#include "mapa.h"

Mapa::Mapa() {

}

Mapa Mapa::mapa() const {
    //vector<vector<tipoCasillero>> _mapa;
    //return Mapa;
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
    vector<int> filas(ancho);
    for(int i = 0; i < alto; i++){
        filas[i]= PISO;
    }
    vector<vector<int>> columnas;
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




