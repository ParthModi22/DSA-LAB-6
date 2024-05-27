#include <iostream>
using namespace std;

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; ++i) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    const int num_buckets = 10;
    float buckets[num_buckets][n];
    
    // Initialize bucket sizes to 0
    int bucket_sizes[num_buckets] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucket_index = arr[i] * num_buckets;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < num_buckets; ++i) {
        insertionSort(buckets[i], bucket_sizes[i]);
    }

    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < num_buckets; ++i) {
        for (int j = 0; j < bucket_sizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[]={0.13,0.45,0.12,0.89,0.75,0.63,0.85,0.39};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout <<endl;

    bucketSort(arr, n);

    cout << "Sorted array:" <<endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout <<endl;

    return 0;
}
