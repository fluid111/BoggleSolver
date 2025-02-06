#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Trie.h"

// class Trie{
// public:
    Trie::Trie(){
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    // Function to get a node corresponding to a given prefix
    Trie* Trie::getNode(const std::string& word) {
        Trie* node = this;
        for (char c : word) {
            int index = c-'a'; // get index
            if (node->child[index] == nullptr) {
                return nullptr; // No such word
            }
            node = node->child[index];
        }
        return node;
    }

    void Trie::insertKey(const std::string& key) {
        // Initialize the curr pointer with the root node
        Trie* curr = this;

        // Iterate across the length of the string
        for (char c : key) {
            int index = c - 'a';

            // Check if the node exists for the 
            // current character in the Trie
            if (curr->child[index] == nullptr) {
            
                // If node for current character does 
                // not exist then make a new node
                Trie* newNode = new Trie();
            
                // Keep the reference for the newly
                // created node
                curr->child[index] = newNode;
            }
        
            // Move the curr pointer to the
            // newly created node
            curr = curr->child[index];
        }

        // Mark the end of the word
        curr->wordEnd = true;
}

// Method to search a key in the Trie
bool Trie::searchKey(const std::string& key) {
  
    // Initialize the curr pointer with the root node
    Trie* curr = this;

    // Iterate across the length of the string
    for (char c : key) {
      
        int index = c - 'a';
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->child[index] == nullptr){ 
            return false;
        }
        // Move the curr pointer to the 
        // already existing node for the 
        // current character
        curr = curr->child[index];
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
//     std::string word;
    
//     std::cout<<"Hellow world\n";
    
//     while (std::getline(file, word)) {
//         root.insertKey(word);  // Insert each word into the Trie
//     }

//     // Test the Trie with some words
//     std::vector<std::string> testWords = {"hello", "world", "Apple", "banana"};
    
//     for (const auto& word : testWords) {
//         if (root.searchKey(word)) {
//             std::cout << "Found: " << word << std::endl;
//         } else {
//             std::cout << "Not Found: " << word << std::endl;
//         }
//     }
    
//     std::cout<<"Hellow world\n";

//     return 0;
// }