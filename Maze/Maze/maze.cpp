#include <iostream>
#include <stack>
#include <string>

using namespace std;

const char WALL = 'X';
const char OPEN = '.';
const char SEEN = 'o';

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

void explore(string maze[], stack<Coord>& toDo, int r, int c)
{
    if (maze[r][c] == OPEN)
    {
        toDo.push(Coord(r,c));
        maze[r][c] = SEEN;  // anything non-OPEN will do
    }
}

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    return false;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X........X",
        "XX.X.XXXXX",
        "X..X.X...X",
        "X..X...X.X",
        "XXXX.XXX.X",
        "X.X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}