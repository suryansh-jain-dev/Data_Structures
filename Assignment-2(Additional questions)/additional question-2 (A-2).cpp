#include <iostream>
using namespace std;

bool isSubstring(const string &a, const string &b) {
    if (b.size() < a.size()) return false;
    for (size_t i = 0; i + a.size() <= b.size(); i++) {
        if (b.substr(i, a.size()) == a) return true;
    }
    return false;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int n = s.size();

    bool possible = false;

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            if (isSubstring(A, B) && isSubstring(A, C)) possible = true;
            if (isSubstring(B, A) && isSubstring(B, C)) possible = true;
            if (isSubstring(C, A) && isSubstring(C, B)) possible = true;

            if (possible) break;
        }
        if (possible) break;
    }

    if (possible) cout << "Yes, it can be split as required." << endl;
    else cout << "No, such a split is not possible." << endl;

    return 0;
}
