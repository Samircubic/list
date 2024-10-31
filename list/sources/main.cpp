#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define ARG_LIST int

int const POISON = -992416;
int const SIZE = 10;
int const NULL_ELEM = 1;

typedef struct list
{
    ARG_LIST *data;
    int *next;
    int head;
    int *prev;
    int tail;
    int free;
    int number_free;
    int capacity;
} list_t;

typedef enum list_check
{
    OK,
    ERROR
} list_check_t;

list_t*         ctor_list       ();
int             dtor_list       (list_t* my_list);
list_check_t    list_error      (list_t* my_list);
int             dump_list       (list_t* my_list);
int             push_front      (list_t* my_list, int elem);
int             push_back       (list_t* my_list, int elem);
int             emplace_back    (list_t* my_list, int elem, int elem_push);
int             emplace_front   (list_t* my_list, int elem, int elem_push);
int             remove          (list_t* my_list, int elem);

//-------------------------------------------------------------------------

int main ()
{
    list_t* my_list = ctor_list ();

    push_back (my_list, 6);
    push_back (my_list, 5);
    push_back (my_list, 4);
    push_back (my_list, 3);
    push_back (my_list, 2);
    push_back (my_list, 1);

    // emplace_front (my_list, 1, 10);

    remove (my_list, 2);

    dump_list (my_list);

    dtor_list (my_list);

    return 0;
}

//-------------------------------------------------------------------------

list_t* ctor_list ()
{
    list_t* my_list = (list_t*) calloc (1, sizeof (list_t));
    assert (my_list);

    my_list->data = (ARG_LIST*) calloc (SIZE, sizeof (ARG_LIST));
    assert (my_list->data);

    my_list->next = (int*) calloc (SIZE, sizeof (int));
    assert (my_list->next);

    my_list->head = 0;

    my_list->prev = (int*) calloc (SIZE, sizeof (int));
    assert (my_list->prev);

    for (int i = 0; i < SIZE; i++)
    {
        my_list->data[i] = POISON;
    }

    for (int i = 1; i < SIZE - 1; i++)
    {
        my_list->next[i] = -i - 1;
    }

    my_list->number_free = SIZE - NULL_ELEM;

    for (int i = 1; i < SIZE; i++)
    {
        my_list->prev[i] = -1;
    }

    my_list->capacity = SIZE;

    my_list->tail = 0;

    my_list->free = 1;

    return my_list;
}

//-------------------------------------------------------------------------

list_check_t list_error (list_t* my_list)
{
    if (my_list == 0)
    {
        printf ("ERROR\n"
                "pointer for list == 0\n");

        return ERROR;
    }
    else if (my_list->data == 0)
    {
        printf ("ERROR\n"
                "pointer for list_data == 0\n");

        return ERROR;
    }
    else if (my_list->next == 0)
    {
        printf ("ERROR\n"
                "pointer for list_next == 0\n");

        return ERROR;
    }
    else if (my_list->prev == 0)
    {
        printf ("ERROR\n"
                "pointer for list_prev == 0\n");

        return ERROR;
    }
    else if (my_list->free == 0)
    {
        printf ("ERROR\n"
                "list_free == 0\n");

        return ERROR;
    }

    return OK;
}

//-------------------------------------------------------------------------

int push_front (list_t* my_list, int elem)
{
    list_error (my_list);

    int head_last = my_list->head;

    my_list->number_free--;

    my_list->head = my_list->free;
    my_list->data[my_list->head] = elem;

    my_list->free = - my_list->next[my_list->free];

    if (my_list->tail == 0)
    {
        my_list->tail = my_list->head;
        my_list->next[my_list->head] = 0;
    }
    else
    {
        my_list->prev[head_last] = my_list->head;
        my_list->next[my_list->head] = head_last;
    }

    my_list->prev[my_list->head] = 0;

    return 0;
}

//-------------------------------------------------------------------------

int push_back (list_t* my_list, int elem)
{
    list_error (my_list);

    int tail_last = my_list->tail;

    my_list->number_free--;

    my_list->tail = my_list->free;
    my_list->data[my_list->tail] = elem;

    my_list->free = - my_list->next[my_list->free];

    if (my_list->head == 0)
    {
        my_list->head = my_list->tail;
        my_list->prev[my_list->head] = 0;
    }
    else
    {
        my_list->next[tail_last] = my_list->tail;
        my_list->prev[my_list->tail] = tail_last;
    }

    my_list->next[my_list->tail] = 0;

    return 0;
}

//-------------------------------------------------------------------------

int remove (list_t* my_list, int elem)
{
    list_error (my_list);

    int number_elem = my_list->head;

    int next_elem = 0;
    int prev_elem = 0;

    for (int i = 0; i < my_list->capacity - my_list->number_free - NULL_ELEM; i++)
    {
        if (my_list->data[number_elem] == elem)
        {
            next_elem = my_list->next[number_elem];
            prev_elem = my_list->prev[number_elem];
        }
        else
        {
            number_elem = my_list->next[number_elem];
        }
    }

    if (next_elem != 0)
    {
        my_list->prev[next_elem] = prev_elem;
    }

    if (prev_elem != 0)
    {
        my_list->next[prev_elem] = next_elem;
    }

    return 0;
}

//-------------------------------------------------------------------------

int emplace_back (list_t* my_list, int elem, int elem_push)
{
    return 0;
}

//-------------------------------------------------------------------------

int emplace_front (list_t* my_list, int elem, int elem_push)
{
    list_error (my_list);

//     int number_elem = my_list->head;
//
//     int next_elem = 0;
//     int prev_elem = 0;

    // for (int i = 0; i < my_list->capacity - my_list->number_free - NULL_ELEM; i++)
    // {
    //     if (my_list->data[number_elem] == elem)
    //     {
    //         next_elem = my_list->head[number_elem];
    //         prev_elem = my_list->tail[number_elem];
    //     }
    //     else
    //     {
    //         number_elem = my_list->next[number_elem];
    //     }
    // }

//     my_list->number_free--;
//
//     my_list->tail = my_list->free;
//     my_list->data[my_list->tail] = elem;
//
//     my_list->free = - my_list->next[my_list->free];
//
//     if (my_list->head == 0)
//     {
//         my_list->head = my_list->tail;
//         my_list->prev[my_list->head] = 0;
//     }
//     else
//     {
//         my_list->next[tail_last] = my_list->tail;
//         my_list->prev[my_list->tail] = tail_last;
//     }
//
//     my_list->next[my_list->tail] = 0;

    return 0;
}

//-------------------------------------------------------------------------

int dump_list (list_t* my_list)
{
    int check = list_error (my_list);

    if (check == OK)
    {
        FILE* file = fopen ("data/log.dot", "w+");
        assert (file);

        fprintf (file, "digraph G{\n"
                 "\trankdir=LR;\n");

        fprintf (file, "\telem_list [shape=record, label= \"LIST | CAPACITY: %d | <f_head> HEAD: %d | <f_tail> TAIL: %d | <f_free> FREE: %d | NUMBER_FREE: %d\"];\n", my_list->capacity, my_list->head, my_list->tail, my_list->free, my_list->number_free);

        for (int i = 0; i < SIZE; i++)
        {
            fprintf (file, "\telem_%d [shape=record, label= \"IP: %d | DATA: %d| NEXT: %d| PREV: %d\"];\n", i, i, my_list->data[i], my_list->next[i], my_list->prev[i]);         //TODO наверно все надо записывать в буфер и выводить вместе в бинарно открытый файл
        }

        fprintf (file, "\telem_0 -> elem_0;\n");

        if (my_list->number_free != 0)
        {
            fprintf (file, "\telem_list:<f_free> -> elem_%d;\n", my_list->free);

            fprintf (file, "\telem_%d -> ", my_list->free);

            int next = - my_list->next[my_list->free];

            for (int i = my_list->free; 1; i++)
            {
                fprintf (file, "elem_%d", next);

                if (my_list->next[i] != 0)
                {
                    fprintf (file, " -> ");

                    next = - my_list->next[next];
                }

                if (my_list->next[i] == 0)
                {
                    break;
                }
            }

            fprintf (file, ";\n");
        }

        fprintf (file, "\telem_list:<f_head> -> elem_%d;\n", my_list->head);

        fprintf (file, "\telem_list:<f_tail> -> elem_%d;\n", my_list->tail);

        if (my_list->number_free < my_list->capacity - 2)
        {
            fprintf (file, "\telem_%d -> ", my_list->head);

            int next = my_list->next[my_list->head];

            for (int i = 0; i < my_list->capacity - my_list->number_free - NULL_ELEM; i++)
            {
                fprintf (file, "elem_%d", next);

                if (i + 1 != my_list->capacity - my_list->number_free - NULL_ELEM)
                {
                    fprintf (file, " -> ");

                    next = my_list->next[next];
                }
            }

            fprintf (file, ";\n");
        }

        fprintf (file, "}\n");

        fclose (file);
    }
    else
    {
        printf ("Critical error, dump output not possible\n");
    }

    return check;
}

//-------------------------------------------------------------------------

int dtor_list (list_t* my_list)
{
    assert (my_list);
    assert (my_list->data);
    assert (my_list->next);
    assert (my_list->prev);

    free (my_list->data);

    free (my_list->next);

    free (my_list->prev);

    free (my_list);

    return 0;
}

//-------------------------------------------------------------------------

// 1) ctor dtor +++
// 2) верификацию +-
// 3) dump_list +-
// 4) получения указателя на первый элемент списка      получения указателя на последний элемент списка     получения указателя на элемент, следующий за данным         получения указателя на элемент, предшествующий данному
// 5) вставки элемента в начало списка +                вставки элемента в конец списка +                   вставки элемента перед заданным элементом                   вставки элемента после заданного элемента
// 6) удаления заданного элемента
// 7) поиска элемента по его значению                   удаления всех элементов

