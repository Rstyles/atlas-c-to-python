/**
 * ***********************Question 2****************************************************
**/


#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

struct Entry {
    char key[256];
    char value[256];
};

int main() {
    char keys[3][256] = {"name", "age", "city"};
    char values[3][256] = {"Alice", "25", "New York"};

    struct Entry hashtable[TABLE_SIZE];

    for(int i = 0; i < 3; i++) {
        strcpy(hashtable[i].key, keys[i]);
        strcpy(hashtable[i].value, values[i]);
    }

    for(int i = 0; i < 3; i++) {
        printf("%s: %s\n", hashtable[i].key, hashtable[i].value);
    }

    return 0;
}
