#include <iostream>
#include <string>
#include "row.h"
#include "table.h"
#include "command-type.h"
#include "commandParser.h"
#include "stringUtils.h"
#include "database.h"
#include "command.h"
#include <regex>

using namespace std;

int main()
{
    std::string inputs[] = {
        "CREATE TABLE mytable1 IF NOT EXISTS ((column_1_name,integer,5, 2), (column_2_name,text,23, default_value), (column_3_name, float, 124, 2.0))",
        "CREATE TABLE table_name ((column_1_name,integer,5, 2), (column_2_name,text,23, default_value), (column_3_name, float, 124, 2.0))",
        "CREATE TABLE ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value))",

        "DISPLAY TABLE mytable1",
        "DROP TABLE mytable1",

        "CREATE INDEX index_name ON table_name (column_name)",
        "CREATE INDEX IF NOT EXISTS index_name ON table_name (column_name)",
        "DROP INDEX index_name",

        "INSERT INTO mytable1 VALUES(5 ,'blabla', 6.7)",
        "INSERT INTO mytable2 VALUES('blabla')",

        "DELETE FROM table_name WHERE column_name = value",

        "SELECT (column_1, column_2) FROM table_name",
        "SELECT (column_1) FROM table_name WHERE column_name = value",
        "SELECT ALL FROM table_name",
        "SELECT ALL FROM table_name",

        "UPDATE table_name SET column_name = value WHERE column_name = value",
        "UPDATE table_name SET column_name = value WHERE some_other_column = some_value",
    };
	
	CommandParser parser;
    for (string input : inputs) {
        Command* cmd = parser.parseCommand(input);
        if (cmd == nullptr) {
            continue;
        }
        Database* db = Database::getInstance();
        db->executeCommand(cmd);
        std::cout << *db;
        cout << input << endl;
        cout << cmd << endl << endl;
    }

    Database* db = Database::getInstance();
    Database* db2 = Database::getInstance();
    
    *db = *db2;
    
	
	cout << endl;
	return 0;
}