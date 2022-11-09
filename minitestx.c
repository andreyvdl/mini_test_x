//compile with the flags -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_pointers {
	void	*mlx;
	void	*win;
}	t_pointers;

int	deal_key(int key, t_pointers *param)
{
	ft_printf("key: %d\n", key);
	for (int i = 600; i > 0; i--)
		mlx_pixel_put(param->mlx, param->win, i * 0.1, i, 0xA55A55);
	return (1);
}

int	main(void)
{
	t_pointers	ptrs;

	ptrs.mlx = mlx_init();
	if (!ptrs.mlx)
		return (printf("mlx_init can't communicate with the x server"));
	ptrs.win = mlx_new_window(ptrs.mlx, 800, 600, "So long bowser");
	if (!ptrs.win)
		return (printf("mlx_new_window failed to create a new window"));
	// for (int i = 1; i < (800 + 1) / 2; i++)
	// {
	// 	mlx_pixel_put(ptrs.mlx, ptrs.win, i, i, 0xFF0000);
	// 	mlx_pixel_put(ptrs.mlx, ptrs.win, 800 / i, 600 / i, 0xFFFF00);
	// 	mlx_pixel_put(ptrs.mlx, ptrs.win, 250 + i, 250 - i, 0xFFFFFF);
	// 	mlx_pixel_put(ptrs.mlx, ptrs.win, 250 - i, 250 + i, 0xFF00FF);
	// 	mlx_pixel_put(ptrs.mlx, ptrs.win, 500, i * 2, 0x00FFFF);
	// 	mlx_pixel_put(ptrs.mlx, ptrs.win, i * 2, 600 / i, 0x00FF00);
	// }
	// mlx_key_hook(ptrs.win, deal_key, &ptrs);
	for (int i = 0; i < 100; i++)
	{
		usleep(30000);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 100 + i, 500, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 100, 500 - i, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 100 + i, 400, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 200, 400 + i, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 200 + i, 500, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 300 + i, 500, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 400, 500 - i, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 400 - i, 400 - i, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 300 - i, 300, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 300 - i, 300 + i, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 100 + i, 400 - i, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 200 + i, 400, 0xFFFFFF);
		mlx_pixel_put(ptrs.mlx, ptrs.win, 300 + i, 400, 0xFFFFFF);
	}
	mlx_loop(ptrs.mlx);
}
