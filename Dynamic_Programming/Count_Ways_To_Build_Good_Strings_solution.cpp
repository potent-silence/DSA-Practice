class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>ran(high+1,0);
        long ans=0,mod=1e9+7;
        ran[zero]+=1;// We are setting the minimum no. of zeroes
        ran[one]+=1;// We are setting the minimum no. of ones
        for(int i=0;i<high+1;i++){
            if(i+zero<high+1)   ran[i+zero]+=ran[i]%mod;//We are just adding the next batch of zeroes to current one
            if(i+one<high+1)   ran[i+one]+=ran[i]%mod;//We are just adding the next batch of ones to current one
        }
        for(int i=low;i<high+1;i++) ans+=ran[i]%mod;// Adding values from low to high
        ans%=mod;
        return ans;
    }
};
