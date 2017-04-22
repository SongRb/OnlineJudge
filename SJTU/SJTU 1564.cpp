#include <iostream>

using namespace std;

// Dimension 1: row index
// Dimension 2: column index
int matrix[6][6];

int desR, desC;
int minCost = 1000000;


void search(int r, int c, int cost, int totalCost)
{
    if (totalCost > minCost) return;

    if (r == desR && c == desC)
    {
        if (minCost > totalCost)
            minCost = totalCost;
        return;
    }

    int state = cost % 4 + 1;

    int nextR[4] = {1, 0, -1, 0};
    int nextC[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        if (r + nextR[i] < 6 && r + nextR[i] >= 0 && c + nextC[i] < 6 && c + nextC[i] >= 0)
        {
            int curCost = matrix[r + nextR[i]][c + nextC[i]] * state;
            search(r + nextR[i], c + nextC[i], curCost, totalCost + curCost);
        }
    }
}


// Input coor format: row index, column index
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        minCost = 1000000;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                cin >> matrix[i][j];

        int startR, startC;
        cin >> startR >> startC >> desR >> desC;
        search(startR, startC, 0, 0);

        cout << minCost << endl;
    }
}