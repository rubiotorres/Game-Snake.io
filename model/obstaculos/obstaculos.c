#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "obstaculos.h"
void obstaculos_cria(Obstaculos lista[],int tamanho){
    Obstaculos novo;
    novo.tamx_obstaculos=25;
    novo.tamy_obstaculos=25;
    novo.x_obstaculos=(1+rand()%700);
    novo.y_obstaculos=(1+rand()%500);
    novo.texturaObstaculos = SOIL_load_OGL_texture(
        "texturas/obstaculo.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
    );
    lista[tamanho]=novo;
    
}
/*int alimento_colisao(Cobra zero, Alimento[] atual,int tamanho){
    /*if(zero.x_obstaculos+zerox_obstaculos<(atual[i].x_obstaculos+atual[i]x_obstaculos)&&
      (zero.y_obstaculos+zero.tamy_obstaculos<(atual[i].y_obstaculos+atual[i].tamy_obstaculos))&&
      (zero.x_obstaculos+zerox_obstaculos>atual[i].x_obstaculos)&&
      (zero.y_obstaculos+zero.tamy_obstaculos>atual[i].y_obstaculos)) return 1;*/
 /*     int distancia;
      for(int i=1;i<=tamanho;i++){
        distancia=sqrt(pow(((zero.x_obstaculos+zerox_obstaculos/2)-(atual[i].x_obstaculos+atual[i]x_obstaculos/2)),2)+
        pow(((zero.y_obstaculos+zero.tamy_obstaculos/2)-(atual[i].y_obstaculos+atual[i].tamy_obstaculos/2)),2));
        if(distancia<=16) return i;
      }
      
      return 0;
   
}*/
void obstaculos_desenha(Obstaculos atual){
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(atual.x_obstaculos,atual.y_obstaculos,0);
    glBindTexture(GL_TEXTURE_2D, atual.texturaObstaculos);
    glBegin(GL_TRIANGLE_FAN);
    
        glTexCoord2f(0, 0); glVertex3f(-atual.tamx_obstaculos, atual.tamy_obstaculos,  0);
        glTexCoord2f(1, 0); glVertex3f(atual.tamx_obstaculos,atual.tamy_obstaculos,  0);
        glTexCoord2f(1, 1); glVertex3f(atual.tamx_obstaculos,  -atual.tamy_obstaculos,  0);
        glTexCoord2f(0, 1); glVertex3f(-atual.tamx_obstaculos, -atual.tamy_obstaculos,  0);
    glEnd();
    glPopMatrix();
}
