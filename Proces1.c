#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(){
    int choose,size=0;
    char a;
    char *buf;

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
            buf=(char*)malloc(1*sizeof(char));

            do{
                a=getchar();
                buf[size++]=a;
                printf("%s", buf);
            }while(a!='.');

            free(buf);

            break;
        }
        else {
            printf("Jestes debilem\n");
        }
    }
}
