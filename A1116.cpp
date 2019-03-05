//2019/3/5 15:45
#include<cstdio>
#include<set>
#include<vector>
#include<map>
using namespace std;
const int maxn = 10050;
vector<int> pri;
set<int> pri_final;
map<int, int> price;
int n, k;
void initial(){
	pri.push_back(2);
	for(int i = 3; i < maxn; ++i){
		bool flag = true;
		for(int j = 0; j < pri.size(); ++j){
			if(i % pri[j] == 0){
				flag = false;
				break;
			}
		}
		if(flag) pri.push_back(i);
	}
	for(int i = 0; i < pri.size(); ++i)
		pri_final.insert(pri[i]);
}
void print(int id){
	if(price.find(id) == price.end()){
		printf("%04d: Are you kidding?\n", id);
		return ;
	} 
	if(price[id] == 1) printf("%04d: Mystery Award\n", id);
	else if(price[id] == 2) printf("%04d: Minion\n", id);
	else if(price[id] == 3)printf("%04d: Chocolate\n", id);
	else if(price[id] == 0) printf("%04d: Checked\n", id);
	price[id] = 0;
}
int main(){
	scanf("%d", &n);
	initial();
	int i;
	for(i = 1; i <= n; ++i){
		int id;
		scanf("%d", &id);
		if(i == 1) price[id] = 1;
		else if(pri_final.find(i) != pri_final.end()) price[id] = 2;
		else price[id] = 3;
	}
	scanf("%d", &k);
	for(int j = 0; j < k; ++j){
		int id;
		scanf("%d", &id);
		print(id);
	}
	return 0;
}
