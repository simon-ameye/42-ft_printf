#include "../ft_printf.h"
#include <stdio.h>

int main(void)
{
	int *pt;
	int nb;

	nb = -2147483648;
	pt = &nb;


	printf("\nres returned value : %d\n", 
	ft_printf   ("res : c:%c, s:%s, p:%p, d:%d, i:%i, u:%u, x:%x, X:%X, pourcen:%%", 'C', "caca", pt, nb, nb, nb, nb, nb));
	
	printf("\nref returned value : %d\n",
	printf      ("res : c:%c, s:%s, p:%p, d:%d, i:%i, u:%u, x:%x, X:%X, pourcen:%%", 'C', "caca", pt, nb, nb, nb, nb, nb));

//	printf("\nres returned value : %d\n", 
//	ft_printf   ("!%88.*d!", 66, 123456));

//	printf("\nref returned value : %d\n",
//	printf      ("!%-4.7d!", 123456));
//	printf("\nref returned value : %d\n",
//	printf      ("!%.14d!", 123456));
}
