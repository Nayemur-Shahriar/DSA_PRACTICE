//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B

#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n;
    ll x;

    cin>>n>>x;

    ll a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    ll r=0,l=0, sum=0,ans=INT_MAX;

    while(r<n)
    {
        sum+=a[r];

        while(sum>=x)
        {
            ans= min(ans,r-l+1);
            sum-=a[l];
            l++;

        }

        r++;

    }

    if(ans==INT_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}

