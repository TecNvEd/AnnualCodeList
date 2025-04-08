#include <bits/stdc++.h>
using namespace std;

vector<int>A, B, C;
string a, b;
vector<int> add(vector<int>a, vector<int>b) {
	vector<int> C;
	if (a.size() < b.size())
		return add(b, a);
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		int tmp = a[i] + carry;
		if (i < b.size())
			tmp += b[i];
		carry = tmp / 10;
		C.push_back(tmp % 10);
	}
	if (carry)
		C.push_back(1);
	reverse(C.begin(), C.end());
	return C;
}

int main(void) {
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)
		A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--)
		B.push_back(b[i] - '0');
	C = add(A, B);
	for (int i = 0; i < C.size(); i++)
		cout << C[i];

}