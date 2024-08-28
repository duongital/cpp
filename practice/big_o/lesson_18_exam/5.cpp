// Phone List
// using trie to check all strings are not included in another

#include <bits/stdc++.h>

using namespace std;

struct trieNode {
  map<char, trieNode *> children;
  bool endOfWord;
};

trieNode *createTrieNode() {
  trieNode *node = new trieNode();
  node->endOfWord = false;
  return node;
}

void insert(trieNode *root, string s) {
  trieNode *current = root;
  for (int i = 0; i < s.length(); i++) {
    map<char, trieNode *>::iterator itr = current->children.find(s[i]);
    if (itr == current->children.end()) {
      trieNode *node = createTrieNode();
      current->children.insert(pair<char, trieNode *>(s[i], node));
      current = node;
    } else {
      current = itr->second;
    }
  }
  current->endOfWord = true;
}

bool search(trieNode *root, string s) {
  trieNode *current = root;
  for (int i = 0; i < s.length(); i++) {
    map<char, trieNode *>::iterator itr = current->children.find(s[i]);
    if (itr == current->children.end()) {
      return false;
    }
    current = itr->second;
    if (current->children.empty()) {
      return false;
    }
  }
  return true;
}

int main() {  // main flows
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    trieNode *root = createTrieNode();
    string s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      insert(root, s[i]);
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (search(root, s[i])) {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}