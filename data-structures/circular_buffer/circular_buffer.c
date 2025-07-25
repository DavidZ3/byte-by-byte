#include "circular_buffer.h"
#define NEXT_IDX(x, size) ((x + 1) % size)

struct circular_buffer {
    uint8_t *buffer;
    size_t size;
    size_t read_idx;
    size_t write_idx;
    bool is_full;
};
struct circular_buffer cb;

void cb_init(uint8_t *buffer, size_t size){
    cb.buffer = buffer;
    cb.size = size;
    cb.read_idx = 0;
    cb.write_idx = 0;
    cb.is_full = false;
}

bool cb_push(uint8_t byte){
    if(cb.is_full){
        return false;
    }

    cb.buffer[cb.write_idx] = byte;
    cb.write_idx = NEXT_IDX(cb.write_idx, cb.size);

    if(cb.write_idx == cb.read_idx){
        cb.is_full = true;
    }
    return true;
}

bool cb_pop(uint8_t *byte){
    if(!cb.is_full && (cb.read_idx == cb.write_idx)){
        return false;
    }
    *byte = cb.buffer[cb.read_idx];
    cb.read_idx = NEXT_IDX(cb.read_idx, cb.size);
    cb.is_full = false;
    return true;
}

bool cb_is_empty(){
    return (!cb.is_full) && (cb.read_idx == cb.write_idx);
}

bool cb_is_full(){
    return cb.is_full;
}
