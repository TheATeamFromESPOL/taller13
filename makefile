pc: pc.c 
	gcc -Wall -g $^ -o $@ -pthread
clean:
	rm -rf ./buscar
