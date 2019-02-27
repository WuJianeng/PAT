#include<iostream>
#include<vector>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<string> ve;
	for(int i = 0; i < N; ++i){
		string name,pass;
		cin>> name >> pass;
		int flag = 0, len = pass.length();
		for(int j = 0; j < len; j++){
			switch (pass[j]){
				case '1': pass[j] = '@'; flag = 1; break;
				case '0': pass[j] = '%'; flag = 1; break;
				case 'l': pass[j] = 'L'; flag = 1; break;
				case 'O': pass[j] = 'o'; flag = 1; break;
			}
		}
		if(flag){
				string temp = name + " " + pass;
				ve.push_back(temp);
		}
	}
	int n = ve.size();
	if(n != 0){
		cout<<n<<endl;
		for(int i = 0; i < n; ++i){
			cout<<ve[i]<<endl;
		}
	}else if(N == 1){
		cout<<"There is 1 account and no account is modified"<<endl;
	}else  cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
	return 0;
}
