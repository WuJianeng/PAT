//2019 2.13 22:09 forked from Qingshen Notes
#include<iostream>
#include<cstring>
using namespace std;
int n;
string deal(string s, int &e){
	int k = 0;
	while(s.size() > 0 && s[0] == '0')
		s.erase(s.begin() );
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s.size() > 0 && s[0] == '0'){
			e--;
			s.erase(s.begin());
		}
	}
	else{
		while(k < s.size() && s[k] != '.'){
			e++;
			k++;
		}
		if(k < s.size()) s.erase(s.begin() + k);
	}	
	if(s.size() == 0) e = 0;
	string str;
	str = "0.";
	int i;
	for(i = 0; i < n && i <s.size(); ++i)
		str += s[i];
	if(i < n)
		for(; i < n; ++i)
			str += '0';
	return str;
}
int main(){
	string s1, s2, s3, s4;
	int e1 = 0, e2 = 0;
	cin>> n>> s1>> s2;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if(s3 == s4 && e1 == e2) cout<<"YES "<<s3<<"*10^"<<e1<<endl;
	else cout<<"NO "<<s3<<"*10^"<<e1<<" "<<s4<<"*10^"<<e2<<endl;
	return 0;
}
