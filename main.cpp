#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    if(__builtin_popcount(a)==__builtin_popcount(b))
        return a<b;
    else
        return __builtin_popcount(a)<__builtin_popcount(b);
}

int main() {
    int n,k;
    cin>>n>>k;
    multimap<int ,int> m;
    for(int i=0;i<k;i++)
    {
        int y;
        vector <int> integer_first;
        while(1)
        {
            cin >> y;
            // cout << y << ' ';
            integer_first.push_back(y);
            // peek next charcter w/o extracting it
            char ch = cin.peek();
            if(ch == '\n' or ch == EOF)
                break;
        }

        int x;
        x=integer_first.size();
        int num=0;
        for(int i=0;i<x;i++)
        {
            num|=(1<<(integer_first[i]-1));
        }

        int z;
        vector <int> integer_second;
        while(1)
        {
            cin >> z;
            // cout << z << ' ';
            integer_second.push_back(z);
            // peek next charcter w/o extracting it
            char ch = cin.peek();
            if(ch == '\n' or ch == EOF)
                break;
        }



        y=integer_second.size();
        int num1=0;
        for(int i=0;i<y;i++)
        {
            num1|=(1<<(integer_second[i]-1));
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

                if ((num & x.first) == x.first){
                    num |= x.second;
                }
            }


        }
        if(flag&&num==((1<<n)-1))
            ar[i]=true;
    }

    vector<int> answer;
    for(int i=1;i<(1<<n);i++)
        if(ar[i])
        {
            answer.push_back(i);
            // cout<<i<<endl;
        }
    sort(answer.begin(),answer.end(),comp);
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<n;j++)
        {
            if(answer[i]&((1<<(j))))
                cout<<j+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}