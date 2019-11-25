#pragma once
class Log
{
public:
	enum Level {
		LevelError = 0, LevelWarning, LevelTrace, LevelVerbose
	};
	void SetLevel(Level);
	void Verbose(const char*);
	void Trace(const char*);
	void Warn(const char*);
	void Error(const char*);
	Log();
	Log(Level);
private:
	Level m_LogLevel;
};

