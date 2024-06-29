#include <iostream>
#include <cstring>
using namespace std;

int num_sentence(const char* str, const char* sep_words) {
    int num_sentence = 0;

    int len_str = strlen(str);
    int len_sep = strlen(sep_words);
    bool in_sentence = false;

    for (int i = 0; i < len_str; i++) {
        bool is_separator = false;
        for (int j = 0; j < len_sep; j++) {
            if (str[i] == sep_words[j]) {
                is_separator = true;
                break;
            }
        }

        if (is_separator) {
            if (in_sentence) {
                num_sentence++;
                in_sentence = false;
            }
        }
        else {
            in_sentence = true;
        }
    }

    // If the last character is not a separator, count the last sentence
    if (in_sentence) {
        num_sentence++;
    }

    return num_sentence;
}

int main() {
    char str[] = "Lorem ipsum dolor do sit amet !do ,hello consectetur adipiscing !? elit hello. Nam accumsan, hello, ex do dodo varius cursus egestas, lacus hello tellus convallis nisi, ut porttitor!!!";
    cout << str << endl;
    char sep_words[] = ".!?";

    int num_sent = num_sentence(str, sep_words);

    cout << "Number of sentences in text: " << num_sent << endl;

    return 0;
}
