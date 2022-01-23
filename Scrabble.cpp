// Scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.
/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikol Nikolaeva
* @idnumber 2MI0600079
* @compiler VC
*
* cpp file with the functions and main function
*
*/


// Using a premade online dictionary, some words may be missing!!!

#include "Scrabble.h"
using namespace std;

fstream myfile("words_scrabble.txt");
int const MAX_SIZE = 100;

bool endOfTheGame = true;
string input;


bool checkIfDictionaryContainTheWord(string input, vector<string> words)
{
	fstream file;
	file.open("words_scrabble.txt");

	if ((find(words.begin(), words.end(), input) != words.end()) == false)
	{
		return false;
	}
	return true;
}

bool checkIfLengthOfInputIsSmallerThanGivenLetters(int currentMaxLetters, string input)
{
	if (currentMaxLetters < input.length())
	{
		return false;
	}

	return true;
}

bool checkCharacters(string input, vector<char> characters)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (find(characters.begin(), characters.end(), input[i]) != characters.end() == false)
		{
			return false;
		}
	}

	return true;
}

void playGame()
{

	vector<string> words;
	ifstream myfile("words_scrabble.txt"); //file with words which play the function of Dictionary
	copy(istream_iterator<string>(myfile), istream_iterator<string>(), back_inserter(words));
	vector<char> characters;
	int points = 0;
	int roundNumber = 1;
	int currentRounds = rounds;
	int currentMaxLetters = maxLetters;
	int currentShuffles = shuffles;
	int currentTries = tries;
	"\n";
	cout << "   When you want to finish the game, type 7" << endl;



	while (currentRounds > 0)                                // loop for the rounds
	{
		cout << endl;
		cout << "   -------->Round: " << roundNumber << " ";


		while (currentTries > 0)                             //loop for the tries in one round
		{
			int iterator = 0;
			int residue;

			cout << "   Available letters: ";

			while (iterator < currentMaxLetters)
			{
				residue = rand() % 26;                       ////(rand() % 26)- a residue from a random number from 26(letters in the alphabet are 26)
				characters.push_back('a' + residue);         // generate a random number, convert to a character from a-z
				cout << characters[iterator] << " ";         //'a'+ residue gives the number ftom ASCII and it is transfer in char symbol
				iterator += 1;
			}


			cout << endl;
			cout << "   Try with word or type 0 for new letters: ";
			cout << "   ";
			cin >> input;

			if (input == "7")
			{
				endOfTheGame = false;
				break;
			}

			if (input == "0" && currentShuffles > 0)
			{
				characters.clear();
				currentShuffles -= 1;
				cout << "   Remaining shuffles: " << currentShuffles << endl;
				cout << "   Try again with -> ";
				iterator = 0;
				continue;
			}
			else if (!checkIfLengthOfInputIsSmallerThanGivenLetters(currentMaxLetters, input) || !checkCharacters(input, characters) || !checkIfDictionaryContainTheWord(input, words))
			{
				currentTries -= 1;
				if (currentTries > 0)
				{
					cout << "   Invalid word. Remaining tries: " << currentTries << endl;
				}
				else
				{
					cout << "   Invalid word. No remaining tries!" << endl;
				}
				continue;
			}
			else
			{
				points += input.length();
				cout << "   Your points so far are: " << points << endl;
				characters.clear();
				break;
			}
		}
		if (input == "7")
		{
			cout << "   Game over! :(" << endl;
			endOfTheGame = false;
			break;
		}
		currentShuffles = shuffles;
		roundNumber++;
		currentRounds--;
		currentTries = tries;
		characters.clear();
		if (currentRounds == 0)
		{
			cout << endl;
			cout << "   Game over!" << endl;
			cout << "   Your total points are: " << points << endl;
			cout << "   Returning to menu." << endl;
			cout << endl;
		}
	}
}

void numberFromTheList()
{
	char input;
	cin >> input;

	if (input == '1')
	{
		playGame();
	}
	else if (input == '2')
	{
		cout << "   Maxmium letters: ";
		cin >> maxLetters;
	}
	else if (input == '3')
	{
		cout << "   Rounds: ";
		cin >> rounds;
	}
	else if (input == '4')
	{
		cout << "   Maxmium tries: ";
		cin >> tries;
	}
	else if (input == '5')
	{
		cout << "   Shuffles: ";
		cin >> shuffles;
	}
	else if (input == '6')
	{
		cout << "   Please input the new word: ";
		string word;
		fstream myfile;
		myfile.open("words_scrabble.txt", ios::app);		// using ios::app to append(edit) file instead of
		cin >> word;
		myfile << "\n";										// overwriting it(adds the word at the end) instead of
		myfile << word;										// removing all the content and adding the new word as the only entry
		myfile.flush();										// also writes the new word at the bottom
		myfile.close();										// flush saves changes made		
		cout << "   Word added!" << endl;
	}
	else if (input == '7')
	{
		endOfTheGame = false;
	}
	else {
		while (input != '1' || input != '2' || input != '3' || input != '4' || input != '5' || input != '6' || input != '7')
		{
			cout << "   Wrong operator used. Please use from 1-7(Single digits only)" << endl;
			cin >> input;
		}
	}
}

void nameOfTheGame()
{
	cout << "   Let's play" << endl;
	cout << endl;
	cout << "   ####    ####   ####       #       ###     ###     #      ####" << endl;
	cout << "   #      #       #   #     # #      #   #   #   #   #      #" << endl;
	cout << "    ##    #       ####     #####     ####    ####    #      ####" << endl;
	cout << "      #   #       # #     #     #    #   #   #   #   #      #" << endl;
	cout << "   ####    ####   #  #   #       #   ###     ###     ####   ####" << endl;
	cout << endl;
}
void menu()
{
	cout << "   -----Menu:-------------------------------------------" << endl;
	cout << "   ->Enter 1 to start a new game" << endl;
	cout << "   ->Enter 2 to change the number of letters" << endl;
	cout << "   ->Enter 3 to change the number of rounds" << endl;
	cout << "   ->Enter 4 to change the number of tries in one round" << endl;
	cout << "   ->Enter 5 to change the number of shuffles" << endl;
	cout << "   ->Enter 6 to add a new word in the Dictionary" << endl;
	cout << "   ->Enter 7 to finish the game" << endl;
	cout << "   -----------------------------------------------------" << endl;
	cout << "   Your choice: ";
}

void inputFromThePlayer()
{
	while (endOfTheGame != false)
	{
		menu();
		numberFromTheList();
	}

}

int main()
{
	srand(time(NULL));             //Used to generate the random letters for the game
	nameOfTheGame();
	inputFromThePlayer();

	return 0;
}
