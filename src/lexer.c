#include <stdio.h>
#include <stdbool.h> // C-99 implementation or higher

//int *pos; //token position in file

typedef struct list_node list_node;
struct list_node {
    list_node *next;
    void *data;
};

struct circ_buffer {
  int read_pos;     // Where is the processor up to?
  int write_pos;    // Track where we've written to so we don't accidentally
                    // overwrite where the read head is at
  size_t buff_size; // How big is our "zero length" buffer actually?
  char buffer[0];   // Despite appearances this isn't useless
                    // zero length *apparently* doesn't actually *mean* zero length.
}

#define FOR_EACH(item, list) \
    for (list_node *(item) = (list); (item); (item) = (item)->next)

int main(int argc, char **argv)
{
    if ((fd = fopen(*argv, 0)) < 0) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    file_buffer = malloc(sizeof(struct circ_buffer));

    // ensure cursor is at start of file.
    fseek(fd, 1, SEEK_SET);
}

// pass in with: read_in(&file_buffer, fd);
void read_in(struct circ_buffer *file_buffer, FILE *fd)
{
  char tmp[24];
  char character[1]

  // Do nothing if we haven't processed buffer contents yet
  if (file_buffer->read_pos == file_buffer->write_pos) {
    return 0;
  }

  // check for boundary
  if (file_buffer->read_pos == file_buffer->buff_size) {
    file_buffer->read_pos = 0;
  }
  if (file_buffer->write_pos == file_buffer->buff_size) {
    file_buffer->write_pos = 0;
  }

  // ensure we're at the correct position in the file, then read the next character block and increment counters
  fseek(fd, 1, SEEK_CUR);
  fread(tmp, 1, file_buffer->write_pos - file_buffer->read_pos, fd);

  FOR_EACH(character, tmp){
    file_buffer->buffer[file_buffer->read_pos] = character;
    file_buffer->read_pos++
  }
}
