//2019/4/27 23:42
#include<iostream>
#include<string>
using namespace std;
const int maxn = 25;
int node[maxn][2];
string str[maxn];
void addInclude(string &s){
	s = "(" + s + ")";
}
string inOrder(int root){
	string left = "", right = "";
	if(node[root][0] != -1){
		int lNode = node[root][0];
		left = inOrder(lNode);
		if(node[lNode][0] != -1 || node[lNode][1] != -1) addInclude(left);
	}
	if(node[root][1] != -1){
		int rNode = node[root][1];
		right = inOrder(rNode);
		if(node[rNode][0] != -1 || node[rNode][1] != -1) addInclude(right);
	}
	return left + str[root] + right;
}
int findRoot(int n){
	bool vis[maxn] = {false};
	for(int i = 1; i <= n; ++i){
		if(node[i][0] != -1) vis[node[i][0]] = true;
		if(node[i][1] != -1) vis[node[i][1]] = true;
	}
	int root;
	for(int i = 1; i <= n; ++i){
		if(vis[i] == false) return i;
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i){
		string s;
		int left, right;
		cin>>s>>left>>right;
		str[i] = s;
		node[i][0] = left;
		node[i][1] = right;
	}
	int root = findRoot(n);
	string s = inOrder(root);
	cout<<s<<endl;
	return 0;
}
