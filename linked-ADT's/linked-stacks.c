#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int data;
    struct link *next;

} Link;

Link *createInitialLink(Link *nextval) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->next = nextval;

    return n;
}

Link *createLink(Link *nextval, int it) {
    Link *n = (Link*)malloc(sizeof(Link));
    n->data = it;
    n->next = nextval;

    return n;
}

typedef struct {
    Link *top;
    int size;

} Stack;

Stack *createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;

    return s;
}

void push(Stack *s, int it) {
    s->top = createLink(s->top, it);
    s->size++;
}

void pop(Stack *s) {
    if (s->top == NULL) {
        return;
    }

    int it = s->top->data; // we can return this
    Link *temp = s->top;

    s->top = s->top->next;
    s->size--;

    free(temp);
}

int topValue(Stack *s) {
    if (s->top == NULL) {
        printf("ERROR ");
        return 404;
    }

    return s->top->data;
}

int length(Stack *s) {
    return s->size;
}

void clear(Stack *s) {
    Link *temp = s->top;

    while (temp != NULL) {
        Link *next = temp->next;

        free(temp);
        temp = next;
    }

    s->top = NULL;
    s->size = 0;
}

void printStack(Stack *s) {
    Link *temp = s->top;

    while (temp != NULL) {
        printf("%d ", temp->data);

        temp = temp->next;
    }

    printf("\n");
}
