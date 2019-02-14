//2019 2.14 10:18
#include<cstdio>
#include<stack>
using namespace std;
stack<int> st;
int seq[1010];
int main(){
	int size, n, k;
	scanf("%d %d %d", &size, &n, &k);
	for(int i = 0; i < k; ++i){
		for(int i = 1; i <= n; ++i)
			scanf("%d", &seq[i]);
		int  j = 1;
		while(st.size() != 0) st.pop();
		for(int num = 1; num <= n && st.size() <= size; ++num){
			st.push(num);
			if(st.size() > size) break;
			while(!st.empty() && st.top() == seq[j]){
				st.pop();
				j++;
			}
		
		}
		if(j == n + 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
