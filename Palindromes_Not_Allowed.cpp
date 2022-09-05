#include <bits/stdc++.h>

using namespace std;

bitset<1001> func(bitset<1001> a, bitset<1001> b)
{
    return a ^ b;
}

bitset<1001> query(int a, int b, int n, vector<bitset<1001>> &tree)
{
    a += n;
    b += n;
    bitset<1001> s = 0;
    while (a <= b)
    {
        if (a % 2 == 1)
            s = func(s, tree[a++]);
        if (b % 2 == 0)
            s = func(s, tree[b--]);
        a /= 2;
        b /= 2;
    }
    return s;
}

void add(int k, bitset<1001> x, int n, vector<bitset<1001>> &tree)
{
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2)
    {
        tree[k] = func(tree[2 * k], tree[2 * k + 1]);
    }
}

vector<int> solve(int N, int Q, vector<int> Arr, vector<vector<int>> queries)
{

    int n, q;
    n = N, q = Q;
    vector<int> ans;
    bitset<1001> allnums[1001];
    for (int i = 0; i <= 1000; i++)
    {
        allnums[i][i] = 1;
    }
    vector<bitset<1001>> tree(4 * n);

    for (int i = 1; i <= n; i++)
    {
        int x = Arr[i - 1];
        add(i, allnums[x], n, tree);
    }

    for (int i = 1; i <= q; i++)
    {
        int t, a, b;
        t = queries[i - 1][0];
        a = queries[i - 1][1];
        b = queries[i - 1][2];

        if (t == 1)
        {
            add(a, allnums[b], n, tree);
        }
        else
        {
            ans.push_back(query(a, b, n, tree).count());
        }
    }

    return ans;
}

int main()
{

    // your code goes here
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        vector<vector<int>> Q;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < q; i++)
        {
            vector<int> t(3, 0);
            cin >> t[0] >> t[1] >> t[2];
            Q.push_back(t);
        }

        vector<int> ans = solve(n, q, v, Q);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}