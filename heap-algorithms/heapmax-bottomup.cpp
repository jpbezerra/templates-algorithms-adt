#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heapArr;
    vector<int> heapsortArr;
    int capacity;
    int currsize;

public:
    MaxHeap(int size) {
        heapArr.resize(size + 1);
        heapsortArr.resize(size + 1);
        capacity = size;
        currsize = 0;

        for (int i = 1; i < size + 1; i++) {
            heapArr[i] = i + 1; // example
            currsize++;
        }

        BottomUp();
    };

    ~MaxHeap() {
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

    void BottomUp() {
        for (int i = (currsize / 2); i >= 1; i--) {
            int sup = i;
            int value = heapArr[i];
            bool heap = false;

            while (!heap && 2 * sup <= currsize) {
                int aux = 2 * sup;

                if (aux < currsize) {
                    if (heapArr[aux] < heapArr[aux + 1]) {
                        aux++;
                    }   
                }

                if (value >= heapArr[aux]) {
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

    void printHeap() { 
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

        BottomUp();
    };

    int findMax() {
        if (currsize > 0) {
            return heapArr[1];            
        }
        
        cout << "Heap is empty\n";
        return 0; // valor simbólico
    };

    int removeMax() {
        if (currsize > 0) {
            int max = findMax();
            int change = heapArr[currsize];

            heapArr[1] = change;
            heapArr[currsize] = max;
            currsize--;

            BottomUp();

            return max; 
        }
        
        cout << "There is no elements" << endl;
        return 0; // valor simbólico
    };

    void heapsort() {
        int temp = currsize;

        for (int i = 1; i <= temp; i++) {
            heapsortArr[i] = removeMax();    
        }

        currsize = temp;

        BottomUp();
    };

    void printHeapSort() {
        for (int i = 1; i < currsize + 1; i++) {
            cout << heapsortArr[i] << " ";
        }
        
        cout << endl;
    }
};

int main() {
    MaxHeap heap(4);

    heap.printHeapSort();
    heap.printHeap();
    heap.heapsort();
    heap.printHeapSort();
    heap.removeMax(); 
    heap.add(7);
    heap.printHeap();
    heap.heapsort();
    heap.printHeapSort();

    return 0;
}
