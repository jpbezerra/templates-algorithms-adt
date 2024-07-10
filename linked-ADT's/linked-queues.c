#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int data;
    struct link *next;

} Link;

Link *create_initial_link(Link *nextval) {
    Link *node = (Link*)malloc(sizeof(Link));

    node->next = nextval;

    return node;
}

Link *create_more_links(Link *nextval, int it) {
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

Queue *create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = queue->rear = create_initial_link(NULL);
    queue->size = 0;

    return queue;
}

void enqueue(Queue *queue, int it) {
    queue->rear->next = create_more_links(NULL, it);
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

void print_queue(Queue *queue) {
    Link *temp = queue->front->next;

    while (temp != NULL) {
        if (temp->next != NULL) {
            printf("%d ", temp->data);
        }
        
        else {
            printf("%d\n", temp->data);
        }
        
        temp = temp->next;
    }
}

void clear(Queue *q) {
    Link *temp = q->front->next;

    while (temp != NULL) {
        Link *next = temp->next;
        free(temp);
        temp = next;
    }
    
    q->front = q->rear = create_initial_link(NULL);
    q->size = 0;
}

int frontValue(Queue *q) {
    return q->front->data;
}

int length(Queue *q) {
    return q->size;
}