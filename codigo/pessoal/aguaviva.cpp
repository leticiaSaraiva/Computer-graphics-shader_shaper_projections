#include "aguaviva.h"

AguaViva::AguaViva()
{
    model = new Model3DS("../3ds/agua-viva2.3DS");
    tipoObjeto = 'A';
}

AguaViva::AguaViva(Vetor3D t, Vetor3D a, Vetor3D s){
    this->t = t;
    this->a = a;
    this->s = s;
    model = new Model3DS("../3ds/agua-viva2.3DS");
    tipoObjeto = 'A';
}

void AguaViva::desenha()
{
    Objeto::desenha();
    glPushMatrix();
        glTranslatef(0,-1.2,0);
        glRotatef(-90,1,0,0);
        glScalef(0.1,0.1,0.1);
        model->draw();
    glPopMatrix();
}
