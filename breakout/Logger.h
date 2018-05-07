#pragma once
#include <string>
#include <ctime>

class Logger
{
public:
	Logger();
	
	void error(std::string err);
	void warning(std::string err);
};

