#include <iostream>
#include <vector>
using namespace std;
// 題目描述:
// https://zerojudge.tw/ShowProblem?problemid=c824 -> wrong???
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// https://hackmd.io/@nehs-iced-7th/Hk9_m5KH_/https%3A%2F%2Fhackmd.io%2F%40Paul-Liao%2FSJHC9SE0u
// (一維DP!!!)
vector<int> weight = {10, 20, 30};
vector<int> price = {60, 100, 120};
int n = 3, maxw = 50;
int dfs(int pos, int w) {
    if (w > maxw)
        return -100000; // enough?
    if (pos >= weight.size())
        return 0;
    int maxp = -100000; // return 會出錯 拿超過會也變成0
    maxp = max(maxp, dfs(pos + 1, w + weight[pos]) + price[pos]);
    maxp = max(maxp, dfs(pos + 1, w));
    return maxp;
}
// top-down
// return value: max value, if return negative value(-10000) that mean visited
// and cannot go. array store: the row: Each item ;colume: each weight
vector<vector<int>> dp(weight.size(),
                       vector<int>(maxw + 1, -1)); //-1會被抓到的情況
int dp_dfs(int pos, int w) {
    if (w > maxw)
        return -100000;
    if (pos >= price.size())
        return 0; // 區別 走過,走不過, if getting nothing is optimal
    if (dp[pos][w] >= 0)
        return dp[pos][w];
    int maxp = -100000;
    if (dp[pos][w] == -1) {
        maxp = max(maxp,
                   dfs(pos + 1, w + weight[pos]) + price[pos]); //情況: -1+price
        maxp = max(maxp, dfs(pos + 1, w));
    }
    return dp[pos][w] = maxp;
}
// bottom-up
vector<vector<int>>
    dp2(n + 1, vector<int>(maxw + 1, -1e9)); // infeasible solution + price > 0
void dp_bottom2D() {

    for (int i = 0; i < n + 1; i++) {
        dp2[i][0] = 0;
    }
    for (int i = 0; i < maxw + 1; i++) {
        dp2[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) { // 0 ~ weight.size // i = 1是要討論物品的0項!
        for (int j = 1; j <= maxw; j++) { // 0 ~ maxweight
            if (j - weight[i - 1] >= 0) { // 0是可以放的  //其一個湊不湊得出來!
                dp2[i][j] =
                    max(dp2[i - 1][j - weight[i - 1]] + price[i - 1],
                        dp2[i - 1][j]); // weight[i-1] 跟
                                        // price[i-1]是因為我會表格時有平移了
            } else {
                dp2[i][j] = dp2[i - 1][j];
            }
        }
    }
    cout << dp2[n][maxw] << "\n";
    return;
}

int main() {
    cout << dfs(0, 0) << endl;    // 220
    cout << dp_dfs(0, 0) << endl; // 220
    dp_bottom2D();                // 220
    return 0;
}