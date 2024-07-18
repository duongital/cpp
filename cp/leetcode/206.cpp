// reverse a linked list

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  void print(ListNode* head) {
    cout << "--print--" << endl;
    while (head != nullptr) {
      cout << head->val << endl;
      head = head->next;
    }
  }

  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* target = nullptr;
    while (head != nullptr) {
      if (target == nullptr) {
        target = new ListNode(head->val);
      } else {
        ListNode* temp = new ListNode(head->val);
        temp->next = target;
        target = temp;
      }
      head = head->next;
    }

    return target;
  }
};

int main() {
  Solution s;
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(2);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(4);
  a->next = b;
  b->next = c;
  c->next = d;

  s.reverseList(a);
  return 0;
}