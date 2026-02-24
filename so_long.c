#include <mlx.h>
#include <so_long.h>

static void	initialise_game(t_game *game)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->consum_count = 0;
	game->exit_count = 0;
	game->player_count = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->move_count = 0;
}

int main(int ac, char **av)
{
	t_game	game;
	
	if (ac != 2)
		return (0);
	initialise_game(&game);
	parsing(&game, av[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		handle_map_error(&game, "Invalid Mlx call");
	init_game(&game);
	mlx_loop(game.mlx);
	free_tab(game.map);
	free(game.mlx);
}