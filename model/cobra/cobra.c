#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cobra.h"
#include "../alimentos/alimentos.h"
void cobra_cria(Cobra lista[]){
    for(int i=0;i<100;i++){
        lista[i].x_cobra=390;
        lista[i].y_cobra=290;
        lista[i].tamx_cobra=15;
        lista[i].tamy_cobra=15;
        lista[i].texturaCobra[0]=SOIL_load_OGL_texture(
            "texturas/cobra.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );
    }
}
void cobra_cria_autonoma(Cobra lista[]){
    for(int i=0;i<100;i++){
        lista[i].x_cobra=1;
        lista[i].y_cobra=1;
        lista[i].tamx_cobra=15;
        lista[i].tamy_cobra=15;
        lista[i].texturaCobra[0]=SOIL_load_OGL_texture(
            "texturas/cobra.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );
    }
}
Cobra cobra_desenhar_w(Cobra atual,int especial){
    if(especial==0){
        glColor3f(1,1,1);        
    }
    else{
        glColor3f(1,.3,.3);
    }
    if(atual.x_cobra+atual.tamx_cobra<0){
        atual.x_cobra=780;
    }
    if(atual.y_cobra>605){
        atual.y_cobra=0;
    }
    if(atual.x_cobra+atual.tamx_cobra>810){
        atual.x_cobra=-10;
    }
    if(atual.y_cobra<-10){
        atual.y_cobra=590;
    }
    glPushMatrix();
    glTranslatef(atual.x_cobra,atual.y_cobra,0);
    glBindTexture(GL_TEXTURE_2D, atual.texturaCobra[0]);
    glBegin(GL_TRIANGLE_FAN);
    
        glTexCoord2f(0, 0); glVertex3f(-atual.tamx_cobra, atual.tamy_cobra,  0);
        glTexCoord2f(1, 0); glVertex3f(atual.tamx_cobra,atual.tamy_cobra,  0);
        glTexCoord2f(1, 1); glVertex3f(atual.tamx_cobra,  -atual.tamy_cobra,  0);
        glTexCoord2f(0, 1); glVertex3f(-atual.tamx_cobra, -atual.tamy_cobra,  0);
    glEnd();
    glPopMatrix();
    return atual;
}