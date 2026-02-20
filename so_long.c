#include <mlx.h>
#include <so_long.h>

static void	initialise_map(t_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->consum_count = 0;
	map->exit_count = 0;
	map->player_count = 0;
}

static void	initialise_pos(t_position *position)
{
	position->player_x = 0;
	position->player_y = 0;
}

int main(void)
{
	void	*mlx;
	t_position position;
	t_map	map;
	
	initialise_map(&map);
	initialise_pos(&position);
	parsing(&map, &position);
	mlx = mlx_init();
	if (!mlx)
		handle_map_error(&map);
	init_game(mlx, &map);
	free_tab(map.map);
}