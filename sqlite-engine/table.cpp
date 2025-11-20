#include <iostream>
#include "table.h"
#include "row.h"

void Table::addRow(Row r)
{	
	this->rows[this->rowCount] = r;
	this->rowCount++;
}

void Table::printRows()
{
	for (int i = 0; i < this->rowCount; i++)
	{
		this->rows[i].print(); 
	}
}

Table::Table()
{
	this->rows = new Row[100];
	//this->rowCount = 0;
}

Table::~Table()
{
	delete[] this->rows;
}