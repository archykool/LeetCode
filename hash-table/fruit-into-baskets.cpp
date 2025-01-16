class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int k = 0; // # of trees
        int i = 0;
        for(int j = 0; j < fruits.size(); j++) {
            basket[fruits[j]]++;
            while(basket.size() > 2) {
                basket[fruits[i]]--; //why???
                if(basket[fruits[i]] == 0) {
                    basket.erase(fruits[i]);
                    i++;
                }
            }
            k = max(j - i + 1, k);
        }
        return k;
    }
};