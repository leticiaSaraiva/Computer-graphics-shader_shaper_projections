#include "estreladomar.h"

EstrelaDoMar::EstrelaDoMar()
{

}

void EstrelaDoMar::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            GUI::setColor(1,0,0);
        } else {
            GUI::setColor(0,1,0);
        }

        //frente
        glBegin(GL_POLYGON);
            glNormal3f(1,1,0);
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
            glNormal3f(1,1,0);

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

        glPushMatrix();
            glTranslatef(0,0,0);
            glRotatef(0,0,0,0);
            glRotatef(0,0,0,0);
            glScalef(1,1,1);
        glPopMatrix();
     glPopMatrix();


}
