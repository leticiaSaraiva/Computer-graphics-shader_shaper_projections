#include "algasmarinhas.h"

AlgasMarinhas::AlgasMarinhas(){
    tipoObjeto = 'a';
}
AlgasMarinhas::AlgasMarinhas(Vetor3D t, Vetor3D a, Vetor3D s){
    this->t = t;
    this->a = a;
    this->s = s;
    tipoObjeto = 'a';
}

void AlgasMarinhas::desenha(){
    glPushMatrix();
        Objeto::desenha();

        GUI::setColor(0,1,0.7);
        glTranslatef(0,0,0);
        glRotatef(0,0,0,0);
        glRotatef(0,0,0,0);
        glScalef(1,1,1);

        //frente
        glBegin(GL_POLYGON);
            glNormal3f(1,0,1);
            glVertex3f(0.3,0,0);
            glVertex3f(0.2,1,0);
            glVertex3f(0.1,0,0);
            glVertex3f(0.19,0,0);

            glVertex3f(0.3,0.2,0);
            glVertex3f(0.7,0.6,0);
            glVertex3f(0.09,0,0);

            glVertex3f(0.1,0.2,0);
            glVertex3f(-0.4,0.6,0);
            glVertex3f(0.1,0,0);
        glEnd();

        //trás
        glBegin(GL_POLYGON);
            glNormal3f(1,0,1);
            glVertex3f(0.19,0,0);
            glVertex3f(0.1,0,0);
            glVertex3f(0.2,1,0);
            glVertex3f(0.3,0,0);

            glVertex3f(0.09,0,0);
            glVertex3f(0.7,0.6,0);
            glVertex3f(0.3,0.2,0);

            glVertex3f(0.1,0,0);
            glVertex3f(-0.4,0.6,0);
            glVertex3f(0.1,0.2,0);

        glEnd();

     glPopMatrix();
}
