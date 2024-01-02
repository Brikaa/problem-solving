#include <cstdio>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui ROWS = 7;
const ui COLS = 8;
const ui PIPS = 7;
ui grid[ROWS][COLS];
ui visited_cells[ROWS][COLS];
ui visited_dominoes[PIPS][PIPS];
ui no_solutions;
const ui table[PIPS][PIPS] = {
    {1, 2, 3, 4, 5, 6, 7},
    {2, 8, 9, 10, 11, 12, 13},
    {3, 9, 14, 15, 16, 17, 18},
    {4, 10, 15, 19, 20, 21, 22},
    {5, 11, 16, 20, 23, 24, 25},
    {6, 12, 17, 21, 24, 26, 27},
    {7, 13, 18, 22, 25, 27, 28}};
ui vid;

void solve(ui cr, ui cc);
void print_grid();

void check_and_solve(ui cr, ui cc, ui nr, ui nc)
{
  if (nr > ROWS || nc > COLS || visited_cells[nr][nc] == vid)
    return;
  ui pip1 = grid[cr][cc];
  ui pip2 = grid[nr][nc];
  if (visited_dominoes[pip1][pip2] == vid)
    return;
  visited_cells[nr][nc] = visited_cells[cr][cc] = vid;
  visited_dominoes[pip1][pip2] = visited_dominoes[pip2][pip1] = vid;
  ui old_current_elem = grid[cr][cc];
  ui old_next_elem = grid[nr][nc];
  grid[nr][nc] = grid[cr][cc] = table[pip1][pip2];
  solve(cr, cc + 1);
  grid[cr][cc] = old_current_elem;
  grid[nr][nc] = old_next_elem;
  visited_cells[nr][nc] = visited_cells[cr][cc] = 0;
  visited_dominoes[pip1][pip2] = visited_dominoes[pip2][pip1] = 0;
}

void print_grid()
{
  for (ui r = 0; r < ROWS; ++r)
    for (ui c = 0; c < COLS; ++c)
      printf("%2u%c", grid[r][c], " \n"[c == COLS - 1]);
  puts("");
}

void solve(ui cr, ui cc)
{
  if (cr == ROWS - 1 && cc == COLS)
  {
    ++no_solutions;
    print_grid();
  }
  else if (cc == COLS)
    solve(cr + 1, 0);
  else if (visited_cells[cr][cc] == vid)
    solve(cr, cc + 1);
  else
  {
    check_and_solve(cr, cc, cr - 1, cc);
    check_and_solve(cr, cc, cr + 1, cc);
    check_and_solve(cr, cc, cr, cc - 1);
    check_and_solve(cr, cc, cr, cc + 1);
  }
}

int main()
{
  bool first = true;
  while (true)
  {
    ++vid;
    no_solutions = 0;
    for (ui r = 0; r < ROWS; ++r)
      for (ui c = 0; c < COLS; ++c)
        if (scanf("%u", &(grid[r][c])) == EOF)
          return 0;
    printf("%sLayout #%u:\n\n", first ? "" : "\n\n\n", vid);
    first = false;
    print_grid();
    printf("Maps resulting from layout #%u are:\n\n", vid);
    solve(0, 0);
    printf("There are %u solution(s) for layout #%u.\n", no_solutions, vid);
  }
  return 0;
}
