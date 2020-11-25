#include "cub3d.h"

int		ft_write_bmp(char *filename, t_s *s)
{
	t_ij	c;
	int		fp;
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
	unsigned int	offset_to_data;
	unsigned long	info_header_size;
	unsigned int	planes;
	unsigned int	color;
	unsigned long	compress;
	unsigned long	data_size;
	long			xppm;
	long			yppm;

	if((fp = open(filename, O_CREAT, 00600 | 00040 | 00004)) == 1)
		return (BMP_FILE_OPEN_ERROR);

	real_width = s->g.img.width * 3 + s->g.img.width % 4;
	/*
	**ここからヘッダ作成
	*/
	file_size = s->g.img.height * real_width + HEADERSIZE;
	offset_to_data = HEADERSIZE;
	info_header_size = INFOHEADERSIZE;
	planes = 1;
	color = 24;
	compress = 0;
	data_size = s->g.img.height * real_width;
	xppm = 1;
	yppm = 1;

	header_buf[0] = 'B';
	header_buf[1] = 'M';
	ft_memcpy(header_buf + 2, &file_size, sizeof(file_size));
	header_buf[6] = 0;
	header_buf[7] = 0;
	header_buf[8] = 0;
	header_buf[9] = 0;
	ft_memcpy(header_buf + 10, &offset_to_data, sizeof(file_size));
	header_buf[11] = 0;
	header_buf[12] = 0;
	header_buf[13] = 0;

	ft_memcpy(header_buf + 14, &info_header_size, sizeof(info_header_size));
	header_buf[15] = 0;
	header_buf[16] = 0;
	header_buf[17] = 0;
	ft_memcpy(header_buf + 18, &s->g.img.width, sizeof(s->g.img.width));
	ft_memcpy(header_buf + 22, &s->g.img.height, sizeof(s->g.img.height));
	ft_memcpy(header_buf + 26, &planes, sizeof(planes));
	ft_memcpy(header_buf + 28, &color, sizeof(color));
	ft_memcpy(header_buf + 30, &compress, sizeof(compress));
	ft_memcpy(header_buf + 34, &data_size, sizeof(data_size));
	ft_memcpy(header_buf + 38, &xppm, sizeof(xppm));
	ft_memcpy(header_buf + 42, &yppm, sizeof(yppm));
	header_buf[46] = 0;
	header_buf[47] = 0;
	header_buf[48] = 0;
	header_buf[49] = 0;
	header_buf[50] = 0;
	header_buf[51] = 0;
	header_buf[52] = 0;
	header_buf[53] = 0;

	/*
	**ヘッダの書き込み
	*/
	write(fp, header_buf, HEADERSIZE);
	/*
	**RGB情報の書き込み
	*/
	if(!(bmp_line_data = (unsigned char *)malloc(sizeof(unsigned char)*real_width)))
	{
		close(fp);
		return (MALLOC_ERROR_BMP_LINE);
	}
	c.i = 0;
	while (c.i < s->g.img.height)
	{
		c.j = 0;
		while (c.j < s->g.img.width)
		{
			bmp_line_data[c.j * 3] = (char)(s->g.img.data[(s->g.img.height - c.i - 1) * s->g.img.width + c.j] >> 16);
			bmp_line_data[c.j * 3 + 1] = (char)((s->g.img.data[(s->g.img.height - c.i - 1) * s->g.img.width + c.j] >> 8) & 0x0000FF);
			bmp_line_data[c.j * 3 + 2] = (char)(s->g.img.data[(s->g.img.height - c.i - 1) * s->g.img.width + c.j] & 0x0000FF);
			c.j++;
		}
		/*
		**RGB情報を4バイトの倍数（=real_width）に合わせる
		*/
		c.j = s->g.img.width * 3;
		while (c.j < real_width)
		{
			bmp_line_data[c.j] = 0;
			c.j++;
		}
		write(fp, bmp_line_data, real_width);
		c.i++;
	}
	free(bmp_line_data);
	close(fp);
	return 0;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*mem_dest;
	const char	*mem_src;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	mem_dest = (char *)dest;
	mem_src = (char *)src;
	while (i < n)
	{
		mem_dest[i] = mem_src[i];
		i++;
	}
	return (dest);
}
