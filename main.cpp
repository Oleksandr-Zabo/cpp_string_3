#include <iostream>
#include <cstring>
using namespace std;

int num_word_input(const char* str, const char* word, const char* sep_words) {
    int num_word = 0;

    int len_str = strlen(str);
    int len_word = strlen(word);
    int len_sep = strlen(sep_words);

    for (int i = 0; i < len_str; i++) {
        if (str[i] == word[0]) {//is still word or start new
            if (i != 0) {
                bool still_word = false;
                for (int s = 0; s < len_sep; s++) {
                    if (str[i - 1] == sep_words[s]) {
                        still_word = true;
                        break;
                    }
                }
                if (!still_word) {
                    continue;
                }
            }

            bool is_input_word = true;//is this word is our word or not
            for (int j = 0; j < len_word; j++) {
                if (str[i + j] != word[j]) {
                    is_input_word = false;
                    break;
                }
            }
            if (is_input_word) {
                bool still_word = false;//is still word or the end of word
                if (i + len_word < len_str) {
                    for (int s = 0; s < len_sep; s++) {
                        if (str[i + len_word] == sep_words[s]) {
                            still_word = true;
                            break;
                        }
                    }
                }
                else {
                    still_word = true;
                }

                if (still_word) {
                    num_word++;
                }
            }
        }
    }

    return num_word;
}

int main() {
    char str[] = "Lorem ipsum dolor do sit amet !do ,hello consectetur adipiscing elit hello. Nam accumsan, hello, ex do dodo varius cursus egestas, lacus hello tellus convallis nisi, ut porttitor.";
    cout << str << endl;
    char sep_words[] = " .,!?;";
    char input_word[20];
    cout << "Enter your word: ";//hello- 4, do-3
    cin >> input_word;

    int num_input_word = num_word_input(str, input_word, sep_words);

    cout << "Number of your word in text: " << num_input_word << endl;

    return 0;
}
