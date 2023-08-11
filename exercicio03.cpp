#include <GL/glut.h>
#include <math.h>
/*
 * Programa 'Primitivas' de OpenGL clÃ¡ssico.
 * Desenha diversas primitivas geomÃ©tricas presentes em OpenGL
 */

//Ã‰ uma boa prÃ¡tica criar uma funÃ§Ã£o para agrupar configuraÃ§Ãµes iniciais do OpenGL para o desenho a ser feito
void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0); //indica qual cor serÃ¡ usada para limpar o frame buffer (serÃ¡ a cor de fundo)
    glPointSize(5); //altera o tamanho de pontos (por padrÃ£o, o tamanho Ã© de 1 pixel)
    glLineWidth(3); //altera a largura de segmentos de reta (por padrÃ£o, a largura Ã© de 1 pixel)
}

//funÃ§Ã£o que desenha vÃ¡rias primitivas diferentes para exemplificar seu uso
void primitivas(){
    /*glBegin(GL_TRIANGLE_FAN); //o primeiro ponto Ã© conectado a todos os demais formando triÃ¢ngulos
        glVertex2f(0, 0);
        glVertex2f(-2,-2);
        glVertex2f(2,-2);
        glVertex2f(2,2);
        glVertex2f(-2,2);
        glVertex2f( -2,-2);
    glEnd();*/

    glBegin(GL_POLYGON); //polÃ­gono de vÃ¡rios lados (deve ser evitado)
        glVertex2f(5, 0);
        glVertex2f(4, 4);
        glVertex2f(0, 5);
        glVertex2f(-4, 4);
        glVertex2f(-5, 0);
        glVertex2f(-4, -4);
        glVertex2f( 0, -5);
        glVertex2f( 4, -4);
    glEnd();
}

//FunÃ§Ã£o que serÃ¡ usada para desenhar o conteÃºdo no frame buffer
void desenha(){
    glClear(GL_COLOR_BUFFER_BIT); //sempre antes de desenhar qualquer coisa, deve-se limpar o frame-buffer

    //por padrÃ£o, o OpenGL exibe apenas as coisas desenhadas dentro do intervalo -1 e 1 nas coordenadas x e y
    //os comandos abaixo alteram esse comportamento padrÃ£o de visualizaÃ§Ã£o (serÃ¡ explicado em mais detalhes futuramente)
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    glOrtho(-20,20,-20,20,-1,1);    //glOrtho(xmin,xmax,ymin,ymax,zmin,zmax) = alterando a Ã¡rea de visualizaÃ§Ã£o (tudo entre 0 e 20 nas coordenadas x e y serÃ¡ visualizado)
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();
    
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL ); //alterando para modo de preenchimento (por padrÃ£o jÃ¡ vem ativado)
    glColor3f(1.0, 0.0, 0.0);                    //cor de preenchimento vermelha  
    primitivas();                                //chamando a funÃ§Ã£o que desenha aquele conjunto de primitivas

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); //alterando para modo de linhas (usado para mostrar as arestas dos polÃ­gonos)
    glColor3f(0.0, 0.0, 0.0);                    //cor das linhas pretas
    primitivas();                                //chamando a funÃ§Ã£o das primitivas novamente (boa prÃ¡tica pra evitar reescrever cÃ³digo)

    glFlush(); //Todas as instruÃ§Ãµes anteriores apenas indicaram o que deve ser feito. Essa Ã© a ordem pra GPU redesenhar com as informaÃ§Ãµes enviadas
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                        //inicializar a biblioteca GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //configuraÃ§Ãµes do frame buffer (um frame buffer com trÃªs canais de cor: RGB)
    glutInitWindowPosition(0,0);                 //posiÃ§Ã£o do canto superior esquerdo da janela com relaÃ§Ã£o a tela
    glutInitWindowSize(500,500);                 //resoluÃ§Ã£o da janela (framebuffer)
    glutCreateWindow("01 - Primitivas");         //cria a janela (a string aparece na barra de tÃ­tulo da janela)

    inicio();

    glutDisplayFunc(desenha); //indica que a funÃ§Ã£o 'desenha' deve ser chamada sempre que o frame buffer deve ser atualizado

    glutMainLoop();           //mantÃ©m um laÃ§o interno usando threads para que a janela permaneÃ§a aberta

    return 0;
}