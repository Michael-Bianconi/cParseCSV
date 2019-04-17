/**
 * @author Michael Bianconi
 * @since 04-17-2019
 *
 * Source code for file IO in cparsecvs.h.
 */

#include "cparsecsv.h"
#include "arraylist.h"
#include <stdio.h>
#include <string.h>

CSVEntry CSV_readLine(FILE* in)
{
	// A buffer for reading from the file
	static char lineBuffer[CSV_LINE_BUFFER];
	fgets(lineBuffer, CSV_LINE_BUFFER-1, in);

	// EOF
	if (!lineBuffer) return NULL;

	// Build CSVEntry
	size_t start = 0;
	size_t end = 0;
	size_t len = strlen(lineBuffer);
	CSVEntry entry = CSVEntry_create(CSV_ENTRY_BUFFER);

	while (end < len) {

		char c = lineBuffer[end];

		// Item found, populate entry
		if (c == ',' || c == '\0' || c == '\n')
		{
			// Don't populate if it's the last comma on the line
			if (end == len-1) break;

			size_t itemLen = end - start;
			char* item = malloc(itemLen);
			strncpy(item, lineBuffer+start, itemLen);
			ArrayList_add(entry->data, item);
			start = end+1;
		}

		end++;
	}

	return entry;
}