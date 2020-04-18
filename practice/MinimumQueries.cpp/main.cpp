#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n"
#define INF std::numeric_limits<int>::max()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll mod=1000000009;
ll n;
const ll MAXN = 100001;
ll a[MAXN];
const int K = 25;
int st[MAXN][K]; 

void precalc(ll N){
	for(ll i = 0; i < N ; i++){
		for(ll j = 1; j <= K ; j++){
			st[i][j] = INF - 1;
		}
	}
	for(ll i = 0; i < N; i++){
		st[i][0] = a[i];
	}
	for(ll j = 1 ; j <= K ; j++){
		for(ll i = 0; i +(1<<j)<=N;i++){
			st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(ll j = 1; j <= K; j++){
		for(ll i = 0; i + (1<<j)<=N;i++){
			cout<<st[i][j]<<" ";
		}
		cout<<nl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i,0,n-1){
		cin>>a[i];
	}
	precalc(n);
	int t;
	cin>>t; 
	while(t-->0){
		ll l,r;
		cin>>l>>r;
		ll i;
		for(i = 0; (1<<i)<= (r - l +1);i++);
		i--;
		ll ans = min(st[l][i],st[r - (1<<i)+1][i]);
		cout<<ans;
	}
	return 0;
}


