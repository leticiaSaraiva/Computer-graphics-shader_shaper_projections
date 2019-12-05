#ifndef BARCO_H
#define BARCO_H


#include <objeto.h>

class Barco : public Objeto
{
public:
    Barco();
    Barco(Vetor3D t, Vetor3D a, Vetor3D s);
    void desenha();
};
#endif // BARCO_H
