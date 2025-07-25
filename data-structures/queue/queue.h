#ifndef QUEUE_H
#define QUEUE_H

typedef int Item;

// Linked list implemenation
typedef struct node{
    Item item;
    struct node* next;
} *Node;

typedef struct queue{
    Node first;
    Node last;
    int size;
} *Queue;


// Essentials
void enqueue(Queue q, Item val);
Item dequeue(Queue q);

// Optionals
Queue newQueue(void);
void destroyQueue(Queue);
int size(Queue);
Item first(Queue);
Item last(Queue);
void print(Queue);

#endif