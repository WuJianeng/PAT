//2019 2.16 13:20
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn = 100050;
struct Tree{
	bool isRetailer;
	vector<int> child;
	int level;
}tree[maxn];
int main(){
	int n;
	double price, rate;
	cin>>n>>price>>rate;
	for(int i = 0; i < n; ++i){
		int num;
		cin>>num;
		if(num == 0) tree[i].isRetailer = true;
		else tree[i].isRetailer = false;
		for(int j = 0; j < num; ++j){
			int child;
			cin>>child;
			tree[i].child.push_back(child);
			}
	}
	//get level
	queue<int> q;
	tree[0].level = 0;
	q.push(0);
	int ret = 0, level = -1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if( tree[now].isRetailer == true && (level == tree[now].level || level == -1) ){
			ret++;
			level = tree[now].level;
		}
		else if(level != -1 && tree[now].level != level) break;
		for(int j = 0; j < tree[now].child.size(); ++j){
			int child = tree[now].child[j];
			q.push(child);
			tree[child].level = tree[now].level + 1;
		}
	}
	double min_price = price * pow(1.0 + rate / 100.0, level);
	printf("%.4f %d\n", min_price, ret);
	return 0;
}

