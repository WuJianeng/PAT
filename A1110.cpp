//2019/2/27 13:07
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector<int> node[25];
int fun(char str[]){
	if(str[0] == '-') return -1;
	int len = strlen(str);
	if(len == 2) return str[1]- '0' + (str[0] - '0') * 10;
	else return str[0] - '0';
}
bool vis[25] = {false};
int find(int nodeNum){
	for(int i = 0; i < nodeNum; ++i)
		if(vis[i] == false) return i;
}
int final;
bool preorder(int n, int nodeNum){
	queue<int> q;
	int mid = nodeNum / 2;
	int root = n;
	q.push(root);
	int count;
	for(count = 1; count < mid; count++){
		int ans = q.front();
		q.pop();
		if(node[ans][0] == -1) return false;
		else q.push(node[ans][0]);
		if(node[ans][1] == -1) return false;
		else q.push(node[ans][1]);
	}
	int ans = q.front();
	q.pop();
	if(node[ans][0] == -1 && node[ans][1] != -1) return false;
	if(node[ans][0] != -1) q.push(node[ans][0]);
	if(node[ans][1] != -1) q.push(node[ans][1]);
	while(!q.empty()){
		int ans = q.front();
		final = ans;
		q.pop();
		if(ans == -1) return true;
		else if(node[ans][0] != -1 || node[ans][1] != -1) return false;
	}
	return true;
}
int main(){
	int nodeNum;
	cin>>nodeNum;
	for(int i = 0; i < nodeNum; ++i){
		int left, right;
		char str[5];
		scanf("%s", str);
		left = fun(str);
		scanf("%s", str);
		right = fun(str);
		node[i].push_back(left);
		node[i].push_back(right);
		vis[left] = true;
		vis[right] = true;
	}
	int root = find(nodeNum);
	bool flag = preorder(root, nodeNum);
	if(flag) cout<<"YES "<<final<<endl;
	else cout<<"NO "<<root<<endl;
	return 0;
}
