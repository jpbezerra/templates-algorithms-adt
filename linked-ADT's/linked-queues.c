#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct link {
    int data;
    struct link *next;

} Link;

Link *createInitialLink(Link *nextval) {
    Link *node = (Link*)malloc(sizeof(Link));

    node->next = nextval;

    return node;
}

Link *createLink(Link *nextval, int it) {
    Link *node = (Link*)malloc(sizeof(Link));

    node->data = it;
    node->next = nextval;

    return node;
}

typedef struct {
    Link *front;
    Link *rear;
    int size;

} Queue;

Queue *createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = queue->rear = createInitialLink(NULL);
    queue->size = 0;

    return queue;
}

void enqueue(Queue *queue, int it) {
    queue->rear->next = createLink(NULL, it);
    queue->rear = queue->rear->next;
    queue->size++;
}

void dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("ERROR");
        return;
    }

    int it = queue->front->next->data; // we can return this

    Link *temp = queue->front->next;

    queue->front->next = temp->next;

    if (queue->front->next == NULL) {
        queue->rear = queue->front;
    }

    free(temp);
    queue->size--;
}

void clear(Queue *q) {
    Link *temp = q->front;

    while (temp != NULL) {
        Link *next = temp->next;
        free(temp);
        temp = next;
    }

    q->front = q->rear = createInitialLink(NULL);
    q->size = 0;
}

int frontValue(Queue *q) {
    if (q->size == 0) {
        printf("ERROR ");
        return 404;
    }

    return q->front->next->data;
}

int length(Queue *q) {
    return q->size;
}

void printQueue(Queue *queue) {
    Link *temp = queue->front->next;

    while (temp != NULL) {
        printf("%d ", temp->data);

        temp = temp->next;
    }

    printf("\n");
}
