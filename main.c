#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_program	prg;
	int			i;
	int			error;

	if (!get_args_in_int(argc - 1, argv, &(prg.args)))
		return (0);
	if (!init_structs(&prg))
		return (0);
	i = -1;
	error = 0;
	while (++i < prg.args.num_of_philo && !error)
	{
		if (pthread_create(&(prg.threads[i]), NULL, start, &(prg.philos[i])))
			error = 1;
	}
	if (!error)
	{
		i = -1;
		while (++i < prg.args.num_of_philo && !error)
		{
			if (pthread_join(prg.threads[i], NULL))
				error = 1;
		}
	}
	free_all_memory(&prg);
	system("leaks philosophers >> .leaks_log.txt");
	return (0);
}
