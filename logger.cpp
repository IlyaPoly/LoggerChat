#include "logger.h"


Log::Log()
{
	file = std::fstream("log.txt", std::ios::in);
}
Log::~Log()
{
	file.close();
}
bool Log::writeFile(std::string str)
{
	sh_m.lock();
	int size = file.tellg();
	file << str;
	if (file.tellg() != size)
	{
		sh_m.unlock();
		return true;
	}
	sh_m.unlock();
	return false;
}
std::string Log::readFile()
{
	std::string str{}, buf{};
	if(!file.is_open())
	{
		std::cout << "File could not be opened" << std::endl;
		exit(1);
	}
	sh_m.lock_shared();
	while (getline(file, buf))
		str = buf;
	sh_m.unlock_shared();
	return str;
}