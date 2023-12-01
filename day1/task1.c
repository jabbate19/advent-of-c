#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("total %lu\n", total);
    fclose(file);
    return 0;
}