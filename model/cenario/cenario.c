#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cenario.h"
void cenario_cria(Cenario atual[]){
    Cenario novo;
    for(int tipo=0; tipo<10;tipo++){
        switch(tipo){
            case 0:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=400;
                novo.tamy_cenario=300;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/fundo.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[0]=novo;
                break;
                case 1:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=400;
                novo.tamy_cenario=300;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/apresentacao.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 2:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=400;
                novo.tamy_cenario=300;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/tela1.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 3:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=400;
                novo.tamy_cenario=300;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/tela2.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 4:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=400;
                novo.tamy_cenario=300;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/tela3.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 5:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=400;
                novo.tamy_cenario=300;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/tela4.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 6:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=300;
                novo.tamy_cenario=200;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/pause1.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 7:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=300;
                novo.tamy_cenario=200;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/pause2.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 8:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=300;
                novo.tamy_cenario=200;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/vitoria.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                atual[tipo]=novo;
                break;
                case 9:
                novo.x_cenario=400;
                novo.y_cenario=300;
                novo.tamx_cenario=300;
                novo.tamy_cenario=200;
                novo.texturaCenario=SOIL_load_OGL_texture(
                    "texturas/perca.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
                );
                
                atual[tipo]=novo;
                break;
                default:
                break;
        }
    }
    
}
void cenario_desenha(Cenario atual,int posicao){
    int estado_luz=1;
    if(posicao>50){
        estado_luz=0;
    }
    if(posicao<0){
        estado_luz=-1;
    }
    if(posicao<-2){
        estado_luz=-2;
    }
    cenario_iluminacao(estado_luz);
    glPushMatrix();
    glTranslatef(atual.x_cenario,atual.y_cenario,0);
    glBindTexture(GL_TEXTURE_2D, atual.texturaCenario);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0); glVertex3f(-atual.tamx_cenario, atual.tamy_cenario,  0);
        glTexCoord2f(1, 0); glVertex3f(atual.tamx_cenario,atual.tamy_cenario,  0);
        glTexCoord2f(1, 1); glVertex3f(atual.tamx_cenario,  -atual.tamy_cenario,  0);
        glTexCoord2f(0, 1); glVertex3f(-atual.tamx_cenario, -atual.tamy_cenario,  0);
    glEnd();
    glPopMatrix();
}
void cenario_iluminacao(int estado_luz){
    if(estado_luz<=0){
        glColor4f (1, 1, 1,1);    
    }
    else{
        glColor3f(rand() / (RAND_MAX *1.0),rand() / (RAND_MAX *1.0),rand() / (RAND_MAX *1.0));
    }
}