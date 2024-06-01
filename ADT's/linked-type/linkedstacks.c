#include <stdio.h>
#include <stdlib.h>

typedef struct link{
    int data;
    struct link *next;

} Link;

Link *create_initial_link(Link *nextval) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->next = nextval;

    return n;
}

Link *create_link(Link *nextval, int it) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->data = it;
    n->next = nextval;

    return n;
}


typedef struct {
    Link *top;
    int size;

} Stack;

Stack *create_stack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = create_initial_link(NULL);
    s->size = 0;

    return s;
}

void push(Stack *s, int it) {
    s->top->next = create_link(s->top->next, it);
    s->size++;
}

void pop(Stack *s) {
    if (s->top->next == NULL) {
        return;
    }
    
    int it = s->top->data; // we can return this
    Link *temp = s->top;

    s->top = s->top->next;
    s->size--;

    free(temp);
}

int topValue(Stack *s) {
    return s->top->next->data;
}

int length(Stack *s) {
    return s->size;
}

void clear(Stack *s) {
    Link *temp = s->top->next;

    while (temp != NULL) {
        Link *next = temp->next;

        free(temp);
        temp = next;
    }
    
    s->top = NULL;
    s->size = 0;
}


void print_stack(Stack *s) {
    Link *temp = s->top->next;

    while (temp != NULL) {
        printf("%d", temp->data);

        temp = temp->next;
    }
}