#include "init/stivale2.h"
#include <stddef.h>

/* function name: stivale2_get_tag
 * arguments: stivale2_struct*, uint64_t id
 * returns: tag with given id
 */
void* stivale2_get_tag(struct stivale2_struct* stivale2_struct, uint64_t id)
{
  // get the first tag from linked list
  struct stivale2_tag *current_tag = (void*)stivale2_struct->tags;
  // loop through all tags
  for(;;)
  {
    // if curent tag is NULL that means it is the last tag
    if(current_tag == NULL)
    {
      return NULL;
    }
    // if current_tag's id matches the requested id, then return this tag
    if(current_tag->identifier == id)
    {
      return current_tag;
    }
    // get the next tag
    current_tag = (void*)current_tag->next;
  }
  // no such tag found, bruh!!
  return NULL;
}
