#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "list.h"

//-------------------------------------------------------------------------
//TODO rename data rename log
int main ()
{
    list_t* my_list = ctor_list ();

    push_back (my_list, 6);
    push_back (my_list, 5);
    push_back (my_list, 4);
    push_back (my_list, 3);
    push_back (my_list, 2);
    push_back (my_list, 1);

    // emplace_front (my_list, 1, 10);              // как мы работает с индексаим которые не действительны

    remove (my_list, 2);                            // как мы работает с индексаим которые не действительны
    remove (my_list, 1);
    remove (my_list, 3);
    remove (my_list, 4);
    remove (my_list, 5);
    remove (my_list, 6);

    push_front (my_list, 7);
    push_back (my_list, 8);

    dump_list (my_list);

    dtor_list (my_list);

    return 0;
}

//-------------------------------------------------------------------------

// 1) ctor dtor +++
// 2) верификацию +-
// 3) dump_list +-
// 4) получения указателя на первый элемент списка      получения указателя на последний элемент списка     получения указателя на элемент, следующий за данным         получения указателя на элемент, предшествующий данному
// 5) вставки элемента в начало списка +                вставки элемента в конец списка +                   вставки элемента перед заданным элементом                   вставки элемента после заданного элемента
// 6) удаления заданного элемента +-
// 7) поиска элемента по его значению                   удаления всех элементов

