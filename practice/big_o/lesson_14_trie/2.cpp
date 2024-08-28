#include <bits/stdc++.h>

using namespace std;
const int MAX = 4;
vector<char> dna = {'A', 'C', 'G', 'T'};
int result = 0;

struct TrieNode {
  TrieNode *child[MAX];
  int countWord;
};

TrieNode *newNode() {
  TrieNode *node = new TrieNode();
  node->countWord = 0;
  for (int i = 0; i < MAX; i++) node->child[i] = NULL;
  return node;
}

void addWord(TrieNode *root, string s) {
  TrieNode *temp = root;
  for (int i = 0; i < s.size(); i++) {
    int level = i + 1;
    int ch = find(dna.begin(), dna.end(), s[i]) - dna.begin();
    if (temp->child[ch] == NULL) {
      temp->child[ch] = newNode();
    }
    temp = temp->child[ch];
    temp->countWord++;
    result = max(result, temp->countWord * level);
  }
}

int main() {
  int TC;
  cin >> TC;
  int current = 1;

  while (TC--) {
    int n;
    cin >> n;
    result = 0;

    TrieNode *root = newNode();
    while (n--) {
      string s;
      cin >> s;
      addWord(root, s);
    }
    cout << "Case " << current << ": " << result << endl;
    current++;
  }
  return 0;
}