#ifndef BIGINT_H
#define BIGINT_H
#include <corecrt_search.h>
#include <stdint.h>
#include <stdlib.h>
#define BIG_INT_DEFAULT_SIZE 20

// *****************************************************************************
// BigInt
// sign: is 0 if positive otherwise negative
// len: number of limbs currently utilised
// cap: current number of limbs allocated to this BigInt
// limbs: little endianess limbs. E.g. ui32 ABCD will be l[0] = A, l[1] = B, ...
// *****************************************************************************
typedef struct {
    uint8_t sign;
    size_t len;
    size_t cap;
    uint32_t* limbs;
} BigInt;

// *****************************************************************************
// Life Cycle
// *****************************************************************************
// Value is OPTIONAL; e.g. NULLABLE
void biInit(BigInt* bi, int32_t* const val);

// We only realloc limbs iff dst->cap < src->len. Otherwise we just copy.
// We DO NOT zero elements we just change len.
void biCopy(BigInt* src, BigInt* dst);

// Free with NULL bi is valid.
void biFree(BigInt* bi);

// *****************************************************************************
// Arithmetic
// *****************************************************************************
void biAdd(BigInt* d, const BigInt* m, const BigInt* n);
void biSub(BigInt* d, const BigInt* m, const BigInt* n);
void biMul(BigInt* d, const BigInt* m, const BigInt* n);
void biDiv(BigInt* d, BigInt* r, const BigInt* m, const BigInt* n); // q = m//n, r = m % n

#endif // BIGINT_H
