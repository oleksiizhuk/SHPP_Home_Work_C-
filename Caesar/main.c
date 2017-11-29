#include <stdio.h>
#include <string.h>
#include <ctype.h>

char getLine(char *string);

int getKey(int key);

int transformKey(int key);

void encoding(char *string, int *key);

void decoding(char *string, int *key);

int main()
{
    const int LENGHT_STRING = 1000000;
    char string[LENGHT_STRING];
    int key = 0;

    getLine(string);

    key = getKey(key);

    key = transformKey(key);

    encoding(string,&key);
    printf("encoding: %s\n", string);

    decoding(string,&key);
    printf("decoding: %s\n", string);

}
char getLine(char *string){
    printf("PLS Get String; \n");
    gets(string);
}

int getKey(int key){

    do{
        printf("PLS Get Key: \n");
        scanf("%d", &key);
        fflush(stdin);
        if(key < 1){
            printf("PLS enter number, more one\n");
        }
    }
    while(key < 1);
    return key;
}

int transformKey(int key){
    if(key > 26){
        key = key % 26;
    }
    return key;
}

void encoding(char *string, int *key){

    int i, result;

    for(i = 0; i < strlen(string);i++){
        result = string[i] + *key;
        if(isupper(string[i]) && ( result > 'Z')){
            result = (result - 26);
        }
        if(islower(string[i]) && ( result > 'z')){
            result = (result - 26);
        }
        if(isalpha(string[i])){
            string[i] = result;
        }
    }
}

void decoding(char *string, int *key){

    int i, result;

    for(i = 0; i < strlen(string);i++){
        result = string[i] - *key;
        if(isupper(string[i]) && ( result < 'A')){
            result = (result + 26);
        }
        if(islower(string[i]) && ( result < 'a')){
            result = (result + 26);
        }
        if(isalpha(string[i])){
            string[i] = result;
        }
    }
}
