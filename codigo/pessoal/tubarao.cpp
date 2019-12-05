#include "tubarao.h"

Tubarao::Tubarao(){
    model = new Model3DS("../3ds/shark.3DS");
    tipoObjeto = 'T';
}
Tubarao::Tubarao(Vetor3D t, Vetor3D a, Vetor3D s){
    this->t = t;
    this->a = a;
    this->s = s;
    model = new Model3DS("../3ds/shark.3DS");
    tipoObjeto = 'T';
}

void Tubarao::desenha()
{
    Objeto::desenha();
    glPushMatrix();
        glTranslatef(1,-1,0);
        glRotatef(-90,1,0,0);
        glRotatef(90,0,0,1);
        glScalef(0.02,0.02,0.02);
        model->draw();
    glPopMatrix();
}

