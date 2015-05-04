/*
  An animal shelter holds only dogs and cats, and operates on a strictly "first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals
at the shelter, or they can select whether they would prefer a dog or a cat (and will
receive the oldest animal of that type). They cannot select which specific animal they
would like. Create the data structures to maintain this system and implement operations
such as enqueue, dequeueAny, dequeueDog and dequeueCat. You may
use the built-in LinkedList data structure.
*/

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

class Animal {
  private:
    int order;

  protected:
    string aname;
    string type;
    typedef Animal super; // note that it could be hidden in
                          // protected/private section, instead

  public:
    Animal() {}
    Animal(string n) {
      aname = n;
    }

    void setOrder(int ord, string t) {
      order = ord;
      type = t;
    }

    int getOrder() {
      return order;
    }

    bool isOlderThan(Animal a) {
      return (getOrder() < a.getOrder());
    }

    bool isDog()
    {
      return (strcmp(type.c_str(), "dog") == 0);
    }
}

class AnimalQueue 
{
  stack<Dog> dogs;
  stack<Cat> cats;

  private:
    int order; // acts as timestamp

  public:
    AnimalQueue() : order(0) {}

    void enqueue(Animal a) {
      /* Order is used as a sort of timestamp, so that we can
      * compare the insertion order of a dog to a cat. */
      a.setOrder(order, a.isDog() ? "dog" : "cat");
      order++;

      if (a.isDog()) 
        dogs.push((Dog) a);
      else if (!a.isDog()) 
        cats.push((Cat) a);
    }

    Animal dequeueAny() 
    {
      /* Look at tops of dog and cat queues, and pop the stack
      * with the oldest value. */
      if (dogs.size() == 0) {
        return dequeueCats();
      } else if (cats.size() == 0) {
        return dequeueDogs();
      }

      Dog dog = dogs.top();
      Cat cat = cats.top();

      if (dog.isOlderThan(cat)) {
        return dequeueDogs();
      } else {
        return dequeueCats();
      }
    }

  Dog dequeueDogs() {
    Dog d = dogs.top();
    dogs.pop();
    return d;
  }

  Cat dequeueCats() {
    Cat c = cats.top();
    cats.pop();
    return c;
  }
}

class Dog : public Animal {
  public:
    Dog(string n) {
      super(n);
    }
}

class Cat : public Animal {
  public:
    Cat(string n) {
      super(n);
    }
}