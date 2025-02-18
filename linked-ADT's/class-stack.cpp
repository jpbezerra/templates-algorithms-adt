#include <iostream>

class Link {
    public:
        int value;
        Link* next;
    
        Link(Link* nxtval, int data) {
            this->next = nxtval;
            this->value = data;
        }
    };
    
    class Stack {
    private:
        Link* top;
        int size;
    
    public:
        Stack() {
            this->top = nullptr;
            this->size = 0;
        }
    
        ~Stack() {
            this->clear();
        }
    
        void push(int data) {
            this->top = new Link(this->top, data);
            this->size++;
        }
    
        void pop() {
            if (this->top == nullptr) {
                return;
            }
    
            int data = this->top->value;
            Link* temp = this->top;
    
            this->top = this->top->next;
    
            delete temp;
    
            this->size--;
        }
    
        void clear() {
            while (this->top != nullptr) {
                this->pop();
            }
        }
    
        int topValue() {
            if (this->top == nullptr) {
                return INT_MAX;
            }
    
            return this->top->value;
        }
    
        int getSize() {
            return this->size;
        }
    };