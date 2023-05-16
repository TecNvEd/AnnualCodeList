#inlude<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mymap;
const int N = 2005;
int a[N][4]

char[4] G = {'C', 'M', 'E', 'A'};

int main(void) {
	int n, m;
	string tmp;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int sum = 0;
		scanf("%s", tmp);
		mymap[tmp] = i;
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
		a[i][3] = sum / 3;
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", tmp);
		if (mymap.find(tmp) == mymap.end())
			printf("%s\n", "N/A");
		else
			int index = mymap[tmp];
		int C = a[index][0], M = a[index][1], E = a[index][2], A = a[index][3];
		int rank[4];
		for (int p = 0; p < 4; p++)
			rank[p] = 1;
		for (int r = 0; r < n; r++) {
			if (a[r][0] > C)
				rank[0]++;
			if (a[r][1] > M)
				rank[1]++;
			if (a[r][2] > E)
				rank[2]++;
			if (a[r][3] > A)
				rank[3]++;
		}
		int minrank = rank[0];
		int subject = 0;
		for (int p = 0; p < 4; p++) {
			if (rank < minrank) {
				minrank = rank[p];
				subject = p;
			}
		}
		printf("%d %c\n", minrank, G[subject]);
	}

}