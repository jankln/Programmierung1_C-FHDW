#include<stdio.h>

//schreibe eine Funktion, die die länge eines Strings bestimmt
int strLen(char st[]){
    int len = 0;

    while(st[len] != '\0'){
        len++;
    }
    return len;
}

//schreibe eine Funktion, die die Anzahl der Vokale im String zählt
int strVocals(char st[]){
    int vokale = 0;
    int i = 0;
    char c;

    while((c = st[i]) != '\0'){

        switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            vokale++;
            break;
        }
        i++;
    }
    return vokale;
}

//schreibe eine Funktion, die den Inhalt eines Strings in einen anderen Sting kopiert
void strCopy(char von[], char nach[]){

    int i=0;

    while(von[i] != '\0'){

        nach[i] = von[i];
        i++;
    }
    nach[i] = '\0';
}

//schreiben eine Funktion, die zwei übergebene Strings hintereinander in einen dritten String schreibt
void strConcat(char st1[], char st2[], char nach[]){
    int len = strLen(st1);
    strCopy(st1, nach);
    strCopy(st2, nach+len);
}

//schreibe eine Funktion, die alle Grossbuchstaben in Kleinbuchstaben wandelt und umgekehrt
strChangeChar(char st[]){
    int i=0;
    while(st[i] != '\0'){
        if(st[i] >= 'a' && st[i] <= 'z') st[i] += 'A' - 'a';
        else
        if(st[i] >= 'A' && st[i] <= 'Z') st[i] += 'a' - 'A';

        i++;
    }
}

//schreibe eine Funktion, die einen String umdreht
strRevert(char st[]){
    int vorn = 0;
    int hinten = strLen(st)-1;
    char tmp;

    while(vorn < hinten){
        tmp        = st[vorn];
        st[vorn]   = st[hinten];
        st[hinten] = tmp;

        vorn++;
        hinten--;
    }
}

int main()
{
    //erzeuge 3 Textarrys im Hauptprogramm mit der Länge 100 und fülle die ersten beiden mit den Werten
    //"Hallo"
    //" Welt"
    char st1[100] = "Hallo";
    char st2[100] = " Welt";
    char st3[100];

    printf("st  = %s\n", st1);
    printf("st1 = %s\n", st2);

    printf("%s ist %d Zeichen lang\n\n", st1, strLen(st1));

    printf("%s enthaelt %d Vokale\n\n", st1, strVocals(st1));

    strCopy(st1, st3);
    printf("s1 = %s, s2=%s\n\n", st1, st3);


    strConcat(st1, st2, st3);
    printf("[%s] + [%s] = [%s]\n\n", st1, st2, st3);

    printf("vorher [%s] ", st1);
    strChangeChar(st1);
    printf("nachher [%s]\n\n", st1);

    printf("vorher [%s] ", st1);
    strRevert(st1);
    printf("vorher [%s] ", st1);

    return 0;
}
