#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// see https://rosalind.info/problems/ba10a/

#define MAX_LINE_LEN 1000
#define READ_MODE "r"
#define SKIP_LINES 4

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

void print_transitions(double (*const transitions)[2][2])
{
  printf("read transition matrix:\n");
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 2; col++) {
      printf("%e ", (*transitions)[row][col]);
    }
    printf("\n");
  }
}

void parse_transitions(FILE *fp, double (*transitions)[2][2])
{
  for (int row = 0; row < 2; row++) {
    char line_buf[MAX_LINE_LEN] = { 0 };
    get_line(fp, line_buf);
    // skip initial letter and spaces
    char *num_start = line_buf + 1;
    while (*num_start++ == ' ') { }

    // prepare str end
    char* num_end = num_start;
    while (*num_end++ != ' ') {}
    *num_end = 0;

    // read in first number
    (*transitions)[row][0] = atof(num_start);

    // skip to next number and read
    num_start = num_end + 1;
    while (*num_start == ' ') {}
    (*transitions)[row][1] = atof(num_start);
  }
}

// get transitions matrix index based on state
inline int tr_index(char state)
{
  return state == 'A' ? 0 : 1;
}

double get_probability(char* path, double (*transitions)[2][2])
{
  // initial probabilities are equal
  double probability = 0.5;

  for (char* tr = path; *(tr+1); tr++) {
    int row = tr_index(*tr);
    int col = tr_index(*(tr+1));
    probability *= (*transitions)[row][col];
  }
  return probability;
}

FILE *open_file(int argc, char** argv)
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

int main(int argc, char** argv)
{
  FILE *fp = open_file(argc, argv);
  double transitions[2][2] = {{0.0, 0.0}, {0.0, 0.0}};
  char path[MAX_LINE_LEN] = { 0 };

  // parse path information
  get_line(fp, path);
  printf("read path: %s\n", path);

  skip_lines(fp, SKIP_LINES);

  // get transition matrix
  parse_transitions(fp, &transitions);
  print_transitions(&transitions);

  double prob = get_probability(path, &transitions);
  printf("found probability: %.10E\n", prob);

  fclose(fp);
  return 0;
}
