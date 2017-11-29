#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GetString(char string[]);
void buubbleSort(char array[][2], int size);
void PrintResult(char array[][2], int size);
CounterLetters(char *string,char array[][2],int size);
//void swap(int *element1Ptr, int *element2Ptr);

int main()
{
    const int SIZE = 26;
    char string[200000];
    char array[SIZE][2];
    int counter;

    for(counter = 0; counter < SIZE; counter++){
        array[counter][0] = 'a' + counter;
        array[counter][1] = 0;
    }

    GetString(string);

    CounterLetters(string,array,SIZE);

    buubbleSort(array, SIZE);

    PrintResult(array, SIZE);

}
CounterLetters(char *string,char array[][2],int size)
{
    int counter,counter2;
     for(counter2 = 0; counter2 < strlen(string);counter2++){
        for(counter = 0; counter < size; counter++){
            if(array[counter][0] == string[counter2]){
                 array[counter][1] = array[counter][1] + 1;
                    break;
            }
        }
    }
}
GetString(char *string)
{
    int counter,counter2;
    char src[800];

    printf("Get String\n");
    gets(src);

    for(counter = counter2 = 0; src[counter] != '\0'; counter++){
        if(src[counter] != ' '){
            string[counter2++] = src[counter];
        }
    }
    string[counter2] = '\0';
 }

void buubbleSort(char array[][2], int size)
{
    int counter,counter2,value;

    for(counter2 = 0; counter2 < size - 1; counter2++){
        for(counter = 0 ; counter < size - 2; counter++){
            if(array[counter][1] < array[counter + 1][1]){
                //swap(&array[i][1], &array[i + 1][1]);
                value = array[counter][1];
                array[counter][1] = array[counter + 1][1];
                array[counter + 1][1] = value;

                value = array[counter][0];
                array[counter][0] = array[counter + 1][0];
                array[counter + 1][0] = value;
            }
         }
    }

}

void PrintResult(char array[][2], int size)
{
    int counter;
    for(counter = 0; counter < size; counter++){
            if(array[counter][1] > 0){
                printf("%c - %d \n", array[counter][0], array[counter][1]);
            }
        }
}

//void swap(char *element1Ptr, char *element2Ptr)
//{
//    int temp;
//    temp = *element1Ptr;
//    *element1Ptr = *element2Ptr;
//    *element2Ptr = temp;
//}


