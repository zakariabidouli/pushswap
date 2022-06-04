#include"pushswap.h"

int main(int ac, char **av)
{
    // t_stack  *s;
    // t_stack  **last;
    char     **tmp;
    int      *i = NULL;
    int      j;
    int      value;


    // *i = NULL;
    if (ac == 2)
    {
        tmp = ft_split(av[1], ' ', i);
        j = 0;
        value = 0;
        while(tmp[j])
        {
            value = ft_atoi(tmp[j]);
           printf("########### :%d\n", value);
           
        }
    }
}