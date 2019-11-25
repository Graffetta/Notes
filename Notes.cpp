#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Log.h"

static Log Logger(Log::LevelTrace);

void SaveNotes(std::string, std::vector<std::string>&);
void LoadNotes(std::string, std::vector<std::string>&);
void Print(std::vector<std::string>&);
void CreateNote(std::vector<std::string>&);
void DeleteNote(std::vector<std::string>&);
void ClearNotes(std::vector<std::string>&);

int main()
{
	Logger.Verbose("Creating notes vector.");
	std::vector<std::string> Notes;

	bool Exit = false;
	std::string UserInput = "";
	while (!Exit)
	{
		std::cout << "/em/Notes $ " << std::flush;
		getline(std::cin, UserInput, '\n');
		if (UserInput == "save") { SaveNotes("Notes.txt", Notes); }
		else if (UserInput == "load") { LoadNotes("Notes.txt", Notes); }
		else if (UserInput == "print") { Print(Notes); }
		else if (UserInput == "create") { CreateNote(Notes); }
		else if (UserInput == "delete") { DeleteNote(Notes); }
		else if (UserInput == "clear") { ClearNotes(Notes); }
		else if (UserInput == "exit" || UserInput == "quit") { Exit = true; }
		else { Logger.Warn("No such command found."); }
	}
	Logger.Trace("Goodbye.");
	std::cin.get();
}
