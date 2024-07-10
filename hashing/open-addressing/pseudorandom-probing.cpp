#include <iostream>
#include <stdio.h>

using namespace std;

class Hash {
private:
    int capacity;
    int currSize;     
    int *HashTable;
    int *perm;

    int HashKey(int value) {
        return value % capacity;
    }

    int PseudoRandomProbing(int key, int value) {
        return (key + perm[value - 1]) % capacity;
    }

public:
    Hash(int size) {
        capacity = size;
        currSize = 0;

        HashTable = (int*)malloc(size * sizeof(int));
        perm = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            HashTable[i] = -1;
            perm[i] = i + 1; // example, probably we can get inputs here
        }
    }

    ~Hash() {
        free(HashTable);
        free(perm);
        printf("HASH TABLE FUCKING DESTROYED\n");
    }


    void insert(int value) {
        int key = HashKey(value);
        int HashIndex = 0;
        int ProbeFactor = PseudoRandomProbing(HashIndex, key);

        while (HashTable[ProbeFactor] != -1 && HashTable[ProbeFactor] != -2) {
            if (HashIndex == capacity) {
                break;
            }
            
            HashIndex++;
            ProbeFactor = PseudoRandomProbing(key, HashIndex);
        }
        

        if (HashTable[ProbeFactor] == -1 || HashTable[ProbeFactor] == -2) {
            HashTable[ProbeFactor] = value;
            currSize++;

            printf("Value: %d, currsize: %d\n", HashTable[ProbeFactor], currSize);

            printf("Success!\n");
            
        }
        
        else {
            printf("Element not inserted.\n");
        }
    }


    void deletion(int value) { // deletando baseado no valor, dá pra deletar com base na key
        for (int i = 0; i < capacity; i++) {
            if (HashTable[i] == value) {
                HashTable[i] = -2;
                
                printf("Element %d deleted at key number %d\n", value, i);
                currSize--;
                return;
            }
        }

        printf("Element not found!\n");

        /*

        fazendo baseada na key:

        if (HashTable[key] != NULL) {
            HashTable[key] = -2;

            printf("Element %d deleted at key number %d", value, i += 1);
            return;
        }

        printf("Element not found!");
        
        */
    }


    int search(int key) {
        if (HashTable[key] == -1) {
            printf("There are no elements that belongs to the key number %d\n", key);
            
            return -1;
        }
        
        if (HashTable[key] != -2) {
            printf("There is an element that belongs to the key number %d and it is at the right spot!!\n", key);

            return HashTable[key];
        }
        
        printf("There was an element that belongs to the key number %d, but it was deleted. Let's check if there are at least one more then.\n", key);

        for (int i = 0; i < capacity; i++) {
            if (HashTable[i] != -1 && HashTable[i] != -2) {
                int value = HashTable[i];
                int key_compare = HashKey(value);

                if (key == key_compare) {
                    printf("We've found the element %d that should've belong to the %d key\n", HashTable[i], key_compare);
                    return HashTable[i];
                }
            }
        }
        
        printf("Unfortunately there are no numbers that belongs to the number %d\n", key);
        
        return -1;
    }


    int size() {
        return capacity;
    }


    int current() {
        return currSize;
    }

    void PrintTable() {
        int cap = size();
        int curr = current();

        printf("Capacity: %d, Current size: %d\n", cap, curr);
        for (int i = 0; i < capacity; i++) {
            printf("Key: %d, Value: %d\n", i, HashTable[i]);
        }
    }

    void clear() {
        for (int i = 0; i < capacity; i++) {
            HashTable[i] = -1;
        }

        currSize = 0;
    }
};


int main() {
    int HashSize = 10;

    Hash dict(HashSize);

    dict.insert(21);
    dict.search(1);
    dict.PrintTable();
    dict.insert(11);
    dict.PrintTable();
    dict.deletion(21);
    dict.search(1);
    dict.search(0);
    dict.deletion(10);
    dict.deletion(11);
    dict.search(1);
    dict.PrintTable();
    dict.clear();
    dict.PrintTable();

    return 0;
}