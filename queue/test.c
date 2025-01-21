#include <stdio.h>
#include "queue.h"

int main(){
    Queue q = newQueue();
    printf("Queueing 1\n");
    enqueue(q, 1);
    printf("Calling print: ");
    print(q);

    printf("\nQueueing 2\n");
    enqueue(q, 2);
    printf("Calling print: ");
    print(q);

    printf("\nQueueing 3\n");
    enqueue(q, 3);
    printf("Calling print: ");
    print(q);

    printf("\nQueueing 4\n");
    enqueue(q, 4);
    printf("Calling print: ");
    print(q);

    Item i = first(q);
    printf("\nFirst: %d\n", i);

    i = last(q);
    printf("\nLast: %d\n", i);

    i = dequeue(q);
    int sz = size(q);
    printf("\nDequeued: %d\n", i);
    printf("Size: %d\n", sz);
    printf("Calling print: ");
    print(q);


    i = dequeue(q);
    sz = size(q);
    printf("\nDequeued: %d\n", i);
    printf("Size: %d\n", sz);
    printf("Calling print: ");
    print(q);

    i = dequeue(q);
    sz = size(q);
    printf("\nDequeued: %d\n", i);
    printf("Size: %d\n", sz);
    printf("Calling print: ");
    print(q);

    i = dequeue(q);
    sz = size(q);
    printf("\nDequeued: %d\n", i);
    printf("Size: %d\n", sz);
    printf("Calling print: ");
    print(q);

    destroyQueue(q);

    return 0;
}