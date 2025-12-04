#include <iostream>
#include <string>
#include "row.h"
#include "table.h"
#include "command-type.h"
#include "commandParser.h"
#include "stringUtils.h"
#include "tokenizer.h"
#include <regex>

using namespace std;

int main()
{
	//Row row0(0, "prod1", 3.99f);
	//Row row1(1, "prod2", 5.99f);
	//Row row2(2, "prod3", 10.99f);

	//Table t;
	//t.addRow(row0);
	//t.addRow(row1);
	//t.addRow(row2);
	//
	//t.printRows();

	//string input = "drop table";
	///*cout << endl << endl << "Command: ";
	//getline(cin, input); FOR USER INPUT*/

	////first of all, make input uppercase
	//toUpper(input);

	////check if we can get the command type
	//CommandType cmdTypeFromInput = CommandParser::getCommandType(input);
	//if (cmdTypeFromInput == CommandType::CREATE_TABLE)
	//{
	//	cout << endl << "Creating table...";
	//}

	//else if (cmdTypeFromInput == CommandType::DROP_TABLE)
	//{
	//	cout << endl << "Drop table command was called...";
	//}
	//else if (cmdTypeFromInput == CommandType::INSERT_CMD)
	//{
	//	cout << endl << "Insert command was called...";
	//}
	//else if (cmdTypeFromInput == CommandType::SELECT_CMD)
	//{
	//	cout << endl << "Select command was called...";
	//}
	//else if (cmdTypeFromInput == CommandType::DELETE_CMD)
	//{
	//	cout << endl << "Delete command was called...";
	//}

	//else
	//{

	//	cout << endl << "Unkown command";
	//}
	//
	////tokenizer test
	//cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	//cout << endl << "Testing the tokenizer";
	//Tokenizer tok(100);
	//tok.tokenize(input);
	//tok.printTokens();
	//cout << endl << "Token at index 0: " << tok.getToken(0);
	//cout << endl << "Token at index 1: " << tok.getToken(1);
	//cout << endl << "Number of tokens(using getter): " << tok.getTokenCount();

	CommandParser parser = CommandParser();
	string input = "CREATE TABLE mytable1 IF NOT EXISTS ((column_1_name,integer,5, 2), (column_2_name,text,23, default_value), (column_3_name, float, 124, 2.0))";
	parser.createTable(input);
	cout << endl;

	cout << endl;
	return 0;
}