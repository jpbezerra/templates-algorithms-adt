#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Hash {
private:
    int capacity;
    int currSize;     
    string *HashTable;

    int SfoldKey(string arr) { // for strings
        int count = 0;

        for (int i = 0; i < arr.length(); i++) {
            count += arr[i] % 'A';
        }
        
        return count % capacity;
    }

public:
    Hash(int size) {
        capacity = size;
        currSize = 0;

        HashTable = (string*)malloc(size * sizeof(string));

        for (int i = 0; i < size; i++) {
            HashTable[i] = "-1";
        }
    }

    ~Hash() {
        free(HashTable);
        printf("HASH TABLE FUCKING DESTROYED\n");
    }


    void insert(string value) {
        int key = SfoldKey(value);
        int HashIndex = 0;
        int ProbeFactor = LinearProbing(HashIndex, key);

        while (HashTable[ProbeFactor] != "-1" && HashTable[ProbeFactor] != "-2") {
            if (HashIndex == capacity) {
                break;
            }
            
            HashIndex++;
            ProbeFactor = LinearProbing(key, HashIndex);
        }
        

        if (HashTable[ProbeFactor] == "-1" || HashTable[ProbeFactor] == "-2") {
            HashTable[ProbeFactor] = value;
            currSize++;

            printf("Value: %s, currsize: %d\n", HashTable[ProbeFactor].c_str(), currSize);

            printf("Success!\n");
            
        }
        
        else {
            printf("Element not inserted.\n");
        }
    }


    void deletion(string value) { // deletando baseado no valor, dá pra deletar com base na key
        for (int i = 0; i < capacity; i++) {
            if (HashTable[i] == value) {
                HashTable[i] = "-2";
                
                printf("Element %s deleted at key number %d\n", value.c_str(), i);
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


    string search(int key) {
        if (HashTable[key] == "-1") {
            printf("There are no elements that belongs to the key number %d\n", key);
            
            return "-1";
        }
        
        if (HashTable[key] != "-2") {
            printf("There is an element that belongs to the key number %d and it is at the right spot!!\n", key);

            return HashTable[key];
        }
        
        printf("There was an element that belongs to the key number %d, but it was deleted. Let's check if there are at least one more then.\n", key);

        for (int i = 0; i < capacity; i++) {
            if (HashTable[i] != "-1" && HashTable[i] != "-2") {
                string value = HashTable[i];
                int key_compare = SfoldKey(value);

                if (key == key_compare) {
                    printf("We've found the element %s that should've belong to the %d key\n", HashTable[i].c_str(), key_compare);
                    return HashTable[i];
                }
            }
        }
        
        printf("Unfortunately there are no numbers that belongs to the key number %d\n", key);
        
        return "-1";
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
            printf("Key: %d, Value: %s\n", i, HashTable[i].c_str());
        }
    }

    void clear() {
        for (int i = 0; i < capacity; i++) {
            HashTable[i] = "-1";
        }

        currSize = 0;
    }
};


int main() {
    int HashSize = 10;

    Hash dict(HashSize);

    dict.insert("Thawan");
    dict.search(1);
    dict.PrintTable();
    dict.deletion("Thawan");
    dict.search(1);
    dict.search(0);
    dict.deletion("Thawan");
    dict.deletion("Th");
    dict.PrintTable();
    dict.clear();
    dict.PrintTable();

    return 0;
}