#include <bits/stdc++.h>
using namespace std;

// Use reference (&) to modify the vector in place!
void insert(stack<int>& p, int temp);

void sortStack(stack<int>& p) {
    if (p.size() <= 1) return;

    int temp = p.top();
    p.pop();

    sortStack(p);
    insert(p, temp);
}

void insert(stack<int>& p, int temp) {
    if (p.size() == 0 || p.top() > temp) {
        p.push(temp);
        return;
    }

    int val = p.top();
    p.pop();

    insert(p, temp);

    p.push(val);
}

int main() {
    stack<int> st;
   st.push(4);
   st.push(2);
   st.push(7);
   st.push(1);
   st.push(0);
    sortStack(st);

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
}
    cout << endl;
    system("pause");

    return 0;
}
