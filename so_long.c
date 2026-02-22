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
}

int main(void)
{
	t_game	game;
	
	initialise_game(&game);
	parsing(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		handle_map_error(&game);
	init_game(&game);
	mlx_loop(game.mlx);
	free_tab(game.map);
	free(game.mlx);
}