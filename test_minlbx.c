#include "mlx/mlx.h"



int	main(void)
{
	void	*mlx;
    

    mlx = mlx_init();
    mlx_new_window(mlx,1920,1080,"HOla");

    mlx_pixel_put(mlx,mlx_new_window,250,250,0xffffff);
    mlx_loop(mlx);


	
}
