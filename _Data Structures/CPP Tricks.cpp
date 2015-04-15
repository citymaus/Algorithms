
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