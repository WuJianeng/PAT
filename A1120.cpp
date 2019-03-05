//2019/3/5 19:45
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
using namespace std;
const int maxn = 10050;
int tran(string str){
	int len = str.length();
	int sum = 0;
	for(int i = 0; i < len; ++i)
		sum += str[i] - '0';
	return sum;
}
int main(){
	int n;
	scanf("%d", &n);
	set<int> st;
	for(int i = 0; i < n; ++i){
		string str;
		cin>>str;
		int sum = tran(str);
		st.insert(sum);
	}
	printf("%d\n", st.size());
	for(set<int>::iterator it = st.begin(); it != st.end(); ++it){
		if(it != st.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n");
	return 0;
}
