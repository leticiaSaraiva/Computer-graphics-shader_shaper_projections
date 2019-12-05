#ifndef CAVALOMARINHO_H
#define CAVALOMARINHO_H


#include <objeto.h>

class CavaloMarinho : public Objeto
{
public:
    Model3DS* model;
public:
    CavaloMarinho();
    CavaloMarinho(Vetor3D t, Vetor3D a, Vetor3D s);
    void desenha();
};
#endif // CAVALOMARINHO_H
