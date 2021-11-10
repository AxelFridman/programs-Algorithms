#ifndef AED2_MAPA_H
#define AED2_MAPA_H

#include "Tipos.h"
#include "mapa.h"

using namespace std;

using Mapa = Mapa/* Completar con la clase Mapa implementada por ustedes */

class aed2_Mapa {
public:

	aed2_Mapa() {

    }

    /**
     * Pre:
     *  Todas las elevaciones están en rango. Todas las coordenadas de receptáculos
     *  están en rango y no se repiten.
     */
    aed2_Mapa(Nat ancho, Nat alto, set<Coordenada> elevaciones, map<Color, Coordenada> receptaculos) {
        Mapa* m_ = new Mapa(ancho, alto,elevaciones, receptaculos) ;
    }

    /**
     * Pre: 
     *  Existe c_1 adyacente a c que es piso y 
     *  existe c_2 adyacente a c que es elevación.
     */
    void agregarRampa(Coordenada c) {
        m_->agregarRampa(c);
    }

    Nat ancho() const {
        return m_->ancho();
    }

    Nat alto() const {
        return m_->alto();
    }

    TipoCasillero tipoCasillero(Coordenada c) const {
        return m_->tipoCasillero(c);
    }

    const map<Color, Coordenada>& receptaculos() const {
        return m_->receptaculos();
    }

    Coordenada receptaculo(Color c) {
        return m_->receptaculo(c);
    }

    // Conversiones
    
    // Esta función sirve para convertir del Mapa implementado por ustedes
    // a la clase Mapa de la cátedra

    aed2_Mapa(Mapa m) {
        *m_ = m ;
    }

    // Esta función sirve para convertir del Mapa de la cátedra (aed2_Mapa)
    // a la clase Mapa definida por ustedes
    Mapa mapa() const {
        return Mapa();
    }


private:
    Mapa* m_;
    //completar
};

#endif // AED2_MAPA_H