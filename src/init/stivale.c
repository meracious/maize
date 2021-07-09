#include <init/stivale2.h>
#include <stddef.h>

/* function name: stivale2_get_tag
 * arguments: stivale2_struct*, uint64_t id
 * returns: tag with given id
 */
void *stivale2_get_tag(struct stivale2_struct *stivale2_struct, uint64_t id)
{
    // get the first tag from linked list
    struct stivale2_tag *current_tag = (void *)stivale2_struct->tags;
    // loop through all tags
    while (current_tag)
    {
        // if current_tag's id matches the requested id, then return the tag
        if (current_tag->identifier == id)
            return current_tag;
        // move to the next tag
        current_tag = (void *)current_tag->next;
    }
    // no such tag found
    return NULL;
}
