
// Difference between -> and .
//  foo->bar() is the same as (*foo).bar()
//  Dot operator (.) cannot be overloaded.

// Passing int by reference.
void foo(int &y)
{
  y++;
}
main()
{
  int x = 4;
  cout << x; // 4
  foo(x);
  cout << x; // 5
}

// Passing array by reference.
void foo(int arr[])
{
}
main()
{
  int arr[5];
}

int       *       p;  // pointer
int const *       p;  // pointer to const value
int       * const p;  // const pointer
int const * const p;  // const pointer to const value

// Defining a struct
struct product {
  int weight;
  double price;
  struct product *next; // pointer to another struct of this type
} apple, banana, melon;
/* apple.weight = 0;
apple.price = 1;
banana.weight
banana.price */


// Public, Protected, Private
public:       Everything that is aware of Base is also aware that Base contains publicMember.
protected:    Only the children (and their children) are aware that Base contains protectedMember.
private:      No one but Base is aware of privateMember.

// CPP Inheritance, abstract / virtual
class Vehicle {
 public:
     explicit
     Vehicle( int topSpeed )
     : m_topSpeed( topSpeed )
     {}
     int TopSpeed() const {
        return m_topSpeed;
     }
 
     virtual void Save( std::ostream& ) const = 0;
 
 private:
     int m_topSpeed;
 };
 
 class WheeledLandVehicle : public Vehicle {
 public:
     WheeledLandVehicle( int topSpeed, int numberOfWheels )
     : Vehicle( topSpeed ), m_numberOfWheels( numberOfWheels )
     {}
     int NumberOfWheels() const {
       return m_numberOfWheels;
     }
 
     void Save( std::ostream& ) const; // is implicitly virtual
 
 private:
     int m_numberOfWheels;
 };