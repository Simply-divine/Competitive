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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i,0,n-1)cin>>a[i];
	int k;
	int first[1000];
	cin>>k;
	REP(i,0,n-1){
		ready[i] = false;	
	}
	//int ans = solve(k);
	value[0] = 0;
	for(int x = 1; x<=k;x++){
		value[x] = INF;
		REP(i,0,n-1)
		if(x-a[i]>=0&&value[x]>value[x-a[i]]+1){
			value[x] =value[x-a[i]]+1;
			first[x] =a[i];
		}	
	}
	cout<<value[k]<<nl;
	while(k>0){
		cout<<first[k]<<" ";
		k-=first[k];
	}
	return 0;
}







