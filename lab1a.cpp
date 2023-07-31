#include <iostream>
using namespace std;
int main()
{

    int n, temp, no_of_comparisons, no_of_swaps;
    bool flag;
    cout << "enter the size of array n: " << endl;
    cin >> n;
    cout<<"array "<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
     flag=false;
        
        for (int j = 0; j < n - i - 1; j++)
        {
           
            no_of_comparisons++;
            if (arr[j] > arr[j + 1])
            {   
                temp=arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                no_of_swaps++;

                flag=true;
            }
            
             
        }
         if (flag=false)
        {
            break;
        }
       
        
    }
    cout << "sorted array :" << endl;
    for (int i = 0; i<n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "no_of_comparisons: " << no_of_comparisons << endl;
    cout << "no of swaps: " << no_of_swaps << endl;
    return 0;
}