#include "cub3d.h"

int		ft_write_bmp(char *filename, t_s *s)
{
	t_ij	c;
	int		fd;
	int		real_width;
	/*
	**画像一行分のRGBデータを格納する。
	*/
	unsigned char	*bmp_line_data;
	/*
	**ヘッダ	を格納する。
	*/
	unsigned char	header_buf[HEADERSIZE];
	unsigned int	file_size;
	unsigned int	reserved;
	unsigned int	offset_to_data;
	unsigned int	info_header_size;
	unsigned int	bit_width;
	unsigned int	bit_height;
	unsigned short	planes;
	unsigned short	color;
	unsigned int	compress;
	unsigned int	data_size;
	unsigned int	xppm;
	unsigned int	yppm;
	unsigned int	pallete_num;
	unsigned int	important;
	int				write_rv;

	if((fd = open(filename, O_CREAT, 00600 | 00060 | 00006)) == 1)
		return (BMP_FILE_OPEN_ERROR);
	close(fd);
	if((fd = open(filename, O_WRONLY)) == 1)
		return (BMP_FILE_OPEN_ERROR);

	real_width = s->g.img.scre_width * 3 + s->g.img.scre_width % 4;
	/*
	**ここからヘッダ作成
	*/
	reserved = 0;
	file_size =  s->g.img.scre_height * real_width + HEADERSIZE;
	offset_to_data = HEADERSIZE;
	info_header_size = INFOHEADERSIZE;
	bit_width = (unsigned int)s->g.img.scre_width;
	bit_height = (unsigned int)s->g.img.scre_height;
	planes = 1;
	color = 24;
	compress = 0;
	data_size =  s->g.img.scre_height * real_width;
	xppm = 0;
	yppm = 0;
	pallete_num = 0;
	important = 0;

	header_buf[0] = 'B';
	header_buf[1] = 'M';
	ft_memcpy(header_buf + 2, &file_size, sizeof(file_size));
	ft_memcpy(header_buf + 6, &reserved, sizeof(reserved));
	ft_memcpy(header_buf + 10, &offset_to_data, sizeof(offset_to_data));
	ft_memcpy(header_buf + 14, &info_header_size, sizeof(info_header_size));
	ft_memcpy(header_buf + 18, &bit_width, sizeof(bit_width));
	ft_memcpy(header_buf + 22, &bit_height, sizeof(bit_height));
	ft_memcpy(header_buf + 26, &planes, sizeof(planes));
	ft_memcpy(header_buf + 28, &color, sizeof(color));
	ft_memcpy(header_buf + 30, &compress, sizeof(compress));
	ft_memcpy(header_buf + 34, &data_size, sizeof(data_size));
	ft_memcpy(header_buf + 38, &xppm, sizeof(xppm));
	ft_memcpy(header_buf + 42, &yppm, sizeof(yppm));
	ft_memcpy(header_buf + 42, &pallete_num, sizeof(pallete_num));
	ft_memcpy(header_buf + 42, &important, sizeof(important));
	/*
	**ヘッダの書き込み
	*/
	write(fd, header_buf, HEADERSIZE);
	/*
	**RGB情報の書き込み
	*/
	if(!(bmp_line_data = (unsigned char *)malloc(sizeof(unsigned char)*real_width)))
	{
		close(fd);
		return (MALLOC_ERROR_BMP_LINE);
	}
	c.i = 0;
	while (c.i <  s->g.img.scre_height)
	{
		c.j = 0;
		while (c.j < s->g.img.scre_width)
		{
			bmp_line_data[c.j * 3] = (unsigned char)(s->g.img.data[( s->g.img.scre_height - c.i - 1) * s->g.img.scre_width + c.j] & 0x0000FF);
			bmp_line_data[c.j * 3 + 1] = (unsigned char)((s->g.img.data[( s->g.img.scre_height - c.i - 1) * s->g.img.scre_width + c.j] >> 8) & 0x0000FF);
			bmp_line_data[c.j * 3 + 2] = (unsigned char)(s->g.img.data[( s->g.img.scre_height - c.i - 1) * s->g.img.scre_width + c.j] >> 16);			c.j++;
		}
		/*
		**RGB情報を4バイトの倍数（=real_width）に合わせる
		*/
		c.j = s->g.img.scre_width * 3;
		while (c.j < real_width)
		{
			bmp_line_data[c.j] = 0;
			c.j++;
		}
		write_rv = write(fd, bmp_line_data, real_width);
		printf("ft_write_bmp: write_rv: %d", write_rv);
		c.i++;
	}
	free(bmp_line_data);
	close(fd);
	return 0;
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*mem_dest;
	unsigned char	*mem_src;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	while (i < n)
	{
		mem_dest[i] = mem_src[i];
		i++;
	}
	return (dest);
}
