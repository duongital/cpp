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

  ListNode* middleNode(ListNode* head) {
    ListNode* ilter = head;
    int len = 0;
    while (ilter != NULL) {
      len++;
      ilter = ilter->next;
    }
    int mid = len / 2;
    int step = 0;
    while (head != NULL) {
      if (mid == step) {
        break;
      }
      step++;
      head = head->next;
    }
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

  s.middleNode(a);
  return 0;
}

/**
 * fast and slow pointer:
 * fast reaches the end node and slow reaches the middle:

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast-> next != NULL)
    {
        slow = slow-> next;
        fast = fast-> next-> next;
    }
    return slow;
}

*/