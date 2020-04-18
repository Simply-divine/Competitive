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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	REP(i,0,n-1) cin>>a[i];
	int sum;
	cin>>sum;
	sort(a.begin(),a.end());
	int f = 1;
	int cnt = 0;
	REP(i,0,n-1){
		int l = i+1;
		int r = a.size()-1;
		f = 1;
		while(l<r){
			if(a[i]+a[l]+a[r]==sum){
				f = 0;
				break;
			}
			else if(a[i]+a[l]+a[r]>sum){
				r--;
			}
			else l++;
		}
		if(f==0){
			cnt++;
		}
	}
	cout<<cnt<<nl;
	return 0;
}




