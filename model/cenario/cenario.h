typedef struct cenario{
    float x_cenario;
    float y_cenario;
    float tamx_cenario;
    float tamy_cenario;
    GLuint texturaCenario;
} Cenario;
void cenario_cria(Cenario atual[]);
void cenario_desenha(Cenario atual,int estado_luz);
void cenario_iluminacao(int estado_luz);