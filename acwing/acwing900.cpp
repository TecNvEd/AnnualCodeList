#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int f[N][N];


int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &f[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				f[i][j] = f[i - 1][j] + f[i][j];
				continue;
			}
			if (j == i) {
				f[i][j] = f[i - 1][j - 1] + f[i][j];
				break;
			}
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + f[i][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (f[n][i] > res)
			res = f[n][i];
	}
	printf("%d", res);

}