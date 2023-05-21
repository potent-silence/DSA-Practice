class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),high=m+n;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==0)    continue;
                // Here we are moving down and right (i.e in diagonally down right direction) and sees if there is 0 we increment it using previous data in matrix
                int d=high,r=high;
                if(i+1<n)  d=mat[i+1][j];
                if(j+1<m)  r=mat[i][j+1];
                mat[i][j]=min(d,r)+1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)    continue;
                // Here we are moving top and left (i.e in diagonally top left direction) and sees if there is 0 and we assign it with min value possible
                int t=high,l=high;
                if(i-1>=0)  t=mat[i-1][j];
                if(j-1>=0)  l=mat[i][j-1];
                mat[i][j]=min(mat[i][j],min(t,l)+1);// Here we assign it minimum between previous and now
            }
        }
        return mat;
    }
};
