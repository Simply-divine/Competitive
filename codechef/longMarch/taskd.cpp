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
const int maxn = 100001;
int cnt = 0;
int t[4*maxn];
int m[4*maxn];
void build ( int tl,int tr,int v,int a){
	if ( tl == tr){
		t[v] = a[tl];
		if(( a[tl] >= 0 && a[tl+1]<=0)||(a[tl]<=0&&a[tk+1]>=0)){
			m[v] = 1;
		}
		else m[v] = 0;
	}
	else{
		int tm = tl + (tr - tl)/2;
		build(tl,tm,2*v,a);
		build(tm+1,tr,2*v+1,a);
		t[v] = 0;
		m[v] = 0;
	}
}
void push(int v){
	t[2*v] = t[2*v+1] = t[v];
	t[v] = 0;
}
void update(int tl,int tr,int l,int r ,int new_val){
	if( l > r) return;
	if(tl == l && tr == r){
		t[v] -= new_val;
	}
	else{
		int tm  = tl + (tr - tl)/2;
		push(v);
		update(tl,tm,l,min(r,tm),new_val);
		update(tm+1,tr,max(l,tm+1),r,new_val);
	}
}

int sum(int tl,int tr,int l,int r,int v){
	if( l > r) return 0;
	if(tl == l && tr == r){
		t[v] = 
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n,q;
		cin>>n>>q;
		int a[n];
		int mx = 0;
		rep(i,0,n-1){
			cin>>a[i];
		}
		while(q-->0){
			int x1,x2,y;
			cin>>x1>>x2>>y;
			x1--;
			x2--;
			sum ( x1 , x2, y );
		}
			
	}
	return 0;
}

