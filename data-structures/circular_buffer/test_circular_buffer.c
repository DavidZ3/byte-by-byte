#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "circular_buffer.h"

#define BUF_SIZE 4

int main(void) {
    uint8_t buf[BUF_SIZE];
    uint8_t val;
    cb_init(buf, BUF_SIZE);

    // Buffer should be empty
    assert(cb_is_empty());
    assert(!cb_is_full());

    // Fill buffer
    assert(cb_push(1));
    assert(cb_push(2));
    assert(cb_push(3));
    assert(cb_push(4));
    assert(cb_is_full());
    assert(!cb_push(5)); // Should fail, buffer full

    // Pop all
    assert(cb_pop(&val) && val == 1);
    assert(cb_pop(&val) && val == 2);
    assert(cb_pop(&val) && val == 3);
    assert(cb_pop(&val) && val == 4);
    assert(cb_is_empty());
    assert(!cb_pop(&val)); // Should fail, buffer empty

    // Wraparound test
    assert(cb_push(10));
    assert(cb_push(20));
    assert(cb_pop(&val) && val == 10);
    assert(cb_push(30));
    assert(cb_push(40));
    assert(cb_push(50));
    assert(cb_is_full());
    assert(!cb_push(60));
    assert(cb_pop(&val) && val == 20);
    assert(cb_pop(&val) && val == 30);
    assert(cb_pop(&val) && val == 40);
    assert(cb_pop(&val) && val == 50);
    assert(cb_is_empty());

    printf("All circular buffer tests passed!\n");
    return 0;
} 