//2019.2.14 23:55
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 100100;
struct Tree{
	int depth, amount;
	bool tag;
	vector<int> child;
}tree[maxn];
double BFS(double p, double r){
	queue<int> q;
	q.push(0);
	tree[0].depth = 0;
	double sum = 0;
	while(!q.empty()){
		int temp = q.front();
		int dep = tree[temp].depth + 1;
		q.pop();
		if(tree[temp].tag) sum += tree[temp].amount * 1.0 * pow(1 + r / 100, tree[temp].depth) * p;
		for(vector<int>::iterator it = tree[temp].child.begin(); it != tree[temp].child.end(); ++it){
			q.push(*it);
			tree[*it].depth = dep;
		}
	}
	return sum;
}
int main(){
	int n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; ++i)
		tree[i].tag = false;
	for(int i = 0; i < n; ++i){
		int k;
		scanf("%d", &k);
		if(k == 0){
			tree[i].tag = true;
			scanf("%d", &tree[i].amount);
		} 
		for(int j = 0; j < k; ++j){
			int temp;
			scanf("%d", &temp);
			tree[i].child.push_back(temp);
		}
	}
	double sum = BFS(p, r);
	printf("%.1f\n", sum);
	return 0;
}
