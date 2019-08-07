Elapsed time for code blocks execution written in C++11

This is a simple header-only library `elapsed.h` just import in your project and you are ready to do...

Here an example...
 
```C++
#include <random>
#include "elapsed.h"
#include "iostream"

using namespace std;

void Fibonacci()
{
    int t1 = 0, t2 = 1, nextTerm = 0, n;
    n = 10;
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";
    nextTerm = t1 + t2;
    while(nextTerm <= n)
    {
        cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}

int main()
{
    Elapsed elapsed;
    Fibonacci();
    return 0;
}
```

Basically when `Elapsed elapsed;` go out of scope it will automatically display the elapsed time in `std::cout`

The execution above will produce something like:

```
Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 
[ Elapsed time: : 	20 us ]
```
