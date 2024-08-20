#include <bits/stdc++.h>

using namespace std;
const int MAX = 26;

struct Node {
  Node *child[MAX];
  int countWord;
};

Node *newNode() {
  Node *node = new Node();
  node->countWord = 0;
  for (int i = 0; i < MAX; i++) node->child[i] = NULL;
  return node;
}

bool isWord(Node *node) { return node->countWord != 0; }

void addWord(Node *root, string s) {
  int ch;
  Node *temp = root;
  for (int i = 0; i < s.size(); i++) {
    ch = s[i] - 'a';
    if (temp->child[ch] == NULL) {
      temp->child[ch] = newNode();
    }
    temp = temp->child[ch];
  }
  temp->countWord++;
}

void printWord(Node *root, string s) {
  if (isWord(root)) cout << s << endl;
  for (int i = 0; i < MAX; i++) {
    if (root->child[i]) {
      printWord(root->child[i], s + (char)('a' + i));
    }
  }
}

int main() {
  int TC;
  cin >> TC;
  int current = 1;
  while (TC--) {
    int n;
    cin >> n;
    while (n--) {
      string s;
      cin >> s;
    }
    cout << "Case " << current << ":" << endl;
    current++;
  }
  return 0;
}