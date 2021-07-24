#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

map<char, int> mp;

string dfs_string = "";

void dfs(int v, const vector<vector<int> > &g, vector<string> &result) {
    if ((int) g[v].size() == 0) {
        result[v] = dfs_string;
        return;
    }
    dfs_string.push_back('0');
    dfs(g[v][0], g, result);
    dfs_string.back() = '1';
    dfs(g[v][1], g, result);
    dfs_string.pop_back();
}

signed main() {
    ofstream fout("stat.txt");
    vector<string> v;
    string s;
    while(getline(cin, s)) {
        v.push_back(s); 
            for (int i = 0; i < (int) s.size(); ++i) {
                mp[s[i]]++;
            }     
    }
    vector<pair<char, int> > start;
    start.clear();
    for (pair<char, int> i : mp) {
        start.push_back(i);
    }
    sort(start.begin(), start.end(), [&] (auto &a, auto &b) {
        return a.second < b.second;
    });
    for (auto i : start) {
        fout << i.second << ' ' << i.first << '\n';
    }
    set<pair<int, int> > position;
    position.clear();
    map<char, int> p;
    p.clear();
    for (int i = 0; i < (int) start.size(); ++i) {
        position.insert(make_pair(start[i].second, i));
        p[start[i].first] = i;
    }
    int t = position.size();
    vector<vector<int> > g((int) start.size(), vector<int>(0));
    while ((int) position.size() > 1) {
        auto a = *position.begin();
        position.erase(position.begin());
        auto b = *position.begin();
        position.erase(position.begin());
        pair<int, int> c(a.first + b.first, t);
        g.push_back(vector<int>(0));
        g[t].push_back(a.second);
        g[t].push_back(b.second);
        position.insert(c);
        t++;
    }
    int root = position.begin()->second;
    vector<string> res(start.size(), "");
    dfs(root, g, res);
    for (auto &i : v) {
        for (auto j : i) {
            cout << res[p[j]];
        }
        cout << '\n';
    }
    return 0;
}
