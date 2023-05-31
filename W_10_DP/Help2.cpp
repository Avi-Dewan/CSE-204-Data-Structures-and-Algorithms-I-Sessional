//Traveling salesman person


#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(int i=a; i<b;i++)
#define fr(i,a,b) for(int i=a; i>=b;i--)
typedef long long int ll;
typedef vector<int> vi;
#define pb push_back

int dp[22][1>>22];
int arr[22][22];
int n;

int shortest_path(int k, int mask) {
    if(mask == 1) return dp[k][0] = arr[k][0];

    if(dp[k][mask]) return dp[k][mask];

    int ans = INT_MAX;
    f(i,1,n+1) {
        if((1<<i) & mask) {
            ans = min(ans,arr[k][i] + shortest_path(i,mask ^ (1<<i)));
        }
    }
    return dp[k][mask] = ans;
}

int main() {
    fastio;
    memset(dp,0,sizeof(dp));
    cin>>n;
    f(i,0,n) {
        f(j,0,n) {
            cin>>arr[i][j];
        }
    }

    cout<<shortest_path(0,(1<<n) - 1);
}
