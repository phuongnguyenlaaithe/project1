#include <bits/stdc++.h> 
using namespace std;


bool check(int x[9][9], int r, int c, int v) {
    // check hàng và cột
    for (int i = 0; i < 9; i++) {
        if (x[r][i] == v || x[i][c] == v) {
            return false;
        }
    }

    // check ô 3x3
    int I = r - r % 3;
    int J = c - c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x[i + I][j + J] == v) {
                return false;
            }
        }
    }

    return true;
}

int countSudokuSolutions(int x[9][9]) {
    int r, c;

    // Tìm ô trống
    bool isEmpty = false;
    for (r = 0; r < 9; r++) {
        for (c = 0; c < 9; c++) {
            if (x[r][c] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // nếu k còn ô, sudoku đã được giải
    if (!isEmpty) {
        return 1;
    }

    int count = 0;

    for (int v = 1; v <= 9; v++) {
        if (check(x, r, c, v)) {
            x[r][c] = v;

            // đệ quy
            count += countSudokuSolutions(x);

            //backtrack
            x[r][c] = 0;
        }
    }

    return count;
}

int main() {
    int x[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> x[i][j];
        }
    }

    int solutions = countSudokuSolutions(x);

    cout << solutions << endl;

    return 0;
}
