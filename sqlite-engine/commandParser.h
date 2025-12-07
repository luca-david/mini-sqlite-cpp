#pragma once
#include "table.h"
#include "command-type.h"
#include "command.h"
#include <regex>

using namespace std;

class CommandParser
{
private:
	int noOfCommandsParsed = 0;

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
	CommandParser(CommandParser& other);
	~CommandParser();
	void operator=(CommandParser other);
	bool operator==(CommandParser& other);
	CommandParser operator++(int); //for post increment
	bool operator>(CommandParser& other);
	friend std::ostream& operator<<(std::ostream& console, CommandParser parser);
	Command* parseCommand(const string& input);


	


};