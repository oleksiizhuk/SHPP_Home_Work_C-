#include <stdio.h>
#include <stdlib.h>

char getLine(char *string);

char getKey(char *key);

char transformKey(char *key);

char encoding(char *string, char *key);

char decoding(char *string, char *key);

int main(){
    const int LENGHT_STRING = 1000000;

    char string[LENGHT_STRING];
    char key[LENGHT_STRING];

    getLine(string);
    printf("string: %s \n", string);

    getKey(key);
    printf("key: %s \n", key);

    transformKey(key);

    encoding(string,key);

    printf("\nPrint encoding result %s ", string);

    decoding(string, key);

    printf("\nPrint decoding result %s", string);

}

char getLine(char *string){
    printf("PLS Get String; \n");
    gets(string);
}

char getKey(char *key){
    printf("PLS Get Key; \n");
    gets(key);
}

char transformKey(char *key){

    int i,n;
    n = strlen(key);
    for(i = 0;i < n; i++){
        if(isupper(key[i])){
            key[i] =  key[i] - 64;
        }
        if(islower(key[i])){
            key[i] =  key[i] - 96;
        }
    }
}

char encoding(char *string, char *key){

    int i,n,result;

    for(i = 0, n =0; i < strlen(string);i++,n++){
        if(n >= strlen(key)){
            n = n % strlen(key);
        }
        result = string[i] + key[n];

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

char decoding(char *string, char *key){

    int i,n,result;

    for(i = 0, n =0; i < strlen(string);i++,n++){
        if(n >= strlen(key)){
            n = n % strlen(key);
        }
        result = string[i] - key[n];

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
