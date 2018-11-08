//
// Created by Shaurya Saklani on 19/07/17.
//


#include <string>
#include <fstream>
#include <iostream>
#include <vector>


enum directionT {
    North, East, South, West
};
struct pointT {
    int x, y;
};

std::vector<std::vector<char> > maze;

void ReadMazeMap(std::string filename) {
    std::fstream file;
    file.open("/Users/sklan/CLionProjects/Programming Abstraction in c++/" + filename);
    if (file.fail()) {
        std::cerr << "Error 001: COULD NOT LOAD WORD FILE.";
    }


    std::string line;

    while (std::getline(file, line)) {
        std::vector<char> chars;
        for (int i = 0; i != line.length(); i++) {
            chars.push_back(line[i]);
        }
        maze.push_back(chars);

    }

}

pointT Start() {
    pointT pt;
    for (int i = 0; i != maze.size(); i++) {
        for (int j = 0; j != maze[i].size(); j++) {
            if (maze[i][j] == 'X') {
                pt.x = i;
                pt.y = j;
                return pt;
            }
        }
    }
    return pt;
}

pointT AdjacentPoint(pointT pt, directionT dir) {
    pointT newpt = pt;
    switch (dir) {
        case North:
            newpt.y++;
            break;
        case East:
            newpt.x++;
            break;
        case South:
            newpt.y--;
            break;
        case West:
            newpt.x--;
            break;;
    }
    return newpt;
}

bool OutsideMaze(pointT pt) {
    return (maze[pt.x][pt.y] == '.');
}

bool WallExists(pointT pt, directionT dir) {
    pointT npt = AdjacentPoint(pt, dir);
    return maze[npt.x][npt.y] == '1';
}

void MarkSquare(pointT pt) {
    maze[pt.x][pt.y] = 'x';
}

void UnmarkSquare(pointT pt) {
    maze[pt.x][pt.y] = ' ';
}

bool IsMarked(pointT pt) {
    return maze[pt.x][pt.y] == 'x';
}

bool SolveMaze(pointT pt) {
    if (OutsideMaze(pt))
        return true;
    if (IsMarked(pt))
        return false;
    MarkSquare(pt);

    for (int i = 0; i < 4; i++) {
        directionT dir = directionT(i);
        if (!WallExists(pt, dir)) {
            if (SolveMaze(AdjacentPoint(pt, dir))) {

                return true;
            }
        }
    }
    UnmarkSquare(pt);
    return false;
}

int ShortestPathLength(pointT pt) {
    return 0;
}

void displayMaze() {
    std::cout << "\n";
    for (int i = 0; i != maze.size(); i++) {
        for (int j = 0; j != maze[i].size(); j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << maze[i].size() << "\n";
    }
}