#include "MLX42/MLX42.h"

#define WIDTH 500
#define HEIGHT 500

typedef struct mlx_conex
{
    void *window;
    void *context;
    int32_t width;
    int32_t height;
    double deta;

}       mlx_conex;


int main()
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (1);
    mlx_key_hook(mlx, &mlx_close_hook,NULL);
    mlx_loop(mlx);
    mlx_terminate(mlx);
}