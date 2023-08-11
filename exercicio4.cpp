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



