#include <stdio.h>
#include <stdlib.h>

int main()
{
   int randomChislo;
   int scanChislo;
   int c;
   int i;
   int programCycle;

   for (programCycle = 0; programCycle < 1; programCycle++){
        srand(time(NULL));
        randomChislo = rand() % 9 + 1;

        printf("random chislo = %d\n", randomChislo);

        for (i = 0; i <3; i++){
            do{
                fflush(stdin);
                printf("ygadai chislo \n");
                scanf("%d", &scanChislo);

                if((scanChislo <= 9) && (scanChislo >= 0)){
                    break;
                }
                else{
                    printf("Vvedite chislo ot 0 do 9\n");
                    scanf("%d", scanChislo);
                    }
            }while(1);

            if(randomChislo > scanChislo){
                printf("vvedite bolshe number\n");
            }
            if(randomChislo < scanChislo){
                printf("vvedite menshe number\n");
            }
            if(randomChislo == scanChislo){
                printf("Good\n");
                break;
            }
        }
        for(;;){
            printf("You play again 1/0\n");
            fflush(stdin);
            scanf("%d", &c);
            if(c == 0){
                return 0;
            }
            if (c == 1){
            programCycle = programCycle - 1;
            break;
            }
            else{
                fflush(stdin);
                printf("vvedite 1 ili 0\n");
            }
        }

    }
}
