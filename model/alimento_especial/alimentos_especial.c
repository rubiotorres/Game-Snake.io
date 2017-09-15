#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "alimentos_especial.h"
void alimento_especial_cria(Alimento lista[],int tamanho){
    Alimento novo;
    novo.tamx_alimento=10;
    novo.tamy_alimento=10;
    novo.x_alimento=(1+rand()%600);
    novo.y_alimento=(1+rand()%400);
    novo.texturaAlimento = SOIL_load_OGL_texture(
        "texturas/especial.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
    );
    lista[tamanho]=novo;
    
}
/*int alimento_colisao(alimento zero, Alimento[] atual,int tamanho){
    /*if(zero.x_alimento+zerox_alimento<(atual[i].x_alimento+atual[i]x_alimento)&&
      (zero.y_alimento+zero.tamy_alimento<(atual[i].y_alimento+atual[i].tamy_alimento))&&
      (zero.x_alimento+zerox_alimento>atual[i].x_alimento)&&
      (zero.y_alimento+zero.tamy_alimento>atual[i].y_alimento)) return 1;*/
 /*     int distancia;
      for(int i=1;i<=tamanho;i++){
        distancia=sqrt(pow(((zero.x_alimento+zerox_alimento/2)-(atual[i].x_alimento+atual[i]x_alimento/2)),2)+
        pow(((zero.y_alimento+zero.tamy_alimento/2)-(atual[i].y_alimento+atual[i].tamy_alimento/2)),2));
        if(distancia<=16) return i;
      }
      
      return 0;
   
}*/
void alimento_especial_desenha(Alimento_especial atual){
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(atual.x_alimento,atual.y_alimento,0);
    glBindTexture(GL_TEXTURE_2D, atual.texturaAlimento);
    glBegin(GL_TRIANGLE_FAN);
    
        glTexCoord2f(0, 0); glVertex3f(-atual.tamx_alimento, atual.tamy_alimento,  0);
        glTexCoord2f(1, 0); glVertex3f(atual.tamx_alimento,atual.tamy_alimento,  0);
        glTexCoord2f(1, 1); glVertex3f(atual.tamx_alimento,  -atual.tamy_alimento,  0);
        glTexCoord2f(0, 1); glVertex3f(-atual.tamx_alimento, -atual.tamy_alimento,  0);
    glEnd();
    glPopMatrix();
}
