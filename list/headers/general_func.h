#ifndef GENERAL_FUNC_H

#define GENERAL_FUNC_H

typedef enum list_check
{
    OK,
    ERROR
} list_check_t;

/*
конструктор списка
*/
list_t*         ctor_list       ();

/*
дистструктор списка
*/
int             dtor_list       (list_t* my_list); //TODO two header - verificate and list.h

/*
верификатор
*/
list_check_t    list_error      (list_t* my_list);

/*
вывод графического представления данныз из списка
*/
int             dump_list       (list_t* my_list);

/*
добавление передаваемого элемента в начало списка
*/
int             push_front      (list_t* my_list, int elem);

/*
добавление элемента в конец списка
*/
int             push_back       (list_t* my_list, int elem);

/*
добавление элемента после определенного элемента
*/
int             emplace_back    (list_t* my_list, int elem, int elem_push);

/*
добавление элемента перед определенным элементом
*/
int             emplace_front   (list_t* my_list, int elem, int elem_push);

/*
удаление передаваемого элемента
*/
int             remove          (list_t* my_list, int elem);

#endif // GENERAL_FUNC_H
