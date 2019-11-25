#include <iostream>
#include <string>
#include <vector>
#include "Log.h"

void Print(std::vector<std::string>& notes)
{
	unsigned int count = 0;
	for (const std::string Note : notes)
		printf(" <note #%u> %s\n", ++count, Note.c_str());
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
	Log Logger(Log::LevelTrace);
	Logger.Trace("Clearing Notes..");
	notes.clear();
}
