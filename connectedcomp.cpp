#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"

using namespace std;
using namespace __gnu_pbds; 


 #define mod 1e9 + 7
#define FOR(a, c) for (long long(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (long long(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (long long(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<long long> vi;
typedef pair<long long, long long> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
typedef long long ll;
const ll INFL=1E18;
#define MP make_pair
#define MOD
typedef tree<pair<long long,long long>, null_type, less<pair<long long,long long>>, rb_tree_tag,
tree_order_statistics_node_update>
new_data_set;
class graph{
private:
    map<int,list<int>> m;
public:
    void add(int a,int b)
    {
        m[a].push_back(b);
        m[b].push_back(a);
    }
    void print()
    {
        for(auto x : m)
        {
            cout << x.first << "->";
            for(auto y : x.second)
                cout << y << ' ';
            cout << endl;
        }
    }
    void bfs(int start)
    {
        queue<int> q;
        q.push(start);
        map<int,int> visited;
        while(!q.empty())
        {
            int front = q.front();
            cout << front << ' ';
            visited[front]++;
            q.pop();
            for(auto x : m[front])
            {
                if(visited[x] == 0)
                {
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
    }
            map<int,int> visited;
    void dfs(int src)
    {
        cout << src << ' ';
        visited[src] = 1;
        for(auto x : m[src])
        {
            if(visited[x] != 1)
            {
                dfs(x);
            }
        }
    }
    void connect()
    {
        for(auto x : m)
        {
            if(visited[x.first] == 0)
            {
                dfs(x.first);
                cout << "op"; // to find kount of connected components
            }
        }
    }
};
signed main()
{
    graph g;
    g.add(0,1);
    g.add(0,3);
    g.add(1,2);
    g.add(2,3);
    g.add(3,4);
    g.add(4,5);
    g.add(6,7); 
    g.connect();
}