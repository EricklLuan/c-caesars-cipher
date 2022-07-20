#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// TODO: ask if are encryption or decryption
// TODO: make the decryption of word if asked

int main(int argc, char** argv) {
    if (argc != 3) return -1;

    int key = atoi(argv[1]);
    if(key == 0) return -1;

    unsigned char* word = argv[2];

    printf("Key: %i\nWord: %s\n", key, word);
    printf("Encryption: ");
    for (int i = 0, size = strlen(word); i < size; i++) {
        if (tolower(word[i]) >= 97 && tolower(word[i] <= 121)) {
            if (tolower(word[i]+key) < 97) {
                printf("%c", 122+(key+1));
            } else {
                printf("%c", tolower(word[i])+key);
            }
        } else {
            printf("%c", tolower(word[i]));
        }
    }
    printf("\n");
}
