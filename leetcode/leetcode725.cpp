#include <bits/stdc++.h>
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
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		vector<ListNode *> ans;
		vector<ListNode *> splitListToParts(ListNode *head, int k) {
			int len;
			ListNode *backhead = head;
			while (backhead->next != nullptr) {
				len++;
				backhead = backhead->next;
			}
			if (k >= len) {
				while (len-- && k--) {
					ListNode listnode = ListNode(head->val);
					ListNode *node = &listnode;
					ans.push_back(node);
					head = head->next;
				}
				for (int i = 0; i < k; i++)
					ans.push_back(nullptr);
			}
			return ans;
		}
};

int vals[3] = {1, 2, 3};

int main(void) {
	Solution s;
	vector<ListNode *> vec;
	ListNode root = ListNode(1);
	ListNode *ptr = &root;
	for (int i = 1; i < 3; i++) {
		ListNode tmp = ListNode(vals[i]);
		ptr->next = &tmp;
		ptr = &tmp;
	}
	ptr = &root;
	vec = s.splitListToParts(ptr, 5);
	printf("%d", vec[0]->val);
}