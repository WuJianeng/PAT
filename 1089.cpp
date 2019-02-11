//2019.2.11 14:03 forked from liuchuo/github
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a = new int [n];
	int *b = new int [n];
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	for(int i = 0; i < n; ++i)
		cin>>b[i];
	//judge
	int i, j;
	for(i = 0; i < n-1 && b[i] <= b[i+1]; ++i);
	for(j = i + 1; j < n && a[j] == b[j]; ++j);
	if(j == n){
		cout<<"Insertion Sort"<<endl;
		sort(a, a + i + 2);
	}
	else{
		cout<<"Merge Sort"<<endl;
		//对数组进行Merge sort，每排序一次进行判断，看是否一致，
		//若一致说明归并排序次数已经是当前次数了，只需再排序一次即可  copy from liuchuo
		int k = 1, flag = 1;
		while(flag){
			flag = 0;
			for(i = 0; i < n; ++i)
				if(b[i] != a[i]) flag = 1;
			k *= 2;
			for(i = 0; i < n / k; ++i)
				sort(a + i * k, a + (i + 1) * k);
			sort(a + n / k * k, a + n);
		}	
	}
	for(i = 0; i < n; ++i)
		if(i == 0) cout<<a[i];
		else cout<<" "<<a[i];
	cout<<endl;
	delete [] a;
	delete [] b;
	return 0;
}
