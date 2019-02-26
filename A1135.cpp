//2019/2/26 18:00
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 305, INF = 1000000000;
int caseNum, nodeNum;
int data[maxn];
struct Node{
	int data;
	bool red;
	Node *lchild, *rchild;
};
Node* preoder(int data[], int fir, int end){
	if(fir > end) return NULL;
	Node *p = new Node;
	if(data[fir] < 0) p->red = true;
	else p->red = false;
	p->data = abs(data[fir]);
	int right;
	for(right = fir + 1; abs(data[right]) < abs(data[fir]); ++right) ;
	p->lchild = preoder(data, fir + 1, right - 1);
	p->rchild = preoder(data, right, end);
	return p;
}
bool verify(Node* p, bool rootIsRed){
	if(p == NULL) return true;
	if(rootIsRed == true && p->red == true){
		printf("No\n");
		return false;
	}
	else{
		bool flag1 = verify(p->lchild, p->red);
		bool flag2 = verify(p->rchild, p->red);
		if(flag1 && flag2) return true;
		else return false;
	}
	
}
bool tag;
int dfs(Node* p){
	if(p == NULL) return 0;
	int num1 = dfs(p->lchild);
	int num2 = dfs(p->rchild);
	if(num1 != num2)
		tag = 1;
	if(p->red == false) num1++;
	return num1;
}
int main(){
	cin>>caseNum;
	for(int i = 0; i < caseNum; ++i){
		cin>>nodeNum;
		fill(data, data + maxn, INF);
		for(int j = 0; j < nodeNum; ++j){
			cin>>data[j];
		}
		Node * p = NULL;
		p = preoder(data, 0, nodeNum - 1);
		bool flag = verify(p, true);
		if(flag == true){
			tag = 0;
			dfs(p);
			if(tag) printf("No\n");
			else printf("Yes\n");
		} 
		
	}
	return 0;
}
