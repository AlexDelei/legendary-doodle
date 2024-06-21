#include "linked_list.h"

int _strlen(char *str)
{
    int len;

    len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return (len);
}

void _strcopy(char *to, char *from)
{
    int i;

    for (i = 0; from[i] != '\0'; i++)
    {
        to[i] = from[i];
    }
    to[i] = '\0';
}

char *_strdup(char *str)
{
    int size;
    char *new;

    size = _strlen(str);
    new = malloc(sizeof(char) * (size + 1));
    _strcopy(new, str);
    return (new);
}

void add_node(list_t **h, char *str)
{
    list_t *new;

    new = malloc(sizeof(list_t));
    new->str = _strdup(str);
    new->len = _strlen(new->str);

    new->next = *h;
    *h = new;
}

void print_list(list_t *h)
{
    while (h != NULL)
    {
        printf("name = [%s], size = [%u]\n", h->str, h->len);
        h = h->next;
    }
    
}

int linked_list_len(list_t *h)
{
    int cnt = 0;

    while (h != NULL)
    {
        cnt++;
        h = h->next;
    }
    return (cnt);
}

void print_linked_list_rev(list_t *h)
{
    if (h != NULL)
    {
        print_linked_list_rev(h->next);
        printf("name = [%s], size = [%u]\n", h->str, h->len);
    }
}

list_t *list_to_array(list_t *h)
{
    int size, i;
    list_t *a;

    size = linked_list_len(h);
    a = malloc(sizeof(list_t) * size);
    for (i = 0; i < size; i++, h = h->next)
    {
        a[i] = *h;
    }
    return (a);
}

void print_array(list_t *a)
{
    int i;

    for (i = 0; a[i].next != NULL; i++)
    {
        printf("name = [%s], size = [%u]\n", a[i].str, a[i].len);
    }
    printf("name = [%s], size = [%u]\n", a[i].str, a[i].len);
}

int main(void)
{
    list_t *h;
    list_t *a;

    h = NULL;
    add_node(&h, "Micheal");
    add_node(&h, "Justin");
    add_node(&h, "Larry");
    print_list(h);
    printf("Size of the list [%d]\n", linked_list_len(h));
    print_linked_list_rev(h);
    printf("\n\n Array \n");
    a = list_to_array(h);
    print_array(a);
    return (0);
}