#include <stdbool.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
  struct ListNode *f = head, *s = head;
  while (f != NULL && s != NULL && f->next != NULL) {
    s = s->next;
    f = f->next->next;
    if (f == s)
      return true;
  }
  return false;
}
