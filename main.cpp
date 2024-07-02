#include <iostream>
#include <cstring>
using namespace std;

char* up_first_el(const char* str, const char* sep) {
    int len_str = strlen(str);
    int len_sep = strlen(sep);

    char* str_new = new char[len_str + 1]; // Allocate memory for the new string
    bool capitalize_next = true; // Flag to capitalize the next character
    bool after_symbol = false; // Flag to check if the character is after a number

    for (int i = 0; i < len_str; i++) {
        if (capitalize_next && !after_symbol && (str[i] >= 'a' && str[i] <= 'z')) {
            str_new[i] = str[i] - 32; // Convert to uppercase
            capitalize_next = false;
        }
        else {
            str_new[i] = str[i];
        }

        // Check if the current character is a separator
        for (int j = 0; j < len_sep; j++) {
            if (str[i] == sep[j]) {
                capitalize_next = true;
                after_symbol = false;
                break;
            }
        }

        // Check if the current character is a number
        if (str[i] != ' ' || (int(str[i]) < 97 && int(str[i]) > 122)) {
            after_symbol = true;
        }

        // Skip spaces 
        if (capitalize_next) {
            while (i + 1 < len_str && str[i + 1] == ' ') {
                str_new[++i] = str[i];
            }
        }
    }

    str_new[len_str] = '\0'; // Null-terminate the new string

    return str_new;
}

int main() {
    char str[] = "  1 lorem ipsum.fdjc ! K    jhyh  ?1 hf. jon";
    char sep[] = ".!?";
    cout << "Old text:" << endl << str << endl;
    char* new_str = up_first_el(str, sep);

    cout << "New text:" << endl << new_str << endl;

    delete[] new_str;
    return 0;
}
