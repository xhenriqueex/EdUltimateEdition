src = $(wildcard *.c) \
	$(wildcard Comando/*.c) \
	$(wildcard Estruturas/Árvore/*.c) \
	$(wildcard Estruturas/Fila/*.c) \
	$(wildcard Estruturas/Hash/*.c) \
	$(wildcard Estruturas/Lista/*.c) \
	$(wildcard Estruturas/Merge/*.c) \
	$(wildcard Formas/Anotação/*.c) \
	$(wildcard Formas/Círculo/*.c) \
	$(wildcard Formas/Retângulo/*.c) \
	$(wildcard Funções/*.c) \
	$(wildcard Objetos/Hidrante/*.c) \
	$(wildcard Objetos/Item/*.c) \
	$(wildcard Objetos/Quadra/*.c) \
	$(wildcard Objetos/Radiobase/*.c) \
	$(wildcard Objetos/Semáforo/*.c) \
obj = $(src:.c=.o)
svg = $(wildcard *.svg)
flags = -lm -g -fstack-protector-all -std=c99

Principal: $(obj)
	$(CC) -o $@ $^ $(flags)
clean:
	rm -f $(obj) Principal $(svg)