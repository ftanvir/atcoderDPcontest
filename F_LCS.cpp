#include <bits/stdc++.h>
using namespace std;

/**----data type----*/
#define ll long long int
#define llu unsigned long long int

#define fast      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi          acos(-1.0)
#define nl          '\n'
/**-------Shortend Library-------*/
#define vi vector<int>
#define mii map<int, int>
#define f(i,n) for(ll i=0; i<n; i++)
#define FOR(i, a, b) for(ll i=a; i<=b; i++)
#define testcase ll t;cin>>t;while(t--)

#define ff first
#define ss second
#define all(a)         a.begin(),a.end()
#define Sort(x)        sort(x.begin(),x.end())
#define SortR(x)       sort(x.begin(),x.end(),greater<int>())
#define Reverse(x)     reverse(x.begin(),x.end())

#define SortA(ar,s)    sort(ar,ar+s)
#define SortD(ar,s)    sort(ar,ar+s,greater<int>())

#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)       (a*(b/gcd(a,b)))
#define sq(x)          (x)*(x)
#define mid(l,r)       (l+(r-l)/2)

#define leftShift(p)         (p<<1)
#define rightShift(p)        (p>>1)

#define min3(a,b,c)       min(a,min(b,c))
#define min4(a,b,c,d)     min(a,min(b,min(c,d)))
#define max3(a,b,c)       max(a,max(b,c))
#define max4(a,b,c,d)     max(a,max(b,max(c,d)))
#define pb(x)             push_back(x)
#define mod               1e8+7
#define precision(x)      cout<<fixed<<setprecision(x)
#define yes               cout<<"YES"<<nl
#define no                cout<<"NO"<<nl
#define min_heap priority_queue<ll,vector<ll>,greater<ll>>

/**----Functions to use----**/
ll powerLog(ll base, ll power)
{
    ll res = 1;
    while(power)
    {
        if(power%2)
        {
            res *= base;
            power--;
        } else 
        {
            base *=base;
            power/=2;
        }
    }
    return res;
}

string s1, s2;
string ans="";
int dp[3010][3010];

int lcs(int i, int j)
{
    if(i<0 or j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) {
        return dp[i][j] = 1+ lcs(i-1, j-1);
    } 
    
    return dp[i][j] = max(lcs(i-1, j), lcs(i, j-1));
    
}

void printlcs(int i, int j)
{
    if(i<0 or j<0) return ;

    if(s1[i]==s2[j]) {
        ans+= s1[i];
        printlcs(i-1, j-1);
        return;
    } else {
        if(dp[i-1][j]>dp[i][j-1]) {
            printlcs(i-1, j);
        } else{
            printlcs(i, j-1);
        }
    }
}

int main()
{
    cin>>s1>>s2;
    int len1, len2;
    len1 = s1.size();
    len2 = s2.size();
    memset(dp, -1, sizeof(dp));
    lcs(len1-1, len2-1);
    printlcs(len1-1, len2-1);

    reverse(ans.begin(), ans.end());
    cout<<ans<<nl;

    // for(int i=0; i<len1; i++) {
    //     for(int j=0; j<len2; j++) {
    //         cout<<dp[i][j]<<' ';
    //     }cout<<nl;
    // }
    // int i=len1, j = len2;
    // while(i>=0 and j>=0) {
    //     if(s1[i-1]==s2[j-1]) {
    //         ans+=s1[i];
    //         i--;
    //         j--;
    //     } else if(dp[i-1][j]>dp[i][j-1]) {
    //         i--;
    //     } else {
    //         j--;
    //     }
    // }
    // reverse(ans.begin(), ans.end());
    // cout<<ans<<nl;

    return 0;
}