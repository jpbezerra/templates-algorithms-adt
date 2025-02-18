class Link {
    public:
        int value;
        Link* next;
    
        Link(Link* nxtval, int data) {
            this->next = nxtval;
            this->value = data;
        }
    };
    
    class Queue {
    private:
        Link* front;
        Link* rear;
        int size;
    
    public:
        Queue() {
            this->front = this->rear = new Link(nullptr, -1);
            this->size = 0;
        }
    
        ~Queue() {
            this->clear();
            delete this->front;
        };
    
        void enqueue(int data) {
            this->rear->next = new Link(nullptr, data);
            this->rear = this->rear->next;
            this->size++;
        }
    
        void dequeue() {
            if (this->size == 0) {
                return;
            }
    
            Link* temp = this->front->next;
            this->front->next = temp->next;
    
            if (this->front->next == nullptr) {
                this->rear = this->front;
            }
    
            delete temp;
            this->size--;
        }
    
        void clear() {
            Link* temp = this->front;
    
            while (temp != nullptr) {
                Link* next = temp->next;
    
                delete temp;
    
                temp = next;
            }
    
            this->front = this->rear = nullptr;
            this->size = 0;
        }
    
        int frontValue() {
            return this->front->next->value;
        }
    
        int getSize() {
            return this->size;
        }
    };