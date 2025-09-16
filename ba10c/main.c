
#include "../common/utils.h"
#include "../common/matrix.h"

int main(int argc, char** argv)
{
  FILE *fp = open_file_arg(argc, argv);
  char observations[MAX_LINE_LEN] = { 0 };
  int obs_indices[26] = { 0 };
  int states_indices[26] = { 0 };


  get_line(fp, observations);
  printf("read observations: %s\n", observations);

  // blank line
  skip_lines(fp, 1);

  // get observation alphabet

  fclose(fp);
  return 0;
}
