#include "doubly.h"
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
* implementing a doubly linked list
 */
void dl_add_node(dlist_t **h, char *str)
{
    dlist_t *new;

    new = malloc(sizeof(dlist_t));
    new->str = _strdup(str);
    new->len = _strlen(str);
    new->prev = NULL;
    new->next = *h;
    if (new->next != NULL)
    {
        new->next->prev = new;
    }
    *h = new;
}
/**
 * pop - removes the first item from the list
 */
list_t *pop(list_t **h)
{
    list_t  *pop;

    pop = *h;
    if (*h != NULL)
    {
        *h = (*h)->next;
    }
    return (pop);
}

/**
* pop_and_free - pops and frees the first item in the list
 */
 void pop_and_free(list_t **h)
{
    list_t *pop;

    pop = *h;
    if (*h != NULL)
    {
        *h = (*h)->next;
        free(pop->str);
        free(pop);
    }
}

/**
*  free_list - deletes everything in the list
and free memory
*/
void free_list(list_t **h)
{
    while(*h != NULL)
    {
        pop_and_free(h);
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

void dl_print_list(dlist_t *dh)
{
    while (dh)
    {
        printf("%s (%u)\n", dh->str, dh->len);
        dh = dh->next;
    }
}

int main()
{
    list_t *h;
    dlist_t *dh;

    dh = NULL;
    dl_add_node(&dh, "BrosThatCode");
    dl_add_node(&dh, "Ezz Morgan");
    dl_add_node(&dh, "Seba Daniel");
    dl_print_list(dh);
    printf("---------------------------\n");
    h = NULL;
    add_node(&h, "whatever");
    add_node(&h, "you say");
    add_node(&h, "is cool");

    print_list(h);
    printf("---------------------------\n");
    add_node(&h, "super duper awesome");
    print_list(h);
    printf("---------------------------\n");
    pop_and_free(&h);
    print_list(h);
    printf("--------------------------\n");
    free_list(&h);
    print_list(h);
    printf("--------------------------\n");
    return (0);
}