#include <bits/stdc++.h>
using namespace std;

// Use reference (&) to modify the vector in place!
void insert(vector<int>& p, int temp);

void sortVector(vector<int>& p) {
    if (p.size() <= 1) return;

    int temp = p[p.size() - 1];
    p.pop_back();

    sortVector(p);
    insert(p, temp);
}

void insert(vector<int>& p, int temp) {
    if (p.size() == 0 || p[p.size() - 1] < temp) {
        p.push_back(temp);
        return;
    }

    int val = p[p.size() - 1];
    p.pop_back();

    insert(p, temp);

    p.push_back(val);
}

int main() {
    vector<int> p = {2, 7, 4, 1, 5, 8};

    sortVector(p);

    for (int i : p) {
        cout << i << " ";
    }
    cout << endl;
    system("pause");

    return 0;
}
