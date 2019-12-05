#ifndef PEIXE_H
#define PEIXE_H

#include <objeto.h>

class Peixe : public Objeto
{
public:
    Peixe();
    Peixe(Vetor3D t, Vetor3D a, Vetor3D s);
    void desenha();
};

#endif // PEIXE_H
