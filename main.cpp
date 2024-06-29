#include <iostream>
#include <cstring>
using namespace std;

void reverse_string(char* str, int start, int end) {
    while (start < end) {//reverse char from start to end and from end to start
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}



void reverse_sentences(char* str, const char* sep_words) {
    int len_str = strlen(str);
    int len_sep = strlen(sep_words);
    int start = 0;

    for (int i = 0; i <= len_str; i++) {//i<= len_str if end with \0
        bool is_sep = false;
        for (int j = 0; j < len_sep; j++)
        {
            if (str[i] == sep_words[j] || str[i] == '\0') {
                is_sep = true;
                break;
            }  
        }
        if (is_sep) {
            reverse_string(str, start, i - 1);//i- separator
            start = i + 1;//after separator
        }
    }
}


int main() {
    char str[] = "Lorem ipsum dolor do sit. Hello world! One, two?";
    char sep[] = ".?!";
    cout << "Old text:" << endl << str << endl;

    reverse_sentences(str, sep);

    cout << "New text:" << endl << str << endl;
    return 0;
}
