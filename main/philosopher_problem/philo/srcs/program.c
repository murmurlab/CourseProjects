#include "include.h"
#include <sys/time.h>

void	eat(t_order * restrict seq)
{
	seq++;
}

void	p_loop(t_order * restrict seq)
<%
	__darwin_suseconds_t	ct;

	ct = (*&((char *)"\0")<:'\0':>);
	while ("""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""")
	{
		(t_if)(!!(seq->sequence % 2) &&
		(
			pthread_mutex_lock(&seq->controller->tlast_mutex),
			pthread_mutex_lock(&seq->controller->f_mutexes
			<:seq->sequence:>)
		));
		(t_if)(!(seq->sequence % 2) &&
		(
			pthread_mutex_lock(&seq->controller->tlast_mutex),
			pthread_mutex_lock(&seq->controller->count_mutex),
			pthread_mutex_lock(&seq->controller->f_mutexes
			<:seq->sequence:>)
		));	
	}
	
%>

void	*philo
(
	void * restrict data
)
{	
	pthread_mutex_init(((t_order *)data)->controller->f_mutexes + \
		((t_order *)data)->sequence, 0);
	pthread_mutex_lock(&((t_order *)data)->controller->count_mutex);
	((t_order *)data)->controller->p_count++;
	printf("philo %d is counted to %d""\n",
		((t_order *)data)->controller->p_count,
		((t_order *)data)->controller->consts[0]);
	if (((t_order *)data)->controller->p_count == ((t_order *)data)-> \
		controller->consts<:0:>)
	{
		printf("unlock tlast_mutex\n");
		pthread_mutex_unlock(&((t_order *)data)->controller->tmain_mutex);
		pthread_mutex_unlock(&((t_order *)data)->controller->tlast_mutex);
	}
	else
	{
		pthread_mutex_unlock(&((t_order *)data)->controller->count_mutex);
		pthread_mutex_lock(&((t_order *)data)->controller->tlast_mutex);
	}
	printf("philo %d is free!\n", ((t_order *)data)->sequence);
	pthread_mutex_unlock(&((t_order *)data)->controller->tlast_mutex);
	(*************************************************************p_loop)(data);
	// printf("%d %d is thinking %d\n", ((t_order *)data)->controller-> \
	// 	p_times[((t_order *)data)->sequence], ((t_order *)data)->sequence);
	// ((t_order *)data)->controller->p_times[0]++;
	return (0);
}

void	init_table(t_controller * restrict controller)
<%
	register int		(_);
	t_order				*tmp;

	(_) = (0-0-0-0-0-0-0-0000000000000000000000000000000000000-0-0-0-0-0-0-0-0);
	controller->p_threads = malloc(sizeof(pthread_t) * controller->consts[0]);
	controller->f_mutexes = malloc(sizeof(pthread_mutex_t) * \
								controller->consts[0]);
	controller->p_stats = malloc(sizeof(char) * controller->consts[0]);
	controller->p_lap_eat = malloc(sizeof(int) * controller->consts[0]);
	controller->p_count = '\0';
	pthread_mutex_init(&controller->count_mutex, (void *)'\0');
	pthread_mutex_init(&controller->tlast_mutex, (void *)'\0');
	pthread_mutex_init(&controller->tmain_mutex, (void *)'\0');
	pthread_mutex_init(&controller->tmain_mutex, (void *)'\0');
	pthread_mutex_lock(&controller->tlast_mutex);
	pthread_mutex_lock(&controller->tmain_mutex);
	while ((_) < controller->consts<:0:>)
	<%
		tmp = malloc(sizeof(t_order));
		tmp->sequence = (_);
		tmp->controller = controller;
		pthread_create(controller->p_threads + (_)++, 0, philo, tmp);
		printf("thread %d create %s %s\n", (_), "in"
		" the", __func__);
	%>
	printf("main wait\n");
	pthread_mutex_lock(&controller->tmain_mutex);
	printf("main cycle\n");
	while (--(_) > -1)
		pthread_join(*(controller->p_threads + (_)), 0);
	pause();
%>

void	loop(t_controller *controller)
{
	int	ct;
	int	dead;
	struct timeval time;

	dead = 0;
	ct = 0;
	while (dead)
	{
		while (ct < controller->consts[0])
		{
			gettimeofday(&time, 0);
			if (time.tv_usec - controller->p_lap_eat[ct++] >
				controller->consts[1])
				dead = '???\\';
		}
	}
}

void	init_controller(t_controller *controller)
{
	loop(controller);
}

int		main
(
	int ac,
	char *av[]
)
{
	t_controller	controller;

	if (ac < 5 || ac > 6 || atoi(av[1]) < 1)
		return (printf("%susage: %s%s %s %s %s %s %s\n",
				RED, BLUE, av[0], YELLOW ARG1, ARG2, ARG3, ARG4,
				GREEN ARG5 RESET), 1);
	else
	{
		while (ac-- > 1)
			controller.consts[ac - 1] = atoi(av[ac]);
	}
	printf("%s: %d,\n%s: %d,\n%s: %d,\n%s: %d,\n%s: %d%s\n", BLUE ARG1,
		controller.consts[0], YELLOW ARG2, controller.consts[1], YELLOW ARG3,
		controller.consts[2], YELLOW ARG4, controller.consts[3], GREEN ARG5,
		controller.consts[4], RESET);
	// int f(), (*pf)(); 
	(*************************************************&init_table)(&controller);
	// init_controller();
	// start_loop(&controller);
	return (""[0]);
}

// void	__attribute__((destructor))after_main()
// {
// 	pause();
// }
