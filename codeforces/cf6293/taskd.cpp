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
void solve(){
	int n;
	cin>>n;
	int a[n];
	map<int,int> mp;
	int cnt=1;
	bool check = false;
	rep(i,0,n-1)
	{
		cin>>a[i];
		if(i&&a[i]!=a[i-1]){
			cnt++;
		}
		else{
			if(i){
				check = true;
			}
		}
	}
	if(cnt%2==0&&check){
		check = false;
	}
	bool done = false;

	if (cnt>1){
		if(cnt%2==0 || check)
			cout<<"2"<<nl;
		else cout<<"3"<<nl;
		int k = 1;
		for(int i = 0; i < n - 1;i++){
			int temp = a[i];
			cout<<k<<" ";
			if(check && a[i+1] == a[i]){
				if(k==1)k=2;
				else k = 1;
				check = false;
				done = true;
			}
			else if (a[i+1] != a[i]){
				if(k==1)k=2;
				else k = 1;
			}
		}
		if (cnt%2==0||done) cout<<k<<nl;
		else cout<<3<<nl;
	}
	else {
		cout<<1<<nl;
		for(int i = 0; i < n;i++)
			cout<<1<<" ";
		cout<<nl;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>q;
	while(q-->0){
		solve();
	}
	return 0;
}




