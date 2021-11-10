#ifndef OBJETIVO_H
#define OBJETIVO_H

#include "Tipos.h"

class Objetivo {
  public:
    
    Objetivo();

    Objetivo(const Color& objeto, const Color& receptaculo);

    const Color& objeto() const;
    
    const Color& receptaculo() const;
  
  private:
    //completar
};

#endif
