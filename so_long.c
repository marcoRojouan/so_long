#include <mlx.h>
#include <so_long.h>

int main(void)
{
	void	*mlx;
	int		parse_is_valid;
	
	parse_is_valid = parsing();
	mlx = mlx_init();
	mlx_new_window(mlx, 800, 400, "prout");
	mlx_loop(mlx);
}