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
int a[100001];
int table[100001];
int size;
int sum(int index){
	int sum=0;
	if(index<=0) return 0;
	while(index>0){
		sum+=table[index];
		index-=(index&(-index));		
	}
	return sum;
}
int update(int index,int delta){
	while( index < size){
		table[index] += delta;
		index+=(index&(-index));
	}
}
int sum(int left,int right){
	return sum(right) - sum(left-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i,1,n) cin>>a[i];
	REP(i,1,n){
		btree[i] = sumq( i - p(i) + 1,i); // p(i) length ka sum ending at i
	}
	int t;
	cin>>t;
	while(t-->0){
		int i,j,k;
		cin>>i>>j>>k;
		// if i = 0 he to sum karne he
		//else hame update karna he
		if(i==0) cout<< sump(k) - sump(j- 1)<<nl;
		else add(j,k);
	}
	return 0;
}




