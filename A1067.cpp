//2019 2.9 15:25
#include<cstdio>
#include<algorithm>
using namespace std;
int seq[100010];
int place = 0;
int find(int seq[], int n){
	int i = place;
	while(seq[i] != n) ++i;
	return i;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	int count = 0, tag, flag = 0;
	for(int i = 0; i < n; ++i){
		if(seq[i] == 0) tag = i;
		if(seq[i] != i && seq[i] != 0) count++;
	}	
	while(count > 0){
		if(seq[0] != 0) {
			int temp = find(seq, tag);
			swap(seq[tag], seq[temp ] );
			tag = temp;
			flag++;
			count--;
		}
		else
			for(int i = place; i < n; i++)
				if(seq[i] != i){
					swap(seq[0], seq[i]);
					tag = i;
					flag++;
					break;
				}
	}
	printf("%d\n", flag);
	return 0;
}
