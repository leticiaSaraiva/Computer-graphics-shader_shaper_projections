#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::desenha()
{
    glTranslatef(t.x,t.y,t.z);
    glRotatef(a.z,0,0,1);
    glRotatef(a.y,0,1,0);
    glRotatef(a.x,1,0,0);

    if (selecionado) {
        GUI::setColor(1,0,0);
        glPushMatrix();
            //Seta (frente)
            glBegin(GL_POLYGON);
                glVertex2f(0.25,1);
                glVertex2f(0.5,1.2);
                glVertex2f(0.3,1.2);
                glVertex2f(0.3,1.8);
                glVertex2f(0.2,1.8);
                glVertex2f(0.2,1.2);
                glVertex2f(0,1.2);
            glEnd();

            //Seta (trás)
            glBegin(GL_POLYGON);
                glVertex2f(0.25,1);
                glVertex2f(0,1.2);
                glVertex2f(0.2,1.2);
                glVertex2f(0.2,1.8);
                glVertex2f(0.3,1.8);
                glVertex2f(0.3,1.2);
                glVertex2f(0.5,1.2);
            glEnd();
        glPopMatrix();
    }
    if(eixosLocais){
        GUI::drawOrigin(1);
    }

    glScalef(s.x,s.y,s.z);
}
