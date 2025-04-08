#include<iostream>
#include<queue>

using namespace std;


struct Buy {
	int price;
	int quantity;
	int id;
	Buy(int _price, int _quantity,int _id):price(_price),quantity(_quantity),id(_id) {};
};
struct Sold {
	int price;
	int quantity;
	int id;
	Sold(int _price, int _quantity,int _id):price(_price),quantity(_quantity),id(_id) {};

};

struct BuyCompare{
	//buy价格从高到低
	//id从小到大
	bool operator()(const Buy & b1,const Buy & b2){
		if(b1.price != b2.price )
			return b1.price < b2.price;
		else {
			return b1.id > b2.id;
		}
	}
};

struct SoldCompare{
	bool operator()(const Sold & s1,const Sold & s2){
		if(s1.price != s2.price )
			return s1.price > s2.price;
		else {
			return s1.id > s2.id;
		}
	}
};

priority_queue<Buy,vector<Buy>,BuyCompare> pq1;
priority_queue<Sold,vector<Sold>,SoldCompare> pq2;

void checkBuy(Buy b) {
	if(pq2.empty() || pq2.top().price > b.price) {
		pq1.push(b);
		return;
	} else {
		while(b.quantity > 0 && !pq2.empty() && pq2.top().price <= b.price) {
			auto x = pq2.top();
			pq2.pop();
			int minCnt = min(b.quantity, x.quantity);
			b.quantity -= minCnt;
			x.quantity -= minCnt;
			if(x.quantity > 0) {
				pq2.push(x);
			}
			if(b.quantity == 0) {
				return;
			}
		}
		if(b.quantity > 0)pq1.push(b);
	}
}
void checkSold(Sold s) {
	if(pq1.empty() || pq1.top().price < s.price) {
		pq2.push(s);
		return ;
	} else {
		while(s.quantity > 0 && !pq1.empty() && pq1.top().price >= s.price) {
			auto x = pq1.top();
			pq1.pop();
			int minCnt = min(s.quantity,x.quantity);
			s.quantity -= minCnt;
			x.quantity -= minCnt;
			if(x.quantity > 0) {
				pq1.push(x);
			}
			if(s.quantity == 0) {
				return;
			}
		}
		if(s.quantity > 0)pq2.push(s);
	}

}
char t;
int n, p, q;
int main(void) {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t >> p >> q;
		if(t == 'B') {
			Buy b = Buy(p, q, i);
			checkBuy(b);
		} else {
			Sold s = Sold(p, q, i);
			checkSold(s);
		}
	}
	int l1 = pq1.size();
	cout << l1 << endl;
	for(int i = 0; i < l1; i++) {
		auto x = pq1.top();
		pq1.pop();
		cout << "B" <<" "<< x.price <<  " " << x.quantity << endl;
	}

	int l2 = pq2.size();
	cout << l2 << endl;
	for(int i = 0; i < l2; i++) {
		auto x = pq2.top();
		pq2.pop();
		cout << "S" <<" "<< x.price <<  " " << x.quantity << endl;
	}




}