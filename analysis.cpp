#include <iostream>
#include <fstream>
#include <set>
#include <utility>

using namespace std;

int main() {
    int res = 0;
    {
        string s;
        while(getline(cin, s)) {
            res += (int) s.size();
        }
    }
    ifstream fin("input.txt");
    set<char> s;
    string t;
    int sz = 0;
    while (getline(fin, t)) {
        sz += (int) t.size();
        for (auto i : t) {
            s.insert(i);
        }
    }
    int cnt = 1;
    while ((1 << cnt) < (int) s.size()) {
        cnt++;
    }
    cout << "Compression : " << res << " bits" << '\n';
    cout << "Original : " << cnt * sz << " bits" << '\n';
    cout << "Compressed ";
    cout << fixed << setprecision(2) << ((double) (cnt * sz - res) / (double) (cnt * sz)) * 100.0 << "%\n";
    return 0;
}
