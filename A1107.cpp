//2019 2.16 21:07 forked from QingShen Notes
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn], course[maxn] = {0}, isRoot[maxn] = {0};
void init(int n){
	for(int i = 1; i <= n; ++i)
		father[i] = i;
}
int findFather(int x){
	int a = x;
	while(x != father[x])	x = father[x];
	//压缩并查集路径 
	while(a != father[a]){
		int z = a;
		a = father[a];//x的father可能也不是root，故继续更新，直到a = fahter[a] 
		father[z] = x;
	} 
	return x;
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) father[faA] = faB;
}
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	cin>>n;
	init(n);
	for(int i = 1; i <= n; ++i){
		int k;
		scanf("%d:", &k);
		for(int j = 1; j <= k; ++j){
			int temp;
			cin>>temp;
			if(course[temp] == 0) course[temp] = i;
			Union(i, course[temp]);
		}
	}
	for(int i = 1; i <= n; ++i)
		isRoot[findFather(i)]++;
	int count = 0;
	for(int i = 1; i <= n; ++i)
		if(isRoot[i]) count++;
	cout<<count<<endl;
	sort(isRoot + 1, isRoot + 1 + n, cmp);
	for(int i = 1; i <= count; ++i){
		if(i != 1) cout<<" ";
		cout<<isRoot[i];
		}
	return 0;	
}
