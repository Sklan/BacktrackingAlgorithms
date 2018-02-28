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


double raiseToPower(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        double k = 1;
        while (n != 0 && n % 2 == 0) {
            k *= x;
            n /= 2;
        }
        return raiseToPower(k, n) * k;
    } else {
        return raiseToPower(x, n - 1) * x;
    }
}

void insertionSort(std::vector<int> &v) {
    for (int i = 1; i != v.size(); i++) {
        int key = v[i];
        int j = i - 1;
        while (j > 0 && v[i] > key) {
            v[j + 1] = v[j];
            i = i - 1;
        }
        v[j + 1] = key;
    }
}

int Partition(std::vector<int> &vec, int start, int finish) {
    int pivot = vec[start];
    int lh = start + 1;
    int rh = finish;
    while (true) {
        while (lh < rh && vec[rh] >= pivot) rh--;
        while (lh < rh && vec[lh] < pivot) lh++;
        if (lh == rh) break;
        int temp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = temp;
    }
    if (vec[lh] >= pivot) return start;
    vec[start] = vec[lh];
    vec[lh] = pivot;
    return lh;
}

void Quicksort(std::vector<int> &vec, int start, int finish) {
    if (start >= finish) return;
    int boundary = Partition(vec, start, finish);
    Quicksort(vec, start, boundary - 1);
    Quicksort(vec, boundary + 1, finish);
}


void newSort(std::vector<int> &vec, int start, int finish) {
    if (vec.size() <= 30) {
        insertionSort(vec);
        return;
    } else if (start >= finish) {
        return;
    }
    int boundary = Partition(vec, start, finish);
    Quicksort(vec, start, boundary - 1);
    Quicksort(vec, boundary + 1, finish);
}

void newSort2(std::vector<int> &vec, int start, int finish) {
    if (vec.size() <= 5) {
        return;
        return;
    } else if (start >= finish) {
        return;
    }
    int boundary = Partition(vec, start, finish);
    Quicksort(vec, start, boundary - 1);
    Quicksort(vec, boundary + 1, finish);
}

void time() {
    double start, finish, elapsed;
    double sum_time = 0;
    std::cout << "\tN\t|\tTime (us)\n";
    for (int x:{10, 20, 40, 100, 200, 400, 1000, 2000, 4000, 10000}) {
        std::vector<int> v;
        for (int i = x; i != 0; i--) {
            v.push_back(i);
        }

        for (int i = 0; i != 1000; i++) {
            start = double(clock()) / CLOCKS_PER_SEC;
            newSort(v, 0, v.size() - 1);
            insertionSort(v);
            finish = double(clock()) / CLOCKS_PER_SEC;
            elapsed = finish - start;
            sum_time += elapsed;
        }
        std::cout << "\t" << x << "|\t" << sum_time / 1000 * 1000000 << "\n";
    }
}

int MajorityElement(std::vector<int> &vec) {
    int count = 0;
    int maje;
    for (int i: vec) {

    }
    if (count < vec.size() / 2)
        return -1;
    else
        return maje;
}
