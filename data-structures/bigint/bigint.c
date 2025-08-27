#include "bigint.h"

void biInit(BigInt* bi, int32_t* const val)
{
    bi->cap = BIG_INT_DEFAULT_SIZE;
    bi->len = 0;
    bi->sign = 0;
    bi->limbs = (uint32_t*)malloc(sizeof(uint32_t) * BIG_INT_DEFAULT_SIZE);
    if (!val)
        return;

    bi->sign = (*val >= 0) ? 0 : 1;
    bi->limbs[0] = *val;
    bi->len = 1;
}

void biCopy(BigInt* src, BigInt* dst)
{
    if (!src)
        return;

    dst->sign = src->sign;
    dst->len = src->len;
    if (src->limbs == NULL) {
        dst->cap = src->cap;
        dst->limbs = NULL;
    } else if (dst->cap < src->len) {
        if (dst->limbs)
            free(dst->limbs);
        dst->limbs = (uint32_t*)malloc(sizeof(uint32_t) * src->cap);
        dst->cap = src->cap;
        for (int i = 0; i < src->len; ++i) {
            dst->limbs[i] = src->limbs[i];
        }
    } else {
        dst->cap = src->cap;
        for (int i = 0; i < src->len; ++i) {
            dst->limbs[i] = src->limbs[i];
        }
    }
}

void biFree(BigInt* bi)
{
    if (!bi)
        return;

    if (bi->limbs)
        free(bi->limbs);

    free(bi);
}

void biAdd(BigInt* d, const BigInt* m, const BigInt* n) { }
void biSub(BigInt* d, const BigInt* m, const BigInt* n) { };
void biMul(BigInt* d, const BigInt* m, const BigInt* n) { };
void biDiv(BigInt* d, BigInt* r, const BigInt* m, const BigInt* n) { }; // q = m//n, r = m % n
