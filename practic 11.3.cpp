#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l;
    if (!(cin >> n >> k >> l)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    long long sum = 0;
    int taken = 0;

    for (int i = 0; i < n && taken < k; ++i) {
        int take = min(l, k - taken);
        sum += (long long)a[i] * take;
        taken += take;
    }

    cout << sum << "\n";

    return 0;
}
