//2019.2.16 16:27
#include<iostream>
#include<vector>
using namespace std;
int post[1010], s[1010];
bool preToPost(int s[], int post[], int pre_first, int pre_end, int post_first, int post_end, int flag){
	if(pre_first > pre_end) return true;
	int root = s[pre_first];
	post[post_end] = root;
	int mid;
	for(mid = pre_first + 1; mid <= pre_end; mid++)
		if(flag == 0 && s[mid] >= root || flag && s[mid] < root) break;
	int left_num = mid - pre_first - 1;
	for(int i = mid + 1; i <= pre_end; ++i)
		if(flag == 0 && s[i] < root || flag && s[i] >= root) return false;
	bool tag1 = preToPost(s, post, pre_first + 1, mid - 1, post_first, post_first + left_num - 1, flag);
	bool tag2 = preToPost(s, post, mid, pre_end, post_first + left_num, post_end - 1, flag);
	if(tag1 && tag2) return true;
	else return false;
}
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>s[i];
	bool tag = preToPost(s, post, 0, n - 1, 0, n - 1, 0);
	if(tag == false){
		bool tag1 = preToPost(s, post, 0, n - 1, 0, n - 1, 1);
		tag = tag1;
	}	
	if(tag){
		cout<<"YES"<<endl;
		for(int i = 0; i < n; ++i){
			if(i) cout<<" ";
			cout<<post[i];
		}
		cout<<endl;
	}		
	else cout<<"NO\n";
	return 0;
}
