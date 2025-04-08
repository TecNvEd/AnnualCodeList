#include <algorithm>
#include <iostream>
using namespace std;



int main() {
	int a;
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	int ans = 0;
	while (str != "1") {
		if (str[0] == '0') {
			str.erase(0, 1);
			ans++;
		} else if (str[0] == '1') {
			int i = 1;
			while (str[i] == '1') {
				str[i++] = '0';
			}
			if (i == str.length())
				str += '1';
			else
				str[i] = '1';

			ans++;
		}
		cout << "str:" << str << endl;
	}
	printf("%d", ans);
}