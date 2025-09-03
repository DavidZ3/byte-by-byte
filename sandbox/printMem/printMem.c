#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>

typedef struct {
    int test; // 4
    char k; // 1
    char str[10]; // 10
    int* p; // 8
    short sh; // 2
} Thing;

int main(int argc, char* argv[])
{
    int i;
    Thing t = { 12, 'k', "testing", &i, 256 };
    printf("%zu\n", sizeof(t));
    unsigned char data;
    for (int i = 0; i < sizeof(t); ++i) {
        if (i % 4 == 0) {
            printf("\n");
        }
        data = *(((unsigned char*)&t) + i);
        printf("%02x ", data);
    }
    return 0;
}
