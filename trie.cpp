#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode
{
    public:
    unordered_map<char, TrieNode*>children;
    bool isEnd;
    TrieNode() : isEnd(false) {}
};

class Trie
{
    private:
    TrieNode* root;

    public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string& word)
    {
        TrieNode* current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
                current->children[ch] = new TrieNode();
            current = current->children[ch];
        }
        current->isEnd = true;
    }

    bool search(const string& word, int& iterations)
    {
        TrieNode* current = root;
        for (char ch : word)
        {
            iterations++;
            if (current->children.find(ch) == current->children.end())
                return false; 
            current = current->children[ch];
        }
        return current->isEnd; 
    }

};

int main()
{
    Trie techTrie;

    techTrie.insert("Microsoft");
    techTrie.insert("Apple");
    techTrie.insert("Google");
    techTrie.insert("Amazon");
    techTrie.insert("Facebook");

    string userInput;
    cout << "Enter a tech company name : ";
    cin >> userInput;

    int iterations = 0;
    bool found = techTrie.search(userInput, iterations);

    if (found)
        cout<<"Company found in the trie in "<<iterations<<" iterations";
    else cout<<"Company not found in the trie";

    return 0;
}
