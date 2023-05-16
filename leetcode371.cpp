#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b) {
	int carry = 0;
	for (int i = 0; i < 31; i++) {
		int aright = ((a >> i) & 1) + carry;
		int bright = ((b >> i) & 1);

		//此处需要设置a的第i位为left  我一直没整明白
		int left = aright ^ bright;
		if (i >= 1)
			a &= (((left << i) + (1 << i - 1)) & 0xffffffff);
		else
			a &= ((left << i) & 0xffffffff);
		int carry = aright & bright;
	}
	return a;
}

int main(void) {
	int a, b;
	cin >> a >> b;
	cout << getSum(a, b) << endl;
}