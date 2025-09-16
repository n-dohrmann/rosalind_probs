#include "utils.h"

void get_line(FILE *fp, char* line)
{
  if (!fgets(line, MAX_LINE_LEN, fp)) {
    printf("could not parse path from input file...\n");
    exit(1);
  }

  // discard the new line char
  char *pn = strchr(line, '\n');
  if (pn) *pn = 0;
}

void skip_lines(FILE *fp, int to_skip)
{
  // skip unimportant lines
  char line_buf[MAX_LINE_LEN] = { 0 };
  for (int i = 0; i < to_skip; ++i) {
    if (!fgets(line_buf, MAX_LINE_LEN, fp)) {
      printf("error - file format not read as expected!\n");
      exit(1);
    }
  }
}

FILE *open_file_arg(int argc, char** argv)
{
  if (argc != 2) {
    printf("must give name of input file!\n");
    exit(1);
  }

  const char* in_file = argv[1];
  printf("loading input file: %s\n", in_file);

  FILE *fp = fopen(in_file, READ_MODE);

  if (!fp) {
    printf("could not open input file...\n");
    exit(1);
  }

  return fp;
}
