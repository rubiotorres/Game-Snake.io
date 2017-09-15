CC=gcc
OPCOES_COMPILADOR=-I. -I/usr/include/SOIL -lglut -lGLU -lSOIL -lGLEW -lGL -lm -lSDL -lSDL_mixer
TODOS_ARQUIVOS_PONTOH = 	../main.h ../model/cobra/cobra.h ../model/alimentos/alimentos.h ../model/obstaculos/obstaculos.h  ../model/cenario/cenario.h  ../model/basic/basic.h  
TODOS_ARQUIVOS_OBJ = main.o  ../model/cobra/cobra.o ../model/alimentos/alimentos.o ../model/obstaculos/obstaculos.o  ../model/cenario/cenario.o  ../model/basic/basic.o  

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o main $^ $(OPCOES_COMPILADOR)

run: all
	(cd .. && exec Makefile/main)

clean:
	rm *.o main
