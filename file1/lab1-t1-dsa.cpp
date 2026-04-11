#include <iostream>
#include <string>
using namespace std;

template <typename T, int N>
void printArray(T (&arr)[N]) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T, int N>
void selectionSort(T (&arr)[N]) {
    for (int i = 0; i < N - 1; i++) {
        int SmallSub = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[SmallSub])
                SmallSub = j;
        }
        T temp = arr[i];
        arr[i] = arr[SmallSub];
        arr[SmallSub] = temp;
    }
}

int main() {
    int intArray[5] = {64, 25, 12, 22, 11};
    cout << "Original integer array: ";
    printArray(intArray);
    selectionSort(intArray);
    cout << "Sorted integer array: ";
    printArray(intArray);

    string stringArray[4] = {"apple", "orange", "banana", "grape"};
    cout << "\nOriginal string array: ";
    printArray(stringArray);
    selectionSort(stringArray);
    cout << "Sorted string array: ";
    printArray(stringArray);

    return 0;
}