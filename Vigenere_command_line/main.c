#include <stdio.h>
#include <stdlib.h>

char transformKey(char *key);

char encoding(char *string, char *key);

char decoding(char *string, char *key);

int main(int argc, char **argv){

    char *string;
    char *key;
    int choice;

    if(argc < 4){
        printf("Use: program {str} {key} {choice}");
        return 1;
    }

    string = argv[1];
    key = argv[2];
    choice = (atoi(argv[3]));

    switch(choice)
    {
    case 1:
        transformKey(key);
        encoding(string,key);
        printf("\nPrint encoding result %s ", string);
        break;
        return 0;
    case 2:
        transformKey(key);
        decoding(string,key);
        printf("\nPrint encoding result %s ", string);
        break;
        return 0;
    }
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
