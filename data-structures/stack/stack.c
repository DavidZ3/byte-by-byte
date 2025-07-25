#include <stdio.h>
#include <malloc.h>
#include "stack.h"

Stack newStack(){
    Stack s =  (Stack) malloc(sizeof(struct stack));
    s->node = NULL;
    s->size = 0;
    return s;
}

void push(Stack s, Item item) {
    if(!s){
        return;
    }
    Node newNode = (Node) malloc(sizeof(struct node));

    newNode->next = s->node;
    newNode->item = item;

    s->node = newNode;
    s->size += 1;
}

Item pop(Stack s){
    if(!s || !(s->node)){
        return -1;
    }

    Item item = s->node->item;
    Node oldNode = s->node;
    s->node = oldNode->next;
    s->size -= 1;

    free(oldNode);
    return item;
}

void destroyStack(Stack s){
    Node n = s->node;
    free(s);

    while(n){
        Node oldNode = n;
        n = n->next;
        free(oldNode);
    }
}

int size(Stack s){
    return s->size;
}

Item top(Stack s){
    return s->node->item;
}

void print(Stack s){
    Node n = s->node;
    while(n){
        printf("%d ", n->item);
        n = n->next;
    }
}