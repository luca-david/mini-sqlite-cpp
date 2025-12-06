#include <iostream>
#include "table.h"
#include "row.h"


Table::Table() {
	this->rows = new Row[100];
	this->rowCount = 0;
}

Table::~Table() {
	delete[] this->rows;
}

string Table::getName() {
	return this->tableName;
}