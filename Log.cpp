#include "Log.h"
#include <iostream>

void Log::SetLevel(Level level)
{
	this->m_LogLevel = level;
}

void Log::Verbose(const char* message)
{
	if (this->m_LogLevel >= LevelVerbose)
		std::cout << "[Verbose]: " << message << std::endl;
}

void Log::Trace(const char* message)
{
	if (this->m_LogLevel >= LevelTrace)
		std::cout << "[Trace]: " << message << std::endl;
}

void Log::Warn(const char* message)
{
	if (this->m_LogLevel >= LevelWarning)
		std::cout << "[Warning]: " << message << std::endl;
}

void Log::Error(const char* message)
{
	if (this->m_LogLevel >= LevelError)
		std::cout << "[Error]: " << message << std::endl;
}

Log::Log() 
{
	this->SetLevel(LevelWarning);
}

Log::Log(Level level)
{
	this->SetLevel(level);
}
