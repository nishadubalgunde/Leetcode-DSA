class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            int row = n - 1;
            int col = 0;

            // Count elements <= mid
            while (row >= 0 && col < n) {

                if (matrix[row][col] <= mid) {
                    // Everything above this element
                    // in this column is also <= mid
                    count += row + 1;
                    col++;
                }
                else {
                    // Current element is too large,
                    // move upward
                    row--;
                }
            }

            // Decide which half to search
            if (count < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};