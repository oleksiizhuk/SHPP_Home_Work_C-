#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
 int cent50 = 0;
 int cent25 = 0;
 int cent10 = 0;
 int cent5 = 0;
 int cent1 = 0;
 float zdacha = 0;

    scanf("%f", &zdacha);
        zdacha = zdacha * 100;
    if(zdacha / 50 > 0){
        cent50 = zdacha / 50;
        zdacha = zdacha - (50 * cent50);
    }
    if(zdacha / 25 > 0){
        cent25 = zdacha / 25;
        zdacha = zdacha - (25 * cent25) ;
    }
    if(zdacha / 10 > 0){
        cent10 = zdacha / 10;
        zdacha = zdacha - (10 * cent10) ;
    }
    if(zdacha / 5 > 0){
        cent5 = zdacha / 5;
        zdacha = zdacha - (5 * cent5) ;
    }
     if(zdacha / 1 > 0){
        cent1 = zdacha / 1;
        zdacha = zdacha - (1 * cent1) ;
        printf("%d\n", zdacha);
    }
    printf("po 50 centov - %d\n", cent50);
    printf("po 25 centov - %d\n", cent25);
    printf("po 10 centov - %d\n", cent10);
    printf("po 5 centov - %d\n", cent5);
    printf("po 1 centov - %d\n", cent1);
    printf("vsego monet - %d\n", cent50 + cent25 + cent10 + cent5 +cent1);
}
