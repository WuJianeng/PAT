//2019 4/30 
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
vector<int> v;
const int maxn = 10050;
int s[maxn][maxn];
int m, n, N;
void insert(int &left, int &right, int &down, int &top, int &fir){
	for(int j = left; j <= right; ++j){
		s[top][j] = v[fir];
		fir++;
		if(fir == N) return;
	}
	top++;
	
	for(int i = top; i <= down; ++i){
		s[i][right] = v[fir];
		fir++;
		if(fir == N) return;
	}
	right--;
	
	for(int j = right; j >= left; --j){
		s[down][j] = v[fir];
		fir++;
		if(fir == N) return;
	}
	down--;
	
	for(int i = down; i >= top; i--){
		s[i][left] = v[fir];
		fir++;
		if(fir == N) return;
	}
	left++;
}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	int sqr;
	sqr = (int)ceil( sqrt(N) );
	for(m = sqr; m <= N; ++m){
		if(N % m == 0) break;
	}
	n = N / m;
	sort(v.begin(), v.end(), greater<int>());
	//insert
	int left = 0, right = n - 1, top = 0, dowm = m - 1, fir = 0;
	while(fir != N){
		insert(left, right, dowm, top, fir);
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(j) printf(" ");
			printf("%d", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
