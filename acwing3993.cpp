#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 2e5 + 5;
const int M = 2e5 + 5;
int h[M];
int stoneMin = INT_MAX, stoneMax = INT_MIN;

int count(int n) {
	int ans = 0;
	for (int i = n; i <= stoneMax; i++) {
		ans += h[i];
	}
	return ans;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	int tmp;

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp < stoneMin)
			stoneMin = tmp;
		if (tmp > stoneMax)
			stoneMax = tmp;
		h[tmp]++;
	}
	int times = 0;
	while (stoneMax != stoneMin) {
		int index = stoneMax - 1;
		int prev = h[stoneMax];
		int minusK = 0;
		while (true) {
			minusK += prev * (stoneMax - index);
			if (minusK > k)
				break;
			else {
				stoneMax -= 1;
				h[stoneMax] += prev;
				prev = h[stoneMax];
				index = stoneMax - 1;
			}
		}
		times++;
	}
	printf("%d", times);
}