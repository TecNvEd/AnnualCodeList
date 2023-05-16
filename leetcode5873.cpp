#include <bits/stdc++.h>
using namespace std;
vector<int> answers;

int maxConsecutiveAnswers(string answerKey, int k) {
	char prev;
	int tmp = 0;
	for (int i = 0; answerKey[i]; i++) {
		if (i != 0)
			prev = answerKey[i - 1];
		if (i == 0 || answerKey[i] == prev ) {
			tmp++;
			if (i == answerKey.size() - 1)
				answers.push_back(tmp);
		}

		else {
			answers.push_back(tmp);
			tmp = 1;
		}
	}
	int ans = answers[0];
	int sz = answers.size();
	for (int i = 1; i < sz; i++) {
		if (k >= answers[i]) {
			if (i + 1 < answers.size())
				ans = max(ans, answers[i - 1] + answers[i] + answers[i + 1]);
			else
				ans = max(ans, answers[i - 1] + answers[i]);
		} else
			continue;
	}
	return ans;
}

int main(void) {
	printf("%d", maxConsecutiveAnswers("TFFT", 1));
}