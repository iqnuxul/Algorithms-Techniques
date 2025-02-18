#include <iostream>
#include <vector>
#include <climits>

using namespace std;



vector<int> minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    int coinUsed[amount + 1];
    dp[0] = 0;



    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        coinUsed[i] = -1;
    }



    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX && dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
                coinUsed[j] = i;
            }
        }


        if(dp[amount]== 0){
            break;
        }
    }




    vector<int> result;
    if (dp[amount] == INT_MAX) {
        cout << "No solution is possible."<< endl;
    } else {
        int amountLeft = amount;
        while (amountLeft > 0) {
            int coin = coins[coinUsed[amountLeft]];
            result.push_back(coin);
            amountLeft -= coin;
        }
    }
    return result;
}





int main() {
    int coins[] = {2,3,5,10};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;


        vector<int> result = minCoins(coins, n, amount);

        cout << "Minimum number of coins needed: " << result.size() << endl;
        cout << "Coins used: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }


    return 0;
}
