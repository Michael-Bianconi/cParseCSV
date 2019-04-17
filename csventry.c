/**
 * @author Michael Bianconi
 * @since 04-17-2019
 *
 * Source code for CSVEntry and MappedCSVEntry (found in cparsecsv.h).
 */

#include "cparsecsv.h"
#include "arraylist.h"
#include <stdlib.h> // size_t, malloc(), free()
#include <string.h> // strcmp()

CSVEntry CSVEntry_create(const size_t buffer)
{
	CSVEntry entry = malloc(sizeof(struct CSVEntry_s));
	entry->data = ArrayList_create(buffer);
	return entry;
}

void CSVEntry_free(CSVEntry entry)
{
	ArrayList_free(entry->data);
	free(entry);
}

char* CSVEntry_get(const CSVEntry entry, const size_t index)
{
	if (entry->data->size >= index) return NULL;
	else return ArrayList_get(entry->data, index);
}

MappedCSVEntry MappedCSVEntry_create(const CSVHeader header)
{
	size_t buffer = header->data->size;
	MappedCSVEntry entry = malloc(sizeof(struct MappedCSVEntry_s));
	CSVEntry data = CSVEntry_create(buffer);
	entry->data = data;
	return entry;
}

void MappedCSVEntry_free(MappedCSVEntry entry)
{
	CSVEntry_free(entry->data);
	free(entry);
}

char* MappedCSVEntry_get(const MappedCSVEntry entry, const char* column)
{
	for (size_t i = 0; i < entry->header->data->size; i++)
	{
		if (strcmp(ArrayList_get(entry->header->data, i), column) == 0)
		{
			return CSVEntry_get(entry->data, i);
		}
	}

	return NULL;
}

char* MappedCSVEntry_getIndex(const MappedCSVEntry entry, const size_t index)
{
	return CSVEntry_get(entry->data, index);
}