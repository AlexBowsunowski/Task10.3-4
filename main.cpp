#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 255

using namespace std;

void problem1(char * str,char * words){
    memset(words, '\0', MAXSIZE);
    char *word = strtok(str, " .");
    while (word != NULL) {
        strcat(words, word);
        strcat(words, " ");
        word = strtok(NULL, " .\n");
    }

}


char * problem2(char * words, char * new_word){
    memset(new_word, '\0', MAXSIZE);
    char* words_copy = (char *) malloc(sizeof(char) * MAXSIZE);
    char* last_word = (char *) malloc(sizeof(char) * MAXSIZE);
    strcpy(words_copy, words);
    char *cur = strtok(words," .");

    while (cur != NULL){
        last_word = cur;
        cur = strtok(NULL," .");
    }


    char *check_word=strtok(words_copy," .");

    while (check_word!=NULL){
        if(strcmp(check_word, last_word) != 0) {strcat(new_word, check_word); strcat(new_word, " ");}
        check_word=strtok(NULL," .");
    }

}

int check(char * word, char sym, int n){
    for(int i = 0; i < n; ++i){
        if(word[i] == sym) return 0;
    }
    return 1;
}


void problem3(char * str, char * new_str){
    memset(new_str, '\0', MAXSIZE);
    int k = 0;
    char *check_word = strtok(str," .");

    while (check_word!=NULL){
        int flag = 1;

        for(int i = 0; check_word[i] != '\0'; ++i){

            if(check(check_word, check_word[i], i)){
                int count = 1;
                for(int j = i + 1; check_word[j] != '\0'; ++j){
                    if(check_word[j] == check_word[i]) {count++;}
                }

                if(count != 2) {flag = 0; break;}

            }
            k = i;
        }

        if(flag == 1) { strcat(new_str, check_word); strcat(new_str, " ");}
        check_word=strtok(NULL," .");
    }

}



int main() {

    FILE *fileInput = fopen("input.txt", "r");
    FILE *fileOutput = fopen("output.txt", "a+");
    char inputString[MAXSIZE];
    fgets(inputString, MAXSIZE, fileInput);
    char * str = (char *) malloc(sizeof(char) * MAXSIZE);
    strcpy(str, inputString);

    char new_str[MAXSIZE];

    fgets(str, MAXSIZE, fileInput);
    problem1(str, new_str);
    fprintf(fileOutput, "Problem1:\n%s\n", new_str);
    char* new_str1 = (char *) malloc(sizeof(char) * MAXSIZE);
    strcpy(new_str1, new_str);
    char* res2= (char *) malloc(sizeof(char) * MAXSIZE);
    problem2(new_str, res2);
    fprintf(fileOutput, "Problem2:\n%s\n", res2);
    char* res3= (char *) malloc(sizeof(char) * MAXSIZE);
    problem3(new_str1, res3);
    fprintf(fileOutput, "Problem3.18(Slova u kotorih kazhdaya bukva vstrechaetcya dva raza):\n%s\n", res3);

    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}