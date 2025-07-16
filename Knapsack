#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack01(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                               K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    cout << "========================" << endl;
    cout << "Muhammad Rifqi Aminulloh" << endl;
    cout << "23533806" << endl;
    cout << "4A" << endl;
    cout << "Knapsack" << endl;
    cout << "========================" << endl;

    int nim[8];
    cout << "Masukkan NIM Anda (8 digit, pisahkan spasi): ";
    for (int i = 0; i < 8; i++) {
        cin >> nim[i];
        if (nim[i] == 0) nim[i] = 11;
    }

    int profit[8];
    cout << "\nMasukkan profit untuk setiap objek knapsack (8 profit):\n";
    for (int i = 0; i < 8; i++) {
        cin >> profit[i];
    }

    int capacity;
    cout << "Masukkan kapasitas knapsack: ";
    cin >> capacity;

    int maxProfit = knapsack01(capacity, nim, profit, 8);
    cout << "Total Knapsack 0-1 profit maksimum: " << maxProfit << endl;

    return 0;
}
