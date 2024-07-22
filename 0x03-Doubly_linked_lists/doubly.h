#include <stdio.h>
#include <stdlib.h>


typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

typedef struct dlist_s
{
    char *str;
    unsigned int len;
    struct dlist_s *prev;
    struct dlist_s *next;
} dlist_t;