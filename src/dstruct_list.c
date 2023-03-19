
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dstruct_list.h>

// **************************************
List list_create(int size_of_elt) {

    List list = (List) malloc(sizeof(List));
    if(list == NULL)
        return NULL;

    list->first = NULL;
    list->callback = NULL;
    list->size = 0;
    list->size_of_elt = size_of_elt ?? -1;

    return list;
}

// **************************************

BOOL list_empty(List li) {
    
    CHECK_IF_LIST(li);
    return li->first == NULL;
}

// **************************************

BOOL list_append(List li, pointer data) {

    CHECK_IF_LIST(li);

    ListElement *tmp;
    ListElement *current = (ListElement *) malloc(sizeof(ListElement));
    if(!current)
        return FALSE;

    current->data = (pointer) malloc(li->size_of_elt);
    if(!current->data)
        return FALSE;

    // if everything is OK,  we can add the value in the list
    memcpy(current->data, data, li->size_of_elt);
    current->next = NULL;

    if(!list_empty(li)) {
        tmp = li->first;
        while (tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = current;
        
    } else {
        li->first = current;
    }
    li->size++;

    return TRUE;
}

BOOL list_append_int(List li, int data) {
    return list_append(li, &data, sizeof(int));
}

BOOL list_append_char(List li, char data){
    return list_append(li, &data, sizeof(char));
}

BOOL list_append_float(List li, float data) {
    return list_append(li, &data, sizeof(float));
}

BOOL list_append_double(List li, double data) {
    return list_append(li, &data, sizeof(double));
}

BOOL list_append_short(List li, short data) {
    return list_append(li, &data, sizeof(short));
}

// ************************************

size_t list_size(List li) {
    
    CHECK_IF_LIST(li);
    return li->size;
}

// ***************************************

BOOL list_remove(List li, int index) {

}

BOOL list_remove_first(List li) {

    CHECK_IF_LIST(li);

    ListElement *elt;

    if(li->first) {

        elt = li->first;
        li->first = elt->next;

        if(elt->data)
            free(elt->data);
        free(elt);

        li->size--;
        return TRUE;
    }

    return FALSE;

}

// ****************************************

pointer list_get_first(List li)
{
    CHECK_IF_LIST(li);

    if(list_size(li) > 0)
        return li->first->data;
    return NULL;
}

int list_get_first_to_int(List li)
{
    if(li->first)
        return * (int *) list_get_first(li);
}

char list_get_first_to_char(List li)
{
    if(li->first)
        return * (char *) list_get_first(li);
}

float list_get_first_to_float(List li)
{
    if(li->first)
        return * (float *) list_get_first(li);
}

double list_get_first_to_double(List li)
{
    if(li->first)
        return * (double *) list_get_first(li);
}

short list_get_first_to_short(List li)
{
    if(li->first)
        return * (short *) list_get_first(li);
}

char * list_get_first_to_string(List li)
{
    return (char *) list_get_first(li);
}

// ********************************************

BOOL list_insert(List li, pointer data, int index)
{
    CHECK_IF_LIST(li);

    if((index >= list_size(li)) && (index < 0))
        return FALSE;
    
    ListElement *tmp;
    ListElement *current = (ListElement *) malloc(sizeof(ListElement));
    if(!current)
        return FALSE;

    current->data = (pointer) malloc(li->size_of_elt);
    if(!current->data)
        return FALSE;

    // if everything is OK,  we can add the value in the list
    memcpy(current->data, data, li->size_of_elt);
    //current->next = NULL;

    if(index > 0) {
        tmp = li->first;
        for(int i=0; i<index-1; i++)
            tmp = tmp->next;
        
        current->next = tmp->next;
        tmp->next = current;
        
    } else {
        current->next = li->first;
        li->first = current;
    }
    li->size++;

    return TRUE;

}

pointer list_get(List li, int index)
{
    CHECK_IF_LIST(li);

    if((index >= 0) && (list_size(li) <= index))
        return NULL;
    
    ListElement *cur = li->first;
    for(int i=0; i<index; i++)
        cur = cur->next;
    
    return cur->data;
}

void list_prepend(List li, pointer data, size_t _size) {

    CHECK_IF_LIST(li);

    list_insert(li, data, 0);
}

// *********************************************

List list_concat(List _dest, List _src) {

    CHECK_IF_LIST(_dest);
    CHECK_IF_LIST(_src);

    ListElement * __dest, __src;
    
    __src = _src->first;

    if(_dest->first)
        __dest = _dest->first;

    return _dest;
}

// *********************************************

void list_foreach(List li, void (* func)(List li, pointer _elemt, int index, pointer data), pointer data) {

    CHECK_IF_LIST(li);

    ListElement *tmp = li->first;

    int i = 0;
    while(tmp) {
        func(li, tmp->data, i, data);
        tmp = tmp->next;
        i++;
    }
}

// *********************************************

void list_show(List li) {

    CHECK_IF_LIST(li);

    ListElement *elt;
    if(!list_empty(li) && li->callback) {
        elt = li->first;
        while (elt)
        {
            li->callback(elt->data);
            elt = elt->next; 
        }  
    }

}

void list_set_show_callback(List li, DstructCallbackFunc callback) {
    
    CHECK_IF_LIST(li);

    if(callback)
        li->callback = callback;
}

// ********************************************

void list_free(List li) {

    CHECK_IF_LIST(li);

    while (!list_empty(li))
        list_remove_first(li);
    
    free(li);
    
}

