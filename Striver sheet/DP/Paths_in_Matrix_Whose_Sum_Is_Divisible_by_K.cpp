// Problem URL : https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

// Vedio Editorial : https://youtu.be/zWoUoQ5svro

class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> mat;
    long long ans = 0;
    const int mod = 1e9 + 7;
    int helper(int i, int j, int rem_val , int k){
        if(i >= mat.size() or j >= mat[0].size())return 0;
        if(i == mat.size() - 1 and j == mat[0].size() - 1){
            if(mat[i][j]%k == rem_val){
                // cout << "aa gya"<< endl;
                return 1;
            }
            return 0;
        }
        
        if(memo[i][j][rem_val] != -1)return memo[i][j][rem_val];
      
        int remainder = (rem_val - (mat[i][j] % k) + k)%k;
      
        int rSum = helper(i, j + 1, remainder, k)%mod;
        int lSum = helper(i + 1, j ,remainder, k)%mod;
      
        memo[i][j][rem_val]= (rSum + lSum)%mod;
        return memo[i][j][rem_val];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m = grid[0].size();
        
        memo.resize(n, vector<vector<int>>(m, vector<int>(k, -1)));
        mat = grid;
        return helper(0, 0, 0, k);
        // return ans;
    }
};
