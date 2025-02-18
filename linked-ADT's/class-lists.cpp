class Link {
    public:
        int value;
        Link* next;

        Link(Link* nxtval = nullptr, int data) {
            this->next = nxtval;
            this->value = data;
        }
};

class LinkedList {
    private:
        Link* head;
        Link* curr;
        Link* tail;
        int size;

    public:
        LinkedList() {
            this->head = this->curr = this->tail = nullptr;
            this->size = 0;
        }

        ~LinkedList() {
            this->clear();
        }

        void insert(int data) {
            this->curr->next = new Link(this->curr->next, data);

            if (this->tail == this->curr) {
                this->tail = this->curr->next;
            }

            this->size++;
        }

        void remove() {
            if (this->curr->next == nullptr) {
                return;
            }

            Link* temp = this->curr->next;
            int data = temp->value;

            if (this->tail == temp) {
                this->tail = this->curr;
            }

            this->curr->next = temp->next;

            delete temp;

            this->size--;
        }

        void moveToStart() {
            this->curr = this->head;
        }

        void moveToEnd() {
            this->curr = this->tail;
        }

        void prev() {
            if (this->curr == this->head) {
                return;
            }

            Link* temp = this->head;

            while (temp->next != this->curr) {
                temp = temp->next;
            }

            this->curr = temp;
        }

        void next() {
            if (this->curr != this->tail) {
                this->curr = this->curr->next;
            }
        }

        void clear() {
            Link* temp = this->head;

            while (temp != nullptr) {
                Link* next = temp->next;

                delete temp;

                temp = next;
            }

            this->curr = this->head = this->tail = nullptr;
            this->size = 0;
        }

        int getSize() {
            return this->size;
        }

        int getValue() {

            return this->curr->next->value;
        }
};