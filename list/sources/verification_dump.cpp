#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "list.h"

//-------------------------------------------------------------------------
//TODO enum
// 100001111
// 1 << 0
// 1 << 1
// 1 << 2

list_check_t list_error (list_t* my_list, int line)
{
    if (my_list == 0)
    {
        printf ("ERROR\n"
                "pointer for list == 0\n"
                "line = %d\n", line);

        return ERROR;
    }
    else if (my_list->data == 0) //TODO use define and multy-error
    {
        printf ("ERROR\n"
                "pointer for list_data == 0\n"
                "line = %d\n", line);

        return ERROR;
    }
    else if (my_list->next == 0)
    {
        printf ("ERROR\n"
                "pointer for list_next == 0\n"
                "line = %d\n", line);

        return ERROR;
    }
    else if (my_list->prev == 0)
    {
        printf ("ERROR\n"
                "pointer for list_prev == 0\n"
                "line = %d\n", line);

        return ERROR;
    }
    else if (my_list->free == 0)
    {
        printf ("ERROR\n"
                "list_free == 0\n"
                "line = %d\n", line);

        return ERROR;
    }
    else if (my_list->number_free == 0)
    {
        printf ("ERROR\n"
                "list_number_free == 0\n"
                "line = %d\n", line);

        return ERROR;
    }

    return OK;
}

//-------------------------------------------------------------------------

int dump_list (list_t* my_list)
{
    int check = list_error (my_list, __LINE__);

    if (check == OK)
    {
        FILE* file = fopen ("log/log.dot", "w"); //TODO const
        assert (file);

        fprintf (file, "digraph G{\n"
                 "\trankdir=LR;\n"); //TODO

        fprintf (file, "\telem_list [color = \"red\",shape=record, label= \"LIST | CAPACITY: %d | <f_head> HEAD: %d | <f_tail> TAIL: %d | <f_free> FREE: %d | NUMBER_FREE: %d\"];\n", my_list->capacity, my_list->next[0], my_list->prev[0], my_list->free, my_list->number_free);

        for (int i = 0; i < SIZE; i++) //TODO not use SIZE
        {
            char color[10] = {};

            if (my_list->prev[i] < 0)
            {
                color[0] = 'g';
                color[1] = 'r';
                color[2] = 'e';
                color[3] = 'e';
                color[4] = 'n';
            }
            else
            {
                color[0] = 'b';
                color[1] = 'l';
                color[2] = 'u';
                color[3] = 'e'; //TODO use second fprintf
                color[4] = '\0';
            }

            fprintf (file, "\telem_%d [color = \"%s\", shape=record, label= \"IP: %d | DATA: %d| NEXT: %d| PREV: %d\"];\n", i, color, i, my_list->data[i], my_list->next[i], my_list->prev[i]);         //TODO наверно все надо записывать в буфер и выводить вместе в бинарно открытый файл
        }

        fprintf (file, "\telem_0 -> elem_0;\n");

        if (my_list->number_free != 0)
        {
            fprintf (file, "\telem_list:<f_free> -> elem_%d;\n", my_list->free);

            fprintf (file, "\telem_%d -> ", my_list->free);

            int next = - my_list->next[my_list->free];

            for (int i = my_list->free; 1; i = - my_list->next[i])
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

        fprintf (file, "\telem_list:<f_head> -> elem_%d;\n", my_list->next[0]);

        fprintf (file, "\telem_list:<f_tail> -> elem_%d;\n", my_list->prev[0]);

        if (my_list->number_free < my_list->capacity - 2)
        {
            fprintf (file, "\telem_%d -> ", my_list->next[0]);

            int next = my_list->next[my_list->next[0]];

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
