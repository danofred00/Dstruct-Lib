
#include <stdio.h>
#include <assert.h>
#include <dstruct.h>

void show(pointer data) { 
    printf("Data : %d \n", * (int *)data);
}

int main(void) {

    Stack stack = stack_create();

    stack_push(stack, "hello world", 12);
    stack_push_int(stack, 4);

    printf("First : %d \n", stack_get_first_to_int(stack));
    stack_pop(stack);

    printf("First : %s \n", stack_get_first_to_string(stack));

    stack_free(stack);

    return 0;
}