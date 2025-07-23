# Spec
Write a simple circular buffer (ring buffer) for bytes (uint8_t) in C. Your implementation should support the following functions:

void cb_init(uint8_t *buffer, size_t size);
bool cb_push(uint8_t byte);
bool cb_pop(uint8_t *byte);
bool cb_is_empty();
bool cb_is_full();

    cb_push() should return false if the buffer is full.

    cb_pop() should return false if the buffer is empty.

    The buffer is fixed-size and should not dynamically allocate memo
