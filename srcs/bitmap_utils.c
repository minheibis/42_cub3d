#include "cub3d.h"

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
