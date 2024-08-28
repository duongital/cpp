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

  ListNode* removeElements(ListNode* head, int val) {
    ListNode* ilter = head;
    ListNode* prev = nullptr;
    while (ilter != nullptr) {
      if (ilter->val == val) {
        if (prev == nullptr) {
          head = head->next;
          prev = nullptr;
        } else {
          prev->next = ilter->next;
        }
      } else {
        prev = ilter;
      }
      ilter = ilter->next;
    }
    print(head);
    return head;
  }
};

int main() {
  Solution s;
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(2);
  ListNode* c = new ListNode(2);
  ListNode* d = new ListNode(1);
  a->next = b;
  b->next = c;
  c->next = d;

  s.removeElements(a, 2);
  return 0;
}