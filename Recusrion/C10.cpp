//Set Matrix Zeroes

#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<int>> &matrix)
{
    int m = matrix.size(); //no of cols
    int n = matrix[0].size();// no of rows
    bool zerorow = false;
    bool zerocol = false;

    //check if any zero at row or col
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) zerorow = true;
    }

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) zerocol = true;
    }
    //now traverse and if any zero get then make that row and col =0 so that in next loop 
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // now you mark that row and col where 0 exist in matrix now check if row or col of that element is 0 then make that element 0
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0||matrix[0][j]==0)
            {
                matrix[i][j] = 0;
              
            }
        }
    }
    //now make row and col
    if(zerocol){
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }
    if(zerorow){
        for(int i=0;i<n;i++){
            matrix[0][i]=0;
        }
    }
}

int main()
{
  vector<vector<int>> res = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

  change(res);

for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
  


    return 0;
}