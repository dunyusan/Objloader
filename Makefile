draw: glm.h glm.c draw.c
	gcc -lGL -lGLU -lglut -lm glm.c draw.c -o draw

clean:
	rm -rf *~ ol draw
