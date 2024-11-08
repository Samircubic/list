#ifndef VERIFICATION_DUMP_H

#define VERIFICATION_DUMP_H

typedef enum list_check //TODO in one place - header
{
    OK,
    ERROR
} list_check_t;


/*
верификатор
*/
list_check_t    list_error      (list_t* my_list, int line);

/*
вывод графического представления данныз из списка
*/
int             dump_list       (list_t* my_list);

#endif // VERIFICATION_DUMP_H
