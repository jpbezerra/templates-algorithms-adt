#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heapArr;
    vector<int> heapsortArr;
    int capacity;
    int currsize;

public:
    MinHeap(int size) {
        heapArr.resize(size + 1);
        heapsortArr.resize(size + 1);
        capacity = size;
        currsize = 0;

    };

    ~MinHeap() {
        heapArr.clear();
        capacity = currsize = 0;
    };

    int getCapacity() {
        return capacity;
    };

    int getCurrSize() {
        return currsize;
    };

    int leftChild(int idx) {
        return 2 * idx;
    };

    int rightChild(int idx) {
        return (2 * idx) + 1;
    };

    int parent(int idx) {
        return idx / 2;
    };

    void Heapify() {
        for (int i = (currsize / 2); i >= 1; i--) {
            int sup = i;
            int value = heapArr[i];
            bool heap = false;

            while (!heap && 2 * sup <= currsize) {
                int aux = 2 * sup;

                if (aux < currsize) {
                    if (heapArr[aux] >= heapArr[aux + 1]) {
                        aux++;
                    }   
                }

                if (value < heapArr[aux]) {
                    heap = true;
                }
                
                else {
                    heapArr[sup] = heapArr[aux];
                    sup = aux;
                }
            }

            heapArr[sup] = value;
        }
    };

    void TopDown() {
        int idx = currsize;
        int idx_parent = parent(idx);

        while (idx > 1 && heapArr[idx_parent] >= heapArr[idx]) {
            int sup = heapArr[idx_parent];
            int aux = heapArr[idx];

            heapArr[idx_parent] = aux;
            heapArr[idx] = sup;

            idx = idx_parent;
            idx_parent = parent(idx);
        } 
    };

    void printHeap() { // meu plano era printar como se fosse uma árvore
        for (int i = 1; i <= currsize; i++) {
            cout << heapArr[i] << " ";
        }

        cout << endl;
    };

    void add(int key) {
        if (currsize >= capacity) {
            cout << "Heap is full\n";
            return;
        }
        
        currsize++;
        heapArr[currsize] = key;

        TopDown();
    };

    int findMin() {
        if (currsize > 0) {
            return heapArr[1];            
        }
        
        cout << "Heap is empty\n";
        return 0; // valor simbólico
    };

    int removeMin() {
        if (currsize > 0) {
            int max = findMin();
            int change = heapArr[currsize];

            heapArr[1] = change;
            heapArr[currsize] = max;
            currsize--;

            Heapify();

            return max; 
        }
        
        cout << "There is no elements" << endl;
        return 0; // valor simbólico
    };

    void heapsort() {
        int temp = currsize;

        for (int i = 1; i <= temp; i++) {
            heapsortArr[i] = removeMin();    
        }

        currsize = temp;

        TopDown();
    };

    void printHeapSort() {
        for (int i = 1; i < currsize + 1; i++) {
            cout << heapsortArr[i] << " ";
        }
        
        cout << endl;
    }
};

int main() {
    MinHeap heap(6);

    heap.add(6);
    heap.add(8);
    heap.add(2);
    heap.add(4);
    heap.add(9);
    heap.add(3);
    heap.printHeap();
    heap.heapsort();
    heap.printHeapSort();

    return 0;
}
