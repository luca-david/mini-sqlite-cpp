#include "database.h"

Database::Database() {
}

Database::~Database() {
	delete[] this->tables;
}

Table** Database::getTable(string name) {
	for (int i = 0; i < this->count; i++) {
		string dbNames = tables[i].getName();
		if (name == dbNames) {
			return &tables;
		}
	}
}

void Database::addTable(Table* table) {
	
	Table* copy = new Table[this->count + 1];
	for (int i = 0; i < this->count; i++) {
		copy[i] = this->tables[i];
	}
	delete[] this->tables;
	copy[this->count] = *table;
	this->count++;

	this->tables = copy;
}

bool Database::createTable(Command* cmd) {
	//CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), ...)
	string tableName = cmd->getArgument(0);
	//if not exists 
	bool ifNotExists = cmd->getArgument(1).length() > 0;
	
	return false;
}

bool Database::executeCommand(Command* cmd) {
	switch (cmd->getCommandType()) {
	case CommandType::CREATE_TABLE:
		return this->createTable(cmd);
	}
	return false;
}

Database* Database::instance = nullptr;

Database* Database::getInstance() {
	if (Database::instance == nullptr) {
		Database::instance = new Database();
	}
	return Database::instance;
}


