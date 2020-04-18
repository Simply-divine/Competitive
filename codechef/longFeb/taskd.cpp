#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MAXN 100005
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
ll mod=1000000009;
int t[4*MAXN],n;
void build(int a[],int v,int tl,int tr){
	if( tl == tr) t[v] = a[tl];
	else{
		int tm = (tl + tr)/2;
		build(a,2*v,tl,tm);
		build(a,2*v+1,tm+1,tr);
		t[v] = min(t[2*v],t[2*v+1]);
	}
}

int min(int v,int tl,int tr,int l,int r){
	if(l > r){
		return INF - 1;
	}	
	if(l == tl && r == tr)
		return t[v];
	else{
		int tm = (tl + tr)/2;
		return min(min(2*v,tl,tm,l,min(tm,r)),min(2*v+1,tm+1,tr,max(tm+1,l),r));
	}
}

void update(int v,int tl,int tr,int pos,int new_val){
	if(tl == tr){
		t[v] = new_val;
	}
	else{
		int tm = (tl + tr)/2;
		if(pos<=tm)
			update(2*v,tl,tm,pos,new_val);
		else update(2*v+1,tl,tm,pos,new_val);
		t[v] = min(t[2*v],t[2*v+1]);
	}
}
void solve(){
	ll n,p;
	cin>>n>>p;
	ll d[n];
	ll ind = -1;
	map<ll,ll> mp;
	rep(i,0,n-1){
		cin>>d[i];
		if(p%d[i] !=0){
			ind = i;	
		}
		mp.insert(MP(d[i],i));
	}
	if(ind!=-1){
		cout<<"YES ";
		rep(i,0,n-1){
			if(i!=ind)cout<<"0 ";
			else cout<< (ll)(p/d[i]+1)<<" ";
		}
		cout<<nl;
	}
	else{
		ll ans;
		rep(i,1,n-1){
			if((d[i]%d[i-1]) != 0){
				int x = p - d[i];
				ans = (ll)(x/d[i-1]+1);
			       	ind = i - 1;			
			}
		}
		if(ind==-1){
			cout<<"NO"<<nl;
		}
		else{
			cout<<"YES ";
			rep(i,0,n-1){
				if(i==ind){
					cout<<ans<<" "<<"1 ";
					i++;
				}
				else cout<<"0 ";
			}
			cout<<nl;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		solve();
	}
	return 0;
}




