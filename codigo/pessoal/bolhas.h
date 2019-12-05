#ifndef BOLHAS_H
#define BOLHAS_H

#include <objeto.h>

class Bolhas : public Objeto
{
public:
    Bolhas();
    Bolhas(Vetor3D t, Vetor3D a, Vetor3D s);
    void desenha();
};

#endif // BOLHAS_H
