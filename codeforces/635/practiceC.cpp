// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a ; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int MAXN = 100005;
ll mod=1000000007;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vi a(n);
		rep(i,0,n-1)cin>>a[i],a[i]--;
		int M = 200;
		vector<vi> pre(M,vi(n+1,0));
		vector<vi> at(M); 
		rep(i,0,M - 1){
			rep(j,0,n-1) {
				pre[i][j + 1] = pre[i][j] + (a[j]==i);
				if(a[j] == i){
					at[i].push_back(j);
				}
			}
		}
		int ans = 0;
		// aaaab      baaaa
		rep(i,0,M - 1) ans = max(ans,pre[i][n]);
		for(int i = 0; i < M; i++){
			// mark the left half and the right half

			int p = at[i].size();
			for(int k = 1; 2*k <= p; i++){
				int from = at[i][k - 1]; //(k - 1)st index of at[i]  = 3 and I want pre 
				int to = at[i][p - k];  // p - k 7 - 6 = 1
				for(int j = 0; j < M; j++){
					ans = max(ans, pre[j][to] - pre[j][from] + 2*k);
				}
			}
		}
		cout<<ans<<nl;
	}
	return 0;
}
