#include <cstdio>

bool isRun(int year) {
	return (!(year % 4) && year % 100) || !(year % 400);
}

int days[12][2] = {
	{31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};

int main(void) {
	for (int i = 1; i < 12; i++) {
		for (int j = 0; j < 2; j++) {
			days[i][j] = days[i][j] + days[i - 1][j];
		}
	}

	int year, day;
	int isrun, month = 0;
	scanf("%d%d", &year, &day);
	isrun = isRun(year);
	while (true) {
		if (day > days[month][isrun])
			month++;
		else
			break;
	}
	printf("%d\n", month + 1);
	printf("%d", day - days[month - 1][isrun]);
}