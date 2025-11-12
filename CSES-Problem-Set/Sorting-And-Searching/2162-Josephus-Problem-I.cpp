#include <cstdint>
#include <iostream>

struct Node {
  int val;
  Node *next, *prev;
};

int main() {
  std::ios::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  uint64_t n;
  std::cin >> n;
  struct Node *head = new Node;
  struct Node *tail = head;
  head->val = 1;
  for (uint64_t i = 2; i <= n; i++) {
    tail->next = new Node;
    tail->next->prev = tail;
    tail = tail->next;
    tail->val = i;
  }
  tail->next = head;
  head->prev = tail;
  struct Node *curr = head->next;
  while (n != 0) {
    struct Node *prev = curr->prev;
    struct Node *next = curr->next;
    prev->next = next;
    next->prev = prev;
    std::cout << curr->val << " ";
    delete curr;
    curr = next->next;
    n--;
  }
}
