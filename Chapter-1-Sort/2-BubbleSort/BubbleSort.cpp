#include "BubbleSort.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;


void AssertNotAscendingOrder(int s[MAX], int n)
{
    bool res = true;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] > s[i+1]) {
            res = false;
            break;
        }
    }
    assert(!res && "Array Not Ascending Fail");
}
void AssertAscendingOrder(int s[MAX], int n)
{
    bool res = true;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] > s[i+1]) {
            res = false;
            break;
        }
    }
    assert(res && "Array Ascending Fail");
}
void AssertBubbleSort(int s[MAX], int n)
{
    AssertNotAscendingOrder(s, n);
    BubbleSort(s, 0, n);
    AssertAscendingOrder(s, n);
}


#define TEST_MAX 1024

int main(void)
{
    int s[MAX];

    for (int i = 0; i < TEST_MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            s[j] = rand() % TEST_MAX;
        }
        AssertBubbleSort(s, MAX);
    }

    return 0;
}
