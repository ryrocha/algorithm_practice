#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> prices{7,6,4,3,1};
    int maxProfit {0};

    // Nested loops; brute force, first attempt
    for (size_t i = 0; i < prices.size(); ++i) {
        for (size_t j = i + 1; j < prices.size(); ++j) {
            int profit {prices[i] - prices[j]};
            if (profit < 0) 
                if (maxProfit > profit) 
                    maxProfit = profit;                 
        }
    }

    cout << abs(maxProfit) << endl; 

    // Single loop; attempted only after being hinted that one pass works
    int minPrice {prices[0]};
    int profit {0};
    int maxprofit {0};
    for (int price: prices) {
        if (price < minPrice) {
            minPrice = price;
        } else {
            profit = price - minPrice;
            if (profit > maxprofit) 
                maxprofit = profit;
        }
    }

    cout << abs(maxprofit) << endl; 

    return 0;
}