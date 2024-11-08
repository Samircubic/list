#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "list.h"

//-------------------------------------------------------------------------

list_t* ctor_list () //TODO rename this file
{
    list_t* my_list = (list_t*) calloc (1, sizeof (list_t));
    assert (my_list); //TODO use self macros for user - error || if()

    my_list->data = (ARG_LIST*) calloc (SIZE, sizeof (ARG_LIST)); //TODO rename SIZE - Initial capacity
    assert (my_list->data);

    my_list->next = (int*) calloc (SIZE, sizeof (int));   //TODO free memory if error
    assert (my_list->next);

    my_list->next[0] = NULL_INDEX;

    my_list->prev = (int*) calloc (SIZE, sizeof (int)); //TODO ssize_t
    assert (my_list->prev);

    for (int i = 0; i < SIZE; i++)
    {
        my_list->data[i] = POISON;
    }

    for (int i = 1; i < SIZE - 1; i++)
    {
        my_list->next[i] = -i - 1; //TODO not use -i
    }

    my_list->number_free = SIZE - NULL_ELEM;

    for (int i = 1; i < SIZE; i++) //TODO !!!!!!!!!!!!!!!!!!!!!!!!!!func!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        my_list->prev[i] = -1;
    }

    my_list->capacity = SIZE;

    my_list->prev[0] = 0;

    my_list->free = 1; //TODO const

    return my_list;
}

//-------------------------------------------------------------------------

int poison_in_prev (list_t* my_list)
{
    int i = 0;

    for (i = NULL_ELEM; i < my_list->capacity - NULL_ELEM; i++)
    {
        my_list->prev[i] = -1;
    }

    return i - NULL_ELEM;
}

//-------------------------------------------------------------------------

int dtor_list (list_t* my_list) //TODO return value
{
    assert (my_list);
    assert (my_list->data);
    assert (my_list->next);
    assert (my_list->prev); //TODO use before assert VERIFICATE

    for (int i = 0; i < my_list->capacity; i++) //TODO
    {
        my_list->data[i] = POISON;
        my_list->next[i] = POISON;
        my_list->prev[i] = POISON;
    }

    free (my_list->data);

    free (my_list->next);

    free (my_list->prev);

    free (my_list);

    return 0;
}

//-------------------------------------------------------------------------
