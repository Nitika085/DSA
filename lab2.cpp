#include <iostream>
using namespace std;

int bubble_sort(int A[], int n)
{
    int temp;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;

        for (int j = 0; j < n - i - 1; j++)
        {

            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;

                flag = true;
            }
        }
        if (flag = false)
        {
            break;
        }
    }
}
