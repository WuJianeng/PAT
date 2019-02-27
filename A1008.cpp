#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
bool tag[101] = {false};
// 2019.1.18 10:30
using namespace std;

int main(){
	int K,sum = 0;
	int seq[100];
	scanf("%d",&K);
	for(int i = 0;i < K; i++){
		scanf("%d",&seq[i]);
		//tag[seq[i]] = true;
	}
	int stop = 0;
	for(int i = 0; i < K; ++i){
			if(seq[i] > stop) sum += (seq[i] - stop) * 6 + 5;
			else sum += (stop - seq[i]) * 4 + 5;
			stop = seq[i];
	}
	cout<<sum<<endl;
	return 0;
}

