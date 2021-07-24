#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

signed main() {
    ifstream fin("stat.txt");
    vector<pair<char, int> > start;
    {
        char c;
        int x;
        while (fin >> x) {
            c = fin.get();
            c = fin.get();
            start.push_back(make_pair(c, x));
        }
    }
    set<pair<int, int> > position;
    position.clear();
    vector<char> p(start.size());
    p.clear();
    for (int i = 0; i < (int) start.size(); ++i) {
        position.insert(make_pair(start[i].second, i));
        p[i] = start[i].first;
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
    {
        string s;
        int now = root;
        while (cin >> s) {
            for (auto i : s) {
                if (i == '0') {
                    now = g[now][0];
                } else {
                    now = g[now][1];
                }
                if (g[now].size() == 0) {
                    cout << p[now];
                    now = root;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
