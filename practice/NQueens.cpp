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

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
int n;
int cnt=0;
int col[1000];
int diag1[1000];
int diag2[1000];
void solve(int y){
	if(y==n){
		cnt++;
		return;
	}
	else{
		for(int x = 0;x < n; x++){
			if(diag1[x+y]||diag2[x-y+n-1]||col[x])
				continue;
			diag1[x+y] = 1;
			diag2[x-y+n-1] = 1;
			col[x] = 1;
			solve(y+1);
			diag1[x+y] = 0;
			diag2[x-y+n-1] = 0;
			col[x] = 0;
		}
	}	
		

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cnt=0;
	solve(0);
	cout<<cnt<<nl;
	return 0;
}




