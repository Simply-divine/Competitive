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
	int n,k;
	cin>>n>>k;
	int a[n];
	int pre[n],suff[n];
	int count[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(i!=0){
			pre[i] = pre[i-1]+a[i]%k;
			count[i] = count[i-1]+a[i]/k;
		}
		else {
			pre[i] = a[i]%k;
			count[i] = a[i]/k;
		}
	}
	if(a[n-1]%k==0)
	suff[n-1] = 0;
	else suff[n-1] = k - a[n-1]%k;
	for(int i = n-2; i >=0; i--){
		if(a[i]%k==0)
		suff[i] = suff[i+1];
		else suff[i]= suff[i+1]+k - a[i]%k;
	}
	int mn = 1e9+1,ans;
	for(int i = 0; i < n - 1; i++){

		if(count[i]*k+pre[i]>suff[i+1]){
			int req = suff[i+1] - pre[i];
			if(req < 0){
				ans = pre[i] - suff[i+1];
			}
			else {
				int togo = (req/k);
				ans = (togo+1)*k - req;
			}
			mn = min(mn,ans);
		}
	}	
	mn = min(mn,pre[n-1]);
	cout<<mn<<nl;

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




