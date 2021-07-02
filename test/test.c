#include "../ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("\ntest returned value : %d", 
    ft_printf("%s%s", "Hello", "caca"));
}