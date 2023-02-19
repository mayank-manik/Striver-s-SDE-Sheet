#include <bits/stdc++.h>
using namespace std;

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
*/

void dfs(vector<vector<int>> &vis, vector<vector<int>> &image, int x, int y, int n, int m, int scolor, int color)
{
    vis[x][y] = 1;
    image[x][y] = color;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = x + drow[i];
        int ncol = y + dcol[i];
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and image[nrow][ncol] == scolor)
        {
            dfs(vis, image, nrow, ncol, n, m, scolor, color);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int scolor = image[sr][sc];
    dfs(vis, image, sr, sc, n, m, scolor, color);
    return image;
}

int main()
{

    return 0;
}