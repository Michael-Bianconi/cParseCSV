/**
 * @author Michael Bianconi
 * @since 04-17-2019
 *
 * Source code for CSVEntry and MappedCSVEntry (found in cparsecsv.h).
 */

#include "cparsecsv.h"
#include <stdlib.h> // size_t, malloc(), free()

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
	if (ArrayList_size(entry->data) >= index) return NULL;
	else return ArrayList_get(entry->data, index);
}

MappedCSVEntry MappedCSVEntry_create(const CSVHeader header)
{
	size_t buffer = ArrayList_size(header->data);
	MappedCSVEntry entry = malloc(sizeof(struct MappedCSVEntry_s));
	CSVEntry data = CSVEntry_create(buffer);
	return entry;
}

void MappedCSVEntry_free(MappedCSVEntry entry)
{
	CSVEntry_free(entry->data);
	free(entry);
}

char* MappedCSVEntry_get(const MappedCSVEntry entry, const char* column)
{
	for (size_t i = 0; i < ArrayList_size(entry->header->size); i++)
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