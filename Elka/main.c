#include <stdio.h>
int main (void)
{
    int vusota;
    scanf("%d", &vusota);
    int y = vusota - 1;
    int b;
    int probel = vusota + 3;
    int block;
    int penek;

    int g = vusota  - 1;
    for(b = vusota ; b > 0; b--)
    {
        for(probel = y + vusota ; probel > vusota; probel--){
            printf("_");
        }
        for(block = g; block < vusota; block++){
             printf("*");
        }
        printf("\n");
        y = y - 1;
        g = g -2;
    }
       int k = vusota - 1; //4
        for(penek = k + vusota; penek > vusota; penek--){
            printf("_");
        }
        printf("*");
}
