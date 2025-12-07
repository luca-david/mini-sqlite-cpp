#pragma once
#include "table.h"
#include "commandParser.h"
#include "command.h"

class Database { 
	static Database* instance;
	Table* tables = nullptr;
	int count = 0;
	Database();
	~Database();
	Database(Database& other);
	Table** getTable(string name);
	void addTable(Table* table);
	bool createTable(Command* cmd);

public:
	Table* getTables();
	int getCount();
	static Database* getInstance();
	
	void operator=(Database& other);
	void operator+=(int additionalTables);
	bool operator==(Database& other);
	friend std::ostream& operator<<(std::ostream& console, Database& db);
	
	bool executeCommand(Command* cmd);
	
};