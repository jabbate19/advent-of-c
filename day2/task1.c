#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int red;
    int green;
    int blue;
} Bag;

int main(int argc, char *argv[]) {
    char const* const fileName = (argc > 1) ? "test.txt" : "input.txt";
    FILE* file = fopen(fileName, "r"); 
    char line[500];
    int total = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strlen(line)-1] = 0;
        char *token;
        char *save;
        const char s[2] = ":";
        token = strtok_r(line, s, &save);
        char gameNum = atoi(&token[5]);
        token = strtok_r(NULL, s, &save);
        token = &token[1];
        char *token2;
        char *save2;
        const char s2[2] = ";";
        token2 = strtok_r(token, s2, &save2);
        int validGame = 1;
        while (token2 != NULL) {
            Bag bag = {0,0,0};

            char *token3;
            char *save3;
            const char s3[2] = ",";
            token3 = strtok_r(token2, s3, &save3);
            while (token3 != NULL) {
                const char s4[2] = " ";
                char *save4;
                char *data;
                data = strtok_r(token3, s4, &save4);
                int count = atoi(data);
                data = strtok_r(NULL, s4, &save4);
                if (strncmp(data, "red", 3) == 0) {
                    bag.red = count;
                }
                if (strncmp(data, "green", 5) == 0) {
                    bag.green = count;
                }
                if (strncmp(data, "blue", 4) == 0) {
                    bag.blue = count;
                }
                token3 = strtok_r(NULL, s3, &save3);
            }
            if (bag.red > 12 || bag.green > 13 || bag.blue > 14) {
                validGame = 0;
                break;
            }
            token2 = strtok_r(NULL, s2, &save2);
        }
        if (validGame == 1) {
            total += gameNum;
        }
    }
    printf("total %d\n", total);
    fclose(file);
    return 0;
}