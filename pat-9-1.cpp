#include <bits/stdc++.h>
using namespace std;
double a[3][3];
double m[3][2];
double ans = 1;

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
			if (a[i][j] > m[i][0]) {
				m[i][0] = a[i][j];
				m[i][1] = j;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		ans *= m[i][0];
		if (m[i][1] == 0)
			printf("%c ", 'W');
		if (m[i][1] == 1)
			printf("%c ", 'T');
		if (m[i][1] == 2)
			printf("%c ", 'L');
	}
	ans = (1.0 * ans * 0.65 - 1) * 2;
	printf("%0.2ld", ans);
	fclose(stdin);
	fclose(stdout);

}