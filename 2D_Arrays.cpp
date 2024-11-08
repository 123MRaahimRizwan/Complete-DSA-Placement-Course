#include <iostream>
#include <vector>
#include <climits>

using namespace std;


bool linearSearch(int mat[][3], int rows, int cols, int key) {
    cout << "========== Linear Search in a Matrix ==========" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                return true;
            }
        }
    }
    return false;
}

int diagonalSum(int mat[][3], int n) {
    cout << "========== Diagonal Sum of a Matrix ==========" << endl;
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += mat[i][i];

        if (i != n-i-1) {
            sum += mat[i][n-i-1];
        }
    }

    return sum;
}

void inputMatrix(int mat[][3], int rows, int cols) {
    cout << "========== Enter elements of Matrix ==========" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cin >> mat[i][j];
        }
    }
}

void outputMatrix(int mat[][3], int rows, int cols) {
    cout << "========== Elements of Matrix ==========" << endl;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int getMaxRowSum(int mat[][3], int rows, int cols) {
    cout << "========== Maximum Row Sum of a Matrix ==========" << endl;
    int maxRowSum = INT_MIN;
    for (int i=0; i<rows; i++) {
        int rowSum = 0;
        for (int j=0; j<cols; j++) {
            rowSum += mat[i][j];
        }
        maxRowSum = max(maxRowSum, rowSum);
    }
    return maxRowSum;
}

int getMaxColSum(int mat[][3], int rows, int cols) {
    cout << "========== Maximum Column Sum of a Matrix ==========" << endl;
    int maxColSum = INT_MIN;
    for (int i=0; i<rows; i++) {
        int colSum = 0;
        for (int j=0; j<cols; j++) {
            colSum += mat[j][i];
        }
        maxColSum = max(maxColSum, colSum);
    }
    return maxColSum;
}

int main() {

    int matrix[3][3];
    int rows = 3;
    int cols = 3;
    int n = 3;

    inputMatrix(matrix, rows, cols);
    outputMatrix(matrix, rows, cols);

    if (linearSearch(matrix, rows, cols, 5)) {
        cout << "Element found in the matrix " << endl;
    } else {
        cout << "Element not found in the matrix " << endl;
    }

    cout << "Maximum row sum: " << getMaxRowSum(matrix, rows, cols) << endl;
    cout << "Maximum column sum: " << getMaxColSum(matrix, rows, cols) << endl;

    cout << "Diagonal Sum: " << diagonalSum(matrix, n) << endl;

    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    return 0;
}