//2019.02.04
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){
	int n,len;
	cin>>n;
	getchar();
	string s;
	for(int i = 0; i < n; ++i){
		string temp;
		getline(cin,temp);
		reverse(temp.begin(),temp.end());
		if(i == 0){
			s = temp;
			len = s.length();
		}
		else{
			if(len > temp.length() ) len = temp.length();
			for(int j = 0; j < len; j++){
				if(s[j] != temp[j] ){
					len = j;
					break;
				}
			}
		}	
	}
	s = s.substr(0,len);
	reverse(s.begin(),s.end());
	if(s.length()) cout<<s<<endl;
	else cout<<"nai"<<endl;
	return 0;
}
