#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define PII pair<int,int>
using namespace std;
const int N = 2e5 + 5;

int n, k;
int tmp1, tmp2;
vector<PII> solders;



int h[N], e[N], ne[N], idx;
void add(int a, int b) { // Ìí¼ÓÒ»Ìõ±ßa->b
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp1);
		solders.push_back({tmp1, i});
	};
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &tmp1, &tmp2);
		add(tmp1, tmp2), add(tmp2, tmp1);
	}
	sort(solders.begin(), solders.end());
	int sz = solders.size();
	for (int i = 0; i < sz; i++) {
		int ans = i;
		while (ans >= 1 && solders[ans].first == solders[ans - 1].first) {
			ans--;
		}
		for (int j = h[solders[i].second]; ~j; j = ne[j]) {
			int k = e[j];
			if (solders[k].first < solders[i].first)
				ans--;
		}
		printf("%d ", ans);
	}
}