#include <iostream>
#include <cstring>
using namespace std;

char* rewrite_word(char* str, const char* word, const char* sep_words, const char* new_word){
    int len_str = strlen(str);
    int len_word = strlen(word);
    int len_sep = strlen(sep_words);
    int len_new = strlen(new_word);
    

    char* temp = new char[1000];
    int len_temp = 0;

    for (int i = 0; i < len_str; i++) {
        bool is_word_start = (i == 0);
        for (int s = 0; s < len_sep; s++) {
            if (i > 0 && str[i - 1] == sep_words[s]) {
                is_word_start = true;
                break;
            }
        }

        bool is_word_end = (i + len_word == len_str);
        for (int s = 0; s < len_sep; s++) {
            if (i + len_word < len_str && str[i + len_word] == sep_words[s]) {
                is_word_end = true;
                break;
            }
        }

        bool is_input_word = true;
        for (int j = 0; j < len_word; j++) {
            if (str[i + j] != word[j]) {
                is_input_word = false;
                break;
            }
        }

        if (is_word_start && is_input_word && is_word_end) {
            for (int t = 0; t < len_new; t++)
            {
                temp[len_temp++] = new_word[t];
            }
            i += len_word - 1;//go to end of word
        }
        
        else {//write to temp from old
            temp[len_temp++] = str[i];
        }
        
    }
    temp[len_temp] = '\0'; // add zero terminator to temp


    //rewrite str have bugs when len_temp > len_str
    //temp[len_temp] = '\0';//add zero terminator to temp
    //len_temp++;
    ////rewrite str to temp
    //for (int i = 0; i < len_temp; i++)
    //{
    //    str[i] = temp[i];
    //}
    //str[len_temp] = '\0';//add zero terminator to str


    return temp;
}

int main() {
    char str[] = "Lorem ipsum dolor do sit amet !do ,hello consectetur adipiscing elit hello. Nam accumsan, hello, ex do dodo varius cursus egestas, lacus hello tellus convallis nisi, ut porttitor.";
    cout << "Old text: " << endl;
    cout << str << endl << endl;
    char sep_words[] = " .,!?;";
    char input_word[20];
    cout << "Enter word you want to rewrite: ";//hello- 4, do-3
    cin >> input_word;

    char new_word[20];
    cout << "Enter new word: ";//hello- 4, do-3
    cin >> new_word;

    char* new_str = rewrite_word(str, input_word, sep_words, new_word);

    cout << "\nNew text: " << endl;

    cout << new_str << endl;

    delete[] new_str;
    return 0;
}
