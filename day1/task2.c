#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(char* line, int size) {
    char *ret = malloc(size+1);
    ret[size] = 0;
    int i = 0;
    while (i < size) {
        ret[i] = line[i];
        i++;
    }
    return ret;
}

int getFromText(char *line, int i) {
    char *test = trim(line+i, 3);
    printf("test 3 %s\n", test);
    if (strcmp(test, "one") == 0) {
        return 1;
    }
    if (strcmp(test, "two") == 0) {
        return 2;
    }
    if (strcmp(test, "six") == 0) {
        return 6;
    }
    free(test);
    test = trim(line+i, 4);
    if (strcmp(test, "four") == 0) {
        return 4;
    }
    if (strcmp(test, "five") == 0) {
        return 5;
    }
    if (strcmp(test, "nine") == 0) {
        return 9;
    }
    free(test);
    test = trim(line+i, 5);
    if (strcmp(test, "three") == 0) {
        return 3;
    }
    if (strcmp(test, "seven") == 0) {
        return 7;
    }
    if (strcmp(test, "eight") == 0) {
        return 8;
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    unsigned long int total = 0;
    char const* const fileName = "input.txt";
    FILE* file = fopen(fileName, "r"); 
    char line[500];

    while (fgets(line, sizeof(line), file)) {
        int first = 0;
        int last = 0;
        line[strlen(line)-1] = 0;
        for (int i = 0; i < strlen(line); i++) {
            char lig = {line[i], 0};
            int can = atoi(&lig);

            if (can == 0) {
                can = getFromText(line, i);
            }

            if (can != 0) {
                if (first == 0) {
                    first = can;
                    last = can;
                } else {
                    last = can;
                }
            }
        }
        total += (first*10) + last;
    }
    fclose(file);
    return 0;
}