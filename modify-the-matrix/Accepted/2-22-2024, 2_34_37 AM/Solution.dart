// https://leetcode.com/problems/modify-the-matrix

class Solution {
  List<List<int>> modifiedMatrix(List<List<int>> matrix) {
    int m = matrix.length;
    int n = matrix[0].length;
    
    // Create answer matrix and copy values from original matrix
    List<List<int>> answer = List.generate(m, (index) => List<int>.from(matrix[index]));
    
    // Find maximum value in each column
    List<int> maxValues = List.filled(n, -1);
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) {
        maxValues[j] = maxValues[j].compareTo(matrix[i][j]) < 0 ? matrix[i][j] : maxValues[j];
      }
    }
    
    // Replace -1 values with maximum value in respective column
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) {
        if (answer[i][j] == -1) {
          answer[i][j] = maxValues[j];
        }
      }
    }
    
    return answer;
  }
}
