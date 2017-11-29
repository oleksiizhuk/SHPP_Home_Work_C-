#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letter[] = "qwertyuiopasdfghjklzxcvbnmq";
    for(;;){
        printf("\nEnter letter\n");
        char userAnswer;
        scanf("%c \n", &userAnswer);
        fflush (stdin);

        int i = 0;
        for (i = 0; i < 26; i++){
            if (letter[i] == userAnswer){
                printf("\nNext letter is %c\n", letter[i+1]);
                break;
            }
            if (i == 26) {
                    printf("\nYou did not enter the letter of the Latin alphabet");
            }
        }
    }
}
