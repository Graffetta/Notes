#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Log.h"

static Log Logger(Log::LevelTrace);

void LoadNotes(std::string filename, std::vector<std::string>& notes)
{
	Logger.Verbose("Clearing existing notes.");
	notes.clear();
	Logger.Verbose("Notes cleared.");
	std::ifstream InputStream(filename);
	if (!InputStream.is_open()) 
	{
		Logger.Error("Could not open file.");
		return;
	}
	Logger.Verbose("Loading notes.");
	for (std::string line; getline(InputStream, line); )
		notes.push_back(line);
	Logger.Verbose("Done.");
	InputStream.close();
}

void SaveNotes(std::string filename, std::vector<std::string>& notes)
{
	std::ofstream OutputStream(filename);
	if (!OutputStream.is_open()) 
	{
		Logger.Error("Could not open file.");
		return;
	}
	Logger.Verbose("Saving notes.");
	for (const std::string Note : notes)
		OutputStream << Note << '\n';
	Logger.Verbose("Done.");
	OutputStream.close();
}

void Print(std::vector<std::string>& notes)
{
	Logger.Verbose("Printing notes.");
	unsigned int count = 0;
	for (const std::string Note : notes)
		printf(" <note #%u> %s\n", ++count, Note.c_str());
	Logger.Verbose("Done.");
}

void CreateNote(std::vector<std::string>& notes)
{
	std::string UserInput;
	printf("<notes - new> ");
	getline(std::cin, UserInput, '\n');
	notes.push_back(UserInput);
}

void DeleteNote(std::vector<std::string>& notes)
{
	Print(notes);
	int Index;
	bool ValidIndex = false;
	while (!ValidIndex)
	{
		printf("insert index: ");
		std::cin >> Index;
		Index--;
		if (Index == -1)
			return;
		if (Index <= notes.size() - 1 && Index >= 0)
			ValidIndex = true;
	}
	notes.erase(notes.begin() + Index);
}

void ClearNotes(std::vector<std::string>& notes)
{
	Logger.Verbose("Clearing Notes.");
	notes.clear();
}

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
		else if (UserInput == "-v") { Logger.SetLevel(Log::LevelVerbose); }
		else { Logger.Warn("No such command found."); }
	}
	Logger.Trace("Goodbye.");
	std::cin.get();
}
