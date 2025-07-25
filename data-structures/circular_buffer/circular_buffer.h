#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

void cb_init(uint8_t *buffer, size_t size);
bool cb_push(uint8_t byte);
bool cb_pop(uint8_t *byte);
bool cb_is_empty();
bool cb_is_full();


#endif

