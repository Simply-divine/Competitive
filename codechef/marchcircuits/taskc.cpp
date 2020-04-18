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
int n,q;
int maxUpto[1e5+1];
int maxAfter[1e5+1];
void reverse(string& s){
	reverse(s.begin(),s.end());
}
struct data{
	int pre,suff,sum,ans;
}

data combine(int l, int r){
	data res;
	res.sum = l.sum + r.sum;
	res.pre = l.pre;
	res.suff = r.suff;
	res.ans = max(res.sum + l.pre,max(res.sum,res.sum+r.suff));
	return res;
}
data make_data(int val,int pos){
	data res;
	res.sum = val;
	res.pre = maxUpto[pos];
	res.suff = maxAfter[pos];
}	
void 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		cin>>n>>q;
		int a[n];
		rep(i,0,n-1){
			cin>>a[i];
			maxUpto[i] = 0;
			maxAfter[i] = 0;
		}
		maxUpto[0] = 0;
		rep(i,1,n-1){
			maxUpto[i] = max(maxUpto[i-1]+a[i-1],a[i-1]);
		}
		maxAfter[n-1] = 0;
		for(int i = n-2; i>=0 ; i--){
			maxAfter[i] = max(maxAfter[i+1]+a[i+1],a[i+1]);
		}
		while(q-->0){
			int q1,q2,q3;
			cin>>q1>>q2>>q3;
			
				
		}
	}
	return 0;
}




