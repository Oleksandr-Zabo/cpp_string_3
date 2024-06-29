#include <iostream>
#include <cstring>
using namespace std;

int num_dotes(const char* str) {
    int num_dot = 0;

    int len_str = strlen(str);
    
    for (int i = 0; i < len_str; i++) {
        if (str[i] == '.') {
            num_dot++;
        }
    }
    return num_dot;
}

int num_comas(const char* str) {
    int num_coma = 0;

    int len_str = strlen(str);

    for (int i = 0; i < len_str; i++) {
        if (str[i] == ',') {
            num_coma++;
        }
    }
    return num_coma;
}

int main() {
    char str[] = "Lorem ipsum dolor do sit amet. do ,hello consectetur adipiscing elit hello. Nam accumsan, hello, ex do dodo varius cursus egestas, lacus hello tellus convallis nisi, ut porttitor!!!";
    cout << str << endl;

    int num_dot = num_dotes(str);
    int num_coma = num_comas(str);
    cout << "Number of dotes in text: " << num_dot << endl;
    cout << "Number of commas in text: " << num_coma << endl;

    return 0;
}
