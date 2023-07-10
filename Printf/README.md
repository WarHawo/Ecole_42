# **Définition**

Printf est une fonction permettant d’afficher une ou plusieurs variables de façon formatée dans le flux de sortie (stdout).

Il est nécessaire d’inclure l’en-tête standard <stdio.h> au début du code source du programme.

```c
	int printf (const char *format, ...);
```

Les ... signifient que c’est une fonction variadique, qui peut prendre un nombre variable de paramètres. 

Format représente, comme son nom l’indique, de quoi sera fait la sortie (Entier, Double ...). À chaque fois qu’il y a un % printf regarde la lettre qui suit ce % et écrit la variable qui correspond dont les paramètres. Si c’est le n ième % printf regarde le (n ième + 1) paramètre.   

# **Valeur renvoyée**

Retourne le nombre de caractère imprimés ou une valeur négative si une erreur se produit.

# **Syntaxe de spécification de format**

La fonction printf acceptent une chaîne de format et des arguments facultatifs et génère en sortie une séquence de caractères mise en forme. La chaîne de format contient  zéro ou plusieurs directives qui sont soit des caractères littéraux pour la sortie, soit des spécifications de conversion codées qui décrivent comment mettre en forme un argument dans la sortie.

Une spécification de conversion se compose de champs facultatifs et obligatoires mis en forme comme suit :

> %[[indicateurs]][largeurs][.précision][taille][type]
> 

Une spécification de conversion de base contient uniquement le symbole de pourcentage et un caractère *type.* Exemple %s.

## [Spécificateur de conversion de type]

Le caractère spécificateur de conversion type précise si l'argument correspondant doit être interprété comme un caractère, une chaîne, un pointeur ou un nombre à virgule flottante. C'est le seule champs obligatoire!

[Caractères du champ type]

## [Directives d'indicateurs]

Dans une spécification de conversion, le premier champ facultatif contient des directives d'indicateur qui spécifient la justification de la sortie et qui contrôlent la sorties des signes, des espaces, des zéros non significatifs. Plusieurs directives d'indicateurs peuvent apparaître dans une spécification de conversion, et les caractères d'indicateur peuvent apparaître dans n'importe quel ordre. 

[Caractères d'indicateurs ]

## Spécification de largeur (width)

Ce champs facultatif apparaît après n'importe quel caractère [d'indicateur]. 

L'argument width est un entier décimal non négatif qui contrôle le nombre minimal de caractères qui sont générés. 

Si le nombre de caractères dans la valeur de sortie est inférieur à la largeur spécifiée, des espaces sont ajoutés à gauche ou à droite des valeurs, selon que l’indicateur d’alignement à gauche ( ***** ) est spécifié ou non, jusqu’à ce que la largeur minimale soit atteinte. Si *width* est préfixé par 0, des zéros non significatifs sont ajoutés aux conversions en entiers ou en nombres à virgule flottante jusqu’à ce que la largeur minimale soit atteinte, sauf en cas de conversion en valeur infinie ou NaN.

La spécification de largeur ne provoque jamais la troncature d’une valeur. Si le nombre de caractères dans la valeur de sortie est supérieur à la largeur spécifiée, ou si *width* n’est pas spécifié, tous les caractères de la valeur sont générés, conformément à la spécification *precision*.

Si la spécification de largeur est un astérisque ( *)``un **`int`** argument de la liste d’arguments fournit la valeur. L’argument *width* doit précéder la valeur mise en forme dans la liste des arguments, comme illustré dans l’exemple suivant :

`printf("%0*d", 5, 3); /* 00003 is output */`

Une valeur *width* manquante ou petite dans une spécification de conversion n’entraîne pas la troncation d’une valeur de sortie. Si le résultat d’une conversion est plus large que la valeur *width*, le champ peut être développé pour contenir le résultat de la conversion.

[Caractère de spécification de largeur]

## Spécification de précision

La spécification de précision est le troisième champs facultatif. Il se compose d'un point (.) suivi d'un entier décimal non négatif qui, selon le type de conversion, spécifie le nombre de caractères de chaîne, le nombre de décimales ou le nombre de chiffres significatifs à générer.

Si on a 0 comme précision et que la valeur à convertir est 0 on obtient aucune sortie.
```c
			printf("%.0d, 0); /* No characters output */
```

Si la spécification est un astérisque (*), un int argument de la liste d'argument fournit la valeur. Dans la liste la liste d'argument précision doit précéder la valeur mise en forme :

```c
		printf("%.*f", 3, 3.1457890); /* 3.145 output */
```

Le caractère type détermine soit l'interprétation de précision, soit la précision par default quand précisons est omis

# **Les fonctions variadiques**

Pour n’importe quel fonction ou l’on souhaite utilisé une fonction variadique nous devons utilisé l’entête <stdarg.h>

Il y a un un type de donnée à connaitre : va_list. Et les macros va_start, va_arg, va_end. 

va_list est un type de donnée implémenté sous forme d'une structure. Elle est utilisé par les macro du module <stdarg.h>. Il n'est pas de notre responsabilité d'initialiser une telle structure. Au contraire, il es demandé d'utilisé la macro va_start pour réaliser cette initialisation.

Avant de parcourir notre liste de paramètre supplémentaire on fait un appel à va_start.

Ensuite dés que l’on appelle va_arg ça nous retourne l’élément suivant dans la liste. A chaque appelle de va_arg on avance dans la liste!

Et quand on a terminer on appelle une fois va_end.  

```c
// Exemple utilisation des fonctions variadiques avec la fonctions print int
void print_ints (int num, ...)
{
	va_list args; 

	va_start (args, num); // la macros va_strat prend deux arguments la va_list 
												// et le nom du derniers argument mis en paramètre avant "..."
	for (int i = 0; i < num; i++)
		{
			int value = va_arg(args, int); // appelle les argumentd un par un dans l'ordre où ils sont listés
																		// il faut indiqué le type pour qu'il sache la taille 
																		// attention pas de float, short ou de char autorisé 
			printf("%d: %d\n, i, value);
		}
	va_end(args);
}
```

Il faut garder des choses en têtes, le programme ne sait pas vraiment le nombre d’argument qu’on lui passe en paramètre, si on met un extra int alors qu’on lui avait indiqué qu’on voulait seulement imprimer 3 le quatrième sera  ignoré. Et je ne ne mets pas assez d’argument ça va faire buger la fonction. 
