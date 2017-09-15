typedef struct obstaculos{
    float x_obstaculos;
    float y_obstaculos;
    float tamx_obstaculos;
    float tamy_obstaculos;
    GLuint texturaObstaculos;
} Obstaculos;

void obstaculos_desenha(Obstaculos atual);
//int alimento_colisao(Alimento atual);
void obstaculos_cria(Obstaculos lista[],int tamanho);
//void alimento_alimento(Alimento atual);