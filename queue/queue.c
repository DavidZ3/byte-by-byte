#include <stdio.h>
#include <malloc.h>
#include "queue.h"

Queue newQueue(){
    Queue q =  (Queue) malloc(sizeof(struct queue));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue q, Item item) {
    if(!q){
        return;
    }
    Node newNode = (Node) malloc(sizeof(struct node));

    newNode->next = NULL;
    newNode->item = item;

    if(q->last){
        q->last->next = newNode;
    }else{
        q->first = newNode;
    }
    q->last = newNode;
    q->size += 1;
}

Item dequeue(Queue q){
    if(!q || !q->last){
        return -1;
    }

    Item i = q->last->item;
    Node prevNode = q->first;
    Node currNode = q->first;
    while(currNode != q->last){
        prevNode = currNode;
        currNode = currNode->next;
    }

    q->size--;
    free(q->last);

    if(q->size){
        q->last = prevNode;
    }else{
        q->first = NULL;
        q->last = NULL;
    }

    return i;
}

void destroyQueue(Queue q){
    Node prevNode = q->first;
    Node currNode = q->first;
    while(currNode != NULL){
        prevNode = currNode;
        currNode = currNode->next;
        free(prevNode);
    }
    free(q);
}

int size(Queue q){
    return q->size;
}

Item first(Queue q){
    return q->first->item;
}

Item last(Queue q){
    return q->last->item;
}

void print(Queue q){
    Node n = q->first;
    printf("[");
    while(n != q->last){
        printf("%d, ", n->item);
        n = n->next;
    }
    if(n){
    printf("%d", n->item);
    }
    printf("]\n");
}
