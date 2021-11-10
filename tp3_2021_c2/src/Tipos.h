#ifndef TIPOS_H
#define TIPOS_H

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
#include <string>
#include <map>
#include <list>
#include <vector>
#include "string_map.h"
#include "Objetivo.h"

using namespace std;

using Nat = unsigned int;

using Coordenada = pair<Nat, Nat>;

using Color = string;

using ConjObjetivos = set<Objetivo>;

using ConjObjetos = set<Color>;

using TuplaColor_Trie = pair<Color, string_map<iterator<set<Objetivo>,Objetivo,Objetivo>>>;

enum Direccion {
    ARRIBA, ABAJO, IZQUIERDA, DERECHA
};

enum TipoCasillero {
  PISO, RAMPA, ELEVACION
};

#endif // TIPOS_H
