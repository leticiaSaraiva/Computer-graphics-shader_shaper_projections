#include "peixe.h"

Peixe::Peixe(){
    tipoObjeto = 'P';
}
Peixe::Peixe(Vetor3D t, Vetor3D a, Vetor3D s){
    this->t = t;
    this->a = a;
    this->s = s;
    tipoObjeto = 'P';
}

void Peixe::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        GUI::setColor(3,2,0.5);
        glTranslatef(0,0,0);
        glRotatef(0,0,0,0);
        glRotatef(0,0,0,0);
        glScalef(0.7,0.7,0.7);

        //frente cabeça cima
        glBegin(GL_POLYGON);
            glNormal3f(0.8,0.7,0.8);
            glVertex3f(1.5,0,0);
            glVertex3f(0.8,0.8,0);
            glVertex3f(0.5,0,1);
        glEnd();

        //frente cabeça baixo
        glBegin(GL_POLYGON);
            glNormal3f(0.8,-0.7,0.8);
            glVertex3f(1.5,0,0);
            glVertex3f(0.5,0,1);
            glVertex3f(0.8,-0.8,0);

        glEnd();

        //frente corpo cima
        glBegin(GL_POLYGON);
            glNormal3f(-0.8,2.3,1.6);
            glVertex3f(0.8,0.8,0);
            glVertex3f(-1.5,0,0);
            glVertex3f(0.5,0,1);
        glEnd();

        //frente corpo baixo
        glBegin(GL_POLYGON);
            glNormal3f(-0.8,-2.3,1.6);
            glVertex3f(0.5,0,1);
            glVertex3f(-1.5,0,0);
            glVertex3f(0.8,-0.8,0);
        glEnd();

        //rabo frente
        glBegin(GL_POLYGON);
            glNormal3f(0,0,0.5);
            glVertex3f(-1.5,0,0);
            glVertex3f(-2, 0.5, 0);
            glVertex3f(-2,-0.5,0);
        glEnd();

        //trás cabeça cima
        glBegin(GL_POLYGON);
            glNormal3f(0.8,0.7,-0.8);
            glVertex3f(0.5,0,-1);
            glVertex3f(0.8,0.8,0);
            glVertex3f(1.5,0,0);
        glEnd();

        //trás cabeça baixo
        glBegin(GL_POLYGON);
            glNormal3f(0.8,-0.7,-0.8);
            glVertex3f(0.8,-0.8,0);
            glVertex3f(0.5,0,-1);
            glVertex3f(1.5,0,0);
        glEnd();

        //tras corpo cima
        glBegin(GL_POLYGON);
            glNormal3f(-0.8,2.3,-1.6);
            glVertex3f(0.5,0,-1);
            glVertex3f(-1.5,0,0);
            glVertex3f(0.8,0.8,0);
        glEnd();

        //trás corpo baixo
        glBegin(GL_POLYGON);
            glNormal3f(-0.8,-2.3,-1.6);
            glVertex3f(0.8,-0.8,0);
            glVertex3f(-1.5,0,0);
            glVertex3f(0.5,0,-1);
        glEnd();

        //rabo trás
        glBegin(GL_POLYGON);
            glNormal3f(0,0,-0.5);
            glVertex3f(-2,-0.5,0);
            glVertex3f(-2, 0.5, 0);
            glVertex3f(-1.5,0,0);
        glEnd();

        //olho frente
        glPushMatrix();
            GUI::setColor(0,0,0);
            GUI::drawSphere(0.9,0.4,0.2,0.1);
        glPopMatrix();

        //olho trás
        glPushMatrix();
            GUI::setColor(0,0,0);
            GUI::drawSphere(0.9,0.4,-0.2,0.1);
        glPopMatrix();

     glPopMatrix();
}
