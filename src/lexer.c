#include <stdio.h>

int *pos; //token position in file

struct circ_buffer {
  int read_pos;     // Where is the processor up to?
  int write_pos;    // Track where we've written to so we don't accidentally
                    // overwrite where the read head is at
  size_t buff_size; // How big is our "zero length" buffer actually?
  char buffer[0];   // Despite appearances this isn't useless
                    // zero length *apparently* doesn't actually *mean* zero length.
}

int main(int argc, char **argv)
{
    if ((fd = open(*argv, 0)) < 0) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    circ_buffer *file_buffer;
}

/*

void read_in(*file_buffer, *pos)
{
  // Do nothing if we haven't processed anything yet
  if (file_buffer.read_pos == file_buffer.write_pos) {
    return 0;
  }

  // do read/write here?

  // check for boundary
  if (file_buffer.read_pos == file_buffer.buff_size) {
    file_buffer.read_pos = 0;
  }
  if (file_buffer.write_pos == file_buffer.buff_size) {
    file_buffer.write_pos = 0;
  }
}

*/
