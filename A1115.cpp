//2019/3/5 11:17
#include<cstdio>
using namespace std;
const int maxn = 1050;
int n, maxDep = 0, maxDepNum = 0, maxDepAboNum = 0;
struct Node{
	int data;
	Node *left, *right;
};
void insert(int k, Node* &root, int dep){
	if(root == NULL){
		root = new Node;
		root->data = k;
		root->left = NULL;
		root->right = NULL;
		if(dep > maxDep){
			maxDepAboNum = maxDepNum;
			maxDep = dep;
			maxDepNum = 1;
		}
		else if(dep == maxDep)
			maxDepNum++;
		else if(dep == maxDep - 1) maxDepAboNum++;
		return ;
	}
	if(k <= root->data) insert(k, root->left, dep + 1);
	else insert(k, root->right, dep + 1);
}
int main(){
	scanf("%d", &n);
	Node* root = NULL;
	for(int i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		insert(temp, root, 1);
	}
	printf("%d + %d = %d\n", maxDepNum, maxDepAboNum, maxDepNum + maxDepAboNum);
	return 0;
} 
