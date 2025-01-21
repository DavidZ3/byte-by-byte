#include <stdio.h>
#include "stack.h"

int main(){
    Stack s = newStack();

    printf("Pushing 1\n");
    push(s, 1);
    printf("Calling print: ");
    print(s);

    printf("\nPushing 2\n");
    push(s, 2);
    printf("Calling print: ");
    print(s);

    printf("\nPushing 3\n");
    push(s, 3);
    printf("Calling print: ");
    print(s);

    printf("\nPushing 4\n");
    push(s, 4);
    printf("Calling print: ");
    print(s);

    Item i = top(s);
    printf("\nTop: %d\n", i);


    i = pop(s);
    int sz = size(s);
    printf("Popped: %d\n", i);
    printf("Size: %d\n", sz);


    i = pop(s);
    sz = size(s);
    printf("Popped: %d\n", i);
    printf("Size: %d\n", sz);

    i = pop(s);
    sz = size(s);
    printf("Popped: %d\n", i);
    printf("Size: %d\n", sz);

    i = pop(s);
    sz = size(s);
    printf("Popped: %d\n", i);
    printf("Size: %d\n", sz);



    destroyStack(s);
    return 0;
}
