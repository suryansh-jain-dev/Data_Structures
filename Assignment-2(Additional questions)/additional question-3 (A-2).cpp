#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (s1.length() != s2.length()) {
        cout << "Not anagrams" << endl;
        return 0;
    }

    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; i < s1.length(); i++) {
        count1[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.length(); i++) {
        count2[s2[i] - 'a']++;
    }

    bool same = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            same = false;
            break;
        }
    }

    if (same) {
        cout << "Anagrams" << endl;
    } else {
        cout << "Not anagrams" << endl;
    }

    return 0;
}
