#ifndef ALGASMARINHAS_H
#define ALGASMARINHAS_H

#include <objeto.h>

class AlgasMarinhas : public Objeto
{
public:
    AlgasMarinhas();
    AlgasMarinhas(Vetor3D t, Vetor3D a, Vetor3D s);
    void desenha();
};

#endif // ALGASMARINHAS_H
