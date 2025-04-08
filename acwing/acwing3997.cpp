#include <iostream>
using namespace std;

int T, k, l;
int main(void) {
	freopen("input.txt", "r", stdin);
	cin >> T;
	while (T--) {
		cin >> k >> l;
		int tmp = 1;
		while (true) {
			tmp *= k;
			if (tmp == l) {
				puts("YES");
				break;
			} else if (tmp > l) {
				puts("NO");
				break;
			}
		}
	}
}