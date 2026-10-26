// 3 задача
#include <iostream>
#include <string>
using namespace std;

// получает следующий член последовательности из предыдущего
string nextTerm(string s) {
    string result = "";
    int i = 0;
    while (i < s.length()) {
        int count = 1;
        while (i + count < s.length() && s[i + count] == s[i]) {
            count++;
        }
        result += to_string(count);
        result += s[i];
        i += count;
    }
    return result;
}

// рекурсия: n-ый член = следующий после (n-1)
string get(string x, int n) {
    if (n == 1) {
        return x;
    }
    return nextTerm(get(x, n - 1));
}

int main() {
    int x, n;
    cin >> x >> n;

    cout << get(to_string(x), n) << endl;

    return 0;
}
