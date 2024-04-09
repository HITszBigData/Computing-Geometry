#include <iostream>

using namespace std;
const int N = 100010;
int a[N], n;

void quick_sort(int a[], int l, int r)
{
    if (l >= r) {
        return;
    }
    else {
        int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
        while (i < j) {
            while (a[++i] < x);
            while (a[--j] > x);
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
        quick_sort(a, l, i);
        quick_sort(a, i + 1, r);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    return 0;
}