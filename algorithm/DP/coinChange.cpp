#include <iostream>
#include <vector>
using namespace std;
// 湊零錢
// 實作了 暴力法、備忘錄、DP陣列迭代
// return 最小組合的零錢個數
int brute(vector<int> coins, int target) {
    if (target == 0)
        return 0;

    if (target < 0)
        return 1e8; // never choose this combination!
    int res = 1e8;
    // 嘗試不同的零錢
    for (int c : coins) {
        res = min(res, brute(coins, target - c) + 1);
    }
    // 無法找剛好
    if (res == 1e8)
        return res;

    return res;
}
// memo紀錄已嘗試過的target (已減少遞迴次數)
int memorization(vector<int> coins, int target, vector<int> memo) {
    if (target == 0)
        return 0;
    if (target < 0)
        return 1e8; // 永遠不會選到這個組合!
    int res = 1e8;
    // 嘗試不同的零錢
    for (int c : coins) {
        res = min(res, brute(coins, target - c) + 1);
    }
    // 無法找剛好
    if (res == 1e8)
        return res;
    // 代表找到最小組合的零錢個數，那就紀錄後回傳!
    memo[target] = res;
    return res;
}

// 從base開始想 -> dp[0] = 0
// 代表找不到一個組合可以湊出零錢!
// 轉移式: dp[i] = min(dp[i], dp[i-coin]), when i > coin

// buttomUP 1與2 就只差在轉移式寫法不同~
int buttomUp_1(vector<int> coins, int target) {
    vector<int> dp(target + 1, 1e8);
    dp[0] = 0;
    for (int i = 0; i < target + 1; i++) {
        for (int c : coins) {
            if (i + c <= target) {
                dp[i + c] = min(dp[i + c], dp[i] + 1);
            }
        }
    }
    if (dp[target] == 1e8)
        return -1;
    return dp[target];
}

int buttomUp_2(vector<int> coins, int target) {
    vector<int> dp(target + 1, 1e8);
    dp[0] = 0;
    for (int i = 0; i < target + 1; i++) {
        // dp[i]有存在能湊出零錢的組合
        if (dp[i] != 1e8) {
            for (int c : coins) {
                if (i + c <= target) {
                    dp[i + c] = min(dp[i + c], dp[i] + 1);
                }
                if (i - c < 0)
                    continue;
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    if (dp[target] == 1e8)
        return -1;
    return dp[target];
}

int main() {
    vector<int> coins = {50, 10, 5};
    int target = 75;
    cout << brute(coins, target) << endl;                             // 4
    cout << memorization(coins, target, vector<int>(target)) << endl; // 4
    cout << buttomUp_1(coins, target) << endl;
    cout << buttomUp_2(coins, target);
    return 0;
}