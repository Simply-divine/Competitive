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
			if(b%2==1)ans*=a;
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
int gcd,x,y;
void extendedEuclid(int A,int B){
	if(B == 0){
		gcd = A;
		x = 1;
		y = 0;
		return;
	}
	extendedEuclid(B,A%B);
	//current value of x and y will be x1 and y1 in the equation
	int temp = x;
	x = y;
	y = temp - (A/B)*y;
}
int modInverse(int A,int M){
	extendedEuclid(A,M);
	return (x%M+M)%M;
}
//when M is prime
int modInversePrime(int A,int M){
	return power((ll)A,(ll)M - 2,(ll)M)%M;
}
void reverse(string& s){
	reverse(s.begin(),s.end());
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	extendedEuclid(16,10);
	cout<<"GCD "<<gcd<<nl;
	cout<<"Coefficients of x and y are "<<x<<" "<<y<<nl;
	cout<<"Mod inverse of 11 is "<<modInversePrime(12,5)<<nl;
	return 0;
}




