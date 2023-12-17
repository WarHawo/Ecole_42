#include <unistd.h>

/* fonction qui affiche l’alphabet en minuscule sur une seule ligne, dans
l’ordre décroissant, à partir de la lettre ’z’.. */

void ft_print_alphabet(void) 
{
    char c = 'z';
    while (c >= 'a') {
        write(1, &c, 1);
        c--;
    }
}


int main(void) {
    ft_print_alphabet();
    return 0;
}
