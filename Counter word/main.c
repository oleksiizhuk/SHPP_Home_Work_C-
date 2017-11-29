#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char getString(char* s);

char wordCount(char* string, int* word);

void print(int* a);

int main(){
    const int LENGHT_OF_STRING = 100000;
    char string[LENGHT_OF_STRING];
    int word = 0;

    getString(string);

    wordCount(string, &word);

    printf("count word: ");
    print(&word);
}

char getString(char* s){
    printf("Get String\n");
    gets(s);
}

char wordCount(char* string, int* word){
    int i,n;
    for(i = 0, n = strlen(string); i < n ;i++){
        if((tolower(string[i]) >= 'a')||(string[i] >= 'z')){
            (*word)++;
            if((tolower(string[i - 1]) >= 'a')||(string[i - 1] >= 'z')){
                (*word)--;
            }
        }
    }
}

void print(int *display){
    printf("%d", *display);
}


