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
// #define sq(a) (a)*(a)
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

ll sq(ll x){
	return (x)*(x);
}
ll f(ll x1,ll x2,ll x3){
	return sq(x1 - x2) + sq(x1 - x3) + sq(x2 - x3);
}
ll solve(vector<ll> a, vector<ll> b, vector<ll> c){
	ll mn = 9e18;
	for(auto x: a){
		auto it1 = lower_bound(b.begin(),b.end(),x);
		if(it1 == b.end())continue;
		auto it2 = upper_bound(c.begin(),c.end(),x);
		if(it2 == c.begin())continue;
		it2--;
		mn = min(mn,f(x,*it1,*it2));
	}
	return mn;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		vi n(3);
		cin>>n[0]>>n[1]>>n[2];
		vector<vector<ll>> a(3);
		rep(i,0,2){
			a[i].resize(n[i]);
			for(int j = 0; j < n[i]; j++){
				cin>>a[i][j];
			}
			sort(a[i].begin(),a[i].end());
		}
		vector<int> per(3);
		iota(per.begin(),per.end(),0);
		ll mn = 9e18;
		do{
			// debug(per[0]);
			// debug(per[1]);
			// debug(per[2]);		
			// debug(nl);
			mn = min(mn ,solve(a[per[0]],a[per[1]],a[per[2]]));
		}while(next_permutation(per.begin(),per.end()));
		cout<<mn<<nl;
	}

	return 0;
}
