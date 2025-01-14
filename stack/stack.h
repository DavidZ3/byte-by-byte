#ifndef STACK_H
#define STACK_H

typedef int Item;

// Linked list implemenation
typedef struct node{
    Item item;
    struct node* next;
} *Node;

typedef struct stack{
    Node node;
    int size;
} *Stack;


// Essentials
void push(Stack s, Item val);
Item pop(Stack s);

// Optionals
Stack newStack(void);
void destroyStack(Stack);
int size(Stack);
Item top(Stack);
void print(Stack);

#endif