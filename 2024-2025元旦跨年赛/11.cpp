#include <iostream>
#include <vector>
using namespace std;

// 定义方向数组，用于寻找 8 个邻居
const int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                              {0, 1},   {1, -1}, {1, 0},  {1, 1}};

// 检查坐标是否有效
bool isValid(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

// 计算周围未知格子和已标记地雷的数量
pair<vector<pair<int, int>>, int>
countUnknownsAndMines(int x, int y, const vector<vector<int>> &matrix,
                      const vector<vector<int>> &mines) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<pair<int, int>> unknowns;
  int mineCount = 0;

  for (int i = 0; i < 8; ++i) {
    int nx = x + directions[i][0];
    int ny = y + directions[i][1];
    if (isValid(nx, ny, n, m)) {
      if (mines[nx][ny] == 1) {
        mineCount++;
      } else if (matrix[nx][ny] == 0 && mines[nx][ny] == 0) {
        unknowns.emplace_back(nx, ny);
      }
    }
  }
  return make_pair(unknowns, mineCount); // 使用 make_pair
}

// 解决扫雷问题
void solveMinesweeper(vector<vector<int>> &matrix, vector<vector<int>> &mines) {
  int n = matrix.size();
  int m = matrix[0].size();
  bool progress = true;

  while (progress) {
    progress = false;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] > 0) { // 如果是数字格子
          auto [unknowns, mineCount] =
              countUnknownsAndMines(i, j, matrix, mines);

          // 如果剩余地雷数量等于未知格子数量，标记所有未知格子为地雷
          if (matrix[i][j] == mineCount + (int)unknowns.size()) {
            for (auto &cell : unknowns) {
              mines[cell.first][cell.second] = 1;
            }
            progress = true;
          }
          // 如果地雷数量已满足，则标记未知格子为安全
          else if (matrix[i][j] == mineCount) {
            for (auto &cell : unknowns) {
              matrix[cell.first][cell.second] = -1; // 标记为安全
            }
            progress = true;
          }
        }
      }
    }
  }
}

// 显示最终的地雷标记矩阵
void displayMines(const vector<vector<int>> &matrix,
                  const vector<vector<int>> &mines) {
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mines[i][j] == 1) {
        cout << "* "; // 地雷
      } else if (matrix[i][j] == -1) {
        cout << ". "; // 安全格子
      } else {
        cout << matrix[i][j] << " "; // 显示数字
      }
    }
    cout << endl;
  }
}

int main() {
  // 输入矩阵
  vector<vector<int>> matrix = {{0, 0, 0, 0, 0, 1, 0}, {2, 3, 5, 0, 5, 3, 0},
                                {0, 0, 3, 0, 0, 0, 0}, {0, 3, 3, 0, 4, 4, 3},
                                {2, 0, 0, 3, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 2, 1, 2, 0}};

  // 初始化地雷矩阵
  vector<vector<int>> mines(matrix.size(), vector<int>(matrix[0].size(), 0));

  // 求解问题
  solveMinesweeper(matrix, mines);

  // 输出结果
  cout << "最终地雷标记矩阵：" << endl;
  displayMines(matrix, mines);

  return 0;
}
