#include <iostream>

using namespace std;
int a[55][55];
int n, m;
long long ans;
int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < n; i++) {
		int black = 0, white = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j])
				black++;
			else
				white++;

		}
		if (black)
			ans += (1ll << black) - 1;
		if (white)
			ans += (1ll << white) - 1;
	}


	for (int j = 0; j < m; j++) {
		int black = 0, white = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j])
				black++;
			else
				white++;

		}
		if (black)
			ans += (1ll << black) - 1;
		if (white)
			ans += (1ll << white) - 1;
	}




	ans -= n * m;
	printf("%ld", ans);
}