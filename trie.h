#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>

class Trie {
public:
    Trie* child[26]; // Array to store children for each letter
    bool wordEnd;

    Trie(); // Constructor

    Trie* getNode(const std::string& word); // Function to get a node from Trie
    void insertKey(const std::string& key); // Insert a word into Trie
    bool searchKey(const std::string& key); // Search for a word in Trie
};

#endif // TRIE_H
