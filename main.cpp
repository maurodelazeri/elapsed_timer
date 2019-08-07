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