#include "../ft_printf.h"
#include <stdio.h>

int main(void)
{
	int *pt;
	int a;
	int nb;

	nb = +43567899;
	pt = &a;

	printf("\nres returned value : %d\n", 
	ft_printf   ("res : c:%c, s:%s, p:%p, d:%d, i:%i, u:%u, x:%x, X:%X, pourcen:%%", 'C', "caca", pt, nb, nb, nb, nb, nb));
	
	printf("\nref returned value : %d\n",
	printf      ("res : c:%c, s:%s, p:%p, d:%d, i:%i, u:%u, x:%x, X:%X, pourcen:%%", 'C', "caca", pt, nb, nb, nb, nb, nb));
}
