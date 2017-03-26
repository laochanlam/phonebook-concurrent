#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "phonebook_orig.h"

/* original version */
entry *findName(char lastname[], entry *pHead)
{
    while (pHead) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

entry *removeName(char lastName[], entry *pHead)
{
    while (pHead) {
        if (strcasecmp(lastName, pHead->lastName) == 0) {
            pHead = pHead->pNext;
            return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}
