//2019 2.16 22:03
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 105;
bool verify(int init[], int seq[], int n){
	for(int i = 1; i <= n; ++i)
		if(init[i] != seq[i]) return false;
	return true;
}
void InsertionSort(int init[], int seq[], int n){
	for(int i = 2; i <= n; ++i){
		sort(init + 1, init + i + 1);
		if(verify(init, seq, n)){
			cout<<"Insertion Sort"<<endl;
			sort(init + 1, init + i + 2);
			for(int i = 1; i <= n; ++i){
				if(i != 1) cout<<" ";
				cout<<init[i];
			}
			cout<<endl;
			return ;
		}
	}
}
void adjust(int s[], int k, int n){
	int i = k, j = k * 2;
	while(j <= n){
		if(j + 1 <= n && s[j] < s[j + 1]) j++;
		if(s[i] < s[j]){
			swap(s[i], s[j]);
			i = j;
			j = j * 2;
		}
		else break;
	}
}
void HeapSort(int init[], int seq[], int n){
	for(int k = n / 2; k >= 1; k--)
		adjust(init, k, n);
	bool flag = false;
	for(int i = n; i > 1; --i){
		flag = verify(init, seq, n);
		swap(init[1], init[i]);
		adjust(init, 1, i - 1);		
		if(flag){
			cout<<"Heap Sort\n";
			for(int i = 1; i <= n; ++i){
				if(i != 1) cout<<" ";
				cout<<init[i];
			}
			cout<<endl;
			return ;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int init[maxn], init1[maxn], seq[maxn];
	for(int i = 1; i <= n; ++i){
		cin>>init[i];
		init1[i] = init[i];
	} 
	for(int i = 1; i <= n; ++i) cin>>seq[i];
	InsertionSort(init1, seq, n);
	HeapSort(init, seq, n);
	return 0;
}
