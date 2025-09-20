struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) { return exchange(head); }
  ListNode* exchange(ListNode* node) {
    if (!node || !node->next) return node;

    ListNode* next = exchange(node->next->next);
    ListNode* head = node->next;

    head->next = node;
    node->next = next;

    return head;
  }
};
