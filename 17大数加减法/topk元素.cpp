//
// Created by lhc456 on 2024/3/16.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int partition(vector<int> &arr, int l, int r) {
    int k = arr[l];
    while (l < r) {
        while (l < r && arr[r] >= k) {
            r--;
        }
        if (l < r) {
            arr[l++] = arr[r];
        }
        while (l < r && arr[l] < k) {
            l++;
        }
        if (l < r) {
            arr[r--] = arr[l];
        }
    }
    arr[l] = k;
    return l;
}

int selectTok(vector<int> &arr, int i, int j, int k) {
    int pos = partition(arr, i, j);
    if (pos == k - 1) {
        return arr[pos];
    } else if (pos < k - 1) {
        return selectTok(arr, pos + 1, j, k);
    } else {
        return selectTok(arr, i, pos - 1, k);
    }
}

// method1
int main() {
//    vector<int> vec;
//    for (int i = 0; i < 60000; i++) {
//        vec.push_back(rand() + i);
//    }
//    priority_queue<int, vector<int>, greater<int> > minHeap;
//    int k = 0;
//    for (; k < 10; k++) {
//        minHeap.push(vec[k]);
//    }
//    for (; k < vec.size(); k++) {
//        if (vec[k] > minHeap.top()) {
//            minHeap.pop();
//            minHeap.push(vec[k]);
//        }
//    }
//    while (!minHeap.empty()) {
//        cout << minHeap.top() << " ";
//        minHeap.pop();
//    }
//    cout << endl;
    vector<int> vec;
    for (int i = 0; i < 60000; i++) {
        vec.push_back(rand() + i);
    }
    cout << selectTok(vec, 0, vec.size() - 1, 10) << endl;

    return 0;
}
// 快排分割
