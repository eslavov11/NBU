#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n]();
    }

    int count = 1, i = 0, j = 0;
    while (count < n * n) {
        while (j < n - 1 && (arr[i][j + 1] == 0 || count == n * n)) {
            arr[i][j] = count++;
            j++;
        }

        while (i < n - 1 && (arr[i + 1][j] == 0 || count == n * n)) {
            arr[i][j] = count++;
            i++;
        }

        while (j > 0 && (arr[i][j - 1] == 0 || count == n * n)) {
            arr[i][j] = count++;
            j--;
        }

        while (i > 0 && (arr[i - 1][j] == 0 || count == n * n)) {
            arr[i][j] = count++;
            i--;
        }
    }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            cout << arr[row][col] << (arr[row][col] < 10 ? "   " : (arr[row][col] < 100 ? "  " : " "));
        }

        cout << endl;
    }
}
