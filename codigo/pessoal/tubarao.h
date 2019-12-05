#ifndef TUBARAO_H
#define TUBARAO_H

#include <objeto.h>

class Tubarao : public Objeto
{
public:
    Model3DS* model;
public:
    Tubarao();
    Tubarao(Vetor3D t, Vetor3D a, Vetor3D s);
    void desenha();
};

#endif // TUBARAO_H
