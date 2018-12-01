#ifndef LISTA_H
#define LISTA_H

typedef void* Lista;
typedef void* Posic;

Lista criarLista();
int tamanhoLista(Lista list);
Posic inserirObjetoLista(Lista list, void *obj);
Posic removerObjetoLista(Lista list, Posic p);
void* getObjetoLista(Posic p);
Posic inserirAntesLista(Lista list, Posic p, void* obj);
Posic insertDepoisLista(Lista list, Posic p, void* obj);
Posic getPrimeiroLista(Lista list);
Posic getProximoLista(Lista list, Posic p);
Posic getUltimoLista(Lista list);
Posic getAnteriorLista(Lista list, Posic p);
Posic liberarElementoLista(Lista list, Posic p);
void liberarLista(Lista list);

#endif