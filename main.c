#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "model/cobra/cobra.h"
#include "model/alimentos/alimentos.h"
#include "model/obstaculos/obstaculos.h"
#include "model/cenario/cenario.h"
#include "model/basic/basic.h"
#include "main.h"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#define LARGURA_DO_MUNDO 800
#define ALTURA_DO_MUNDO 600
char url_entrada[] = "score.txt";
FILE *arq;
int alturaDoMundo=ALTURA_DO_MUNDO;
int larguraDoMundo=LARGURA_DO_MUNDO;
///////////////Objetos///////////////////////////////////////////////////
Alimento lista_alimentos[10];
Alimento_especial lista_especial[10];
Alimento_especial lista_especial_2[10];
Obstaculos lista_obstaculos[10];
Cenario principais[10];
Cobra lista[100];
Cobra lista_i[100];
Mouse novo_mouse;
/////////////////////////////Variaveis////////////////////////////////////
int apresenta=0;
int score;
int musica_fim=0;
int musica_vitoria=0;
int tecla_um=0;
int jogo=0;
int fim_jogo=0;
int vitoria_jogo=0;
int parada=0;
int controle=1;
int keyState[256];
int velocidade_autonomo=0;
int obstaculos_1x=0;
int quantidade_alimento=0;
int quantidade_alimento_2_especial=0;
int quantidade_alimento_especial=0;
int quantidade_obstaculos=1;
int velocidade[3]={0,0,0,0};
int alimento=0; //OLHAR
int alimentacao_1x=0;
int tamanho_cobra=0;
int tamanho_cobra_p2=0;
int especial=0;
int pause=0;
////////////////////////// Variaveis do som//////////////////////////
Mix_Music *derrota = NULL;
Mix_Music *musica_fundo = NULL;
Mix_Chunk *comer_alimento = NULL;
Mix_Chunk *comer_especial = NULL;
Mix_Chunk *vitoria = NULL;

///////////Colisoes//////////////////////////////////////////////////
int colisao(Cobra zero, Alimento inimiga){
    /*if(zero.x_cobra+zero.tamx_cobra<(inimiga.x_cobra+inimiga.tamx_cobra)&&
      (zero.y_cobra+zero.tamy_cobra<(inimiga.y_cobra+inimiga.tamy_cobra))&&
      (zero.x_cobra+zero.tamx_cobra>inimiga.x_cobra)&&
      (zero.y_cobra+zero.tamy_cobra>inimiga.y_cobra)) return 1;*/
      int distancia=sqrt(pow(((zero.x_cobra+zero.tamx_cobra/2)-(inimiga.x_alimento+inimiga.tamx_alimento/2)),2)+
      pow(((zero.y_cobra+zero.tamy_cobra/2)-(inimiga.y_alimento+inimiga.tamy_alimento/2)),2));
      if(distancia<=26){
      Mix_PlayChannel( -1, comer_alimento, 1 ); 
      return 1;
      }
      return 0;

   
}
int colisao_e(Cobra zero, Alimento_especial inimiga){
    /*if(zero.x_cobra+zero.tamx_cobra<(inimiga.x_cobra+inimiga.tamx_cobra)&&
      (zero.y_cobra+zero.tamy_cobra<(inimiga.y_cobra+inimiga.tamy_cobra))&&
      (zero.x_cobra+zero.tamx_cobra>inimiga.x_cobra)&&
      (zero.y_cobra+zero.tamy_cobra>inimiga.y_cobra)) return 1;*/
      int distancia=sqrt(pow(((zero.x_cobra+zero.tamx_cobra/2)-(inimiga.x_alimento+inimiga.tamx_alimento/2)),2)+
      pow(((zero.y_cobra+zero.tamy_cobra/2)-(inimiga.y_alimento+inimiga.tamy_alimento/2)),2));
      if(distancia<=26){
      Mix_PlayChannel(-1, comer_alimento,1 ); 
      return 1;
      }
      return 0;

   
}
int colisao_o(Cobra zero, Obstaculos inimiga){
    /*if(zero.x_cobra+zero.tamx_cobra<(inimiga.x_cobra+inimiga.tamx_cobra)&&
      (zero.y_cobra+zero.tamy_cobra<(inimiga.y_cobra+inimiga.tamy_cobra))&&
      (zero.x_cobra+zero.tamx_cobra>inimiga.x_cobra)&&
      (zero.y_cobra+zero.tamy_cobra>inimiga.y_cobra)) return 1;*/
      int distancia=sqrt(pow(((zero.x_cobra+zero.tamx_cobra/2)-(inimiga.x_obstaculos+inimiga.tamx_obstaculos/2)),2)+
      pow(((zero.y_cobra+zero.tamy_cobra/2)-(inimiga.y_obstaculos+inimiga.tamy_obstaculos/2)),2));
      if(distancia<=40 ){ 
      //Mix_PlayChannel( -1, derrota, 1 ); 
      return 1;
      }
      return 0;
   
}   
int colisao_c(Cobra zero, Cobra inimiga){
    /*if(zero.x_cobra+zero.tamx_cobra<(inimiga.x_cobra+inimiga.tamx_cobra)&&
      (zero.y_cobra+zero.tamy_cobra<(inimiga.y_cobra+inimiga.tamy_cobra))&&
      (zero.x_cobra+zero.tamx_cobra>inimiga.x_cobra)&&
      (zero.y_cobra+zero.tamy_cobra>inimiga.y_cobra)) return 1;*/
      int distancia=sqrt(pow(((zero.x_cobra+zero.tamx_cobra/2)-(inimiga.x_cobra+inimiga.tamx_cobra/2)),2)+
      pow(((zero.y_cobra+zero.tamy_cobra/2)-(inimiga.y_cobra+inimiga.tamy_cobra/2)),2));
      if(distancia<=20 ) {
      //Mix_PlayChannel( -1, derrota, 1 ); 
      return 1;
      }
      return 0;
   
}
//////////////////////Reiniciar/////////////////////////////////////////
int reiniciar(){
    musica_fim=0;
    musica_vitoria=0;
    Mix_Pause(derrota);
    Mix_Pause(vitoria);
    Mix_PlayMusic(musica_fundo, -1);
    velocidade_autonomo=0;
    obstaculos_1x=0;
    quantidade_alimento=0;
    quantidade_obstaculos=1;
    velocidade[0]=0;
    velocidade[1]=0;
    velocidade[2]=0;
    velocidade[3]=0;
    tecla_um=0;
    alimento=0;
    alimentacao_1x=0;
    tamanho_cobra=0;
    tamanho_cobra_p2=0;
    pause=0;
    cobra_cria(lista);
    cobra_cria_autonoma(lista_i);
    alimento_cria(lista_alimentos,quantidade_alimento);
    alimento_especial_cria(lista_especial,quantidade_alimento_especial);
    alimento_especial_2_cria(lista_especial_2,quantidade_alimento_2_especial);
    
    obstaculos_cria(lista_obstaculos,quantidade_obstaculos);
    cenario_cria(principais);
}
///////INICIAR/////////////////////
void init(void){
    glClearColor (0, 0, 0, 0);
    arq= fopen(url_entrada,"r+");
    if(arq == NULL) printf("Erro no arquivo");
    else{
        fscanf(arq,"%d\n",&score);   
    }
    fclose(arq);
    int i;
    for(i=0;i<256;i++) keyState[i]=0;
    cobra_cria(lista);
    cobra_cria_autonoma(lista_i);
    alimento_cria(lista_alimentos,quantidade_alimento);
    alimento_especial_cria(lista_especial,quantidade_alimento_especial);
    alimento_especial_cria(lista_especial_2,quantidade_alimento_2_especial);
    
    obstaculos_cria(lista_obstaculos,quantidade_obstaculos);
    cenario_cria(principais);
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    
    // Implementação do som
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    }
    if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    musica_fundo = Mix_LoadMUS( "audios/background1.mp3" );
    if(musica_fundo == NULL){
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
    derrota = Mix_LoadMUS( "audios/sadover.mp3" );
    if(derrota == NULL){
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
    comer_alimento = Mix_LoadWAV( "audios/comer_alimento.wav" );
    if( comer_alimento == NULL ){
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    ///aqui
    comer_especial = Mix_LoadWAV( "audios/comer_especial.wav" );
    if( comer_especial == NULL ){
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    vitoria = Mix_LoadWAV( "audios/vitoria.wav" );
    if( vitoria == NULL ){
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    Mix_PlayMusic(musica_fundo, -1);

}
///////VERIFICADORES ALIMENTOS OBSTACULOS//////////////////////////////////
void estado_alimento(){
    for(int i=0;i<=quantidade_alimento;i++){
        if(colisao(lista[0],lista_alimentos[i])==1){
            lista_alimentos[i].x_alimento=(1+rand()%800);
            lista_alimentos[i].y_alimento=(1+rand()%600);
            tamanho_cobra+=1;
            if(quantidade_obstaculos<=3){
                quantidade_obstaculos=tamanho_cobra-2;  
                obstaculos_cria(lista_obstaculos,quantidade_obstaculos);  
            }
            
        }
        if(colisao(lista_i[0],lista_alimentos[i])==1){
            tamanho_cobra_p2+=1;
        }
        alimento_desenha(lista_alimentos[i]);
        
    }    
}
void estado_alimento_especial(){
    for(int i=0;i<=quantidade_alimento_especial;i++){
        if(colisao_e(lista[0],lista_especial[i])==1){
            lista_especial[i].x_alimento=(1+rand()%790);
            lista_especial[i].y_alimento=(1+rand()%590);
            especial=1;
            if(especial==1){
                Mix_PlayChannel(-1,comer_especial, 1 );
                
            }                             
            
        }
        alimento_especial_desenha(lista_especial[i]);
        
    }    
}
void estado_alimento_2_especial(){
    for(int i=0;i<=quantidade_alimento_2_especial;i++){
        if(colisao_e(lista[0],lista_especial_2[i])==1){
            lista_especial_2[i].x_alimento=(1+rand()%790);
            lista_especial_2[i].y_alimento=(1+rand()%590);
            tamanho_cobra+=3;
            
        }
        alimento_especial_desenha(lista_especial_2[i]);
        
    }    
}
void estado_obstaculos(){
    for(int i=0;i<=quantidade_obstaculos;i++){
            lista_obstaculos[i].x_obstaculos+=.1;
            lista_obstaculos[i].y_obstaculos+=.1;
            if(lista_obstaculos[i].x_obstaculos+lista_obstaculos[i].tamx_obstaculos<0){
                lista_obstaculos[i].x_obstaculos=780;
            }
            if(lista_obstaculos[i].y_obstaculos>605){
                lista_obstaculos[i].y_obstaculos=0;
            }
            if(lista_obstaculos[i].x_obstaculos+lista_obstaculos[i].tamx_obstaculos>810){
                lista_obstaculos[i].x_obstaculos=-10;
            }
            if(lista_obstaculos[i].y_obstaculos<-10){
                lista_obstaculos[i].y_obstaculos=590;
            }
            
    }
    for(int i=0;i<=quantidade_obstaculos;i++){
        obstaculos_desenha(lista_obstaculos[i]);
        if(colisao_o(lista[0],lista_obstaculos[i])==1&&especial==0){
            fim_jogo=1;
            arq = fopen(url_entrada, "w");
            if (arq == NULL)
                printf("Erro no arquivo");
            else
            {
                fprintf(arq, "%d\n", tamanho_cobra);
            }
            fclose(arq);
        }
        else if(colisao_o(lista[0],lista_obstaculos[i])==1&&especial==1){
            tamanho_cobra=0;
            especial=0;       
            lista[0].x_cobra=(1+rand()%390);
            lista[0].y_cobra=(1+rand()%290);
            Mix_Pause(comer_especial);     
            
        }
    }
    
        
    
}
/////DESENHAR//////////////////////////
void desenha(void)
{
    char numero[40];
    
    //Desenha jogo e tudo após o menu
    if(jogo ){
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        cenario_desenha(principais[0],tamanho_cobra);
        for(int j=tamanho_cobra;j>=0;j--){
            lista[j]=cobra_desenhar_w(lista[j],especial);
        }
        for(int j=0;j<=tamanho_cobra_p2;j++){
            lista_i[j]=cobra_desenhar_w(lista_i[j],0);
        }
        if(pause==0){
            estado_alimento();
            estado_obstaculos();
            if(tamanho_cobra%2==0){
                estado_alimento_especial();                
            }
            if(tamanho_cobra%5==0){
                estado_alimento_2_especial();                
                
            }
        }
        
        if(tamanho_cobra>0&&pause==0){
            for(int i=tamanho_cobra;i>0;i--){
                    lista[i]=lista[i-1];
                    
                }
            }
            if(tamanho_cobra_p2>0){
                for(int i=tamanho_cobra_p2;i>0;i--){
                        lista_i[i]=lista_i[i-1];
                        
                    }
                }
            
                if(pause){
                    para();
                }
                if(fim_jogo){
                    cenario_desenha(principais[9],-1);
                    if(musica_fim==0){
                        Mix_PlayMusic(derrota, 1 ); 
                        musica_fim=1;                        
                    }
                    Mix_Pause(musica_fundo);
                    
                }
                if(vitoria_jogo){
                    if(musica_vitoria==0){
                        Mix_PlayChannel(-1, vitoria, 1 );                 
                        musica_vitoria=1;   
                    }
                    cenario_desenha(principais[8],-1);
                    Mix_Pause(musica_fundo);
		}
        glDisable(GL_TEXTURE_2D);
        glColor3f(1,1,1);
        if(fim_jogo==0){
                sprintf(numero,"Pontos: %d",tamanho_cobra);
                escreveTexto(GLUT_BITMAP_HELVETICA_18,numero,5,20,0);
        }
        else{
            if(tamanho_cobra>score){

                sprintf(numero,"Pontos: %d NOVO RECORDE",tamanho_cobra);
                escreveTexto(GLUT_BITMAP_HELVETICA_18,numero,5,20,0);  
            }
            else{
                sprintf(numero,"Pontos: %d     Record: %d",tamanho_cobra,score);
                escreveTexto(GLUT_BITMAP_HELVETICA_18,numero,5,20,0);

            }               
        }

        
        if(pause){
            escreveTexto(GLUT_BITMAP_HELVETICA_18,"Utilize W,S para selecionar voltar ou reiniciar",200 ,120,0);
            escreveTexto(GLUT_BITMAP_HELVETICA_18,"Pressione ENTER",330 ,510,0);
        }
        if(fim_jogo){
            escreveTexto(GLUT_BITMAP_HELVETICA_18,"Pressione ENTER",330 ,410,0);
        }
        if(vitoria_jogo){
            escreveTexto(GLUT_BITMAP_HELVETICA_18,"Pressione ENTER",330 ,410,0);
        }
        if(controle==3){
            desenha_tecla_um();
        }
        
    }
    //Tela inicial
    else{
        glClear(GL_COLOR_BUFFER_BIT);   
        glEnable(GL_TEXTURE_2D);
        cenario_desenha(principais[1],0);
        glDisable(GL_TEXTURE_2D);

        sprintf(numero,"Recorde: %d",score);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,numero,350,20,0);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,"Pressione ENTER",330 ,380,0);
    }
    //Menu
    if(apresenta==1 && jogo==0){
        glClear(GL_COLOR_BUFFER_BIT);   
        glEnable(GL_TEXTURE_2D);
        menu();
        glDisable(GL_TEXTURE_2D);

        sprintf(numero,"Recorde: %d",score);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,numero,5,20,0);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,"Utilize  W,A,S,D para selecionar o tipo de controle",200 ,380,0);
        escreveTexto(GLUT_BITMAP_HELVETICA_18,"Pressione ENTER",330 ,410,0);
    }

    
    glutSwapBuffers();
}

void redimensiona(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA_DO_MUNDO, ALTURA_DO_MUNDO, 0, -1, 1);
    
    float razaoAspectoJanela = ((float)width)/height;
    float razaoAspectoMundo = ((float) LARGURA_DO_MUNDO)/ ALTURA_DO_MUNDO;
    if (razaoAspectoJanela < razaoAspectoMundo) {
        float hViewport = width / razaoAspectoMundo;
        float yViewport = (height - hViewport)/2;
        alturaDoMundo=razaoAspectoJanela-razaoAspectoMundo;
        larguraDoMundo=razaoAspectoJanela-razaoAspectoMundo;
        glViewport(0, yViewport, width, hViewport);
    }
    else if (razaoAspectoJanela > razaoAspectoMundo) {
        float wViewport = ((float)height) * razaoAspectoMundo;
        float xViewport = (width - wViewport)/2;
        alturaDoMundo=razaoAspectoJanela-razaoAspectoMundo;
        larguraDoMundo=razaoAspectoJanela-razaoAspectoMundo;
        glViewport(xViewport, 0, wViewport, height);
    } else {
        glViewport(0, 0, width, height);
        alturaDoMundo=1;
        larguraDoMundo=1;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclado(unsigned char key, int x, int y)
{ 
    keyState[key] = 1;
   switch(key){
        case 'p':
            if(pause==1){
                pause=0;
            }
            else{
                pause=1;
            }
            break;
            case 'P':
            if(pause==1){
                pause=0;
            }
            else{
                pause=1;
            }
            break;
        case 'r':
            if(pause==1){
                pause=0;
            }
            else{
                pause=1;
            }
            parada=1;
            break;
        case 'R':
            if(pause==1){
                pause=0;
            }
            else{
                pause=1;
            }
            parada=1;
            break;
        case    13:
            if(apresenta==0){
                apresenta=1;
            }
            else{
                if(jogo==0){
                    reiniciar();
                }
                jogo=1;
                
            }
            if(pause==1&&jogo==1){
                if(parada){
                    reiniciar();
                }
                else{
                    pause=0;
                }
            }
            
            break;
        default:
            break;
   }
}
void desenha_tecla_um(){
    escreveTexto(GLUT_BITMAP_HELVETICA_18,"Utilize a tecla h para mudar de direcao no sentido horario",200 ,20,0);
    
}

void tecladoUp(unsigned char key, int x, int y)
{
    keyState[key] = 0;
    switch(key){
        if(controle==3){            
            case 'h':
                
                if(tecla_um==0){
                    tecla_um=1;
                }
                else if(tecla_um==1){
                    tecla_um=2;
                }
                else if(tecla_um==2){
                    tecla_um=3;
                }
                else if(tecla_um==3){
                    tecla_um=0;
                }
                velocidade[0]=0;
                velocidade[1]=0;
                velocidade[2]=0;
                velocidade[3]=0;   
            
                
                break;
        }
        default:
            break;
    }
}

void teclas_atualiza(){
    
    if(keyState['w']||keyState['W']){
        if(velocidade[2]==0&&controle==1){
            velocidade[0]=1;
        }
        else{
            if(velocidade[1]==1||velocidade[3]==1){
                for(int p=0;p<=3;p++){
                    velocidade[p]=0;
                    }
                    velocidade[0]=1;
            }
            
        }
        if(jogo==0){
            controle=1;
        }
        if(pause==1){
            parada=0;
        } 
    
	}
    if(keyState['d']||keyState['D']){
		if(velocidade[3]==0&&controle==1){
            velocidade[1]=1;
        }
        else{
            if(velocidade[0]==1||velocidade[2]==1){
                for(int p=0;p<=3;p++){
                    velocidade[p]=0;
                    }
                    velocidade[1]=1;
            }
        } 
        if(jogo==0){
            controle=2;
        }
	}
	if(keyState['s']||keyState['S']){
		if(velocidade[0]==0&&controle==1){
            velocidade[2]=1;
        }
        else{
            if(velocidade[1]==1||velocidade[3]==1){
                for(int p=0;p<=3;p++){
                    velocidade[p]=0;
                    }
                    velocidade[2]=1;
            }
            
        } 
        if(jogo==0) {
            controle=3;
        } 
        if(pause==1){
            parada=1;
        }
	}
	if(keyState['a']||keyState['A']){
        if(velocidade[1]==0&&controle==1){
            velocidade[3]=1;
        }
        else{
            if(velocidade[0]==1||velocidade[2]==1){
                for(int p=0;p<=3;p++){
                    velocidade[p]=0;
                    }
                    velocidade[3]=1;
            }
        } 
        if(jogo==0){
            controle=1;
        }
		
    }
	if(keyState[27]){
		exit(0);
         	
    }
    if(keyState[13]){
		if(fim_jogo==1||vitoria_jogo==1){
            apresenta=0;
            jogo=0;
            fim_jogo=0;
            vitoria_jogo=0;
            reiniciar();
            
        }
         	
	}
    
}
void cobra_velocidade_autonomo(){
    if(velocidade_autonomo==0) lista_i[0].y_cobra+=0.003;
    if(velocidade_autonomo==1) lista_i[0].y_cobra-=0.003;
    if(velocidade_autonomo==2) lista_i[0].x_cobra+=0.003;
    if(velocidade_autonomo==3) lista_i[0].x_cobra-=0.003;
    
}
void cobra_velocidade_one(){
    if(controle==1){
        if(velocidade[0]) lista[0].y_cobra-=0.003;
        if(velocidade[2]) lista[0].y_cobra+=0.003;
        if(velocidade[1]) lista[0].x_cobra+=0.003;
        if(velocidade[3]) lista[0].x_cobra-=0.003;
    }
    else if(controle==3){
        if(tecla_um==0) lista[0].y_cobra-=0.003;
        else if(tecla_um==2) lista[0].y_cobra+=0.003;
        else if(tecla_um==1) lista[0].x_cobra+=0.003;
        else if(tecla_um==3) lista[0].x_cobra-=0.003;
    }
    
}
//////MOUSE////////////////////////////////
void controleMouse(int x, int y) {
    novo_mouse.x = x+larguraDoMundo;
    novo_mouse.y = y+alturaDoMundo;
}
void cobra_velocidade_mouse(){
    lista[0].x_cobra += (novo_mouse.x - lista[0].x_cobra)/(30000);
    lista[0].y_cobra += (novo_mouse.y-lista[0].y_cobra)/(30000);
}
/////////////////////////////////////
void menu(){
    switch(controle){
        case 0 :    
        cenario_desenha(principais[2],-1);
        break;
        case 1 :
        cenario_desenha(principais[3],-1);
        break;
        case 2 :
        cenario_desenha(principais[4],-1);
        break;
        case 3 :
        cenario_desenha(principais[5],-1);
        break;
        default:
        break;
    }
}
    void para(){
        switch(parada){
            case 0 :
            cenario_desenha(principais[6],-3);
            break;
            case 1 :
            cenario_desenha(principais[7],-3);
            break;
            default:
            break;
        }
}
void atualiza(int idx) {
    
    if(pause==0 && jogo==1&&fim_jogo==0 && vitoria_jogo==0){
        velocidade_autonomo=rand()%3;
        cobra_velocidade_autonomo();
        for(int i=0;i<=tamanho_cobra_p2;i++){
            if(colisao_c(lista[0],lista_i[i])){
                fim_jogo=1;
                arq = fopen(url_entrada, "w");
                if (arq == NULL)
                    printf("Erro no arquivo");
                else
                {
                    fprintf(arq, "%d\n", tamanho_cobra);
                }
                fclose(arq);
            }
        }
        if(tamanho_cobra==70){
            vitoria_jogo=1;
        }
        for(int i=1;i<=tamanho_cobra;i++){
            if(colisao_c(lista[i],lista_i[0])&&tamanho_cobra<tamanho_cobra_p2){
                fim_jogo=1;
                arq = fopen(url_entrada, "w");
                if (arq == NULL)
                    printf("Erro no arquivo");
                else
                {
                    fprintf(arq, "%d\n", tamanho_cobra);
                }
                fclose(arq);
            }
            else if(colisao_c(lista[i],lista_i[0])&&tamanho_cobra>tamanho_cobra_p2){
                tamanho_cobra-=tamanho_cobra_p2+1;
                tamanho_cobra_p2=0;
                lista_i[0].x_cobra=0;
                lista_i[0].y_cobra=0;
            }
        }
        if(controle==1||controle==0||controle==3){
            cobra_velocidade_one();
        }
        else if(controle==2){
            cobra_velocidade_mouse();
        }
        
    }
    srand( (unsigned)time(NULL) );    
    teclas_atualiza();
    glutTimerFunc(17, atualiza, 0);
    //glutTimerFunc(17, estado_luz, 0);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(LARGURA_DO_MUNDO, ALTURA_DO_MUNDO);
   glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-LARGURA_DO_MUNDO)/2,
                      (glutGet(GLUT_SCREEN_HEIGHT)-ALTURA_DO_MUNDO)/2);
   //glutCreateWindow(argv[0]); 
   glutCreateWindow("Snake of Legends");
   init();
   glutIgnoreKeyRepeat(1);
   glutReshapeFunc(redimensiona);
   glutKeyboardFunc(teclado);
   glutKeyboardUpFunc(tecladoUp);
   glutDisplayFunc(desenha);
   glutPassiveMotionFunc(controleMouse);   
   glutIdleFunc(atualiza);
   glutMainLoop();
   return 0;
}
