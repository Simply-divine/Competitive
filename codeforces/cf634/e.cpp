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
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
			--a[i];
		}
		const int M = 200;
		vector<vector<int>> pref(M,vector<int>(n+1));
		vector<vector<int>> at(M);
		for(int i = 0; i < M; i++){
			for(int j = 0; j < n; j++){
				pref[i][j+1] = pref[i][j] + (a[j]==i);
				if(a[j] == i){
					at[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < M; i++){
			int u = pref[i][n];
			ans = max(ans,u);
			for(int c = 1; 2*c <= u; c++){
				int from = at[i][c-1];
				int to = at[i][u - c];
				for(int j = 0; j < M; j++){
					if(i!=j){
						ans = max(ans, 2*c + pref[j][to] - pref[j][from]);
					}
				}
			}
		}
		cout<<ans<<nl;
	}
	return 0;
}
