
#ifndef __LIST_H__

    #define __LIST_H__

    // includes
    #include <dstruct_types.h>
    #include <dstruct_const.h>
    #include <dstruct_def.h>

    typedef struct _ListElement ListElement;
    struct _ListElement {
        pointer data;
        ListElement *next;
    };

    typedef struct _List *List;
    struct _List {

        ListElement *first;
        size_t size;
        DstructCallbackFunc callback;

    };

    // methods

    #define CHECK_IF_LIST(li) DSTRUCT_ASSERT(li != NULL, "List object should'nt NULL")

    #ifdef __cplusplus
        extern "C" {
    #endif

        /**
            @brief Create the list structure
            @return List if the list is successful created
            @return NULL if have some error
        */
        extern List list_create();

        /**
            @brief Check is the list is empty
            @param li Represent the list to check 
            @return TRUE if yes or FALSE if no
        */
        extern BOOL list_empty(List li);

        /**
         * @brief To add data int list
         * 
         * @param li - List in where we want to add data 
         * @param data - the data to add in list
         * @param size_of_data - the size of this data. Given by sizeof() function if you use your
         * custom structure or type
         * @return BOOL - TRUE if value is added and FALSE if else  
         */
        extern BOOL list_append(List li, pointer data, size_t size_of_data);

        /**
         * @brief To add int value in list
         * 
         * @param li 
         * @param data int value to add
         * @return BOOL 
         */
        extern BOOL list_append_int(List li, int data);

        /**
         * @brief To add char value in list
         * 
         * @param li 
         * @param data a char to add
         * @return BOOL 
         */
        extern BOOL list_append_char(List li, char data);

        /**
         * @brief Push value as float
         * 
         * @param li 
         * @param data 
         * @return BOOL 
         */
        extern BOOL list_append_float(List li, float data);

        /**
         * @brief add value as double
         * 
         * @param li 
         * @param data 
         * @return BOOL 
         */
        extern BOOL list_append_double(List li, double data);

        /**
         * @brief Function to remove the first value in the list
         * The removed value is not returned by the function 
         *
         * @param li 
         * @return BOOL TRUE if success and FALSE if failed
         */
        extern BOOL list_remove_first(List li);

        /**
         * @brief Get the size of the list
         * 
         * @param li 
         * @return size_t 
         */
        extern size_t list_size(List li);

        /**
         * @brief This function return the first value in the list as an object.
         * The object here is a memory allocated
         * 
         * @param li list in where we take the first value
         * @return pointer 
         * @return NULL if the list is empty
         */
        extern pointer list_get_first(List li);

        /**
         * @brief Get the first value in list as an integer
         * 
         * @param li 
         * @return int 
         */
        extern int list_get_first_to_int(List li);

        /**
         * @brief Get the first value in list as a char
         * 
         * @param li 
         * @return char 
         */
        extern char list_get_first_to_char(List li);

        /**
         * @brief Get the first value in list as a float
         * 
         * @param li 
         * @return float 
         */
        extern float list_get_first_to_float(List li);

        /**
         * @brief Get the first value in list as a double
         * 
         * @param li 
         * @return double 
         */
        extern double list_get_first_to_double(List li);

        /**
         * @brief Get the first value in list as a string
         * 
         * @param li 
         * @return char* 
         */
        extern char * list_get_first_to_string(List li);

        /**
         * @brief Get the first value in list as a short
         * 
         * @param li 
         * @return short 
         */
        extern short list_get_first_to_short(List li);

        /**
         * @brief Insert data at the specific index
         * 
         * @example list_insert(list, &data, sizeof(data), 0);
         * 
         * @param li List in where we gonna insert data
         * @param data data to insert
         * @param _size size of the data
         * @param index index to insert value
         * @return TRUE if value inserted with success
         * @return FALSE if failed 
         */
        extern BOOL list_insert(List li, pointer data, size_t _size, int index);

        /**
         * @brief Get data at the specific index
         * 
         * @param li List
         * @param index int
         * @return pointer if index is found
         * @return NULL if failed
         */
        extern pointer list_get(List li, int index);

        /**
         * @brief Insert data at the start of list
         * 
         * @param li List
         * @param data pointer
         * @param _size int
         */
        extern void list_prepend(List li, pointer data, size_t _size);

        extern void list_show(List li);

        extern void list_set_show_callback(List li, DstructCallbackFunc callback);

        /**
         * @brief Function to free memory allocated by a list
         * 
         * @param li a list to free in memory
         */
        extern void list_free(List li);


    #ifdef __cplusplus
        }
    #endif

#endif