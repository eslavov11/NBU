#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

const int ROWS = 5, COLS = 7;

char path[ROWS * COLS];
int pathLength = 0;

char lab[ROWS][COLS] = {
        {' ', ' ', ' ', '*', ' ', ' ', ' '},
        {'*', '*', ' ', '*', ' ', '*', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', '*', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'e'},
};

void printPath() {
    cout << "Found path: ";

    for (int i = 1; i <= pathLength; ++i) {
        cout << path[i];
    }

    cout << endl;
}

void findPath(int row, int col, char direction) {
    if (row < 0 || col < 0 || row == ROWS || col == COLS) {
        return;
    }

    path[pathLength] = direction;
    pathLength++;

    if (lab[row][col] == 'e') {
        printPath();
        return;
    }

    if (lab[row][col] == ' ') {
        lab[row][col] = 's';

        findPath(row, col + 1, 'R');
        findPath(row, col - 1, 'L');
        findPath(row + 1, col, 'D');
        findPath(row - 1, col, 'U');

        lab[row][col] = ' ';
    }

    pathLength--;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    findPath(0, 0, 'S');

    return 0;
}