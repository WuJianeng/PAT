//2019/3/7 14:51
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 1005;
bool verify(vector<int> v){
	for(int i = 0; i < v.size(); ++i)
		for(int j = 0; j < i; ++j)
			if(v[i] == v[j] || abs(v[i] - v[j]) == i - j) 
				return false;
	return true;
}
void print(bool flag){
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main(){
	int k, n;
	scanf("%d", &k);
	vector<int> v;
	for(int i = 0; i < k; ++i){
		scanf("%d", &n);
		v.clear();
		for(int j = 0; j < n; ++j){
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		bool flag = verify(v);
		print(flag);
	}
	return 0;	
} 
