// -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o 

#include "mlx.h"
#include <stdlib.h>

typedef struct s_image
{
	void		*ptr;
	int	        sizex;
    int         sizey;
	char		*pixels;
	int			bpp; //bits_per_pixel
	int			l_size; //line_size
	int			endian;
}	t_image;

typedef struct s_pro
{
	void		*mlx;
    void		*window;
	t_image     img;
}	t_pro;

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.sizex, &img.sizey);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bpp, &img.l_size, &img.endian);
	return (img);
}

int    event(int key, t_pro *p)
{
    if (key == 65307)
    {
        mlx_loop_end(p->mlx);
    }
    return (0);
}

int main()
{
    t_pro p;

    p.mlx = mlx_init();
    p.window = mlx_new_window(p.mlx, 400, 400, "BItches");

	p.img = ft_new_sprite(p.mlx, "coin.xpm");


    mlx_put_image_to_window(p.mlx, p.window, p.img.ptr, 0 , 0);
    mlx_key_hook(p.window, event, &p);
    mlx_loop(p.mlx);
    mlx_destroy_image(p.mlx, p.img.ptr);
    mlx_destroy_window(p.mlx, p.window);
    mlx_destroy_display(p.mlx);
    free(p.mlx);
    
    return (0);
}