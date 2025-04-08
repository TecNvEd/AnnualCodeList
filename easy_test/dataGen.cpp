#include<iostream>
#include<random>
#include<ctime>
using namespace std;

int main(void){
	srand(time(0));
	rand();
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = 100, m = 78;
	cout << n  << " " << m << endl;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n; j++){
			if(rand() % 2 == 1)
				cout <<"R";
			else
				cout <<"G";
		}
		cout << endl;
	}
	for(int i = 0 ; i < m; i++){
		for(int j = 0 ; j < m; j++){
			if(rand() % 2 == 1)
				cout <<"R";
			else
				cout <<"G";
		}
		cout << endl;
	}
}