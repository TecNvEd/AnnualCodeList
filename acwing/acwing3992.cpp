#include <bits/stdc++.h>
using namespace std;
int n, w, tmp;
const int N = 1005;
int h[N];

int main(void) {
	scanf("%d%d", &n, &w);
	int maxMonkey = 0, minMonkey = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		h[i] = h[i - 1] + tmp;
		if (h[i] > maxMonkey) {
			h[i] = maxMonkey;
		}
		if (h[i] < minMonkey)
			minMonkey = h[i];
	}
	int top = w - maxMonkey;
	int bottom = -minMonkey;
	printf("%d", top - bottom + 1);

}