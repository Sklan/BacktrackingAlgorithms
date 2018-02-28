#include <iostream>
#include <vector>


std::vector<std::vector<std::string>> Board;
int n;


void generateChessBoard() {
    std::cout << "Enter n: ";
    std::cin >> n;
    for (int i = 0; i != n; i++) {
        std::vector<std::string> line;
        for (int j = i; j != n + i; j++) {
            if (j % 2 == 0)
                line.emplace_back(".");
            else
                line.emplace_back("o");
        }
        Board.push_back(line);
    }
}

void show() {
    for (int j = 0; j != n + 3; j++)
        std::cout << " _ ";
    std::cout << '\n';
    for (int i = 0; i != Board.size(); i++) {
        std::cout << "\n|";
        for (int j = 0; j != Board[i].size(); j++) {
            std::cout << "\t" << Board[i][j];
        }
        std::cout << "|\n";
    }
    for (int j = 0; j != n + 3; j++)
        std::cout << " _ ";
    std::cout << '\n';
}

bool canBePlaced(int row, int column) {
    for (int i = 0; i != n; i++) {
        if (Board[i][column] == "x")
            return false;
    }
    for (int i = 0; i != n; i++) {
        if (Board[row][i] == "x")
            return false;
    }
    int a = row, b = column;

    while (a >= 0 && b >= 0) {
        if (Board[a][b] == "x")
            return false;
        a--;
        b--;
    }
    a = row, b = column;
    while (a < n && b < n) {
        if (Board[a][b] == "x")
            return false;
        a++;
        b++;
    }
    int r = 0;
    int s = row + column;
    while (r < n && s >= 0) {
        if (Board[r][s] == "x")
            return false;
        r++;
        s--;

    }
    return true;
}

void placeQueen(int a, int b) {
    Board[a][b] = "x";
}

void removeQueen(int a, int b) {
    Board[a][b] = ".";
}

bool Solve(int cols) {
    if (cols == n - 1) {
        show();
        return true;
    }
    std::cout << cols;
    for (int i = 0; i < n; i++) {
        if (canBePlaced(i, cols + 1)) {
            placeQueen(i, cols + 1);
            if (Solve(cols + 1))
                return true;
            removeQueen(i, cols + 1);
        }
    }
    return false;
}

