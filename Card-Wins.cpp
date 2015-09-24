// Card Wins works out how many people win a game of cards and the gives the players in a text file.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>



struct Players {
	std::string Name = "";
	int Wins = 0;
};

int main() {
	// Start by finding the file you want to use
	std::string FileName;
	// Input file name
	std::cout << "Which file do you want to use.\n:";
	std::cin >> FileName;
	// Create Vector with the players, using vec because of an undiefined amount of players
	std::vector<Players> VecPlayers;
	
	// Count counts number of players and lines
	unsigned int Count = 0;
	// StrLine is a general string used for storing lines in  files
	std::string StrLine = "";

	// Give players that are playing then add them to the vector
	std::cout << "Please give the players.\n: ";
	while (std::cin >> StrLine) {
		VecPlayers.push_back(Players());
		VecPlayers[Count].Name = StrLine;
		Count++;
		std::cout << ": ";
	}
	// Clear the input buffer
	std::cin.ignore('/n');
	std::cin.clear();

	// Awnser is the first name of a player who won
	char Answer = 'a';
	// Checks if Awnser is a players first name
	bool Success = false;
	// File used for all file operations
	std::fstream File;
	// Open the FileName with operations at 
	File.open(FileName, std::ios::app);
	File << "*" << "\n";
	File.close();

	for (Count = 0; Count < VecPlayers.size(); Count++) {
		File.open(FileName);
		while (getline(File, StrLine, '\n')) {
			if (StrLine == VecPlayers[Count].Name)
				VecPlayers[Count].Wins++;
		}
		File.close();
	}
	for (Count = 0; Count < VecPlayers.size(); Count++)
		std::cout << VecPlayers[Count].Name << " has " << VecPlayers[Count].Wins << std::endl;
	
	std::cout << "\nWho won?\n: ";

	
	while (std::cin >> Answer) {
		Answer = toupper(Answer);
		Success = false;
		for (Count = 0; Count < VecPlayers.size(); Count++) {
			if (VecPlayers[Count].Name[0] == Answer) {
				VecPlayers[Count].Wins++;
				File.open(FileName, std::ios::app);
				File << VecPlayers[Count].Name << "\n";
				File.close();
				Success = true;
			}
		}
		if (Success == false) {
			std::cout << "Looks like you entered something that didn't work, "
				<< "you have to enter the first of letter of a players name.";
		}
		else { 
			for (Count = 0; Count < VecPlayers.size(); Count++) {
				std::cout << VecPlayers[Count].Name << " has " << VecPlayers[Count].Wins << std::endl;
			}
		}
		std::cout << "\nWho won?\n: ";
	}

	return 0;
}
