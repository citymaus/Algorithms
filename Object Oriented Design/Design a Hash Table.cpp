/*
  Design and implement a hash table which uses chaining (linked lists) to handle collisions.
*/

#include <list>

template <class K_Type, class V_Type> class Hash
{
  private:
    const int MAX_BUCKETS = 10;           /* ideally a prime number to reduce collisions */
    const int MAX_LIST_LENGTH = 10;
    list<Cell<K_Type, V_Type>> items[MAX_BUCKETS];

  public:
    Hash() 
    {
      for (int i = 0; i < MAX_BUCKETS; i++)
      {
        items[i] = NULL;
      }
    }

    /* Really, really stupid hash. */
    int hashCodeOfKey(K_Type key) 
    {
      return key.toString().length() % MAX_SIZE;
      //return key.toString().length() % items.length;
    }

    void put(K_Type key, V_Type value) 
    {
      int x = hashCodedOfKey(key);
      if (items[x] == NULL) 
      {
        list<Cell<K_Type, V_Type>> newlist;
        items[x] = newlist;
      }

      //LinkedList<Cell<K_Type, V_Type>> collided = items[x];
      list<Cell<K_Type, V_Type>> collided = items[x];


      /* Look for items with same key and replace if found */
      for (list<Cell<K_Type, V_Type>>::iterator listit = collided.begin(); listit != collided.end(); listit++)
      {
        Cell<K_Type, V_Type>> temp(listit->getKey(), listit->getValue());
        if (listit->equivalent(key))
        {
          collided.remove((Cell<K_Type, V_Type) listit);
          break;
        }
      }

      //Cell<K_Type, V_Type> cell = new Cell<K_Type, V_Type>(key, value);
      Cell<K_Type, V_Type> cell(key, value);
      //collided.add(cell);
      collided.push_back(cell);
    }

    V_Type get(K_Type key) 
    {
      int x = hashCodeOfKey(key);
      if (items[x] == NULL) 
      {
        return null;
      }

      list<Cell<K, V>> collided = items [x];
      for (Cell<KJ V> c : collided) 
      {
        if (c.equivalent(key)) 
        {
          return c.getValue();
        }
      }

      return null;
    }
};

template <class K_Type, class V_Type> class Cell
{
  private:
    K_Type key;
    V_Type value;

  public:
    Cell(K_Type k, V_Type v) 
    {
      key = k;
      value = v;
    }

    bool equivalent(Cell<K_Type, V_Type> c) 
    {
      return equivalent(c.getKey());
    }

    bool equivalent(K_Type k) 
    {
      return key.equals(k);
    }

    K_Type getKey() { return key; }
    V_Type getValue() { return value; }
};