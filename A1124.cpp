//2019/3/6 14:27
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
	int m, skip, first;
	vector<string> v;
	set<string> st;
	cin>>m>>skip>>first;
	int temp = skip;
	bool flag = false;
	for(int i = 1; i <= m; ++i){
		string str;
		flag = false;
		cin>>str;
		if(i >= first) flag = true;
		if(flag == false) continue;
		if(temp % skip == 0 && st.find(str) == st.end()){
			cout<<str<<endl;
			st.insert(str);
		}
		else if(temp % skip == 0 && st.find(str) != st.end())
			temp--;
		temp++;
	}
	if(flag == false) cout<<"Keep going..."<<endl;
	return 0;
}
