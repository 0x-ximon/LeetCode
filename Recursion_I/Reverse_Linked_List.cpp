struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) { return reverse(head); }
  ListNode* reverse(ListNode* node) {
    if (!node || !node->next) return node;

    ListNode* head = reverse(node->next);
    node->next->next = node;
    node->next = nullptr;

    return head;
  }
};
