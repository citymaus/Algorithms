/*
  Hash Table (Open Addressing)
    http://www.cprogramming.com/tutorial/computersciencetheory/hash-table.html
    http://www.algolist.net/Data_structures/Hash_table/Open_addressing
    
    Handle collisions with:
    - Array (open addressing), will resize when bucket is full
    - Linked list (chaining)
        
*/

class HashEntry {
private:
      int key;
      int value;
public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }
 
      int getKey() {
            return key;
      }
 
      int getValue() {
            return value;
      }
 
      void setValue(int value) {
            this->value = value;
      }
};

class DeletedEntry: public HashEntry {
private:
      static DeletedEntry *entry;
      DeletedEntry() :
            HashEntry(-1, -1) {
      }
public:
      static DeletedEntry *getUniqueDeletedEntry() {
            if (entry == NULL)
                  entry = new DeletedEntry();
            return entry;
      }
};
 
DeletedEntry *DeletedEntry::entry = NULL;

const int TABLE_SIZE = 128;
 
class HashMap {
private:
      float threshold;
      int maxSize;
      int tableSize;
      int size;
      HashEntry **table;
      
      void resize() {
            int oldTableSize = tableSize;
            tableSize *= 2;
            maxSize = (int) (tableSize * threshold);
            LinkedHashEntry **oldTable = table;
            table = new LinkedHashEntry*[tableSize];
            for (int i = 0; i < tableSize; i++)
                  table[i] = NULL;
            size = 0;
            for (int hash = 0; hash < oldTableSize; hash++)
                  if (oldTable[hash] != NULL) {
                        LinkedHashEntry *oldEntry;
                        LinkedHashEntry *entry = oldTable[hash];
                        while (entry != NULL) {
                             put(entry->getKey(), entry->getValue());
                             oldEntry = entry;
                             entry = entry->getNext();
                             delete oldEntry;
                        }
                  }
            delete[] oldTable;
      }
      
public:
      HashMap() {
            threshold = 0.75f;
            maxSize = 96;
            tableSize = DEFAULT_TABLE_SIZE;
            size = 0;
            table = new LinkedHashEntry*[tableSize];
            for (int i = 0; i < tableSize; i++)
                  table[i] = NULL;
      }
 
      void setThreshold(float threshold) {
            this->threshold = threshold;
            maxSize = (int) (tableSize * threshold);
      }
 
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            int initialHash = -1;
            while (hash != initialHash && (table[hash]
                        == DeletedEntry::getUniqueDeletedEntry() || table[hash] != NULL
                        && table[hash]->getKey() != key)) {
                  if (initialHash == -1)
                        initialHash = hash;
                  hash = (hash + 1) % TABLE_SIZE;
            }
            if (table[hash] == NULL || hash == initialHash)
                  return -1;
            else
                  return table[hash]->getValue();
      }
 
      void put(int key, int value) {
            int hash = (key % tableSize);
            if (table[hash] == NULL) {
                  table[hash] = new LinkedHashEntry(key, value);
                  size++;
            } else {
                  LinkedHashEntry *entry = table[hash];
                  while (entry->getNext() != NULL)
                        entry = entry->getNext();
                  if (entry->getKey() == key)
                        entry->setValue(value);
                  else {
                        entry->setNext(new LinkedHashEntry(key, value));
                        size++;
                  }
            }
            if (size >= maxSize)
                  resize();
      }
 
      void remove(int key) {
            int hash = (key % tableSize);
            if (table[hash] != NULL) {
                  LinkedHashEntry *prevEntry = NULL;
                  LinkedHashEntry *entry = table[hash];
                  while (entry->getNext() != NULL && entry->getKey() != key) {
                        prevEntry = entry;
                        entry = entry->getNext();
                  }
                  if (entry->getKey() == key) {
                        if (prevEntry == NULL) {
                             LinkedHashEntry *nextEntry = entry->getNext();
                             delete entry;
                             table[hash] = nextEntry;
                        } else {
                             LinkedHashEntry *next = entry->getNext();
                             delete entry;
                             prevEntry->setNext(next);
                        }
                        size--;
                  }
            }
      }
 
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL && table[i]
                             != DeletedEntry::getUniqueDeletedEntry())
                        delete table[i];
            delete[] table;
      }
};

