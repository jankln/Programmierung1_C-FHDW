#include<stdio.h>
#include<stdlib.h>

struct Elem_{
    int wert;
    struct Elem_ *next;
};
typedef struct Elem_ Elem;

Elem *CreateElem(int wert){
    Elem *E = (Elem *) malloc(sizeof(Elem));
    E->wert = wert;
    E->next = NULL;
}

Elem *AddElemToList(Elem *L, int wert){

    Elem *E = CreateElem(wert);

    E->next = L->next;
    L->next = E;

    return L;
}
Elem *AddElemToListEnd(Elem *L, int wert){
    Elem *N = L;

    while( N->next != NULL ){
        N = N->next;
    }
    N->next  = CreateElem(wert);

    return L;
}
Elem *CreateList(){
    return CreateElem(0);
}

Elem *FindPrevElem(Elem *E, int wert)
{
    Elem *PE = E;
    E = E->next;
    while(E != NULL){
        if(E->wert == wert) return PE;

        PE = E;
        E  = E->next;
    }
    return NULL;
}
Elem *DeleteElement(Elem *L, int wert){
    Elem *pE = FindPrevElem(L, wert);
    Elem *E;
    if(pE != NULL){
        E = pE->next;
        pE->next = E->next;
        free(E);
    }
    return L;
}
int isListEmpty(Elem *L){
    return L->next == NULL;
}
void PrintElem(Elem *E){
    printf("  %d\n", E->wert);
}
void PrintList(Elem *E){
    E = E->next;
    printf("List:\n");
    while(E){
        PrintElem(E);
        E = E->next;
    }
}

Elem *FindSmallestListElem(Elem *E){
    Elem *SE = NULL;

    E = E->next;
    while(E){
        if(SE == NULL) SE = E;

        if(E->wert < SE->wert) SE = E;

        E = E->next;
    }
    return SE;
}

Elem *SortList(Elem *Lold){
    Elem *L = CreateList();
    Elem *E;
    while(!isListEmpty(Lold)){
        E = FindSmallestListElem(Lold);

        L = AddElemToListEnd(L, E->wert);
        Lold = DeleteElement(Lold, E->wert);
    }
    free(Lold);

    return L;
}

int main(){

    Elem *L1 = CreateList();
    Elem *L2 = CreateList();
    Elem *E;

    L1 = AddElemToList(L1, 1);
    L1 = AddElemToList(L1, 2);
    L1 = AddElemToListEnd(L1, 3);

    PrintList(L1);

    if(isListEmpty(L1)) printf("L1 ist leer\n");
    else printf("L1 ist nicht leer\n");
    if(isListEmpty(L2)) printf("L2 ist leer\n");
    else printf("L2 ist nicht leer\n");

    E = FindPrevElem(L1, 1);
    printf("%d ist vor %d\n", E->wert, 1);

    L1 = DeleteElement(L1, 1);
    PrintList(L1);

    E = FindSmallestListElem(L1);
    printf(" Das kleinste Element der Liste ist %d\n", E->wert);

    L1 = AddElemToList(L1, 20);
    L1 = AddElemToList(L1, 22);
    PrintList(L1);
    L1 = SortList(L1);
    PrintList(L1);

    return 0;
}
