#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
    Map<int, const char*> m;
    // m.Set(40,"ABBA");
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";
    // cout << endl;

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

   /* Map<int, int> r;
    r.Set(1, 23);
    r[23] = 900;
    r[0] = 20;
    r.Set(9, 25);
    r.Set(23, 75);
    for (auto [key, value, index] : r)
    {
        printf("Index:%d, Key=%d, Value=%d\n", index, key, value);
    }*/

    return 0;
}