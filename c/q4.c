/**
 * *****************Question 4**********************************************************
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 100

struct Entry {
    char word[50];
    int count;
};

int hash(char *str) {
    int hash = 0;
    while (*str) {
        hash = (hash + *str) % TABLE_SIZE;
        str++;
    }
    return hash;
}

void insert(struct Entry hashtable[], char *word) {
    int index = hash(word);
    while (hashtable[index].count != 0 && strcmp(hashtable[index].word, word) != 0) {
        index = (index + 1) % TABLE_SIZE;
    }
    if (hashtable[index].count == 0) {
        strcpy(hashtable[index].word, word);
        hashtable[index].count = 1;
    } else {
        hashtable[index].count++;
    }
}

int main() {
    struct Entry hashtable[TABLE_SIZE] = {0};

    char text[] = "This is a test. This test is only a test.";
    char *word = strtok(text, " .");

    while (word != NULL) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        insert(hashtable, word);
        word = strtok(NULL, " .");
    }

    printf("Word Frequency:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashtable[i].count > 0) {
            printf("%s: %d\n", hashtable[i].word, hashtable[i].count);
        }
    }

    return 0;
}
