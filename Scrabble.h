/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* This file contains helper functions for the program
*
*/


#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int maxLetters = 10;
int rounds = 5;
int tries = 2;
int shuffles = 2;

int main();
void menu();
void nameOfTheGame();
void inputFromThePlayer();
void playGame();
void numberFromTheList();
bool checkCharacters(string input, vector<char> characters);
bool checkIfDictionaryContainTheWord(string input, vector<string> words);
bool checkIfLengthOfInputIsSmallerThanGivenLetters(int currentMaxLetters, string input);
