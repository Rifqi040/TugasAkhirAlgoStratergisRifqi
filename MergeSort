#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; i++;
        } else {
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    cout << "========================" << endl;
    cout << "Muhammad Rifqi Aminulloh" << endl;
    cout << "23533806" << endl;
    cout << "4A" << endl;
    cout << "MergeSort" << endl;
    cout << "========================" << endl;

    int nim[8];
    cout << "Masukkan NIM Anda (8 digit, pisahkan spasi): ";
    for (int i = 0; i < 8; i++) {
        cin >> nim[i];
        if (nim[i] == 0) nim[i] = 11;
    }

    mergeSort(nim, 0, 7);

    cout << "\nHasil Merge Sort: ";
    for (int i = 0; i < 8; i++)
        cout << nim[i] << " ";
    cout << endl;

    return 0;
}
