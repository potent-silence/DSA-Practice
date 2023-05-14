class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>ran(amount+1,0);
        ran[0]=1;// Assigning first element as 1 for '0' amount
        for(int j=0;j<coins.size();j++){
            // We are not taking coins array in inner loop but as outer loop because if we keep it as an inner loop we will get repeated pairs and ans will be more than original
            for(int i=0;i<ran.size();i++){
                // For each coin denomination we add the ways we reach to current amount to the next (current amount+coin denomination) index.
                // In this way we dont get repeated ways
                if(i+coins[j]<amount+1) 
                    ran[i+coins[j]]+=ran[i];
            }
        }
        return ran[amount];
    }
};
