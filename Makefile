ol:obj.c obj.h main.c 
	gcc obj.c main.c -o ol

clean:
	rm -rf *~ ol
