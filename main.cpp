#include <iostream>
#include <cstring>
using namespace std;

char* inverte_str(const char* str) {
    int len_str = strlen(str);
    char* str_new = new char[len_str + 1]; // Allocate memory for the new string

    for (int i = 0; i < len_str; i++) {
        str_new[i] = str[len_str - 1 - i]; // Copy characters in reverse order
    }
    str_new[len_str] = '\0'; // Null-terminate the new string

    return str_new;
}

int main() {
    char str[] = "Lorem ipsum dolor do sit";
    cout << "Old text:" << endl << str << endl;
    char* reversed_str = inverte_str(str);

    cout << "New text:" << endl << reversed_str << endl;

    delete[] reversed_str;
    return 0;
}
