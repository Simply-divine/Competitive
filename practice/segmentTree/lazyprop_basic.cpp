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
int t[4*MAXN],n;
// v - > 2*v and 2*v + 1
// update and get
//node -> tl,tr [1 1]  [1 2]  
void build( int a[], int tl, int tr , int v ){
	if ( tl == tr ) t[v] = a[tl];
	else {
		int tm = tl + ( tr - tl )/2;
		build( a, tl , tm , 2*v);
		build( a, tm + 1, tr , 2*v + 1);
		t[v] = 0;
	}
}

void update( int tl, int tr, int l , int r , int v,int new_val){
	if ( l > r) return ;
	if ( l == tl && r == tr ) t[v] += new_val;
	else{
		int tm = tl + ( tr - tl ) /2;
	       	update(tl,tm,l,min(r,tm),2*v,new_val);
		update(tm+1,tr,max(l,tm+1),r,2*v+1,new_val);
	}
}
int get ( int pos , int tl , int tr , int v){
	if ( tl == tr && tl == pos) { return t[v];}
	else {
		int tm = tl + (tr - tl )/2;
		if ( pos <= tm) return t[v] + get(pos,tl,tm,2*v);
		else return t[v] + get(pos,tm+1,tr,2*v+1);
	}
}	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n = 6;
	int a[] = { 1, 3,5 ,7, 2 ,4};
	build(a,0,n-1,1);
	update(0,n-1,2,5,1,2);
	cout<<get(3,0,n-1,1);
	return 0;
}




