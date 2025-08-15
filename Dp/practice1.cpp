#include <bits/stdc++.h>
using namespace std;

int findFirst(const vector<int>& arr, int target) {
    int l = 0, h = arr.size() - 1, first = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target) {
            first = mid;
            h = mid - 1;
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return first;
}

int findLast(const vector<int>& arr, int target) {
    int l = 0, h = arr.size() - 1, last = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target) {
            last = mid;
            l = mid + 1;  // ✅ Fix here
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstandLastOccurence(const vector<int>& arr, int target) {
    int first = findFirst(arr, target);
    if (first == -1) return {-1, -1};
    int last = findLast(arr, target);
    return {first, last};
}

int main() {
    vector<int> arr = {1, 1, 2, 4, 5, 6, 7, 8, 8, 8, 8, 8, 9, 10};
    int target = 8;

    pair<int, int> answer = firstandLastOccurence(arr, target);
    cout << "First: " << answer.first << ", Last: " << answer.second << endl;
    return 0;
}
