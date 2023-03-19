
#ifndef __STACK_H__

    #define __STACK_H__

    // includes
    #include <dstruct/dstruct_types.h>
    #include <dstruct/dstruct_const.h>
    #include <dstruct/dstruct_def.h>

    typedef struct _StackElement StackElement;
    struct _StackElement{
        pointer data;
        StackElement *next;
    };

    typedef struct _Stack *Stack;
    struct _Stack {

        StackElement *first;
        size_t size;
        DstructCallbackFunc callback;

    };

    // methods

    #define CHECK_IF_STACK(st) DSTRUCT_ASSERT(st != NULL, "Stack object should'nt NULL")

    #ifdef __cplusplus
        extern "C" {
    #endif

        /**
            @brief Create the stack structure
            @return Stack if the stack is successful created
            @return NULL if have some error
        */
        extern Stack stack_create();

        /**
            @brief Check is the stack is empty
            @param st - Represent the stack to check 
            @return TRUE if yes or FALSE if no
        */
        extern BOOL stack_empty(Stack st);

        /**
         * @brief To push data int stack
         * 
         * @param st - Stack in where we want to push data 
         * @param data - the data to push in stack
         * @param size_of_data - the size of this data. Given by sizeof() function if you use your
         * custom structure or type
         * @return BOOL - TRUE if value is pushed and FALSE if else  
         */
        extern BOOL stack_push(Stack st, pointer data, size_t size_of_data);

        /**
         * @brief To push int value in stack
         * 
         * @param st 
         * @param data - int value to push
         * @return BOOL 
         */
        extern BOOL stack_push_int(Stack st, int data);

        /**
         * @brief To push char value in stack
         * 
         * @param st 
         * @param data - a char to push
         * @return BOOL 
         */
        extern BOOL stack_push_char(Stack st, char data);

        /**
         * @brief Push value as float
         * 
         * @param st 
         * @param data 
         * @return BOOL 
         */
        extern BOOL stack_push_float(Stack st, float data);

        /**
         * @brief push value as double
         * 
         * @param st 
         * @param data 
         * @return BOOL 
         */
        extern BOOL stack_push_double(Stack st, double data);

        /**
         * @brief Function to pop value in the stack
         * The poped value is not returned by the function 
         *
         * @param st 
         * @return BOOL - TRUE if success and FALSE if failed
         */
        extern BOOL stack_pop(Stack st);

        /**
         * @brief Get the size of the stack
         * 
         * @param st 
         * @return size_t 
         */
        extern size_t stack_size(Stack st);

        /**
         * @brief This function return the first value in the stack as an object.
         * The object here is a memory allocated
         * 
         * @param st - stack in where we take the first value
         * @return pointer 
         * @return NULL if the stack is empty
         */
        extern pointer stack_get_first(Stack st);

        /**
         * @brief Get the first value in stack as an integer
         * 
         * @param st 
         * @return int 
         */
        extern int stack_get_first_to_int(Stack st);

        /**
         * @brief Get the first value in stack as a char
         * 
         * @param st 
         * @return char 
         */
        extern char stack_get_first_to_char(Stack st);

        /**
         * @brief Get the first value in stack as a float
         * 
         * @param st 
         * @return float 
         */
        extern float stack_get_first_to_float(Stack st);

        /**
         * @brief Get the first value in stack as a double
         * 
         * @param st 
         * @return double 
         */
        extern double stack_get_first_to_double(Stack st);

        /**
         * @brief Get the first value in stack as a string
         * 
         * @param st 
         * @return char* 
         */
        extern char * stack_get_first_to_string(Stack st);

        /**
         * @brief Get the first value in stack as a short
         * 
         * @param st 
         * @return short 
         */
        extern short stack_get_first_to_short(Stack st);

        extern void stack_show(Stack st);

        extern void stack_set_show_callback(Stack st, DstructCallbackFunc callback);

        /**
         * @brief Function to free memory allocated by a stack
         * 
         * @param st - a stack to free in memory
         */
        extern void stack_free(Stack st);

    #ifdef __cplusplus
        }
    #endif

#endif
