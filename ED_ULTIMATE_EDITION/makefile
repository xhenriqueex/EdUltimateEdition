main: main.o fila.o arvore.o hash.o lista.o mergesort.o executa_comando.o anotaçao.o circulo.o retangulo.o funçoes.o parproximo.o hidrante.o item.o quadra.o semaforo.o radiobase.o
	gcc -o main main.o fila.o arvore.o hash.o lista.o mergesort.o executa_comando.o anotaçao.o circulo.o retangulo.o funçoes.o parproximo.o hidrante.o item.o quadra.o semaforo.o radiobase.o
main.o: main.c
	gcc -o main.o -c main.c
arvore.o: Estruturas/Árvore/arvore.c
	gcc -o arvore.o -c Estruturas/Árvore/arvore.c
fila.o: Estruturas/Fila/fila.c
	gcc -o fila.o -c Estruturas/Fila/fila.c
hash.o: Estruturas/Hash/hashtable.c
	gcc -o hashtable.o -c Estruturas/Hash/hashtable.c
lista.o: Estruturas/Lista/lista.c
	gcc -o lista.o -c Estruturas/Lista/lista.c
mergesort.o: Estruturas/Merge/mergesort.c
	gcc -o mergesort.o -c Estruturas/Merge/mergesort.c
executa_comando.o: Comando/executa_comando.c
	gcc -o executa_comando.o -c Comando/executa_comando.c
anotaçao.o: Formas/Anotação/anotaçao.c
	gcc -o anotaçao.o -c Formas/Anotação/anotaçao.c
circulo.o: Formas/Círculo/circulo.c
	gcc -o circulo.o -c Formas/Círculo/circulo.c
retangulo.o: Formas/Retângulo/retangulo.c
	gcc -o retangulo.o -c Formas/Retângulo/retangulo.c
funçoes.o: Funções/funçoes.c
	gcc -o funçoes.o -c Funções/funçoes.c
parproximo.o: Funções/parproximo.c
	gcc -o parproximo.o -c Funções/parproximo.c
hidrante.o: Objetos/Hidrante/hidrante.c
	gcc -o hidrante.o -c Objetos/Hidrante/hidrante.c
item.o: Objetos/Item/item.c
	gcc -o item.o -c Objetos/Item/item.c
quadra.o: Objetos/Quadra/quadra.c
	gcc -o quadra.o -c Objetos/Quadra/quadra.c
radiobase.o: Objetos/Radiobase/radiobase.c
	gcc -o radiobase.o -c Objetos/Radiobase/radiobase.c
semaforo.o: Objetos/Semáforo/semaforo.c
	gcc -o semaforo.o -c Objetos/Semáforo/semaforo.c

#clean:
#	rm -f $(obj) Principal $(svg)