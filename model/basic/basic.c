#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "basic.h"
void escreveTexto(void * font, char *s, float x, float y, float z){
    int i;
    glRasterPos3f(x, y, z);

    for (i=0; i < strlen(s); i++)
       glutBitmapCharacter(font, s[i]);
}
