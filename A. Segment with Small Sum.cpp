//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    ll x;

    cin>>n>>x;

    ll a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll r=0,l=0, sum=0,ans=0;

    while(r<n)
    {
        sum+=a[r];

        if(sum<=x)
        {
            ans= max(ans,r-l+1);
        }

        else
        {
            sum-=a[l];
            l++;
        }
        r++;

    }

    cout<<ans<<endl;

    return 0;
}
