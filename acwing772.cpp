#include <iostream>

int s[100];
char c;
int cnt[100], code, lowCode = 30;
int main(void) {
	while (scanf("%c", &c) != EOF) {
		s[c - 'a']++;
		if (s[c - 'a'] == 1)
			cnt[c - 'a'] = code++;
	}
	for (int i = 0; i < 26; i++)
		if (s[i] == 1 && cnt[i] < lowCode)
			c = 'a' + i, lowCode = cnt[i];

	if (lowCode != 30)
		printf("%c", c);
	else
		printf("no\n");
}
