//2019/4/24 19:12
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	if(n % 2 == 0){
		cout<<"0 ";
	}
	else cout<<"1 ";
	int place = n / 2;
	long low = 0, high = 0;
	int i;
	for(i = 0; i < place; ++i){
		low += v[i];
	}
	for( ; i < v.size(); ++i){
		high += v[i];
	}
	cout<<high - low<<endl;
	return 0;	
}
