//2019/3/6 14:27
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<double> st;
	for(int i = 0; i < n; ++i){
		int temp;
		cin>>temp;
		st.push_back(temp);
	}
	sort(st.begin(), st.end());
	while(st.size() > 1){
		double res = (st[0] + st[1]) / 2.0;
		st.erase(st.begin());
		st.erase(st.begin());
		vector<double>::iterator it;
		for(it = st.begin(); it != st.end(); ++it)
			if(*it >= res) break;
		st.insert(it, res);
	}
	int res = floor(st[0]);
	cout<<res<<endl;
	return 0;
}
