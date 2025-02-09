#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>  // For tolower()
// using namespace std;

void toLowercase(std::vector<std::string> &words) {
    for (std::string &word : words) {        // Iterate over each word
        for (char &ch : word) {         // Iterate over each character in the word
            ch = tolower(ch);
        }
    }
}
void toLowercase(std::string& words){
    for (char &ch : words) {        // Iterate over each word
        // for (char &ch : word) {         // Iterate over each character in the word
            ch = tolower(ch);
        // }
    }
}

// int main() {
    // string input;
    // cout << "Enter words separated by spaces: ";
    // getline(cin, input);

    // vector<string> words; //A dynamic array of strings.
    // stringstream ss(input); //stringstream object ss, initialized with the string input. 
    //stringstream is used to break the input string into words.
    //extract words
    //ss acts like a buffer containing "hello world apple".
    // string word;//Declares a string variable named word to store individual words when extracting them from stringstream ss.

    //    while (ss >> word) {  // Split words by spaces
        //loop continues as long as there are words left in ss.
        // words.push_back(word);
    // }
    // toLowercase(words); 
    // cout << "Lowercase words: ";
    // for (const string &word : words) {
        // cout << word << " ";
    // }
    // cout << endl;

    // vector<string> testWords = {"hello", "world", "Apple", "banana"};

    // toLowercase(testWords);  // Convert all words to lowercase

    // cout << "Lowercase words: ";
    // for (const string &word : testWords) {
    //     cout << word << " ";
    // }
    // cout << endl;

    // return 0;
// }
