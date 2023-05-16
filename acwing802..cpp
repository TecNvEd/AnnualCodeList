#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N = 3e5;


vector<PII> inc, query;
vector<int> sub;

int h[N], s[N];

int n, m;
int main(void) {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int fi, sec;
		scanf("%d%d", &fi, &sec);
		inc.push_back({fi, sec});
		sub.push_back(fi);
	}
	for (int i = 0; i < m; i++) {
		int st, ed;
		scanf("%d%d", &st, &ed);
		query.push_back({st, ed});
		sub.push_back(st);
		sub.push_back(ed);
	}

	sort(sub.begin(), sub.end());

	//将index数组去重之后映射到了h[N]数组上面
	sub.erase(unique(sub.begin(), sub.end()), sub.end());

	for (auto &i : inc) {
		int in = lower_bound(sub.begin(), sub.end(), i.first) - sub.begin();
		h[in] += i.second;
	}

	//将h[N]数组的前缀和映射到s[N]上
	for (int i = 0; i < sub.size(); i++) {
		if (!i)
			s[i] = h[i];
		s[i] = s[i - 1] + h[i];
	}

	for (auto &q : query) {
		int index1 = lower_bound(sub.begin(), sub.end(), q.first) - sub.begin();
		int index2 = lower_bound(sub.begin(), sub.end(), q.second) - sub.begin();
		if (index1)
			printf("%d\n", s[index2] - s[index1]);
		else
			printf("%d\n", s[index2]);
	}


}