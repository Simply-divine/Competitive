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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		int x;
		cin>>x;
		int a[n];
		rep(i,0,n-1)cin>>a[i];
		sort(a,a+n);
		int ans = 1e9 + 1;
		rep(i,0,n-1){
			int curr;
			if(a[i]==x) curr =1;
			else if (a[i]>x) curr = 2;
			else {
				int k  = int(lower_bound(a,a+n,x - a[i]) - a);
				if(k < n && a[k]<=a[i]+x){
					curr = 2;
				}
				else{
					if(x%a[i]==0) curr = x/a[i];
					else 
					curr=x/a[i] + 1;
				}
			}
			ans = min(ans,curr);
		}
		cout<<ans<<nl;
	}
	return 0;
}




