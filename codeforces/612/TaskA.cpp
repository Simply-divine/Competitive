#include<cstdio>
#include<vector>
#include<queue>
#include<list>
#include<sstream>
#include<algorithm>
#include<iostream>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
	int n,k;
	cin>>n>>k;
        char s[n][k];
       // char s1[k][n];
        for (int i = 0; i < n; i++) {
            for(int j = 0; j<k;j++)
		    cin>>s[i][j];
        }
        vector<int> li1[k];
        vector<int> li2[k];
        vector<int> li3[k];
      

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {

                if(s[i][j]=='S')
                    li1[j].PB(i);
                else if(s[i][j]=='E')
                    li2[j].PB(i);
                else li3[j].PB(i);
            }
        }
        bool check[n][k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <n ; j++) {
                for (int l = j+1; l < n; l++) {
                    if(s[j][i]==s[l][i]){
                        if(s[j][i]=='S'){
//                            System.out.println(s[j][i]+" "+s[l][i]+" "+j+" "+l+check[n-1][k-1]);
                            for(int m:li1[i]){
                                if(m>=l+1)
                                check[m][i] = 1;

                            }
                        }
                        else if(s[j][i]=='E'){
//                            System.out.println(s[j][i]+" "+s[l][i]+" "+j+" "+l+check[n-1][k-1]);
                            for(int m:li2[i]){
                                if(m>=l+1) {
                                    check[m][i] = 1;
                                }
                            }
                        }
                        else if(s[j][i]=='T'){
//                            System.out.println(s[j][i]+" "+s[l][i]+" "+j+" "+l+check[n-1][k-1]);
                            for(int m:li3[i]){

                                if(m>=l+1)
                                check[m][i] = 1;
                            }
                        }
                    }
                    else{
                        if(s[j][i]+s[l][i]==('S'+'E')){
//                            System.out.println(s[j][i]+" "+s[l][i]+" "+j+" "+l+check[n-1][k-1]);
                            for(int m:li3[i]){
                                if(m>=l+1)
                                check[m][i] = 1;
//                                System.out.println("fir"+m);
                            }
                        }
                        else if(s[j][i]+s[l][i]==('S'+'T')){
//                            System.out.println(s[j][i]+" "+s[l][i]+" "+j+" "+l+check[n-1][k-1]);
                            for(int m:li2[i]){
                                if(m>=l+1)
                                check[m][i] = 1;
                            }
                        }
                        else{
//                            System.out.println(s[j][i]+" "+s[l][i]+" "+j+" "+l+" "+i+check[n-1][k-1]);
                            for(int m:li1[i]){
                                if(m>=l+1)
                                check[m][i] = 1;
                            }
                        }
                    }
                }
            }
        }
//        System.out.println(check[n-1][k-1]);
        int cnt=0;
        for(int i = 0; i <n;i++){
            int check1 = 1;
            for (int j = 0; j < k; j++) {
//                System.out.print(check[i][j]);
                if(!check[i][j])check1 = 0;
            }
//            System.out.println();
            if(check1)cnt++;
        }
        cout<<(cnt);
	 return 0;
}



