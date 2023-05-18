#include "libparse/system.h"

int system_read_char(system_t *system)
{
    if (system->content[system->position] == '\0')
    {
        return;
    }

    return system->content[system->position++];
}
