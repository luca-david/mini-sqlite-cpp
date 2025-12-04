#pragma once
#include "table.h"
#include "command-type.h"
#include <regex>

using namespace std;

class CommandParser
{
private:
	string command = "";
	bool isValid = 0;
	CommandType type = CommandType::UNKNOWN_CMD;

public:
	static CommandType getCommandType(const string& input);

private:
	void extractTableColumns(string input);

public:
	CommandParser();

	void createTable(string input);
	void dropTable(string input);
	void displayTable(string input);
	void createIndex(string input);
	void dropIndex(string input);
	void insertRow(string input);
	void deleteRow(string input);
	void selectRows(string input);
	void updateRow(string input);


};