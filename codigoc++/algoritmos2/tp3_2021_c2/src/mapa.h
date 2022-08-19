//
// Created by Axel on 10/11/2021.
//

#ifndef TP3_ALGO2LANDIA_MAPA_H
#define TP3_ALGO2LANDIA_MAPA_H

class Mapa {
public:

    Mapa();

    Mapa(Nat ancho, Nat alto, set<Coordenada> elevaciones, map<Color, Coordenada> receptaculos);

    void agregarElevacion(Coordenada c);

    void agregarRampa(Coordenada c);

    bool enRango(Coordenada c);

    Nat dist(Coordenada c1, Coordenada c2);

    Nat ancho() const;

    Nat alto() const;

    TipoCasillero tipoCasillero(Coordenada c) const;

    bool esElevacion(Coordenada c) const;

    bool esRampa(Coordenada c) const;

    bool esPiso(Coordenada c) const;

    const map<Color, Coordenada>& receptaculos() const;

    Coordenada receptaculo(Color);


private:
    Nat _alto;
    Nat _ancho;
    map<Color, Coordenada> _receptaculos;
    vector<vector<TipoCasillero>> _mapa;

};

#endif // TP3_ALGO2LANDIA_MAPA_H
// #endif //TP3_ALGO2LANDIA_MAPA_H
