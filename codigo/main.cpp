//Autor(a): Leticia Saraiva Chaves

#include <iostream>
#include <fstream>

using namespace std;

#include <vector>

#include <peixe.h>
#include <tubarao.h>
#include <algasmarinhas.h>
#include <cavalomarinho.h>
#include <bolhas.h>
#include <barco.h>
#include <aguaviva.h>
#include <cubo.h>

vector<Objeto*> objetos;
int posSelecionado = -1;

//-------------------sombra-------------------
bool drawShadow = false;
bool pontual = true;
float k = 0.0;
//-------------------sombra-------------------


//Desenha sombras em um plano. Recebe como parametros: uma luz, um plano
void desenhaSombraPlano( float lightPos[4] , GLfloat plano[4]){

    //desenhando os objetos projetados
    glDisable(GL_LIGHTING); //iluminacao: glEnabled - cor do objeto definido pelo material (desconsidera glColor); glDisabled - considera glColor como a cor do objeto inteiro;

    glColor3d(0.0,0.0,0.0);

    glPushMatrix();
        GLfloat sombra[4][4];
        GUI::shadowMatrix(sombra, plano, lightPos);
        glMultTransposeMatrixf((GLfloat*)sombra);

        if(drawShadow){
            bool aux = glutGUI::draw_eixos;
            glutGUI::draw_eixos = false;
            for (int i = 0; i < objetos.size(); ++i) {
                if(objetos[i]->sombraObjeto){
                    glPushMatrix();
                        objetos[i]->desenha();
                    glPopMatrix();
                }
            }
            glutGUI::draw_eixos = aux;
        }
    glPopMatrix();

    glEnable(GL_LIGHTING);
}

//Desenha um plano dado a normal e a distancia 'k'
void desenhaPlano(GLfloat plano[4], GLfloat len, GLfloat cor ){

    GUI::setColor(0,.5+cor,1+cor);

    glPushMatrix();
        Vetor3D v1 = !Vetor3D(plano[0],plano[1],plano[2]);

        Vetor3D vz = Vetor3D(0,0,1);
        GLfloat k = plano[3];
        k += 0.001;

        Vetor3D vp = v1^vz;
        GLfloat angle = acos(v1*vz)*180.0/PI;

        glRotatef(-angle,vp.x,vp.y,vp.z);

        glBegin(GL_POLYGON);
            glNormal3f(0 , 0, 1);
            glVertex3f(-len,-len, -k);
            glVertex3f(len, -len, -k);
            glVertex3f(len,  len, -k);
            glVertex3f(-len, len, -k);
        glEnd();
    glPopMatrix();

}

void desenha() {
    GUI::displayInit();

//    GUI::setLight(1,1,3,5,true,false);
//    GUI::setLight(2,-1.5,0.5,-1,true,false);

    GUI::drawOrigin(1);

    GUI::setColor(0,0.5,1);

    //GUI::drawFloor();

    //----------------sombra---------------------

    //definindo a luz que sera usada para gerar a sombra
    float lightPos[4] = {-1+glutGUI::lx,2+glutGUI::ly,1+glutGUI::lz,pontual};
    GUI::setLight(0,-1,2,1,true,false,false,false,pontual);

    GLfloat chao[4] = {0,1,0,0};
    desenhaSombraPlano(lightPos, chao);
    desenhaPlano(chao,10,0.4);

    GLfloat tras[4] = {0,0,1,4};
    desenhaSombraPlano(lightPos, tras);
    desenhaPlano(tras, 10, 0.6);

//    GLfloat frente[4] = {0,0,-1,6};
//    desenhaSombraPlano(lightPos, frente);
//    desenhaPlano(frente, 10, 0.2);

    //Plano inclinado
    GLfloat esq[4] = {0.8,0.8,0,3};
    desenhaSombraPlano(lightPos, esq);
    desenhaPlano(esq, 10, 0.7);

    GLfloat dir[4] = {-1,0,0,4};
    desenhaSombraPlano(lightPos, dir);
    desenhaPlano(dir, 10, 0.7);

    //----------------sombra---------------------

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }


    GUI::displayEnd();
}

void salva(){
    ofstream cenarioSalvo;
    cenarioSalvo.open ("../cenarioSalvo.txt");

    cenarioSalvo << objetos.size() << '\n';
    for(auto object: objetos){
       cenarioSalvo << object->tipoObjeto << '\n';
       cenarioSalvo << object->t.x << '\n' << object->t.y << '\n' << object->t.z << '\n';
       cenarioSalvo << object->a.x << '\n' << object->a.y << '\n' << object->a.z << '\n';
       cenarioSalvo << object->s.x << '\n' << object->s.y << '\n' << object->s.z << '\n';
    }
    cenarioSalvo.close();
}

void carrega(){
    ifstream cenarioCarregado;
    cenarioCarregado.open("../cenarioSalvo.txt");

    objetos.clear();
    int quantidadeObjetos;
    cenarioCarregado >> quantidadeObjetos;
    char tipoObjeto;

    for(int i = 0; i < quantidadeObjetos; i++){
        cenarioCarregado >> tipoObjeto;
        double tx, ty, tz, ax, ay, az, sx, sy, sz;

        cenarioCarregado >> tx >> ty >> tz >> ax >> ay >> az >> sx >> sy >> sz;

        Vetor3D t = Vetor3D(tx,ty,tz);
        Vetor3D a = Vetor3D(ax,ay,az);
        Vetor3D s = Vetor3D(sx,sy,sz);

        switch(tipoObjeto){
            case 'A':
                objetos.push_back(new AguaViva(t,a,s));
                break;
            case 'a':
                objetos.push_back(new AlgasMarinhas(t,a,s));
                break;
            case 'B':
                objetos.push_back(new Barco(t,a,s));
                break;
            case 'b':
                objetos.push_back(new Bolhas(t,a,s));
                break;
            case 'C':
                objetos.push_back(new CavaloMarinho(t,a,s));
                break;
            case 'P':
                objetos.push_back(new Peixe(t,a,s));
                break;
            case 'T':
                objetos.push_back(new Tubarao(t,a,s));
                break;
            default:
                break;
        }
    }
    cenarioCarregado.close();
}

bool incluirObjeto = false;

void teclado(unsigned char key, int x, int y) {

    GUI::keyInit(key,x,y);

    switch (key) {
    case 'q':
        exit(0);
        break;

    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    //Seleciona o próximo objeto no vector
    case 'n':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    //Volta para o objeto selecionado anteriormente no vector
    case 'b':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    //Deletar objeto selecionado do vector
    case 'D':
        if(posSelecionado >= 0 and posSelecionado < objetos.size()){
            objetos.erase(posSelecionado + objetos.begin(), posSelecionado +  objetos.begin() + 1);
        }
        if(posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    //Deletar último objeto do vector
    case 'd':
        if(!objetos.empty()) //Se o vector não for vazio
            objetos.pop_back();
        break;

    //Desenhar eixos locais (ou não desenhar)
    case 'e':
        if(posSelecionado >= 0 and posSelecionado < objetos.size()){
            objetos[posSelecionado]->eixosLocais = !objetos[posSelecionado]->eixosLocais;
        }
        break;

    //Câmera vista de cima
    case 'I':
        glutGUI::cam = new CameraDistante(Vetor3D(0, 20, 1), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0));
        break;

    //Câmera vista de longe
    case 'i':
        glutGUI::cam = new CameraDistante(Vetor3D(1, 0, 20), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0));
        break;

    //Câmera vista de lado
    case 'r':
        glutGUI::cam = new CameraDistante(Vetor3D(10, 1, 0), Vetor3D(0, 0, 0), Vetor3D(0, 1, 0));
        break;

    //Câmera padrão
    case 'P':
        glutGUI::cam = new CameraDistante(Vetor3D(0,1,12), Vetor3D(0,0,0), Vetor3D(0,1,0));
        break;

    //Salvar todos os objetos (todos os seus atributos) do vetor em um arquivo
    case 'S':
        salva();
        break;

    //Carregar todos os objetos (todos os seus atributos) do vetor de um arquivo
    case 'L':
        carrega();
        break;

    //-------------------sombra-------------------
    case 'E':
        drawShadow = !drawShadow;
        break;
    case 'v':
        pontual = !pontual;
        break;
    case 'K':
        k += 0.1;
        break;
    case 'k':
        k -= 0.1;
        break;
    //Habilitar/Desabilitar sombra do objeto selecioando
    case 'M':
        if(posSelecionado >= 0 and posSelecionado < objetos.size()){
            objetos[posSelecionado]->sombraObjeto = !objetos[posSelecionado]->sombraObjeto;
        }
        break;
    //-------------------sombra-------------------

    case 'O':
        incluirObjeto = !incluirObjeto;
        break;
    case 'p':
        if(incluirObjeto){
           objetos.push_back(new Peixe() );
        }
        break;
    case 's':
        if(incluirObjeto){
           objetos.push_back(new Tubarao() );
        }
        break;
    case 'a':
        if(incluirObjeto){
           objetos.push_back(new AlgasMarinhas() );
        }
        break;
    case 'h':
        if(incluirObjeto){
           objetos.push_back(new CavaloMarinho() );
        }
        break;
    case 'w':
        if(incluirObjeto){
           objetos.push_back(new Bolhas());
        }
        break;
    case 'B':
        if(incluirObjeto){
           objetos.push_back(new Barco());
        }
        break;
    case 'A':
        if(incluirObjeto){
           objetos.push_back(new AguaViva());
        }
        break;
    case '#':
        if(incluirObjeto){
           objetos.push_back(new Cubo());
        }
        break;

    default:
        break;
    }
}
int main(){

    //Inicializando com uma câmera padrão
    glutGUI::cam = new CameraDistante(Vetor3D(0,1,12), Vetor3D(0,0,0), Vetor3D(0,1,0));

    GUI gui = GUI(800,600,desenha,teclado);

}

