#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* primoFiglio;
    struct node* fratello;
}nodo;

typedef nodo* albero;

int maxalberon(albero T) {
    albero temp=T->primoFiglio;
    int massimo = T->info;
    int currmax;
    while (temp!=NULL){
        currmax=maxalberon(temp);
        if (currmax>massimo)
            massimo=currmax;
        temp=temp->fratello;
        }
    return massimo;
}

int massimoTreNumeri(int a, int b, int c){
    if(a>b){
        if(a>c)
            return a;
        return c;
    }
    else{
        if(b>c)
            return b;
        return c;
    }
}

int massimoAlbero(albero T){
    if(T == NULL)
        return -1;
    return massimoTreNumeri(T->info, massimoAlbero(T->primoFiglio), massimoAlbero(T->fratello));
}

/* calcola il numero di foglie dell’albero generico*/
int numfoglie (albero T){
    if (T==NULL) return 0;
    if (T->primoFiglio ==NULL)
        return 1+ numfoglie(T->fratello);
    else
        return (numfoglie(T->primoFiglio)+numfoglie(T->fratello));
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int altezza(albero T){
    if(T== NULL)
        return -1;
    return 1+ max(altezza(T->primoFiglio), altezza(T->fratello));
}

int altezza2(albero T) {
    albero temp;
    int h=-1;
    int curralt;
    if (T==NULL) return -1;
    temp=T->primoFiglio;
    while (temp!=NULL) {
        curralt=altezza(temp);
        if (curralt > h) h=curralt;
        temp=temp->fratello;
        }
    return (h+1);
}

int gradoMassimo(albero N){
    albero tmp = N->primoFiglio;
    int figlimax = contaFigli(N);
    int curr = 0;
    if(N == NULL) return 0;
    while(tmp!=NULL){
    curr = gradoMassimo(tmp);
    if(curr>figlimax)
            figlimax=curr;
    tmp= tmp->fratello;
    }
    return figlimax;
}

int contaFigli(albero T){
    albero tmp = T->primoFiglio;
    int cont = 0;
    while(tmp){
        cont++;
        tmp = tmp->fratello;
        }
    return cont;
}

int main()
{


    albero giuliano=malloc(sizeof(nodo));
	giuliano->info=44;
	giuliano->primoFiglio=NULL;
	giuliano->fratello=NULL;


    albero quokka=malloc(sizeof(nodo));
	quokka->info=12;
	quokka->primoFiglio=NULL;
	quokka->fratello=giuliano;


    albero treDueFiglio=malloc(sizeof(nodo));
	treDueFiglio->info=32;
	treDueFiglio->primoFiglio=NULL;
	treDueFiglio->fratello=quokka;

    albero treFratello=malloc(sizeof(nodo));
	treFratello->info=31;
	treFratello->primoFiglio=NULL;
	treFratello->fratello=treDueFiglio;



    albero treFiglio=malloc(sizeof(nodo));
	treFiglio->info=3;
	treFiglio->primoFiglio=treFratello;
	treFiglio->fratello=NULL;

    albero dueFratello=malloc(sizeof(nodo));
	dueFratello->info=21;
	dueFratello->primoFiglio=NULL;
	dueFratello->fratello=treFiglio;

    albero dueFiglio=malloc(sizeof(nodo));
	dueFiglio->info=2;
	dueFiglio->primoFiglio=NULL;
	dueFiglio->fratello=dueFratello;

	albero uno = malloc(sizeof(nodo));
	uno->info=1;
	uno->primoFiglio=dueFiglio;
	uno->fratello=NULL;/*
	int max = maxalberon(uno);
	int max2 = massimoAlbero(uno);
	int foglie = numfoglie(uno);
	printf("maxalberon massimo elemento di un albero: %d\n", max);
	printf("massimoAlbero massimo elemento di un albero: %d\n ", max2);
	printf("numfoglie numero di foglie di un albero: %d \n", foglie);
	printf("altezza di un albero come binario: %d\n", altezza(uno));
    printf("altezza di un albero come binario: %d", altezza2(uno));*/

    printf("test grado massimo: %d\n", gradoMassimo(uno));

}
