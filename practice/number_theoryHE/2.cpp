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

ll add(ll a,ll b,ll mod){
	return (a%mod+b%mod)%mod;
}
ll sub(ll a,ll b,ll mod){
	return (a%mod-b%mod+mod)%mod;
}
ll mul(ll a,ll b,ll mod){
	return ((a%mod)*(b%mod))%mod;
}
ll power(ll a, ll b,ll mod){
	ll ans = 1;
	while(b>0){
		if(b%2==1)ans=mul(ans,a,mod);
		a = mul(a,a,mod);
		b/=2;
	}
	return ans;
}
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

int gcd,x,y;
void extendedEuclid(int A,int B){
	if(B==0){
		gcd = A;
		x = 1;
		y = 0;
	}
	else{
		extendedEuclid(B,A%B);
		int temp = x;
		x = y;
		y = temp - (A/B)*y;
	}
}
ll modularInverse(ll A,ll M){
	extendedEuclid(A,M);
	return (x%M+M)%M;
}
//if M is prime 
//Fermat's theorem mod-1 ==> A^(M-2)
ll modularInversePrime(ll A,ll M){
	return power(A,M-2,M);
}
ll div(ll a,ll b,ll mod){
	return ((a%mod)*(modularInverse(b,mod)%mod))%mod;
}
int main()
{
	#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
	#endif 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	int n;
	cin>>n;
	int a[n];
	int cnt[200005] = {0};
	rep(i,0,n-1){
		cin>>a[i];
		for(int j = 1; j*j<= a[i]; j++){
			if(a[i]%j==0){
				cnt[j]++;
				if(j!=(a[i]/j)){
					cnt[(a[i]/j)]++;
				}
			}
		}
	}
	cin>>q;
	while(q-->0){
		ll p,q;
		cin>>p>>q;
		if(p!=q){
		cout<<cnt[p] + cnt[q] - cnt[p*q]<<nl;
		}
		else cout<<cnt[p]<<nl;
	}
	return 0;
}
