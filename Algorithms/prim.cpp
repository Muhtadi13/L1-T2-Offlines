#include <bits/stdc++.h>
#define lli long long
#define plli pair<lli, lli>
#define MAX 505LL
#define MOD 1000000007
#define INF 1000000007
#define cin in

using namespace std;
int main()
{
    lli t = 1;
    ifstream in("in.txt");
    // ofstream out("out6.txt");

    while (t--)
    {
        lli n, e;
        cin >> n >> e;
        vector<pair<lli, lli>> adj[n + 1];
        //vector<pair<lli,pair<lli,lli>>> ans;
        vector<pair<lli,lli>> parent(n+1);


        for (lli i = 0; i < e; i++)
        {
            lli node1, node2, w;
            cin >> node1 >> node2 >> w;
            //cout<<node1<<" "<<node2<<" "<<w<<endl; 

            adj[node1].push_back({node2, w});
            adj[node2].push_back({node1, w});
        }

      
        vector<lli> value(n + 1, INF);
        priority_queue<pair<lli, lli>> pq;

        lli root=0;

        pq.push({0,root});
        value[root]=0;

        vector<bool> processed(n + 1);

        while (!pq.empty())
        {
            lli a = pq.top().second;
            pq.pop();

            if (processed[a])
                continue;
                
            processed[a] = true;

            for (auto u : adj[a])
            {
               
                lli b = u.first;
                lli w = u.second;
                 if(processed[b])
                continue;
                if (w < value[b])
                {
                    value[b] = w;
                    pq.push({-value[b], b});
                    parent[b]={a,w};
                }
            }
        }
       
        lli sum=0;

        for(lli i=1;i<n;i++)
        {
            sum+=parent[i].second;
           
        }
        cout<<"Prim-Jarnik Algorithm:\n";
        cout<<"Total weight = "<<sum<<"\n";
        cout<<"Root node = "<<root<<"\n";

        for(lli i=1;i<n;i++)
        {          
            cout<<parent[i].first<<" "<<i<<"\n";
        }
    }
}