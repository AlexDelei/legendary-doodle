#include "recap.h"
/**
* A recap of likned lists implementation
 */


/**
* copies the string to an allocated memory
 */
void _strcopy(char *to, char *from)
{
    while (*from)
    {
        *to = *from;
        from++;
        to++;
    }
    *to = '\0';
}

/**
* returns the length of out strings
 */
int _strlen(char *str)
{
    int len = 0;

    while (*str != '\0')
    {
        len++;
        str++;
    }
    return (len);
}

/**
* duplicates the string
 */
char *_strdup(char *str)
{
    char *dup;
    int len;

    len = _strlen(str);
    dup = malloc(sizeof(char) * (len + 1));
    _strcopy(dup, str);
    return (dup);
}

/**
* Adding a new node at the end of our linked lists
* and this time using the First In First Out principle
 */
void add_node(list_t **h, char *str)
{
    list_t *new;
    list_t *p;

    new = malloc(sizeof(list_t));
    new->str = _strdup(str);
    new->len = _strlen(str);
    new->next = NULL;

    p = *h;
    if (p == NULL)
    {
        *h = new;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
    }
    
}

/**
* Walks through the list and prints out items
 */
void print_list(list_t *h)
{
    while (h)
    {
        printf("%s (%u)\n", h->str, h->len);
        h = h->next;
    }
}

int main()
{
    list_t *h;

    h = NULL;
    add_node(&h, "whatever");
    add_node(&h, "you say");
    add_node(&h, "is cool");

    print_list(h);
    printf("---------------------------\n");
    add_node(&h, "super duper awesome");
    print_list(h);
    return (0);
}