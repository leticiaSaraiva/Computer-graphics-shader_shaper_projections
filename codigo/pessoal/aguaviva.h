#ifndef AGUAVIVA_H
#define AGUAVIVA_H


#include <objeto.h>

class AguaViva : public Objeto
{
public:
    Model3DS* model;
public:
    AguaViva();
    AguaViva(Vetor3D t, Vetor3D a, Vetor3D s);
    void desenha();
};

#endif // AGUAVIVA_H
