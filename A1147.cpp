//2019/3/1 14:46
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1005;
int node[maxn];
int m, n;
vector<int> postLine;
void postOrder(int root){
	if(root > n) return ;
	postOrder(2 * root);
	postOrder(2 * root + 1);
	postLine.push_back(node[root]);
}
void fun(){
	bool isMaxHeap = true, isChange = false, isHeap = true;
	for(int i = 1; i <= n / 2; ++i){
		if(isMaxHeap){
			int max = node[2 * i], min = node[2 * i];
			if(2 * i + 1 <= n){
				max = node[2 * i] > node[2 * i + 1]? node[2 * i]: node[2 * i + 1];
				min = node[2 * i] < node[2 * i + 1]? node[2 * i]: node[2 * i + 1];
			}
			if(node[i] == max && max == min) isChange = false;
			else if(node[i] >= max) isChange = true;
			else if(node[i] < max && isChange == true){
				printf("Not Heap\n");
				isHeap = false;
				break;
			}
			else if(node[i] < max && isChange == false){
				isChange = true;
				isMaxHeap = false;
			}
		}
		if(isMaxHeap == false){
			int min = node[2 * i];
			if(2 * i + 1 <= n)
				min = node[2 * i] < node[2 * i + 1]? node[2 * i]: node[2 * i + 1];
			if(node[i] > min){
				printf("Not Heap\n");
				isHeap = false;
				break;
			}	
		}
	}
	if(isHeap)
		if(isMaxHeap) printf("Max Heap\n");
		else printf("Min Heap\n");
	//postOrder sort
	postLine.clear();
	postOrder(1);
	for(int i = 0; i < postLine.size(); ++i){
		if(i) printf(" ");
		printf("%d", postLine[i]);
	}
	printf("\n");
}
int main(){
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; ++i){
		for(int j = 1; j <= n; ++j)
			scanf("%d", &node[j]);
		fun();
	}
	return 0;
}
