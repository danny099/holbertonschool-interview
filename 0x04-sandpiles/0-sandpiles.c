#include "sandpiles.h"
/**
 * print_grid_unstable - print a grid
 * @grid: grid to print
 * Return: Nothing
 */
void print_grid_unstable(int grid[3][3])
{
  int i, j;

  printf("=\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (j)
        printf(" ");
      printf("%d", grid[i][j]);
    }
    printf("\n");
  }
}
/**
 * check_pos - is stable or not
 * @grid1: sandpile to check
 * @grid: grid contains will be take off
 * Return: 0 o -1
 */
int check_pos(int grid1[3][3], int grid[3][3])
{
  int i, j, flag = 0;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (grid1[i][j] > 3)
      {
        flag++;
        grid[i][j] = 1;
      }
      else
      {
        grid[i][j] = 0;
      }
    }
  }
  if (flag)
  {
    print_grid_unstable(grid1);
    return (1);
  }
  return (0);
}
/**
 * re_organice - redistribution
 * @grid1: sandpile
 * @i: row
 * @j: col
 * Return: Nothing
 */
void re_organice(int grid1[3][3], int i, int j)
{
  int row_t, row_l, row_r, row_b;
  int col_t, col_l, col_r, col_b;

  row_t = i - 1, row_l = i, row_r = i, row_b = i + 1;
  col_t = j, col_l = j - 1, col_r = j + 1, col_b = j;

  grid1[i][j] -= 4;
  if (row_t >= 0 && row_t < 3 && col_t >= 0 && col_t < 3)
    grid1[row_t][col_t] += 1;
  if (row_l >= 0 && row_l < 3 && col_l >= 0 && col_l < 3)
    grid1[row_l][col_l] += 1;
  if (row_r >= 0 && row_r < 3 && col_r >= 0 && col_r < 3)
    grid1[row_r][col_r] += 1;
  if (row_b >= 0 && row_b < 3 && col_b >= 0 && col_b < 3)
    grid1[row_b][col_b] += 1;
}
/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: first
 * @grid2: second
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
  int i, j, flag = 0;
  int grid[3][3];

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      grid1[i][j] += grid2[i][j];
  }
  flag = check_pos(grid1, grid);
  while (flag)
  {
    for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
      {
        if (grid[i][j] == 1)
          re_organice(grid1, i, j);
      }
    }
    flag = check_pos(grid1, grid);
  }
}