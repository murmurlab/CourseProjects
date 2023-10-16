#include "include.h"

void	*philo(void *data);

void	init_table(t_controller *controller)
{
	int	i;

	i = 0;
	controller->threads = malloc(sizeof(pthread_t) * controller->consts[0]);
	controller->mutexes = malloc(sizeof(pthread_mutex_t) * \
								controller->consts[0]);
	while (i < controller->consts[0])
		pthread_create(controller->threads + i++, 0, philo, 0);
	while (i > -1)
		pthread_mutex_init(controller->mutexes + i--, NULL);
}

int	main(int ac, char *av[])
{
	t_controller	controller;

	if (ac < 5 || ac > 6)
		return (printf("usage:\n%s %s %s %s %s %s",
				av[0], ARG1, ARG2, ARG3, ARG4, ARG5), 1);
	else
	{
		while (ac-- > 1)
			controller.consts[ac - 1] = atoi(av[ac]);
	}
	printf("0: %d, 1: %d, 2: %d, 3: %d, 4: %d \n", controller.consts[0],
		controller.consts[1], controller.consts[2], controller.consts[3],
		controller.consts[4]);
	init_table(&controller);
	(void)av;
	(void)controller;
	return (0);
}

// void	__attribute__((destructor))after_main()
// {
// 	pause();
// }
