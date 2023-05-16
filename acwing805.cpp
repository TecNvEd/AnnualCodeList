#include <bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
vector<PII> segs, ans;
int n;
int s;
int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	segs.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &segs[i].first, &segs[i].second);
	sort(segs.begin(), segs.end());
	int st = 2e-9, ed = 2e-9;
	for (auto &seg : segs) {
		if (seg.first > ed) {
			if (st != 2e-9) {
				ans.push_back({st, ed});
				s++;
			}
			st = seg.first;
			ed = seg.second;
		} else
			ed = max(ed, seg.second);
	}
	if (st != 2e-9)

	{
		s++;
		ans.push_back({st, ed});
	}
	printf("%d", ans.size());
}