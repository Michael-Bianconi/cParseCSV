/**
 * @author Michael Bianconi
 * @since 04-17-2019
 *
 * Unit testing suite for CSVEntry and MappedCSVEntry.
 */

#include "cparsecsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void _TEST_CSVENTRY_CREATE()
{
	CSVEntry entry = CSVEntry_create(0);
	assert(entry != NULL);
	assert(entry->data->buffer == 1);
	CSVEntry_free(entry);

	entry = CSVEntry_create(5);
	assert(entry != NULL);
	assert(entry->data->buffer == 5);
	CSVEntry_free(entry);

	printf("_TEST_CSVENTRY_CREATE(): SUCCESS\n");

	return;
}

static void _TEST_CSVENTRY_GET()
{
	CSVEntry entry = CSVEntry_create(5);
	ArrayList_addAll(entry->data, 5, "1", "12", "123", "1234", "12345");
	for (size_t n = 0; n < entry->data->size; n++)
	{
		char* data = CSVEntry_get(entry, n);
		assert(data != NULL);
	}
	assert(CSVEntry_get(entry, entry->data->size) == NULL);
	CSVEntry_free(entry);

	printf("_TEST_CSVENTRY_GET(): SUCCESS\n");
	return;
}

static void _TEST_MAPPEDCSVENTRY_CREATE()
{
	CSVHeader header = CSVEntry_create(3);
	ArrayList_addAll(header->data, 3, "A", "B", "C");
	MappedCSVEntry entry = MappedCSVEntry_create(header);
	assert(entry != NULL);
	MappedCSVEntry_free(entry);
	CSVEntry_free(header);

	printf("_TEST_MAPPEDCSVENTRY_CREATE(): SUCCESS\n");
	return;
}

static void _TEST_MAPPEDCSVENTRY_GET()
{
	CSVHeader header = CSVEntry_create(3);
	ArrayList_addAll(header->data, 3, "A", "B", "C");
	MappedCSVEntry entry = MappedCSVEntry_create(header);
	ArrayList_addAll(entry->data->data, 3, "a", "b", "c");
	assert(entry != NULL);
	assert(strcmp(MappedCSVEntry_get(entry, "A"),"a") == 0);
	assert(strcmp(MappedCSVEntry_get(entry, "B"),"b") == 0);
	assert(strcmp(MappedCSVEntry_get(entry, "C"),"c") == 0);
	assert(MappedCSVEntry_get(entry, "D") == NULL);

	MappedCSVEntry_free(entry);
	CSVEntry_free(header);

	printf("_TEST_MAPPEDCSVENTRY_GET(): SUCCESS\n");
	return;
}

static void _TEST_MAPPEDCSVENTRY_GETINDEX()
{
	CSVHeader header = CSVEntry_create(3);
	ArrayList_addAll(header->data, 3, "A", "B", "C");
	MappedCSVEntry entry = MappedCSVEntry_create(header);
	ArrayList_addAll(entry->data->data, 3, "a", "b", "c");
	assert(entry != NULL);
	assert(strcmp(MappedCSVEntry_getIndex(entry, 0),"a") == 0);
	assert(strcmp(MappedCSVEntry_getIndex(entry, 1),"b") == 0);
	assert(strcmp(MappedCSVEntry_getIndex(entry, 2),"c") == 0);
	assert(MappedCSVEntry_getIndex(entry, 3) == NULL);

	MappedCSVEntry_free(entry);
	CSVEntry_free(header);

	printf("_TEST_MAPPEDCSVENTRY_GETINDEX(): SUCCESS\n");
	return;
}

int main(int argc, char** argv)
{
	(void) argc;
	(void) argv;

	_TEST_CSVENTRY_CREATE();
	_TEST_CSVENTRY_GET();
	_TEST_MAPPEDCSVENTRY_CREATE();
	_TEST_MAPPEDCSVENTRY_GET();
	_TEST_MAPPEDCSVENTRY_GETINDEX();
}