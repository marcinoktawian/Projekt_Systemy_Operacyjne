#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
    int index;
    char znak;
    struct lista *prev, *next;
}ciag;

ciag *head;
ciag *tail;

ciag* add(char litera,ciag *point){
    point=(ciag*)malloc(sizeof(ciag));
    point->znak=litera;
    if(head==NULL){
        point->index=0;
        point->next=NULL;
        point->prev=NULL;
        head=point;
        tail=head;
    }else{
        point->index=(tail->index+1);
        point->next=NULL;
        point->prev=tail;
        tail->next=point;
        tail=point;
    }
    return head;
}

void save(ciag *point,char tablica[],int size){
    int lp=0;
    if(point==NULL){
        printf("PUSTA LISTA");
    }else{
        while(point!=NULL){
            tablica[lp++]=point->znak;
            point=point->next;
        }
    }
}

void usun(ciag *point){
    if(point!=NULL){
        usun(point->next);
        free(point);
        point=NULL;
    }
    head=NULL;
    tail=NULL;
}


int main(){
    int choose,size=0;
    char a;
    char *tab;
    for(;;) {
        printf("1. Wczytaj z pliku \n2. Wczytaj z stdin\n");
        scanf("%d", &choose);

        if (choose == 1) {

            int n = 0;                                  /* Zmienna do przechwywania liczby znakow w linii */
            FILE *f = fopen("main.c", "r");             /* Otwieram plik */
            const int max_n = 10000;                    /* Maksymalna ilosc znakow w linii */
            char napis[max_n], *result;                 /* Inicjalizacja tablicy do ktorej bedzie wczytywana linia */

            while(1){

                result = fgets(napis, max_n, f);        /* Pobieram z pliku f do tablicy napis max max_n linii */
                n = strlen(napis);                      /* Obliczam ilosc znakow w linii */
                printf("%d\n", n);
                if (result != NULL){                    /* Jezeli wczytalo napis wskaznik jest rozny od NULL*/

                    printf("%s", napis);
                    if (feof (f))   break;              /* Jezeli napotkasz koniec pliku wyjdz z petli */

                }
            }
            break;
        }
        else if (choose == 2) {
            //do{
                printf("\nPodaj swoj tekst\n");
                a = getchar();
                while((a = getchar())!='\n' && a!=EOF){
                    head=add(a,head);
                }
                int const index=tail->index+1;
                int i;
                char tab[index];
                save(head,tab,index);
                for(i=0;i<index;i++){
                    printf("%c\t",tab[i]);
                }
                if(head==tail && head->znak=='.'){
                    break;
                }else{
                    usun(head);
                }
        }
        else {
            printf("Jestes debilem\n");
        }
    }
}
