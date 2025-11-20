#include <iostream>
#include <string>
#include "row.h"
#include "table.h"
using namespace std;

int main()
{
	Row row0(0, "prod1", 3.99f);
	Row row1(1, "prod2", 5.99f);
	Row row2(2, "prod3", 10.99f);

	Table t;
	t.addRow(row0);
	t.addRow(row1);
	t.addRow(row2);
	
	t.printRows();

	cout << endl;
	return 0;
}