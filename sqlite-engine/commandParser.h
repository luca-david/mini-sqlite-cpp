#pragma once
#include "table.h"
#include "command-type.h"
#include "command.h"
#include <regex>

using namespace std;

class CommandParser
{
private:
	void runRegex(string input, Command* cmd, std::regex pattern);
	Command* createTable(string input);
	Command* dropTable(string input);
	Command* displayTable(string input);
	Command* createIndex(string input);
	Command* dropIndex(string input);
	Command* insertRow(string input);
	Command* deleteRow(string input);
	Command* selectRows(string input);
	Command* updateRow(string input);

public:
	CommandParser();
	Command* parseCommand(const string& input);
	


};