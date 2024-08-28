/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
  void printList(ListNode* head) {
    while (head != nullptr) {
      cout << head->val << endl;
      head = head->next;
    }
  }

  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* ilter = head;
    ListNode* ilterPrev = nullptr;
    while (ilter != nullptr) {
      if (ilterPrev != nullptr && ilter->val == ilterPrev->val) {
        ilterPrev->next = ilter->next;  // mutating the original head
        ilter = ilter->next;
      } else {
        ilterPrev = ilter;
        ilter = ilter->next;
      }
    }
    // printList(head);
    return head;
  }
};

int main() {
  Solution s;
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(1);
  ListNode* c = new ListNode(1);
  ListNode* d = new ListNode(3);
  a->next = b;
  b->next = c;
  c->next = d;

  s.deleteDuplicates(a);
  return 0;
}