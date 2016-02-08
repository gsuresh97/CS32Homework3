#include <iostream>
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

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (sc == ec && sr == er) {
        return true;
    }
    maze[sr][sc] = SEEN;
    
    //check North
    if(maze[sr - 1][sc] == OPEN){
        if (pathExists(maze, nRows, nCols, sr - 1, sc, er, ec))
            return true;
    }
    if(maze[sr][sc + 1] == OPEN){
        if (pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
            return true;
    }
    if(maze[sr + 1][sc] == OPEN){
        if (pathExists(maze, nRows, nCols, sr + 1, sc, er, ec))
            return true;
    }
    if(maze[sr][sc - 1] == OPEN){
        if (pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
            return true;
    }
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
    
    if (pathExists(maze, 10,10, 6,1, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}