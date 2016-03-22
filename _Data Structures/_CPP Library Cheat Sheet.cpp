

//Common includes
#include <iostream>
#include <fstream>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

//--------------------------------------------------------------------------------------
//    HEADERS
//
// From http://www.cplusplus.com/reference/
//--------------------------------------------------------------------------------------
/* <cstdio>    (stdio.h)     C library to perform Input/Output operations (header) 
/* <iostream>    ()     C library to perform Input/Output operations (header) */
  printf;
  cout;
    cout << "enter age:\n";
  cin;
    cin >> age;
  FILE *fopen (const char *filename, const char *mode);
  int fclose (FILE *stream);
  scanf(const char *format, ... );
    char str [80];
    printf ("Enter your family name: ");
    scanf ("%79s",str); 
  NULL;

/* <cstdlib> */
  malloc(size_t size);

/* <cstring>   (string.h)    C Strings (header) */
  memset(ptr obj, int value, sizeof(obj));      /* <------------------------------ */
  size_t strlen(const char *str);
    char szInput[256];
    strlen(szInput);
  char *strcpy (char *destination, const char *source);
    char str1[]="Sample string";
    char str2[40];
    char str3[40];
    strcpy (str2,str1);
    strcpy (str3,"copy successful");
    printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
    // str1: Sample string
    // str2: Sample string
    // str3: copy successful
  char *strcat (char *destination, const char *source);
  int strcmp (const char *str1, const char *str2 ) = 0 if strings are equal;
  char *strchr (char *str, int character) = index of first occurence of character, or NULL if not found;
  char *strstr (char *str1, const char *str2) = index of first occurrence of str2 in str1, or NULL if not found;
  char *strtok (char *str, const char *delimiters);
    char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");
    while (pch != NULL)
    {
      printf ("%s\n",pch);
      pch = strtok (NULL, " ,.-");
    }
    /* On strtok first call, the function expects a C string as argument for str, 
       whose first character is used as the starting location to scan for tokens. 
       In subsequent calls, the function expects a null pointer and uses the 
       position right after the end of the last token as the new starting 
       location for scanning. */
  NULL;

/* <cmath>     (math.h)      C numerics library (header) */
  double exp(double x) = e^x;
  double log(double x) = log base e(x);
  double log10(double x) = log base 10(x);
  double pow(double base, double exp) = base^exponent;
  double sqrt(double x) = square root of x;
  double ceil(double x) = round up;
  double floor(double x) = round down;
  double abs(double x) = absolute value of x, |x|;
  INFINITY = math constant;
  NAN = not a number;

/* <algorithm>     ()      C algorithm library (header) */
  double max(double x, double y);
  double min(double x, double y);

/* <climits>   (limits.h)    Sizes of integral types (header) */
  INT_MAX || UINT_MAX || LONG_MAX || ULONG_MAX || ULLONG_MAX;
  INT_MIN, etc.;

/* <cctype>    (ctype.h)     Character handling functions (header) */
  int isupper(char c) = 1 if uppercase;
  int islower(char c) = 1 if lowercase;
  int toupper(char c) = uppercase version of char;
  int tolower(char c) = lowercase version of char;
  int isdigit(char c) = 1 if digit[0-9];
  int iscntrl(char c) = 1 if \n, \t, etc.;
  int isprint(char c) = 1 if character is printable;

/* <ctime>     (time.h)      C Time Library (header) */
  time_t time (time_t* timer);
  double difftime (time_t end, time_t beginning);
    time_t now;
    struct tm newyear;
    double seconds;
    time(&now);  /* get current time; same as: now = time(NULL)  */
    newyear = *localtime(&now);
    newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
    newyear.tm_mon = 0;  newyear.tm_mday = 1;
    seconds = difftime(now,mktime(&newyear));

/* 
LESS COMMON: 
  <cstdbool>  (stdbool.h)   Boolean type (header)
  <cstdint>   (stdint.h)    Integer types (header)
    int16_t, etc.
  <cfenv>     (fenv.h)      Floating-point environment (header)
  <cfloat>    (float.h)     Characteristics of floating-point types (header)
  <cinttypes> (inttypes.h)  C integer types (header)

  <cstdarg>   (stdarg.h)    Variable arguments handling (header)
  <cstddef>   (stddef.h)    C Standard definitions (header)
  <cstdlib>   (stdlib.h)    C Standard General Utilities Library (header)

  <cassert>   (assert.h)    C Diagnostics Library (header)
  <cerrno>    (errno.h)     C Errors (header)
  <ciso646>   (iso646.h)    ISO 646 Alternative operator spellings (header)
  <clocale>   (locale.h)    C localization library (header)
  <csetjmp>   (setjmp.h)    Non local jumps (header)
  <csignal>   (signal.h)    C library to handle signals (header)
  <ctgmath>   (tgmath.h)    Type-generic math (header)
  <cuchar>    (uchar.h)     Unicode characters (header)
  <cwchar>    (wchar.h)     Wide characters (header)
  <cwctype>   (wctype.h)    Wide character type (header)
*/


//--------------------------------------------------------------------------------------
//    CONTAINERS
//
// From http://www.cplusplus.com/reference/
//--------------------------------------------------------------------------------------
#include <set>            // Set stores only unique vars, in order, 
  std::set<int> myset;    // implemented as binary search trees
  myset.insert(20);
  myset.insert(30);
  myset.insert(10);
  std::cout << "myset contains:";
  while (!myset.empty())
  {
     std::cout << ' ' << *myset.begin();
     myset.erase(myset.begin());
  }
  std::cout << '\n';
  /*
  OUTPUT
    myset contains: 10 20 30
  */

#include <list>           // (Linked) List header
  std::list<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << " front:" << myints.front() << '\n';
  myints.insert (myints.begin(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';
  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
  myints.clear();
  std::cout << "4. isempty:" << myints.empty() << '\n';
  /* 
  OUTPUT:
    0. size: 0
    1. size: 10 front:0
    2. size: 20
    3. size: 19
    4. isempty:true
  */

#include <vector>         // Vector header
  // dynamic arrays, might need resizing, fast to access, but can be slow to insert
  std::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';
  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';
  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
  /*
  OUTPUT:
    0. size: 0
    1. size: 10
    2. size: 20
    3. size: 19
  */

#include <queue>          // Queue header: FIFO queue, priority queue
  empty() 
  size()
  push(int x)  (back)
  pop()        (front)
  front()
  back()  
    std::queue<int> myqueue;
    int sum (0);
    for (int i=1;i<=10;i++) myqueue.push(i);
    while (!myqueue.empty())
    {
       sum += myqueue.front();
       myqueue.pop();
    }
    cout << "total: " << sum << '\n';
    /*
    OUTPUT:
      total: 55
    */
  //std::priority_queue, sorts with highest on "top", or the back
  empty()
  size()
  front()
  push_back()
  pop_back()

    std::priority_queue<int> mypq;
    mypq.push(30);
    mypq.push(100);
    mypq.push(25);
    mypq.push(40);
    std::cout << "Popping out elements...";
    while (!mypq.empty())
    {
       std::cout << ' ' << mypq.top();
       mypq.pop();
    }
    /*
    OUTPUT:
      Popping out elements... 100 40 30 25
    */

#include <stack>            // LIFO stack, can be implemented as vector, list or deque, 
  std::stack<int> mystack;  // double-ended-queue (deque) is default
  for (int i=0; i<5; ++i) mystack.push(i);
  std::cout << "Popping out " << mystack.size() << " elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
  /*
  OUTPUT:
    Popping out 5 elements... 4 3 2 1 0
  */

#include <map>            // (Hash?) Map header, typically binary search tree
  std::map<char, int> mymap;
  mymap['a']=10;
  mymap['b']=20;
  mymap.insert(std::pair<char,int>('z',200));
  mymap['c']=30; // inserts in sorted order
  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  /*
  OUTPUT:
    a => 10
    b => 20
    c => 30
    z => 200
  */


#include <bitset>         // Bitset header
#include <array>          // Array header
#include <deque>          // Deque header
#include <forward_list>   // Forward list
#include <unordered_map>  // Unordered map header
#include <unordered_set>  // Unordered set header