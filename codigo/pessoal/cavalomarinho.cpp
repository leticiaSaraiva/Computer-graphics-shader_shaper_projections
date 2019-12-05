#include "cavalomarinho.h"

CavaloMarinho::CavaloMarinho(){
    model = new Model3DS("../3ds/seahorse.3DS");
    tipoObjeto = 'C';
}
CavaloMarinho::CavaloMarinho(Vetor3D t, Vetor3D a, Vetor3D s){
    this->t = t;
    this->a = a;
    this->s = s;
    model = new Model3DS("../3ds/seahorse.3DS");
    tipoObjeto = 'C';
}

void CavaloMarinho::desenha()
{
    Objeto::desenha();
    glPushMatrix();
        glTranslatef(0,-0.4,0);
        glRotatef(-90,1,0,0);
        glScalef(0.1,0.1,0.1);
        model->draw();
    glPopMatrix();
}

