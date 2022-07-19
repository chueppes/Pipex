#include "./libft/libft.h"
# include <stdio.h>

int main ()
{
    char    *str= ft_calloc(31, sizeof (char)); 
    char    **str2;
    int     i;

    i=0;
    ft_strlcpy(str, "alguma coisa 'ai alguma coisa'", 31);
    str2=ft_split(str, ' ');

    while (str2[i])
    {
        printf("%s\n", str2[i]);
        i++;
    }
    return(0);
}