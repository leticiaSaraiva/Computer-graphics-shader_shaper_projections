#include "bolhas.h"

Bolhas::Bolhas(){
    tipoObjeto = 'b';
}
Bolhas::Bolhas(Vetor3D t, Vetor3D a, Vetor3D s){
    this->t = t;
    this->a = a;
    this->s = s;
    tipoObjeto = 'b';
}
void Bolhas::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        GUI::setColor(0.5,0.7,9);
        glTranslatef(0.1,0,0);
        glRotatef(0,0,0,0);
        glRotatef(0,0,0,0);
        glScalef(1,1,1);

        //Bolhas d'água
        glPushMatrix();
            GUI::drawSphere(0,0.15,0,0.14);
            GUI::drawSphere(0.2,0.5,0,0.1);
            GUI::drawSphere(-0.1,0.7,0,0.08);
        glPopMatrix();

    glPopMatrix();
}

