#include <unistd.h>

/* une fonction qui affiche l’alphabet en minuscule sur une seule ligne, dans
l’ordre croissant, à partir de la lettre ’a’. */

void ft_print_alphabet(void) 
{
    char c = 'a';
    while (c <= 'z') {
        write(1, &c, 1);
        c++;
    }
}

/*
int main(void) {
    ft_print_alphabet();
    return 0;
}
*/