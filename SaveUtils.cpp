#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Log.h"

void LoadNotes(std::string filename, std::vector<std::string>& notes)
{
	Log Logger(Log::LevelTrace);
	Logger.Trace("Loading notes..");
	notes.clear();
	std::ifstream InputStream(filename);
	if (!InputStream.is_open())
	{
		Logger.Error("Could not open file.");
		return;
	}
	for (std::string line; getline(InputStream, line); )
		notes.push_back(line);
	InputStream.close();
}

void SaveNotes(std::string filename, std::vector<std::string>& notes)
{
	Log Logger(Log::LevelTrace);
	Logger.Trace("Saving notes..");
	std::ofstream OutputStream(filename);
	if (!OutputStream.is_open())
	{
		Logger.Error("Could not open file.");
		return;
	}
	for (const std::string Note : notes)
		OutputStream << Note << '\n';
	OutputStream.close();
}
