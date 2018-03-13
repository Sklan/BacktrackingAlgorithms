#include <vector>
#include <iostream>
#include <string>
// There are 8 possible moves.


struct pointT {
    int x, y;
};

enum moveT {
    move1, move2, move3, move4, move5, move6, move7, move8
};
std::vector<std::vector<std::string>> chessBoard;
int N;

void display();

void generateBoard() {
    std::cout << "Enter N: ";
    std::cin >> N;
    for (int i = 0; i != N; i++) {
        std::vector<std::string> line;
        for (int j = i; j != N + i; j++) {
            if (j % 2 == 0)
                line.push_back(".");
            else
                line.push_back("o");
        }
        chessBoard.push_back(line);
    }
}


void display() {
    std::cout << "\n";
    for (int j = 0; j != N + 2; j++)
        std::cout << "\t_";
    std::cout << "\n";
    for (int i = 0; i != chessBoard.size(); i++) {
        std::cout << "\t|";
        for (int j = 0; j != chessBoard[i].size(); j++) {
            std::cout << "\t" << chessBoard[i][j];
        }
        std::cout << "\t|\n";
    }
    for (int j = 0; j != N + 2; j++)
        std::cout << "\t_";
    std::cout << "\n\n";
}

bool canMove(int row, int col) {
    return row >= 0 && col >= 0 && row < N && col < N && (chessBoard[row][col] == "." || chessBoard[row][col] == "o");
}

bool tryMove(int row, int col, moveT m) {
    switch (m) {
        case move1:
            return canMove(row + 2, col + 1);
        case move2:
            return canMove(row + 2, col - 1);
        case move3:
            return canMove(row - 2, col + 1);
        case move4:
            return canMove(row - 2, col - 1);
        case move5:
            return canMove(row + 1, col + 2);
        case move6:
            return canMove(row - 1, col + 2);
        case move7:
            return canMove(row + 1, col - 2);
        case move8:
            return canMove(row - 1, col - 2);
    }
}


pointT newMove(pointT pt, moveT m) {
    pointT npt;
    npt.x = pt.x;
    npt.y = pt.y;
    switch (m) {
        case move1:
            npt.x += 2;
            npt.y += 1;
            break;
        case move2:
            npt.x += 2;
            npt.y -= 1;
            break;
        case move3:
            npt.x -= 2;
            npt.y += 1;
            break;
        case move4:
            npt.x -= 2;
            npt.y -= 1;
            break;
        case move5:
            npt.x += 1;
            npt.y += 2;
            break;
        case move6:
            npt.x -= 1;
            npt.y += 2;
            break;
        case move7:
            npt.x += 1;
            npt.y -= 2;
            break;
        case move8:
            npt.x -= 1;
            npt.y -= 2;
            break;
    }
    return npt;
}

void placeKnight(int row, int col, int a) {
    chessBoard[row][col] = std::to_string(a);
}

void removeKnight(int row, int col) {
    chessBoard[row][col] = ".";
}


bool Solve(int row, int col, int c) {
    if (c == 65) { // BASE CASE
        return true;
    }
    pointT p;
    display();
    std::cout << c << "\n";
    for (moveT x: {move1, move2, move3, move4, move5, move6, move7, move8}) {
        p.x = row;
        p.y = col;
        pointT pt = newMove(p, x);
        if (!canMove(pt.x, pt.y))
            continue;
        placeKnight(pt.x, pt.y, c);
        if (Solve(pt.x, pt.y, c + 1)) {
            return true;
        }
        removeKnight(pt.x, pt.y);
    }
    return false;

}
