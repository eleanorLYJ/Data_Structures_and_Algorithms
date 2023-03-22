#include <iostream>
#include <string>

#define maxsize 100
using namespace std;

// recursive
int lcs(string str, string str2, int p1, int p2) {
    if (p1 == 0 || p2 == 0) {
        return 0;
    }
    if (str[p1] == str2[p2]) {
        return lcs(str, str2, p1 - 1, p2 - 1) + 1;
    }
    return max(lcs(str, str2, p1 - 1, p2), lcs(str, str2, p1, p2 - 1));
}

// top-down (memoization)
int td_dp[maxsize][maxsize];

int td_lcs(string str, string str2, int p1, int p2) {
    if (p1 == 0 || p2 == 0) {
        return td_dp[p1][p2] = 0;
    }
    if (td_dp[p1][p2]) {
        return td_dp[p1][p2];
    }
    if (str[p1] == str2[p2]) {
        return td_dp[p1][p2] = lcs(str, str2, p1 - 1, p2 - 1) + 1;
    }
    return td_dp[p1][p2] =
               max(lcs(str, str2, p1 - 1, p2), lcs(str, str2, p1, p2 - 1));

    return 0;
}

// bottom up
// 轉移式:
// dp[i][j] = dp[i-1][j-1] +1 ,if(str[i] == str2[j])
// dp[i][j] = max(dp[i-1][j], dp[i][j-1])
int bu_dp[maxsize][maxsize];
int bu_lcs(string str, string str2) {
    // inti
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            bu_dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= str.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if (str[i] == str2[j]) {
                bu_dp[i][j] = bu_dp[i - 1][j - 1] + 1;
            } else {
                bu_dp[i][j] = max(bu_dp[i - 1][j], bu_dp[i][j - 1]);
            }
        }
    }
    return bu_dp[str.size()][str2.size()];
}

int main() {
    string str = "abc";
    string str2 = "bac";
    cout << lcs(str, str2, str.size(), str2.size()) << endl;
    cout << td_lcs(str, str2, str.size(), str2.size()) << endl;
    cout << bp_lcs(str, str2);
    return 0;
}