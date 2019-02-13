//2019 2.13 23:13
#include<iostream>
#include<map>
#include<string>
using namespace std;
bool check(char &c){
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z'){
		c = c - 'A' + 'a';
		return true;
	}
	return false;
}
int main(){
	string str;
	map<string, int> mp;
	getline(cin, str);
	int i = 0;
	while(i < str.size()){
		string word;
		while(i < str.size() && check(str[i])){
			word += str[i];
			i++;
		}
		if(word != "")	
			if(mp.find(word) == mp.end()) mp[word] = 1;
			else mp[word]++;
		if(i < str.size()) i++;
	}
	string fir;
	int sec = 0;
	map<string, int>::iterator it;
	for(it = mp.begin(); it != mp.end(); it++)
		if(it->second > sec){
			fir = it->first;
			sec = it->second;
		}
	cout<<fir<<" "<<mp[fir]<<endl;
	return 0;
}
