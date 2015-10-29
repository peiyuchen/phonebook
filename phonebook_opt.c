#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* original version */

entry* hash_table[hash_size];
entry* hash_tail[hash_size];
entry *findName(char lastName[], entry *pHead)
{
    unsigned int index = hash2(lastName);
    entry* tmp = hash_table[index];
    while (tmp != NULL) {
        if (strcasecmp(lastName, tmp->lastName) == 0)
            return tmp;
	
        tmp = tmp->pNext;
    }
    return NULL;
}


entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    entry* t = (entry *) malloc(sizeof(entry));
    strcpy(t->lastName, lastName);
    t->pNext = NULL;

    unsigned int index = hash2(lastName);
    if(hash_table[index] == NULL){
	hash_table[index] = t;
    }else{
	//printf("FUCK it: %s\n", pHead->lastName);
	hash_tail[index]->pNext = t;
    }
    hash_tail[index] = t;

    return e;
}
unsigned int hash2(char *key)
{
    unsigned int hashVal = 0;
    while(*key != '\0'){
        hashVal = (hashVal << 5) + *key++;
    }

    return hashVal % hash_size;
}
