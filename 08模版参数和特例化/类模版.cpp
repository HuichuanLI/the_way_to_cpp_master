//
// Created by lhc456 on 2024/3/2.
//

#include <iostream>

template<typename T, int SIZE>
void sort(T *arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {12, 5, 7, 89, 32, 21, 35};
    const int size = sizeof(arr) / sizeof(arr[0]);
    sort<int, size>(arr);
    for (int val: arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}