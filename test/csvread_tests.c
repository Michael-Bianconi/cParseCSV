/**
 * @author Michael Bianconi
 * @since 04-17-2019
 *
 * Unit testing for CSV reading (from cparsecsv.h).
 */

#include "cparsecsv.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


static void _TEST_CSV_READLINE()
{
	FILE* in = fopen("test/csvtest.csv","r");
	assert(in);
	CSVHeader header = CSV_readLine(in);
	ArrayList_print(header->data);
	CSVEntry data1 = CSV_readLine(in);
	ArrayList_print(data1->data);
	CSVEntry data2 = CSV_readLine(in);
	ArrayList_print(data2->data);

	printf("_TEST_CSV_READLINE(): SUCCESS\n");
}

int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	_TEST_CSV_READLINE();

}