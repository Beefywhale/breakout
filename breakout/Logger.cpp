#include "Logger.h"

Logger::Logger()
{
}

void Logger::error(std::string err) {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	char buf[255];
	strftime(buf, sizeof(buf), "[%H:%M %p] ERROR", now);
	std::string time(buf);
	fprintf(stderr, (time+" "+err+"\n").c_str());
}

void Logger::warning(std::string warn) {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	char buf[255];
	strftime(buf, sizeof(buf), "[%H:%M %p] WARNING", now);
	std::string time(buf);
	fprintf(stderr, (time + " " + warn+"\n").c_str());
}