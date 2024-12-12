#include "game.h"

void	quit(void *ptr)
{
	abandonner(*(((void **)ptr) + 0), 0, "quit", 0);
}
