#include <stdio.h>
#include <stdlib.h>

typedef struct link{
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
    Link *head;
    Link *tail;
    Link *curr;
    int size;

} Linklist;

Linklist *createList() {
    Linklist *l = (Linklist*)malloc(sizeof(Linklist));
    l->curr = l->tail = l->head = createInitialLink(NULL);

    l->size = 0;

    return l;
}

void insert(Linklist *l, int it) {
    l->curr->next = createLink(l->curr->next, it);

    if (l->tail == l->curr) {
        l->tail = l->curr->next;
    }

    l->size++;

}

void remove(Linklist *l){
    if (l->curr->next == NULL) {
        return;
    }

    Link *remove_link = l->curr->next;

    int it = remove_link->data; // we can return this

    if (l->tail == remove_link) {
        l->tail = l->curr;
    }

    l->curr->next = remove_link->next;
    free(remove_link);
    l->size--;
}

void moveToStart(Linklist *l) {
    l->curr = l->head;
}

void moveToEnd(Linklist *l) {
    l->curr = l->tail;
}

void prev(Linklist *l) {
    if (l->curr == l->head) {
        return;
    }

    Link *temp = l->head;

    while (temp->next != l->curr) {
        temp = temp->next;
    }

    l->curr = temp;
}

void next(Linklist *l) {
    if (l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

void clear(Linklist *l) {
    Link *temp = l->head;

    while (temp != NULL) {
        Link *next = temp->next;

        free(temp);
        temp = next;
    }

    l->curr = l->tail = l->head = createInitialLink(NULL);
    l->size = 0;
}

int getValue(Linklist *l) {
    return l->curr->next->data;
}

int length(Linklist *l) {
    return l->size;
}

void printList(Linklist *list) {
    Link *temp = list->head;

    while (temp->next != NULL) {
        printf("%d ", temp->next->data);

        temp = temp->next;
    }

    printf("\n");
}
