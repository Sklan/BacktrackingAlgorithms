#ifndef PROGRAMMING_ABSTRACTION_IN_C_BACKTRACKING_H
#define PROGRAMMING_ABSTRACTION_IN_C_BACKTRACKING_H

#include <vector>
#include <iostream>

enum directionT {
    North, East, South, West
};
struct pointT {
    int x, y;
};

//int c = 1;

void generateBoard();

void tour(pointT p);
void display();

#endif //PROGRAMMING_ABSTRACTION_IN_C_BACKTRACKING_H
