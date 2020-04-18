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

vi prefix_function(string s){
	int n = s.length();
	vector<int> p(n);
	p[0] = 0;
	for(int i = 1; i < n; i++){
		int j = p[i - 1];
		while ( j > 0  && s[i]!=s[j]){
			j = p[j - 1];            // if current j is not the solution 	
		}
		if ( s[i] == s[j] ){
			j++;
		}
		p[i] = j;
	}
	return p; 
}

void reverse(string& s){
	reverse(s.begin(),s.end());
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int m = 0;m < t; m++){
		int n,k,p;
		cin>>n>>k>>p;
		int a[n][k];
		int pre[n][k];
		rep(i,0,n-1){
			rep(j,0,k-1){
				cin>>a[i][j];
				pre[i][j] = ((j>0)?pre[i][j-1]:0)+a[i][j];
				cout<<pre[i][j]<<" ";
			}
			cout<<nl;
		}
		int ans =0;
		if (n == 1){
			ans = pre[0][k-1];
		}else if (n == 2){
			if ( k>=2)
				ans = max(pre[0][k-2] + pre[1][0],pre[0][0] + pre[1][k-2]);
				
			ans = max(pre[0][k-1],ans);
			ans = max(pre[1][k-1],ans);
		}
		else if (n == 3){
			if(k>=3){
				// 1 1 k-2
				int sum1 = pre[0][0] + pre[1][0] + pre[2][k-3];
				// k-2 1 1
				int sum2 = pre[0][k-3] + pre[1][0] + pre[2][0];
				// 1 k-2 1
				int sum3 = pre[0][0] + pre[1][k-3] + pre[2][0];
				debug(sum1);
				debug(sum2);
				debug(sum3);
					ans = max(sum1,max(sum2,sum3));
			}
			int sum[6]={0};
			if(k>=2){
				// k-1 1 0
				sum[0] = pre[0][k-2] + pre[1][0];
				// 1 k-1 0
				sum[1] = pre[0][0] + pre[1][k-2];
				// k-1 0 1
				sum[2] = pre[0][k-2] + pre[2][0];
				// 1 0 k-1
				sum[3] = pre[0][0] + pre[2][k-2]; 
				// 0 k-1 1
				sum[4] = pre[1][k-2] + pre[2][k-2];
					// 0 1 k-1
					sum[5] = pre[1][0] + pre[2][k-2];
				sort(sum,sum+6,greater<int>());
				ans = max(ans,sum[0]);
			}
			// k 0 0
			ans = max(ans,pre[0][k-1]);	
			// 0 0 k
			ans = max(ans,pre[2][k-1]);
			// 0 k 0
			ans = max(ans,pre[1][k-1]);
		}
		else {

		}
		cout<<"Case #"<<(m+1)<<": "<<ans<<nl;
	}
	return 0;
}




