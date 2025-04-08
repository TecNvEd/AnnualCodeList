#include<iostream>
#include<algorithm>

using namespace std;

int compareType = 0;
struct Student{
	int score[5];
	int id;
	int admit;
	Student(int s1, int s2,int s3,int s4,int _id){
		score[0] = s1 + s2 + s3 + s4;
		score[1] = s1;
		score[2] = s2;
		score[3] = s3;
		score[4] = s4;
		id = _id;
		admit = 0;					
	}
	Student(){
	};
};
bool cmp(const Student& s1, const Student& s2){
	if(s1.score[0] != s2.score[0])
		return s1.score[0] > s2.score[0];
	else{
		if(compareType == 0){
			return s1.id < s2.id;
		}
		else{
			if(s1.score[compareType] != s2.score[compareType]){
				return s1.score[compareType] > s2.score[compareType];
			}
			else
				return s1.id < s2.id;
		}
	}
}

int n, m;
int s1, s2, s3, s4;
int cnt;
Student Stus[1005];
Student unAdmitStus[1005];
Student selectStus[1005];
int main(void){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s1 >> s2 >> s3 >> s4;
		Stus[i].score[0] = s1 + s2 + s3 + s4;
		Stus[i].score[1] = s1;
		Stus[i].score[2] = s2;
		Stus[i].score[3] = s3;
		Stus[i].score[4] = s4;
		Stus[i].id = i;
		Stus[i].admit = 0;
	}
	for(int i = 0; i < m; i++){
		cin >> cnt >> compareType;
		int k = 0;
		for(int j = 0; j < n; j++){
			if(Stus[j].admit == 0){
				unAdmitStus[k++] = Stus[j];
			}
		}
		sort(unAdmitStus,unAdmitStus + k,cmp);
		if(cnt >= k){
			cout << k;
			for(int i1 = 0 ; i1 < k; i1++){
				cout << " " << unAdmitStus[i1].id + 1;
				Stus[unAdmitStus[i1].id].admit = 1;
			}
		}
		else{
			int finalScore = unAdmitStus[cnt - 1].score[0];
			int finalTypeScore = unAdmitStus[cnt - 1].score[compareType];
			int finalCnt = 0;
			for(int i1 = 0; i1 < k; i1++){
				if(unAdmitStus[i1].score[0] > finalScore || unAdmitStus[i1].score[0] == finalScore &&  unAdmitStus[i1].score[compareType] >= finalTypeScore){
					selectStus[finalCnt++] = unAdmitStus[i1];
					Stus[unAdmitStus[i1].id].admit = 1;
				}
			}
			cout << finalCnt;
			for(int i1 = 0; i1 < finalCnt; i1++){
				cout << " " << selectStus[i1].id + 1;
			}
		}
		cout << endl;
		
	}
}