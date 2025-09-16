
#ifndef UTILS_HEADER
#define UTILS_HEADER

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define READ_MODE "r"

// get a line without the terminating '\n',
void get_line(FILE *fp, char* line);

// skip unwanted lines in buffer
void skip_lines(FILE *fp, int to_skip);

// open file name passed as cmd arg,
// quits if not possible
FILE *open_file_arg(int argc, char** argv);

#endif
