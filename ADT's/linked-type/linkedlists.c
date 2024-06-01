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
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;

} Linklist;


Linklist *create_list() {
    Linklist *l = (Linklist*)malloc(sizeof(Linklist));
    l->curr = l->tail = l->head = create_initial_link(NULL);

    l->cnt = 0;

    return l;
}


void insert(Linklist *l, int it) {
    l->curr->next = create_link(l->curr->next, it);

    if (l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    
    l->cnt++;
}


void remove(Linklist *l){
    if (l->curr->next == NULL) {
        return;
    }

    Link *remove_link = l->curr->next;

    int it = remove_link->data; // we can return this

    if (remove_link->next == NULL) {
        l->tail = l->curr;
    }
    
    l->curr->next = remove_link->next;
    free(remove_link);
}


void moveToStart(Linklist *l) {
    l->curr = l->head;
}


void moveToEnd(Linklist *l) {
    l->curr = l->tail;
}


void prev(Linklist *l) {
    if (l->head == NULL || l->curr == NULL) {
        return;
    }

    if (l->curr->next == l->head->next) {
        return;
    }
    
    Link *temp = l->head->next;

    while (temp->next != l->curr->next) {
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
    Link *temp = l->head->next;

    while (temp != NULL) {
        Link *next = temp->next;

        free(temp);
        temp = next;
    }

    l->curr = l->tail = l->head;
    l->cnt = 0;
}


int getValue(Linklist *l) {
    return l->curr->next->data;
}


void print_list(Linklist *list) {
    moveToStart(list);

    Link *temp = list->curr->next;

    while (temp != NULL) {
        printf("%d", temp->data);

        temp = temp->next;
    }   
}