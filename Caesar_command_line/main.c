#include <stdio.h>
#include <string.h>
#include <ctype.h>

int transformKey(int key);

void encoding(char *string, int *key);

void decoding(char *string, int *key);

int main(int argc, char **argv){
    char *string;
    int key, choice;

    if (argc < 4){
        printf("Use: program.exe {str} {key} {choice}");
        return 1;
    }

    string = argv[1];
    key = (atoi(argv[2]));
    choice = (atoi(argv[3]));

    switch(choice)
    {
        case 1:
            key = transformKey(key);
            encoding(string,&key);
            printf("encoding: %s\n", string);
            break;
            return 0;
        case 2:
            key = transformKey(key);
            decoding(string,&key);
            printf("decoding: %s\n", string);
            break;
            return 0;
    }
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
