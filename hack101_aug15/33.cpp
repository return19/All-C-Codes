
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int N = 100010, K = 300010;
int n, m, l, d, k, s, a[K], t[K];
pair<int, int> p[N], q[N];
map<int, int> ma;

void upd(int i, int x)
{
    for (; i <= k; i += i & -i) t[i] += x;
}

int get(int i)
{
    int s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
}

int main()
{
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 1; i <= n; i++) scanf("%d %d", &p[i].first, &p[i].second), a[++d] = p[i].second;
    for (int i = 1; i <= m; i++) scanf("%d %d", &q[i].first, &q[i].second), a[++d] = q[i].second, a[++d] = q[i].second - l - 1;
    sort(a + 1, a + d + 1);
    ma[a[1]] = k = 1;
    printf("%d %d\n",a[1],ma[a[1]]);
    for (int i = 2; i <= d; i++) ma[a[i]] = a[i] != a[i - 1] ? ++k : k,printf("%d %d\n",a[i],ma[a[i]]);
    sort(p + 1, p + n + 1);
    sort(q + 1, q + m + 1);
    for (int i = 1, x = 1, y = 1; i <= m; i++)
    {
        while (x <= n && p[x].first <= q[i].first) upd(ma[p[x].second], 1), x++;
        while (y <= n && p[y].first < q[i].first - l) upd(ma[p[y].second], -1), y++;
        s = max(s, get(ma[q[i].second]) - get(ma[q[i].second - l - 1]));
    }
    printf("%d", s);
    return 0;
}
