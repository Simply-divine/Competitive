#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n";
#define INF 10000;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
int n;
//bool ready[n];
//int value[n];
bool ready[1000];
int value[1000];
int a[1000];

int solve(int x){
	int best=INF;
	if(x<0)	return INF;
	if(x==0)return 0;
	if(ready[x])return value[x];
	else{
		for(int i = 0; i < n; i++){
			best = min(best,solve(x-a[i])+1);	
		}
		value[x] = best;
		ready[x] = true;
		return best;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i,0,n-1)cin>>a[i];
	int k;
	cin>>k;
	REP(i,0,n-1){
		ready[i] = false;	
	}
	int ans = solve(k);
	cout<<ans;
	return 0;
}




