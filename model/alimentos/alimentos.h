typedef struct alimento{
    float x_alimento;
    float y_alimento;
    float tamx_alimento;
    float tamy_alimento;
    GLuint texturaAlimento;
} Alimento;
typedef struct alimento_especial{
    float x_alimento;
    float y_alimento;
    float tamx_alimento;
    float tamy_alimento;
    GLuint texturaAlimento;
} Alimento_especial;

void alimento_especial_desenha(Alimento_especial atual);
//int alimento_colisao(Alimento atual);
void alimento_especial_cria(Alimento_especial lista[],int tamanho);
//void alimento_alimento(Alimento atual);
void alimento_desenha(Alimento atual);
//int alimento_colisao(Alimento atual);
void alimento_cria(Alimento lista[],int tamanho);
//void alimento_alimento(Alimento atual);