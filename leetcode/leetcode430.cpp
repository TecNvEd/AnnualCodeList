/*

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int val;
		Node *prev;
		Node *next;
		Node *child;
};

class Solution {

	public:
		Node *ans = new Node();
		Node *tail = ans;
		void dfs(Node *node) {
			printf("%d", node->val);
			tail->next = node;
			tail = node;
			if (node->child != nullptr)
				dfs(node->child);
			if (node->next != nullptr)
				dfs(node->next);
		}
		Node *flatten(Node *head) {
			dfs(head);
			return ans;
		}
};

int main(void) {
	Solution s;
	s.flatten()
}