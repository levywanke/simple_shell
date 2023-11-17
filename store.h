#ifndef STORE_H
#define STORE_H

#include <stdlib.h>
void free_memory_pp(void **ptr);
void free_memory_p(void *ptr);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
#endif 
