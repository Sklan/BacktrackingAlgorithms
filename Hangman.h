//
// Created by sklan on 14/07/17.
//

#include <string>
#include <random>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
#ifndef PROGRAMMING_ABSTRACTION_IN_C_RANDWORD_H
#define PROGRAMMING_ABSTRACTION_IN_C_RANDWORD_H

vector <string> initDictionary();
/*
 * This function loads a file and reads words from it.
 */

vector <char> chooseRandomWord();
/*
 * This function calls init dictionary selects a random word from the file and returns it.
 */

void Hangman();
/*
 * Executes Hangman game
 */
#endif //PROGRAMMING_ABSTRACTION_IN_C_RANDWORD_H
