#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
	int n = s.length();
	int i = 0, j = n - 1;
	while (i < j) {
		char left = s[i];
		char right = s[j];
		//if(left==')'||right=='(')return false;
		if ((left == '(' && right == ')') || left == '*' && right == '*' || left == '*' && right == ')' || left == '('
		        && right == '*')
			i++, j--;
		//else if(left=='(')
		else
			return checkValidString(s.substr(0, i + 1)) && checkValidString(s.substr(j, n - j));
	}
	if (i == j)
		return s[i] == '*';
	else
		return true;
}

int main(void) {
	string str = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";
	bool flag = checkValidString(str);
	printf("%d", flag);
}