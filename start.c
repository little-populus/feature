#include <unistd.h>
int not_main();

void _start(void)
{
    not_main();
    _exit(0);
}
