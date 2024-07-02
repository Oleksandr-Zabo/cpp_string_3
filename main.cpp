#include <iostream>
#include <cstring>
using namespace std;

char** num_letter_matrix(const char* str, int& num_letters) {
    int rows = 50;
    int cols = 2;
    char** matrix = new char* [rows]; // Initialize letter matrix
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new char[cols];
        matrix[i][0] = '\0'; // Initialize with null character
        matrix[i][1] = 0; // Initialize count to 0
    }

    int str_len = strlen(str);

    for (int i = 0; i < str_len; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            bool is_in_matrix = false;
            for (int j = 0; j < num_letters; j++) {
                if (str[i] == matrix[j][0]) {
                    matrix[j][1]++; // Increment count
                    is_in_matrix = true;
                    break;
                }
            }
            if (!is_in_matrix) {
                matrix[num_letters][0] = str[i];
                matrix[num_letters][1] = 1; // Initialize count to 1
                num_letters++;
            }
        }
    }

    return matrix;
}

template<typename T>
void printMatrix(T** arr, int row, int col = 2) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            if (j == 1) {
                cout << static_cast<int>(arr[i][j]) << " "; // Print count as integer
            }
            else {
                cout << arr[i][j] << "   ---   ";
            }
        }
        cout << endl;
    }
}

void delete_matrix(char** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    char str[] = "Lorem ipsum dolor do sit amet. do ,hello consectetur adipiscing elit hello. Nam accumsan, hello, ex do dodo varius cursus egestas, lacus hello tellus convallis nisi, ut porttitor!!!";
    cout << str << endl << endl;

    int row_matrix = 0;

    char** matrix = num_letter_matrix(str, row_matrix);

    printMatrix(matrix, row_matrix);

    delete_matrix(matrix, row_matrix);

    return 0;
}
