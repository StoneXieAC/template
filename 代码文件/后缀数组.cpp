#include<bits/stdc++.h>

#define mem(x, y) memset(x,y,sizeof(x)) // 定义快速清空数组的宏
#define endl '\n' // 定义换行符
#define int long long // 定义 long long 类型的整数
#define pb emplace_back // 定义 emplace_back 的快捷方式
using namespace std;

typedef long long lld; // 定义 long long 的别名
typedef long double llf; // 定义 long double 的别名
typedef pair<int, int> pii; // 定义 pair 的别名
const int N = 1e6 + 10; // 定义常量 N

int n, m, p; // 定义变量 n, m, p
int rk[N << 1], oldrk[N << 1], sa[N << 1], id[N], cnt[N]; // 定义后缀数组和相关辅助数组

void solve() {
    string s;
    cin >> s; // 输入字符串 s
    m = 256; // 字符集大小为 256
    n = s.size(); // 字符串长度
    s = " " + s; // 字符串前面加一个空字符，从下标 1 开始存储

    // Step 1: 初始化排序（1-character 排序）
    for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++; // 计数排序
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1]; // 计算前缀和
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i; // 按计数数组将字符串排序得到初始的 sa 数组

    // Step 2: 循环增量排序
    for (int w = 1;; w <<= 1, m = p) {
        int cur = 0;

        // 构造 id 数组，对第二关键字进行排序
        for (int i = n - w + 1; i <= n; i++) id[++cur] = i; // 后缀末尾较短的部分
        for (int i = 1; i <= n; i++)
            if (sa[i] > w) id[++cur] = sa[i] - w; // 根据当前的 sa 数组构造 id 数组

        // 使用 id 数组对 sa 进行第一关键字排序
        memset(cnt, 0, sizeof(int) * (m + 1)); // 清空计数数组
        for (int i = 1; i <= n; i++) cnt[rk[i]]++; // 计数排序
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1]; // 计算前缀和
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i]; // 按照 id 数组排序得到新的 sa 数组

        // 更新 rk 数组
        memcpy(oldrk, rk, sizeof(int) * (n + 1)); // 备份旧的 rk 数组
        p = 1;
        rk[sa[1]] = 1;//注意，rk1特别处理
        for (int i = 2; i <= n; i++) {
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
                rk[sa[i]] = p; // 如果相等，则当前后缀与前一个后缀在同一个等价类中
            else
                rk[sa[i]] = ++p; // 否则，当前后缀与前一个后缀不同，增加等价类数目
        }

        if (p == n) break; // 如果等价类数目达到字符串长度，退出循环
    }

    // 输出后缀数组 sa
    for (int i = 1; i <= n; i++) cout << sa[i] << " ";
}

signed main() {
    ios::sync_with_stdio(false); // 关闭流同步
    cin.tie(0); // 解除 cin 和 cout 的绑定
    cout.tie(0); // 解除 cin 和 cout 的绑定
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve(); // 调用解决函数
    }
    return 0; // 返回值
}

