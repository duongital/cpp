#include <iostream>

using namespace std;

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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (head->next == nullptr) return nullptr;

  ListNode* ilterRemove = head;
  ListNode* ilterPrev = nullptr;
  while (ilterRemove != nullptr) {
    int start = 0;
    ListNode* ilterTemp = ilterRemove;

    while (ilterTemp != nullptr) {
      start++;
      ilterTemp = ilterTemp->next;
    }
    if (start == n) {
      if (ilterPrev != nullptr) {
        ListNode* toDeleteNode = ilterPrev->next;
        ilterPrev->next = toDeleteNode->next;
        break;
      } else {
        head = head->next;
        break;
      }
    }
    ilterPrev = ilterRemove;
    ilterRemove = ilterRemove->next;
  }
  return head;
}

int main() {
  // allocate memory on the stack
  ListNode x = ListNode(700);
  ListNode y = ListNode(800);
  ListNode z = ListNode(900);

  x.next = &y;  // next is a pointer
  y.next = &z;  // next is a pointer

  ListNode* ilter2 = &x;
  while (ilter2 != nullptr) {
    cout << "ilter2: " << ilter2->val << endl;
    ilter2 = ilter2->next;
  }

  // allocate memory on the heap
  ListNode* a = new ListNode(100);
  ListNode* b = new ListNode(200);
  ListNode* c = new ListNode(300);
  ListNode* d = new ListNode(400);

  a->next = b;
  b->next = c;
  c->next = d;

  /**
   * Add to the end of the linked list:
   */
  ListNode* ilterAddEnd = a;
  while (ilterAddEnd->next != nullptr) {
    ilterAddEnd = ilterAddEnd->next;
  }
  ilterAddEnd->next = new ListNode(500);

  /**
   * Remove from nth element
   */
  removeNthFromEnd(a, 2);

  /**
   * Print the linked list:
   */
  ListNode* pointerPrint = a;
  while (pointerPrint != nullptr) {
    cout << "pointerPrint: " << pointerPrint->val << endl;
    pointerPrint = pointerPrint->next;
  }

  return 0;
}