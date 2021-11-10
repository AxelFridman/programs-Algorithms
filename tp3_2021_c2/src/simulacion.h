
#ifndef AED2_SIMULACION_H
#define AED2_SIMULACION_H
#include "aed2_mapa.h"
#include "Tipos.h"
#include "Objetivo.h"
#include "mapa.h"
#include "string_map.h"

class simulacion {
public:

    /**
     * Pre:
     *  > inicio está en contenido en mapa
     *  > las coordenadas en objetos estan en mapa y no se repiten
     *  > las coordenadas en objetos no se solapan con la posición del agente
     */
    simulacion(const aed2_Mapa& mapa, const map<Color, Coordenada>& objetos, Coordenada inicio);

    bool mover(Direccion);

    void agregarObjetivo(Objetivo);

    const aed2_Mapa mapa() const;

    Coordenada posObjetos(Color o);

    const set<Color> coloresObjetos(Color o);

    Coordenada posJug() const;

    const ConjObjetivos& objetivosDisponibles() const;

    Nat cantMovimientos() const;

    Nat cantObjetivosRealizados() const;

    bool hayMovimiento(Direccion d, Coordenada p);

    bool hayObjeto(Coordenada p);

    Coordenada siguientePosicion(Direccion d, Coordenada p);




private:
    aed2_Mapa _mapa;
    ConjObjetivos _objDisp;
    vector<vector<Color>> _mapaObjetos;
    vector<vector<TuplaColor_Trie>> _mapaColores;
    string_map<Coordenada> _posObjetos;
    string_map<Coordenada> _posCasillas;
    ConjObjetos _coloresObjetos;
    Coordenada _posJug;
    Nat _cantMov;
    Nat _cantObjRealizados;

};

#endif // AED2_SIMULACION_H
