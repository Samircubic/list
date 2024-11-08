#ifndef LIST_H

#define LIST_H

#define ARG_LIST int //TODO typedef

int const POISON = -992416; // ядовитое значение //TODO
int const SIZE = 10;        // начальная длина списка (включая фантомный элемент)
int const NULL_ELEM = 1;    // переменная для показывания что мы учитываем именно фантомный элемент (по надобности)
int const NULL_INDEX = 0;   //

typedef struct list
{
    ARG_LIST *data;         // массив данных
    int *next;              // массив индексов (указателей на следующий элемент в списке (если отриц значит указывает на след пустой элемент)) //TODO read about size_t and ssize_t
    // int head;               //
    int *prev;              // массив индексов (указателей на предыдущий элемент (если -1 значит элемент свободный))
    // int tail;               //
    int free;               // первый элемент в подсписке свободных элементов
    int number_free;        // количество свободных элементов //TODO remove
    int capacity;           // количсетво всех элементов (включая фантомный)
} list_t;

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
int             dtor_list       (list_t* my_list);

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
int             remove          (list_t* my_list, int elem); //TODO pop_back pop_front

/*
верификатор
*/
list_check_t    list_error      (list_t* my_list, int line);

/*
вывод графического представления данныз из списка
*/
int             dump_list       (list_t* my_list);

#endif // LIST_H
