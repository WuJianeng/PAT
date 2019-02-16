//2019.2.16 17:55
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n, seq[maxn], s[maxn], index = 0;
void CBT(int root){
	if(root > n) return ;
	CBT(root * 2);
	s[root] = seq[index++];
	CBT(root * 2 + 1);	
}
int main(){
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>seq[i];
	sort(seq, seq + n);
	CBT(1);
	for(int i = 1; i <= n; ++i){
		if(i != 1) cout<<" ";
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}
