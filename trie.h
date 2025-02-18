#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>

class Trie {
public:
    Trie* child[26]; // Array to store children for each letter
    //Assuming 26 lowercase letters
    bool wordEnd=false;

    Trie(); // Constructor
    ~Trie();
    
    Trie* getNode(const std::string& word); // Function to get a node from Trie
    Trie* getChild(const int index); // Function to get a node from Trie
    void insertKey(std::string& key); // Insert a word into Trie
    bool searchKey(std::string& key); // Search for a word in Trie
};

#endif // TRIE_H
