/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

void kthRank(vector<int> arr, int k, int &answer, int lower, int upper) {
    vector<int> arr_(arr.size(), 0);
    int holder = arr[lower];
    
    int start = lower;
    int end = upper;
    for (int i = lower + 1; i <= upper; i++) {
        if (arr[i] < holder) {
            arr_[start] = arr[i];
            start++;
        }
        else {
            arr_[end] = arr[i];
            end--;
        }
    }
    arr_[start] = holder;
    if (start > k) {
        upper = start - 1;
    }
    else if (start < k) {
        lower = start + 1;
    }
    else {
        answer = arr_[start];
        return;
    }
    kthRank(arr_, k, answer, lower, upper);
}

int main()
{
    vector<int> arr{3, 11, 2, 13, 8, 12, 6, 14, 15};
    int answer = 0;
    kthRank(arr, 0, answer, 0, arr.size() - 1);
    cout << answer << endl;

    return 0;
}
