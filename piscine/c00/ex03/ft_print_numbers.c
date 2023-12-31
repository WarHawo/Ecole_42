#include <unistd.h>

/* Écrire une fonction qui affiche tous les chiffres sur une seule ligne, dans l’ordre
croissant. */

void ft_print_numbers(void) 
{
    char c = '0';
    while (c <= '9') {
        write(1, &c, 1);
        c++;
    }
}


int main(void) {
    ft_print_numbers();
    return 0;
}
