#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "main.h"
#include "operation_elements.h"

//-------------------------------------------------------------------------

int push_front (list_t* my_list, int elem) //TODO return index of insert_elem
{
    list_error (my_list);

    int head_last = my_list->head;

    my_list->number_free--; //TODO remove number_free use free

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

int push_back (list_t* my_list, int elem) //TODO return index of insert_elem
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

int remove (list_t* my_list, int elem) //TODO we not use line search in remove elem //TODO index elem
{
    list_error (my_list);

    int number_elem = my_list->head;

    if (my_list->number_free == my_list->capacity - 1)
    {
        my_list->tail = 0;
        my_list->head = 0;
    }

    int next_elem = 0;
    int prev_elem = 0;

    for (int i = 0; i < my_list->capacity - my_list->number_free - NULL_ELEM; i++) //TODO not use!!!!
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

    if (my_list->head == number_elem)
    {
        my_list->head = next_elem;
    }

    if (my_list->tail == number_elem)
    {
        my_list->tail = prev_elem;
    }

    if (next_elem != 0)
    {
        my_list->prev[next_elem] = prev_elem;
    }

    if (prev_elem != 0)
    {
        my_list->next[prev_elem] = next_elem;
    }

    my_list->next[number_elem] = 0;
    my_list->data[number_elem] = POISON;
    my_list->prev[number_elem] = -1; //TODO func prepare free elem

    my_list->number_free++;

    int number_free = 0;

    for (number_free = my_list->free; my_list->next[number_free] != 0; number_free = - my_list->next[number_free]); //TODO not use

    printf ("%d\n", number_free);

    my_list->next[number_free] = - number_elem;

    printf ("%d\n\n", my_list->next[number_free]);

    return 0;
}

//-------------------------------------------------------------------------

int emplace_back (list_t* my_list, int elem, int elem_push) //TODO not use int use typedef and use size_t
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
