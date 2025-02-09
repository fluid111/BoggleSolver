#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


#include "support.h"
#include "trie.h"

    Trie::Trie(){
        wordEnd = false;
        // std::fill(std::begin(child), std::end(child), nullptr);
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    Trie::~Trie()
    {
        for (int i = 0; i < 26; ++i) delete child[i];
    }

    Trie* Trie::getChild(const int index) {
        if (child[index] == nullptr) {
            child[index] = new Trie();
        }
        return child[index];
    }
    // Function to get a node corresponding to a given prefix
    Trie* Trie::getNode(const std::string& word) {
        Trie* node = this;
        for (char c : word) {
            int index = c-'a'; // get index
            node = node->getChild(index);
            if (node == nullptr) {
                return nullptr; // No such word
            }
        }
        return node;
    }

    

    void Trie::insertKey(std::string& key) {
      toLowercase(key);
        // Initialize the curr pointer with the root node
        Trie* curr = this;

        // Iterate across the length of the string
        for (char c : key) {
            int index = c - 'a';

            curr = curr->getChild(index);
        }

        // Mark the end of the word
        curr->wordEnd = true;
}

// Method to search a key in the Trie
bool Trie::searchKey(std::string& key) {
    toLowercase(key);
    // Initialize the curr pointer with the root node
    Trie* curr = this;

    // Iterate across the length of the string
    for (char c : key) {
      
        int index = c - 'a';
        // Check if the node exists for the 
        // current character in the Trie
        curr = curr->getChild(index);
        if (curr == nullptr){ 
            return false;
        }
    }

    // Return true if the word exists 
    // and is marked as ending
    return curr->wordEnd;
}
// };
// int main() {
//     Trie root;

//     // Load dictionary from a file
//     std::ifstream file("dictionary.txt");
//     std::vector<std::string> dictionary;
//     std::string words;
    
//     std::cout<<"Hellow world start\n";
    
//     std::cout << "Total words inserted: " << dictionary.size() << std::endl;

//     while (std::getline(file, words)) {
//       if (!words.empty()) {  // Ignore empty lines
//          dictionary.push_back(words);
//          root.insertKey(words);
//      }
      //   dictionary.push_back(words);
      //   root.insertKey(words);  // Insert each word into the Trie
//     }

//     // Test the Trie with some words
//     // std::vector<std::string> testWords = {"hello", "world", "Apple", "banana"};
    
//     for (auto& word : dictionary) {
//         if (root.searchKey(word)) {
//             std::cout << "Found: " << word << std::endl;
//         } else {
//             std::cout << "Not Found: " << word << std::endl;
//         }
//     }
    
//     std::cout<<"Hellow world end\n";

//     return 0;
// }