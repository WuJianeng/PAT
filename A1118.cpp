//2019/3/5 16:57
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
const int maxn = 10050;
set<int> st;
int pre[maxn];
int findRoot(int n){
	while(pre[n] != n) n = pre[n];
	return n;
}
void insert(int root, int j){
	root = findRoot(root);
	while(pre[j] != root){
		int preRoot = pre[j];
		pre[j] = root;
		j = preRoot;
	}
}
void isSameRoot(int n, int k){
	while(pre[n] != n) n = pre[n];
	while(pre[k] != k) k = pre[k];
	if(n == k) printf("Yes\n");
	else printf("No\n");
}
int main(){
	int n, query;
	scanf("%d", &n);
	for(int i = 1; i <= maxn; ++i)
		pre[i] = i;
	for(int i = 0; i < n; ++i){
		int k;
		scanf("%d", &k);
		int root;
		scanf("%d", &root);
		st.insert(root);
		for(int j = 0; j < k - 1; ++j){
			int now;
			scanf("%d", &now);
			st.insert(now);
			insert(root, now);
		}
	}
	int treeNum = 0;
	for(set<int>::iterator it = st.begin(); it != st.end(); ++it){
		int id = *it;
		if(pre[id] == id) treeNum++;
	}
	printf("%d %d\n", treeNum, st.size());
	scanf("%d", &query);
	for(int i = 0; i < query; ++i){
		int root1, root2;
		scanf("%d %d", &root1, &root2);
		isSameRoot(root1, root2);
	}
	return 0;
}
