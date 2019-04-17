# cParseCSV

cParseCSV is a small library for reading in CSV files.

## CSVEntry (and CSVHeader)

A CSVEntry stores all of the items on one line of the CSV. They are
retrieved through CSVEntry_get(entry, index). CSVHeaders are typedef'd
CSVEntries, and are used for clarity.

## MappedCSVEntry

MappedCSVEntries have a CSVHeader and a CSVEntry. Items can be
retrieved from the MappedCSVEntry through the corresponding
header column name, using MappedCSVEntry_get(entry, column).

## Build

1. Place cparsecsv.h and arraylist.h into the include directory.
2. Place arraylist.c, csventry.c, and csvread.c into the source directory.

## Usage

#### Example CSV file

| Header1 | Header2 | Header3 |
|:-------:|:-------:|:-------:|
|item01   |item02   |item03   |
|item11   |item12   |item13   |

#### Example code

	// Open the file
    FILE* csv = fopen(filepath, "r");

    // Read in lines from the CSV, starting with the header
    CSVHeader header = CSV_readLine(csv);
    CSVEntry line1 = CSV_readLine(csv);
    MappedCSVEntry line2 = CSV_readMappedLine(header, csv);

    // Retrieve some data
    char* item02 = CSVEntry_get(line1, 1);
    char* item13 = MappedCSVEntry_get(line2, "Header3");

    // Show the data
    printf("item02: %s\n", item02); // prints "item02"
    printf("item13: %s\n", item13); // prints "item13"

    // Free resources
    CSVEntry_free(header);
    CSVEntry_free(line1);
    MappedCSVEntry_free(line2);
    fclose(csv);
