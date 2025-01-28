#include<stdio.h>

struct _P{
    char   Name[10];
    int    id;
    int    Menge;
    double Preis;
};

typedef struct _P P;
void replaceCharInString(char *s, char a, char b){

    while(*s != '\0'){
        if(*s == a) *s = b;
        s++;
    }
}

void copyString(char *von, char *nach){

    while(*von != '\0'){
        *nach = *von;
        von++;
        nach++;
    }
    *nach = *von;
}

void swapStrings(char *s1, char *s2){
    char t;
    while(*s1 != '\0' || *s2 != '\0'){
         t  = *s1;
        *s1 = *s2;
        *s2 = t;

        s1++;
        s2++;
    }
}

int isPalindrom(char *s){

    char *send = s;
    while(*send != '\0') send++;
    send--;
    while(s < send){
        if(*s != *send) return 0;
        s++;
        send--;
    }
    return 1;
}

void printP(char *s, P p){
    printf("%s: %d %s %d %.2f\n", s, p.id, p.Name, p.Menge, p.Preis);
}

P setP(char *name, int id, int menge, double preis){
    P p;

    p.id    = id;
    p.Menge = menge;
    p.Preis = preis;

    copyString(name, p.Name);

    return p;
}

void swapP(P *p1, P *p2){
    P p3;

     p3 = *p1;
    *p1 = *p2;
    *p2 = p3;

}
void printPA(P *pa, int n){
    int i = 0;

    for(i=0; i<n; i++)
        printP("pa", pa[i]);
}
int main(){

    char s1[10] = "Hallo";
    char s2[10] = "Welt";
    char s3[10];

    printf("[%s] [%s] [%s]\n", s1, s2, s3);
    replaceCharInString(s1, 'a', 'X');
    printf("[%s] [%s] [%s]\n", s1, s2, s3);
    copyString(s1, s3);
    printf("[%s] [%s] [%s]\n", s1, s2, s3);
    swapStrings(s1, s2);
    printf("[%s] [%s] [%s]\n", s1, s2, s3);

    printf("%s ist ", "lagerregal");
    if(isPalindrom("lagerregal"))
        printf("ein Palindrom\n");
    else
        printf("kein Palindrom\n");


    P p1, p2;
    P pa[5];

    printf("sep p1\n");
    p1 = setP("Mueller", 1, 3, 1.23);
    printP("p1", p1);

    printf("p2=p1\n");
    p2=p1;
    printP("p2", p2);

    printf("sep p2\n");
    p2 = setP("Meier", 2, 4, 5.23);
    printP("p2", p2);

    printf("swap p1 und p2\n");
    swapP(&p1, &p2);
    printP("p1", p1);
    printP("p2", p2);

    pa[0] = setP("M1", 1, 3, 1.23);
    pa[1] = setP("M2", 1, 3, 1.23);
    pa[2] = setP("M3", 1, 3, 1.23);
    printPA(pa, 3);
    return 0;
}
