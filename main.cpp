#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    multimap<int ,int> m;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        int num=0;
        for(int i=0;i<x;i++)
        {
            int a;
            cin>>a;
            num|=(1<<(a-1));
        }
        int y;
        cin>>y;
        int num1=0;
        for(int i=0;i<y;i++)
        {
            int a;
            cin>>a;
            num1|=(1<<(a-1));
        }
        m.insert(pair<int,int>(num,num1));
//        cout<<num<<" "<<num1<<endl;
    }

    bool ar[(1<<n)];
    memset(ar,false,sizeof(ar));
    for(int i=1;i<(1<<(n));i++)
    {

        int num=i;
        bool flag=true;
        int s=0;
        int x=i;
        while(x> 0)
        {
            if(ar[x])
                flag=false;
            x=(x-1)&i;
        }
        while(s!=num&&flag) {
            s = num;
            for (auto x: m) {
                if (num & x.first == x.first)
                    num |= x.second;
            }


        }
        if(flag&&num==((1<<n)-1))
            ar[i]=true;
    }
    for(int i=1;i<(1<<n);i++)
        if(ar[i])
        {
            cout<<i<<endl;
        }
    return 0;
}
