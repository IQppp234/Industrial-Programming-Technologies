#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    if (!(cin >> n >> d)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0, r = a[n - 1] - a[0];
    int ans = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int count = 1;
        int start = a[0];

        for (int i = 1; i < n; ++i) {
            if (a[i] - start > mid) {
                count++;
                start = a[i];
            }
        }

        if (count <= d) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
