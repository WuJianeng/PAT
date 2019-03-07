//2019/3/7 14:51
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
struct Node{
	int id, fre;
};
bool cmp(Node a, Node b){
	if(a.fre != b.fre) return a.fre > b.fre;
	return a.id < b.id;
}
void verify(vector<Node> s, int num, int ss){
	sort(s.begin(), s.end(), cmp);
	for(int j = 0; j <= num && j < ss; ++j)
		cout<<" "<<s[j].id;
	cout<<endl;
}
int main(){
	int n, k;
	cin>>n>>k;
	vector<Node> v(n);
	for(int i = 0; i <= n; ++i){
		v[i].id = i;
		v[i].fre = 0;
	}
	int id;
	for(int i = 0; i < n; ++i){
		if(i >= 1){
			cout<<id<<":";
			verify(v, i - 1, k);
		}
		cin>>id;
		v[id].fre++;
	}
	return 0;
}
