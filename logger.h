#pragma once
#include <iostream>
#include <fstream>
#include <shared_mutex>
#include <string>

class Log
{
	std::fstream file;
	std::shared_mutex sh_m;
public:
	Log();
	~Log();
	bool writeFile(std::string str);
	std::string readFile();
};