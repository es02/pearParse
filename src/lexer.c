#include <stdio.h>

int pos; //token position in file

struct circ_buffer {
  int read_pos;     // Where is the processor up to?
  int write_pos;    // Track where we've written to so we don't accidentally overwrite where the read head is at
  size_t buff_size; // How big is our "zero length" buffer actually?
  char buffer[0];   // Despite appearances this isn't useless - zero length *apparently* doesn't actually *mean* zero length. IDFK
}

int main(int argc, char **argv)
{
    if ((fd = open(*argv, 0)) < 0) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }
}
