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
	CSVEntry data1 = CSV_readLine(in);
	CSVEntry data2 = CSV_readLine(in);
	CSVEntry null = CSV_readLine(in);

	assert(header);
	assert(data1);
	assert(data2);
	assert(!null);

	CSVEntry_free(data1);
	CSVEntry_free(data2);
	CSVEntry_free(header);
	fclose(in);

	printf("_TEST_CSV_READLINE(): SUCCESS\n");
}

static void _TEST_CSV_READMAPPEDLINE()
{
	FILE* in = fopen("test/csvtest.csv","r");
	assert(in);
	CSVHeader header = CSV_readLine(in);
	MappedCSVEntry line1 = CSV_readMappedLine(header, in);
	MappedCSVEntry line2 = CSV_readMappedLine(header, in);
	MappedCSVEntry null  = CSV_readMappedLine(header, in);

	assert(line1);
	assert(line2);
	assert(!null);

    ArrayList_print(line2->data->data);


	CSVEntry_free(header);
	MappedCSVEntry_free(line1);
	MappedCSVEntry_free(line2);
	fclose(in);

	printf("_TEST_CSV_READMAPPEDLINE(): SUCCESS\n");
}

int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	_TEST_CSV_READLINE();
	_TEST_CSV_READMAPPEDLINE();
	test();

}