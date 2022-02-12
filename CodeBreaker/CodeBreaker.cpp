#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>
#define MaxHealth 3

using namespace std;

void GameIntro();
void StoryLine();
void PlayerInputs(char);
void StartGame();
void RestartGame();
bool isPalindrome(string);
void Loading(int);
void AsciiArt();
void TitleAscii();

int health = MaxHealth;
char c;

int main()
{
	TitleAscii();
	cout << "\n			Press 'P' to start the game." << endl;
	cout << "			Press 'Q' to Quit" << endl;
	cout << "\n			Enter Here : ";
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
	fstream f_riddle;

	string words[1000];
	string briefs[1000];
	string riddles[1000];
	string word;
	string brief;
	string riddle;

	int word_index = 0;
	int brief_index = 0;
	int riddle_index = 0;
	int totalWords = 0;
	int correctAns = 0;
	int question = 1;

	f_word.open("word.txt", ios::in);
	f_brief.open("briefs.txt", ios::in);
	f_riddle.open("riddles.txt", ios::in);

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

	if (f_riddle.is_open())
	{
		while (getline(f_riddle, riddle))
		{
			riddles[riddle_index] = riddle;
			riddle_index++;
		}

		f_riddle.close();
	}

	GameIntro();

	do
	{
		cout << setw(25);
		cout << "		Level - " << level << "\t\t" << "Health : " << health << "\n" << endl;
		cout << "		Guess the words To break the password\n" << endl;
		Loading(level);
		cout << "\n";
		cout << "		" << question << ". " << riddles[index] << "\n" << endl;
		cout << "		Hints to guess the word...\n" << endl;
		cout << "		* LENGTH OF THE WORD : " << words[index].length() << endl;
		cout << "		* BRIEF ABOUT THE WORD : " << briefs[index] << endl;

		if (isPalindrome(words[index]))
		{
			cout << "		* THE WORD IS A PALINDROME" << endl;
		}
		else {
			cout << "		* THE WORD IS NOT A PALINDROME" << endl;
		}

		cout << "\n";
		cout << "		Enter the correct words : ";
		cin >> str;
		
		if (str == words[index]) {
			cout << "\n";
			cout << "		THE WORD IS CORRECT" << endl;
			correctAns++;
			index++;
			question++;
			Sleep(2000);
			system("cls");
			TitleAscii();
			GameIntro();
		}
		else
		{
			cout << "\n";
			cout << "		NO.....THAT'S WRONG PLS TRY AGAIN..." << endl;
			health--;
			Sleep(2000);
			system("cls");
			TitleAscii();
			GameIntro();
		}

		if (correctAns == 3) {
			level++;
			cout << "		------You have reached the level " << level << "------" << endl << "\n";
			correctAns = 0;

			if (health < MaxHealth) {
				cout << "		------You got the bonus of extra 1 health------\n" << endl;
				health++;
			}
		}

	} while (index < totalWords && health > 0);

	if (health == 0) {
		RestartGame();
	}

	if (index >= totalWords) {
		AsciiArt();
		RestartGame();
	}
}

void RestartGame() {
	cout << "\n			********** Game Over **********\n" << endl;
	cout << "	Press 'R' to restart the game or Press 'Q' to quit the game..." << endl;
	cout << "	Enter Here : ";
	cin >> c;
	PlayerInputs(c);
}

void PlayerInputs(char c)
{
	switch (c)
	{
	case 'p':
		StoryLine();
		StartGame();
		break;
	case 'r':
		system("cls");
		TitleAscii();
		StartGame();
		break;
	case 'q':
		exit(0);
	default:
		break;
	}
}

void Loading(int level) {
	int percent = 0;
	cout << "		BREACHING STATUS....." << endl;
	cout << "		";
	for (int i = 1; i <= level - 1; i++)
	{
		cout << "##";
		percent += 10;
	}
	cout << "\n		____________________" << endl;
	cout << "			" << percent <<"%	 \n" << endl;
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
	cout << "\n";
	cout << "		Game started.....\n" << endl;
	cout << "		RULES : " << endl;
	cout << "			- The Player will only have three attempts" << endl;
	cout << "			- Each Level has three questions" << endl;
	cout << "			- You need to finish 10 levels to breach the password" << endl;
	cout << "		----------------------------------------------------------------\n" << endl;
}

void StoryLine()
{
	string str = "		YOU ARE A VIGILANTE HACKER WANTS TO HACK THE SYSTEM OF DRUG DEALER WHO MAKES DEALING IN THE DARK WEB.....\n\n";
	string str1 = "		YOU NEED TO BREACH INTO 10 LEVEL OF SECURITY TO CRACK THE PASSWORD OF HIS SYSTEM....\n";

	cout << "\n";
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		Sleep(50);
	}
	cout << "\n";
	for (int i = 0; i < str1.length(); i++)
	{
		cout << str1[i];
		Sleep(50);
	}
}

void TitleAscii()
{
	cout << setw(50);
	cout <<
		R"(                        
		                       $$ |               $$ |                                $$ |                        
		$$$$$$$\ $$$$$$\  $$$$$$$ |$$$$$$\        $$$$$$$\  $$$$$$\  $$$$$$\  $$$$$$\ $$ |  $$\ $$$$$$\  $$$$$$\  
		$$  _____$$  __$$\$$  __$$ $$  __$$\       $$  __$$\$$  __$$\$$  __$$\ \____$$\$$ | $$  $$  __$$\$$  __$$\ 
		$$ /     $$ /  $$ $$ /  $$ $$$$$$$$ |      $$ |  $$ $$ |  \__$$$$$$$$ |$$$$$$$ $$$$$$  /$$$$$$$$ $$ |  \__|
		$$ |     $$ |  $$ $$ |  $$ $$   ____|      $$ |  $$ $$ |     $$   ____$$  __$$ $$  _$$< $$   ____$$ |      
		\$$$$$$$\\$$$$$$  \$$$$$$$ \$$$$$$$\       $$$$$$$  $$ |     \$$$$$$$\\$$$$$$$ $$ | \$$\\$$$$$$$\$$ |      
		\_______|\______/ \_______|\_______|      \_______/\__|      \_______|\_______\__|  \__|\_______\__| 
		)";
}

void AsciiArt()
{
cout << 
R"(   
	   $$\                           $$\                       $$\ 
	   $$ |                          $$ |                      $$ |
	   $$$$$$$\   $$$$$$\   $$$$$$$\ $$ |  $$\  $$$$$$\   $$$$$$$ |
	   $$  __$$\  \____$$\ $$  _____|$$ | $$  |$$  __$$\ $$  __$$ |
	   $$ |  $$ | $$$$$$$ |$$ /      $$$$$$  / $$$$$$$$ |$$ /  $$ |
	   $$ |  $$ |$$  __$$ |$$ |      $$  _$$<  $$   ____|$$ |  $$ |
	   $$ |  $$ |\$$$$$$$ |\$$$$$$$\ $$ | \$$\ \$$$$$$$\ \$$$$$$$ |
	   \__|  \__| \_______| \_______|\__|  \__| \_______| \_______|
    )";
}