#include "barco.h"

Barco::Barco(){
    tipoObjeto = 'B';
}
Barco::Barco(Vetor3D t, Vetor3D a, Vetor3D s){
    this->t = t;
    this->a = a;
    this->s = s;
    tipoObjeto = 'B';
}
void Barco::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        GUI::setColor(1,1,0.5);
        glTranslatef(0.5,0,0);
        glRotatef(0,0,0,0);
        glRotatef(0,0,0,0);
        glScalef(1,1,1);

        //frente fora
        glBegin(GL_POLYGON);
            glNormal3f(0,0.25,0);
            glVertex3f(1.5,0.5,0);
            glVertex3f(1,0.5,0);
            glVertex3f(-1.5,0.5,0.5);
            glVertex3f(-1.5,0,0.5);
            glVertex3f(1,0,0);
        glEnd();

        //frente dentro
        glBegin(GL_POLYGON);
            glNormal3f(-0.25,0.25,-1.5);
            glVertex3f(1.5,0.5,0);
            glVertex3f(1,0,0);
            glVertex3f(-1.5,0,0.5);
            glVertex3f(-1.5,0.5,0.5);
            glVertex3f(1,0.5,0);
        glEnd();

        //trás fora
        glBegin(GL_POLYGON);
            glNormal3f(0,-0.25,0);
            glVertex3f(1.5,0.5,0);
            glVertex3f(1,0.5,0);
            glVertex3f(-1.5,0.5,-0.5);
            glVertex3f(-1.5,0,-0.5);
            glVertex3f(1,0,0);
        glEnd();

        //trás dentro
        glBegin(GL_POLYGON);
            glNormal3f(0.25,-0.25,-1.25);
            glVertex3f(1.5,0.5,0);
            glVertex3f(1,0,0);
            glVertex3f(-1.5,0,-0.5);
            glVertex3f(-1.5,0.5,-0.5);
            glVertex3f(1,0.5,0);
        glEnd();


        //fundo dentro
        glBegin(GL_POLYGON);
            glNormal3f(-0.1,2.5,0);
            glVertex3f(1,0.1,0);
            glVertex3f(-1.5,0,-0.5);
            glVertex3f(-1.5,0,0.5);
        glEnd();

        //fundo fora
        glBegin(GL_POLYGON);
            glNormal3f(0.1,-2.5,0);
            glVertex3f(1,0.1,0);
            glVertex3f(-1.5,0,0.5);
            glVertex3f(-1.5,0,-0.5);
        glEnd();

        //lado do barco (fora)
        glBegin(GL_POLYGON);
            glNormal3f(-0.5,0,0);
            glVertex3f(-1.5,0.5,-0.5);
            glVertex3f(-1.5,0,-0.5);
            glVertex3f(-1.5,0,0.5);
            glVertex3f(-1.5,0.5,0.5);
        glEnd();

        //lado do barco (dentro)
        glBegin(GL_POLYGON);
            glNormal3f(0.5,0,0);
            glVertex3f(-1.5,0.5,-0.5);
            glVertex3f(-1.5,0.5,0.5);
            glVertex3f(-1.5,0,0.5);
            glVertex3f(-1.5,0,-0.5);
        glEnd();

        //Bandeira (frente)
        glPushMatrix();
            GUI::setColor(1,1,1);
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1.08);
                glVertex3f(1,0.52,0);
                glVertex3f(0,1.6,0);
                glVertex3f(0,0.52,0);
            glEnd();
        glPopMatrix();

        //Bandeira (trás)
        glPushMatrix();
            GUI::setColor(1,1,1);
            glBegin(GL_POLYGON);
                glNormal3f(0,0,-1.08);
                glVertex3f(1,0.52,0);
                glVertex3f(0,0.52,0);
                glVertex3f(0,1.6,0);
            glEnd();
        glPopMatrix();

     glPopMatrix();


}
