#include <iostream>
using namespace std;

const int TABLE_SIZE = 907;
int hashTable[TABLE_SIZE];
bool isOccupied[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
        isOccupied[i] = false;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int HashInsertion(int key) {
    int hashIndex = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int probeIndex = (hashIndex + i) % TABLE_SIZE;
        if (!isOccupied[probeIndex]) {
            hashTable[probeIndex] = key;
            isOccupied[probeIndex] = true;
            cout << "Inserted " << key << " at index " << probeIndex << endl;
            return probeIndex;
        }
    }
    cout << "Error: Hash table is full!" << endl;
    return -1;
}

int HashDeletion(int key) {
    int hashIndex = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int probeIndex = (hashIndex + i) % TABLE_SIZE;
        if (isOccupied[probeIndex] && hashTable[probeIndex] == key) {
            hashTable[probeIndex] = -1;
            isOccupied[probeIndex] = false;
            cout << "Deleted " << key << " from index " << probeIndex << endl;
            return probeIndex;
        }
    }
    cout << "Error: Key " << key << " not found!" << endl;
    return -1;
}

void displayTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (isOccupied[i])
            cout << "Index " << i << ": " << hashTable[i] << endl;
        else
            cout << "Index " << i << ": [EMPTY]" << endl;
    }
}

int main() {
    initializeTable();
    HashInsertion(1234);
    HashInsertion(5678);
    HashInsertion(999);
    displayTable();

    HashDeletion(5678);
    HashDeletion(4321);
    displayTable();

    return 0;
}