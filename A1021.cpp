//2019/2/24 21:20
 #include<iostream>
 #include<set>
 #include<vector>
 using namespace std;
 int n;
 vector<int> node[10005];
 bool vis[10005] = {false};
 int dfs(int s){
 	int max = 0;
 	vis[s] = true;
 	for(int i = 0; i < node[s].size(); ++i){
 		if(vis[node[s][i]] == false){
 			int dep = dfs(node[s][i]);
 			if(dep > max) max = dep;
		 }
	 }
	 return max + 1;
 }
 void DFS(){
	int dep[10005] = {0};
	for(int i = 1; i <= n; ++i){
		fill(vis + 1, vis + n + 1, false);
		dep[i] = dfs(i);
	}
	int max_dep = 0;
	for(int i = 1; i <= n; ++i){
		if(dep[i] > max_dep)
			max_dep = dep[i];
	}
	set<int> s;
	for(int i = 1; i <= n; ++i)
		if(dep[i] == max_dep) s.insert(i);
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
		cout<<*it<<endl;
 }
 bool verify(){
 	for(int i = 1; i <= n; ++i)
 		if(vis[i] == false) return false;
 	return true;
 }
 void Fun(){
 	fill(vis + 1, vis + n + 1, false);
 	dfs(1);
 	int flag = verify();
 	if(flag)
 		DFS();
	else{
	 	int num = 0;
	 	fill(vis + 1, vis + n + 1, false);
	 	while(!verify()){
	 		num++;
	 		for(int i = 1; i <= n; ++i){
	 			if(vis[i] == false){
	 				dfs(i);
	 				break;
				 }
			 }
		 }
		 cout<<"Error: "<<num<<" components"<<endl;
	 }
 }
 int main(){
 	cin>>n;
 	for(int i = 1; i < n; ++i){
 		int start, end;
 		cin>>start>>end;
 		node[start].push_back(end);
 		node[end].push_back(start);
	 }
	 Fun();
	 return 0;
 }
