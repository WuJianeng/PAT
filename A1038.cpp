//2019 2.9 16:21
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a, string b){
	return a + b < b + a;
}
string num[10010];
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>num[i];
	sort(num, num + n, cmp);
	string res = "";
	for(int i = 0; i < n; ++i)
		res += num[i];
	while(res[0] == '0' && res.size() > 1)
		res.erase(res.begin());
	cout<<res<<endl;
	return 0;
}
