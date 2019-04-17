/**
 * @author Michael Bianconi
 * @since 04-17-2019
 *
 * Main header file for cparseCSV.
 */

#ifndef CPARSECSV_H
#define CPARSECSV_H

#include "arraylist.h"
#include <stdio.h>  // FILE
#include <stdlib.h> // size_t

/// ===========================================================================
/// Structure definitions
/// ===========================================================================

/**
 * CSVEntries hold data collected from a CSV file. The hold all the data
 * contained on one line. They operate off of an ArrayList data structure.
 *
 * CSVHeaders are the same as CSVEntries, just renamed for clarity.
 * Any function used for CSVEntries should also be used for CSVHeaders.
 */
struct CSVEntry_s
{
	ArrayList data;
};

typedef struct CSVEntry_s* CSVEntry;
typedef struct CSVEntry_s* CSVHeader; // typedef'd for clarity

/**
 * Holds both data and a CSVHeader. The CSVHeader <i>must</i>
 * have the same number of items as the CSVEntry. Failure to
 * do so may result in a seg fault.
 * MappedCSVEntries allow devs to access a specific column
 * via a phrase, rather than an index.
 */
struct MappedCSVEntry_s
{
	CSVHeader header;
	CSVEntry  data;
};

typedef struct MappedCSVEntry_s* MappedCSVEntry;

struct CSVReader
{
	FILE* file;
}

/// ===========================================================================
/// Function declarations
/// ===========================================================================

/**
 * Allocates memory for a new CSVEntry.
 *
 * <b>Use this function to create CSVHeaders as well.</b>
 *
 * @param buffer The number of items expected to be read. Will expand
 *               and trim automatically.
 * @return Returns a new CSVEntry.
 */
CSVEntry CSVEntry_create(const size_t buffer);

/**
 * Frees all memory allocated for the entry.
 *
 * <b>Use this function to free CSVHeaders as well.</b>
 *
 * @param entry Entry to free.
 */
void CSVEntry_free(CSVEntry entry);

/**
 * Returns the data at the given index.
 *
 * @param entry Entry to retrieve from.
 * @param index Index to retrieve at.
 * @return Returns the data, or null if not found.
 */
char* CSVEntry_get(const CSVEntry entry, const size_t index);

/**
 * Creates a new MappedCSVEntries the same size as the header.
 *
 * @param header Header to map to.
 * @return Returns a new MappedCSVEntry.
 */
MappedCSVEntry MappedCSVEntry_create(const CSVHeader header);

/**
 * Frees the memory allocated for the MappedCSVEntry.
 * Does <i>not</i> free the CSVHeader associated with it.
 *
 * @param entry Entry to free.
 */
void MappedCSVEntry_free(MappedCSVEntry entry);

/**
 * Retrieves the data associated with the given column.
 * The data returned is not copied. <b>Do not free.</b>
 * 
 * @param entry Entry to retrieve from.
 * @param column Column name.
 * @return Returns the data in the column, or null.
 */
char* MappedCSVEntry_get(const MappedCSVEntry entry, const char* column);

/**
 * Retrieves the data at the given index. Data is not copied.
 * <b>Do not free.</b>
 *
 * @param entry Entry to retrieve from.
 * @param index Index to retrieve at.
 * @return Returns the data, or null if not found.
 */
char* MappedCSVEntry_getIndex(const MappedCSVEntry entry, const size_t index);

/**
 * 
CSVReader CSVReader_create(FILE* in);

#endif