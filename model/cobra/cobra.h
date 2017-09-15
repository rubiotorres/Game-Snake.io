typedef struct cobra{
    float x_cobra;
    float y_cobra;
    float tamx_cobra;
    float tamy_cobra;
    GLuint texturaCobra[2];
} Cobra;
Cobra cobra_desenhar_w(Cobra atual,int especial);
void cobra_cria_autonoma(Cobra lista[]);
void cobra_cria(Cobra lista[]);