#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    // child is present
    if (root->children[index])
    {
        child = root->children[index];
    }
    else
    {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursive call
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index])
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    // RE
    searchWord(child, word.substr(1));
}

bool deleteWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return true;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index])
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    deleteWord(child, word.substr(1));
}

int main()
{

    TrieNode *root = new TrieNode('-');
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "coding");
    insertWord(root, "codehelp");
    insertWord(root, "codes");

    if (searchWord(root, "coding"))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "absent" << endl;
    }

    if (deleteWord(root, "codes"))
    {
        cout << "deleted successfully ..." << endl;
    }
    else
    {
        cout << "mission failed ... " << endl;
    }

    return 0;
}