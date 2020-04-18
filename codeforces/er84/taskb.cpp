#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define SQ(a) (a)*(a)
#define nl "\n"
#define INF std::numeric_limits<int>::max()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MAXN = 100005;
ll mod=1000000007;

vi prefix_function(string s){
	int n = s.length();
	vector<int> p(n);
	p[0] = 0;
	for(int i = 1; i < n; i++){
		int j = p[i - 1];
		while ( j > 0  && s[i]!=s[j]){
			j = p[j - 1];            // if current j is not the solution 	
		}
		if ( s[i] == s[j] ){
			j++;
		}
		p[i] = j;
	}
	return p; 
}

void reverse(string& s){
	reverse(s.begin(),s.end());
}
void solve(){
		int n;
		cin>>n;
		set<int> princes[n];
		bool vis[(int)1e5+1] = {false};
		int notvisited = -1;
		int c=0;
		rep(i,0,n-1){
			int k;
			cin>>k;
			int v[k];
			rep(j,0,k-1){ 
				cin>>v[j];
				princes[i].insert(v[j]);
			}
			int j = 0;
			while(j < k && vis[v[j]]){
				j++;
			}
			if(j < k&&!vis[v[j]]){
				vis[v[j]] = true;
				c++;
			}
			else{
				notvisited =i;
			}
		}
		bool check = true;
		for(int i = 1; i <= n;i++){
			if(!vis[i]&&notvisited!=-1&&(princes[notvisited].find(i)==princes[notvisited].end())){
				cout<<"IMPROVE"<<nl;
				cout<<(notvisited+1)<<" "<<i<<nl;
				return;
			}
		}
		cout<<"OPTIMAL"<<nl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		solve();
	}
	return 0;
}




