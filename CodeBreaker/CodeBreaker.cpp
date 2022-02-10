#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>
#define MaxHealth 3

using namespace std;

void GameIntro();
void PlayerInputs(char);
void StartGame();
void RestartGame();
bool isPalindrome(string);

int health = MaxHealth;
char c;

int main()
{
	cout << "Press 'P' to start the game." << endl;
	cout << "Press 'Q' to Quit" << endl;

	cout << "\nEnter Here : ";
	cin >> c;

	PlayerInputs(c);

	return 0;
}

void StartGame() {
	int index = 0;
	int level = 1;

	health = 3;

	string str;

	fstream f_word;
	fstream f_brief;

	string words[1000];
	string briefs[1000];
	string word;
	string brief;

	int word_index = 0;
	int brief_index = 0;
	int totalWords = 0;
	int correctAns = 0;

	f_word.open("word.txt", ios::in);
	f_brief.open("briefs.txt", ios::in);

	if (f_word.is_open()) {
		while (getline(f_word, word))
		{
			words[word_index] = word;
			word_index++;
			totalWords++;
		}

		f_word.close();
	}

	if (f_brief.is_open())
	{
		while (getline(f_brief, brief))
		{
			briefs[brief_index] = brief;
			brief_index++;
		}

		f_brief.close();
	}

	GameIntro();

	do
	{
		cout << setw(25);
		cout << "Level - " << level << "\t\t" << "Health : " << health << "\n" << endl;
		cout << "Guess the words To break the password\n" << endl;
		cout << "Hints to guess the word...\n" << endl;
		cout << "* LENGTH OF THE WORD : " << words[index].length() << endl;
		cout << "* BRIEF ABOUT THE WORD : " << briefs[index] << endl;

		if (isPalindrome(words[index]))
		{
			cout << "* THE WORD IS A PALINDROME" << endl;
		}
		else {
			cout << "* THE WORD IS NOT A PALINDROME" << endl;
		}

		cout << "\nEnter the correct words : ";
		cin >> str;

		if (str == words[index]) {
			cout << "\nTHE WORD IS CORRECT" << endl;
			correctAns++;
			index++;
			Sleep(2000);
			system("cls");
		}
		else
		{
			cout << "\n NO.....THAT'S WRONG PLS TRY AGAIN..." << endl;
			health--;
			Sleep(2000);
			system("cls");
		}

		if (correctAns == 3) {
			level++;
			cout << "	------You have reached the level " << level << "------" << endl << "\n";
			correctAns = 0;

			if (health < MaxHealth) {
				cout << "      ------You got the bonus of extra 1 health------\n" << endl;
				health++;
			}
		}

	} while (index < totalWords && health > 0);

	if (health == 0) {
		RestartGame();
	}

	if (index >= totalWords) {
		cout << "The Game Over.... You have successfully completed the game..." << endl;
		RestartGame();
	}
}

void RestartGame() {
	cout << "Game Over" << endl;
	cout << "Press 'R' to restart the game or Press 'Q' to quit the game..." << endl;
	cin >> c;
	PlayerInputs(c);
}

void PlayerInputs(char c)
{
	switch (c)
	{
	case 'p':
		StartGame();
		break;
	case 'r':
		StartGame();
		break;
	case 'q':
		exit(0);
	default:
		break;
	}
}

bool isPalindrome(string str)
{
	string revStr = string(str.rbegin(), str.rend());
	if (str == revStr)
	{
		return true;
	}

	return false;
}

void GameIntro()
{
	cout << "\nGame started.....\n" << endl;
	cout << "RULES : " << endl;
	cout << "    - The Player will have three healths" << endl;
	cout << "    - Each Level has three questions" << endl;
	cout << "    - You need to finish 10 levels to reach the code" << endl;
	cout << "----------------------------------------------------------------\n" << endl;
}
