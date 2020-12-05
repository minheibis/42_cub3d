/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:08:56 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:08:57 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_write_bmp(char *filename, t_s *s)
{
	ft_bmp_init(s);
	if((s->b.fd = open(filename, O_CREAT, 00600 | 00060 | 00006)) == 1)
		return (BMP_FILE_OPEN_ERROR);
	close(s->b.fd);
	if((s->b.fd = open(filename, O_WRONLY)) == 1)
		return (BMP_FILE_OPEN_ERROR);
	if ((s->rv = ft_bmp_head_set(s)))
	{
		close(s->b.fd);
		return (s->rv);
	}
	if ((s->rv = ft_bmp_rgb_set(s)))
	{
		close(s->b.fd);
		return (s->rv);
	}
	close(s->b.fd);
	return (0);
}

int		ft_bmp_init(t_s *s)
{
	s->b.real_width = s->g.img.scre_width * 3 + s->g.img.scre_width % 4;
	/*
	**ここからヘッダ作成
	*/
	s->b.reserved = 0;
	s->b.file_size =  s->g.img.scre_height * s->b.real_width + HEADERSIZE;
	s->b.offset_to_data = HEADERSIZE;
	s->b.info_header_size = INFOHEADERSIZE;
	s->b.bit_width = (unsigned int)s->g.img.scre_width;
	s->b.bit_height = (unsigned int)s->g.img.scre_height;
	s->b.planes = 1;
	s->b.color = 24;
	s->b.compress = 0;
	s->b.data_size =  s->g.img.scre_height * s->b.real_width;
	s->b.xppm = 0;
	s->b.yppm = 0;
	s->b.pallete_num = 0;
	s->b.important = 0;

	s->b.header_buf[0] = 'B';
	s->b.header_buf[1] = 'M';
	return (0);
};

int		ft_bmp_head_set(t_s *s)
{
	ft_memcpy(s->b.header_buf + 2, &s->b.file_size, sizeof(s->b.file_size));
	ft_memcpy(s->b.header_buf + 6, &s->b.reserved, sizeof(s->b.reserved));
	ft_memcpy(s->b.header_buf + 10, &s->b.offset_to_data, sizeof(s->b.offset_to_data));
	ft_memcpy(s->b.header_buf + 14, &s->b.info_header_size, sizeof(s->b.info_header_size));
	ft_memcpy(s->b.header_buf + 18, &s->b.bit_width, sizeof(s->b.bit_width));
	ft_memcpy(s->b.header_buf + 22, &s->b.bit_height, sizeof(s->b.bit_height));
	ft_memcpy(s->b.header_buf + 26, &s->b.planes, sizeof(s->b.planes));
	ft_memcpy(s->b.header_buf + 28, &s->b.color, sizeof(s->b.color));
	ft_memcpy(s->b.header_buf + 30, &s->b.compress, sizeof(s->b.compress));
	ft_memcpy(s->b.header_buf + 34, &s->b.data_size, sizeof(s->b.data_size));
	ft_memcpy(s->b.header_buf + 38, &s->b.xppm, sizeof(s->b.xppm));
	ft_memcpy(s->b.header_buf + 42, &s->b.yppm, sizeof(s->b.yppm));
	ft_memcpy(s->b.header_buf + 46, &s->b.pallete_num, sizeof(s->b.pallete_num));
	ft_memcpy(s->b.header_buf + 50, &s->b.important, sizeof(s->b.important));
	/*
	**ヘッダの書き込み
	*/
	if (write(s->b.fd, s->b.header_buf, HEADERSIZE) == -1)
		return (BMP_HEAD_WRITE_ERROR);
	return (0);
};

int		ft_bmp_rgb_set(t_s *s)
{
	int	i;

	/*
	**RGB情報の書き込み
	*/
	if(!(s->b.bmp_line_data = (unsigned char *)malloc(sizeof(unsigned char)*s->b.real_width)))
		return (MALLOC_ERROR_BMP_LINE);
	i = 0;
	while (i <  s->g.img.scre_height)
	{
		if ((s->rv = ft_bmp_rgb_set_line(i, s)))
			return (s->rv);
		i++;
	}
	free(s->b.bmp_line_data);
	return (0);
}


int		ft_bmp_rgb_set_line(int i, t_s *s)
{
	int		j;

	j = 0;
	while (j < s->g.img.scre_width)
	{
		s->b.bmp_line_data[j * 3] = (unsigned char)(s->g.img.data[( s->g.img.scre_height - i - 1) * s->g.img.scre_width + j] & 0x0000FF);
		s->b.bmp_line_data[j * 3 + 1] = (unsigned char)((s->g.img.data[( s->g.img.scre_height - i - 1) * s->g.img.scre_width + j] >> 8) & 0x0000FF);
		s->b.bmp_line_data[j * 3 + 2] = (unsigned char)(s->g.img.data[( s->g.img.scre_height - i - 1) * s->g.img.scre_width + j] >> 16);
		j++;
	}
	/*
	**RGB情報を4バイトの倍数（=real_width）に合わせる
	*/
	j = s->g.img.scre_width * 3;
	while (j < s->b.real_width)
	{
		s->b.bmp_line_data[j] = 0;
		j++;
	}
	if ((write(s->b.fd, s->b.bmp_line_data, s->b.real_width) == -1))
		return (BMP_RGB_WRITE_ERROR);
	return (0);
}
