
#include <stdlib.h>
#include <string.h>
#include <dstruct_stack.h>


// ************************************

Stack stack_create() {

    Stack stack = (Stack) malloc(sizeof(Stack));

    if(stack == NULL)
        return NULL;
    
    stack->first = NULL;
    stack->size = 0;
    stack->callback = NULL;

    return stack;
}

// ************************************

BOOL stack_empty(Stack st) {
    
    CHECK_IF_STACK(st);
    
    return st == 0;
 
}

// ************************************

BOOL stack_push(Stack st, pointer data, size_t size_of_data) {
    
    CHECK_IF_STACK(st);

    StackElement *current = (StackElement *) malloc(sizeof(StackElement));
    if(current) {
        current->data = (pointer) malloc(size_of_data);
        if(current->data) {
            memcpy(current->data, data, size_of_data);
            current->next = st->first;
            st->first = current;
            st->size++;
            return TRUE;
        }
    }

    return FALSE;
}

BOOL stack_push_int(Stack st, int data) {
    return stack_push(st, &data, sizeof(int));
}

BOOL stack_push_char(Stack st, char data){
    return stack_push(st, &data, sizeof(char));
}

BOOL stack_push_float(Stack st, float data) {
    return stack_push(st, &data, sizeof(float));
}

BOOL stack_push_double(Stack st, double data) {
    return stack_push(st, &data, sizeof(double));
}

BOOL stack_push_short(Stack st, short data) {
    return stack_push(st, &data, sizeof(short));
}

// ************************************

BOOL stack_pop(Stack st) {

    CHECK_IF_STACK(st);

    StackElement *current = st->first;
    if(current) {
        st->first = current->next;
        if(current->data)
            free(current->data);
            
        free(current);
        st->size--;
        return TRUE;
    }

    return FALSE;
}

// ************************************

size_t stack_size(Stack st) {

    CHECK_IF_STACK(st);

    return st->size;
}

// ************************************

pointer stack_get_first(Stack st) {
    
    CHECK_IF_STACK(st);

    return st->first->data;
}

int stack_get_first_to_int(Stack st) {
    return * (int *) stack_get_first(st);
}

char stack_get_first_to_char(Stack st) {
    return * (char *) stack_get_first(st);
}

float stack_get_first_to_float(Stack st) {
    return * (float *) stack_get_first(st);
}

double stack_get_first_to_double(Stack st) {
    return * (double *) stack_get_first(st);
}

char * stack_get_first_to_string(Stack st) {
    return (char *) stack_get_first(st);
}

short stack_get_first_to_short(Stack st) {
    return * (short *) stack_get_first(st);
}

// ************************************

void stack_set_show_callback(Stack st, DstructCallbackFunc callback) {
    
    CHECK_IF_STACK(st);
    st->callback = callback;
}

// ************************************

void stack_show(Stack st) {

    CHECK_IF_STACK(st);
    while(stack_size(st) > 0) {
        st->callback(stack_get_first(st));
        stack_pop(st);
    }
}

// ************************************

void stack_free(Stack st) {

    CHECK_IF_STACK(st);

    while(stack_size(st) > 0)
        stack_pop(st);
    
    free(st);
}