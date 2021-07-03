#include "../ft_printf.h"
#include <stdio.h>

int main(void)
{
    printf("\ntest returned value : %d", 
    ft_printf("le resultat de printf est %s%s%d", "Hello", "caca", -43));
}