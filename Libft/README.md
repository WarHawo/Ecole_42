First project of the school, the goal is to re-code some functions of the C library.
# PART 1 - Fonction de la libcs
## 1.MEMSET
Cette fonction permet de remplir une zone mémoire identifiée par son adresse et sa taille.
### Paramètres
*s : [pointeur], permet de spécifier l’adresse du bloc mémoire à ré-initialiser
c : indique la valeur à utiliser pour remplir le bloc 
size : indique le nombre d’octets à initialiser
### Valeur de retour
Après exécution de la fonction, l’adresse de la mémoire ré-initialisée sera retournée (autrement dit la valeur du paramètre s).


## 2. BZERO
La fonction met à 0 (octets contenant "\0") les n premiers octets du bloc pointé par b.
La fonction n'est pas recommandée, il faut mieux utiliser [memset.]
### Paramètres
- b : pointeur à mettre à zéro
- n : nombre d'octet à mettre à 0.
### Valeur de retour
Aucune


## 3. MEMCPY
Cette fonction permet de copier un bloc de mémoire spécifié par le paramètre source, et dont la taille est spécifiée via le paramètre size, dans un nouvel emplacement désigné par le paramétrer destination.
Il faut allouer suffisamment de mémoire pour le bloc de destination afin qu’il puisse contenir toutes les données.
### Paramètres
- Destination : permet de spécifier l’adresse du bloc mémoire devant recevoir les données à copier. On doit pré-allouer ce bloc de mémoire
- Source : permet de définir l’adresse du bloc de mémoire à dupliquer
- Size :  indique le nom d’octets à dupliquer
### Valeur de retour
La fonction renvoie l’adresse du bloc de mémoire de destination.


## 4. MEMCCPY
Cette fonction permet de copier un bloc de mémoire spécifié par le paramètre source dans un nouvel emplacement désigné par le paramètre destination. La copie s'arrête soit après la première occurence du caractère c, soit à la taille spécifiée par le paramètre max_size.
En cas de chevauchement des deux blocs de mémoire (source et destination) le comportement de la fonction memccpy n'est pas garanti. Dans ce cas, il faut mieux utiliser la fonction [memmove]
### Paramètres
- Destination: permet de spécifier l’adresse du bloc mémoire devant recevoir les données à copier.
- Source : permet de définir l’adresse du bloc de mémoire à dupliquer.
- C : le caractère permettant de mettre fin à la copie du bloc de mémoire. Cet entier sera converti en unsigned char.
- Size : indique le nombre d’octets à dupliquer
### Valeur de retour
Si aucune occurence du caractère c n'est pas trouvé, la fonction renverra un pointeur nul. Dans le cas contraire, la fonction retournera un pointeur vers le caractère c dans la chaîne finale.


## 5. MEMMOVE
Cette fonction permet de copier un bloc de mémoire spécifié par le paramètre source dans un nouvel emplacement désigné par le paramètre destination.
On peut donc dire que cette fonction est proche de la fonction [memcpy]. Néanmoins, la fonction memmove accepte que les deux zones de mémoire puissent se chevaucher.
En cas de chevauchement, la copie se passe comme si les octets de la zone source étaient d’abord copiés dans une zone temporaire, qui ne chevauche aucune des deux zones pointées par source et destination, et les octets sont ensuite copiée de la zone temporaire vers la zone destination.  
### Paramètres
- Destination: permet de spécifier l’adresse du bloc mémoire devant recevoir les données à copier.
- Source : permet de définir l’adresse du bloc de mémoire à dupliquer.
- Size : taille de la source.
### Valeur de retour
La fonction renvoie l’adresse du bloc de mémoire de destination


## 6. MEMCHR
Recherche la première occurence d'une valeur int, mais interprétée en tant que char, dans un bloc mémoire. 
### PARAMÈTRE
- s : un pointeur indiquant l'adresse du bloc mémoire à utiliser pour la recherche.
- c : la valeur à rechercher.
- size : indique la taille du bloc de mémoire dans lequel opérer la recherche.
### VALEUR DE RETOUR
Si la fonction a trouvé le caractère recherché, la fonction renvoie un pointeur vers sa première occurence. Si ce n'est pas le cas, la fonction renvoie la valeur NULL.


## 7. MEMCMP
Cette fonction permet de comparer le contenu de deux blocs de mémoire spécifiés par les deux premiers paramètres de la fonction. Size permet de spécifier le nombre d'octets sur lequel comparer les deux blocs. Les octets des deux blocs sont comparés deux à deux. Tant que les deux octets comparés sont égaux, la fonction  passe aux deux suivants. Si les deux octets comparés sont différents, alors la fonction renverra lequel des blocs  est le plus petit en termes de contenu.
Attention, contrairement à strcpy, aucun test sur une éventuelle valeur nulle n'est réalisé pour stopper la comparaison. Seule la taille du bloc sera considérée.
### PARAMÈTRE
- pointer1 : permet de spécifier l'adresse du premier bloc mémoire à comparer
- pointer2 : permet de spécifier l'adresse du second bloc mémoire à comparer
- size : indique le nombre d'octets maximal à comparer
### VALEUR DE RETOUR
Trois cas sont possible en termes de valeur de retour.
Soit la valeur est négative : dans ce cas, le premier octet qui diffère entre les deux blocs est plus petit dans le premier bloc.
Soit la valeur est nulle : dans ce cas, les deux blocs ont leurs contenus strictement identique.
Si la valeur de retour est positive : dans ce cas, le premier octet qui diffère entre les deux blocs est plus grand dans le premier bloc.


## 8. STRLEN
Cette fonction permet de calculer a longueur, exprimée en nombre de caractères, de la chaîne de caractères.
Attention la fonction ne compte pas le dernier caractère "\0" . 
### PARAMÈTRE
- theString : la chaîne de caractères pour laquelle il faut calculer sa longueur
### VALEUR DE RETOUR
La fonction renvoie le nombre de caractère trouvés.


## 9. ISALPHA
Cette fonction permet de tester si un caractère est alphabétique ou non. Un caractère sera considéré comme alphabétique s'il est de lettres minuscules ou de lettres majuscules. Les fonction de cette librairie ne traitent que les caractères purs ASCII. les lettres accentuées ne seront pas considérées comme des caractères alpha-numérique.
### PARAMÈTRE
- character : le caractères à tester. Il est sur-typé par int car la fonction peut aussi accepter la valeur -1 (End of file) correspondant à la fin d'un flux.
### VALEUR DE RETOUR
La valeur de retour doit être interprétée en tant que la valeur booléenne. Une valeur positive non nulle signifiera qu'il s'agit bien d'un caractère alphabétique.
La valeur 0 indiquera qu'il ne s'agit pas d'un caractère alphabétique.


## 10. ISDIGIT
Cette fonction permet de tester si un caractère est un chiffre décimal ou non.
### PARAMÈTRE
- character : le caractère à tester. Il est sur-typé par int car la fonction peut aussi accepter la valeur -1 (EOF- End Of File) correspond à la fin d'un flux.
### VALEUR DE RETOUR
Une valeur positive non nulle signifiera qu'il s'agit d'un chiffre décimal.
La valeur 0 indiquera qu'il ne s'agit pas d'un chiffre décimal.


## 11.ISALNUM
Cette fonction permet de tester si un caractère est alpha-numérique ou non. Un caractère sera considéré comme alpha-numérique s'il est une lettre (minuscule ou majuscule) ou un chiffre. Rappel : les fonctions de cette librairie ne traitent que les caractères purs ASCII. Les lettres accentuées ne seront donc pas considérées comme des caractères alpha-numériques.
### PARAMÈTRE
- character : le caractère à tester. Il est sur-typé par int car la fonction peut aussi accepter la valeur -1 (EOF - End Of File) correspondant à la fin d'un flux.
### VALEUR DE RETOUR
Une valeur positive non nulle signifiera qu'il s'agit bien d'un caractère alpha-numérique. La valeur 0 indiquera qu'il ne s'agit pas d'un caractère alpha-numérique.

## 12. ISASCII
Vérifie si c est  un  unsigned  char  sur  7  bits, entrant  dans  le  jeu  de  caractères ASCII.
### PARAMÈTRE
- c: le caractère à tester.
### VALEUR DE RETOUR
Une valeur positive si le caractère fait partie de la table ascii.
Une valeur nulle si ce n'est pas le cas.

## 13. ISPRINT
Cette fonction permet de tester si un caractère s'affiche (is printable) ou non. 
### PARAMÈTRE
- character : le caractère à tester. Il est sur-typé par int car la fonction peut aussi accepter la valeur -1 (EOF - End Of File) correspondant à la fin d'un flux.
### VALEUR DE RETOUR
La valeur de retour doit être interprétée en tant que valeur booléenne. Une valeur positive non nulle signifiera qu'il s'agit bien d'un caractère pouvant s'afficher visuellement. La valeur 0 indiquera qu'il ne s'agit pas d'un caractère pouvant s'afficher.


## 14. TOUPPER
Cette fonction permet de convertir une lettre minuscule à une lettre majuscule. Rappel : les fonctions de cette librairie ne traitent que les caractères purs ASCII. Les lettres accentuées ne seront donc pas considérées comme des caractères alpha-numériques.
### PARAMÈTRE
- character : le caractère à convertir. Il est sur-typé par int car la fonction peut aussi accepter la valeur -1 (EOF - End Of File) correspondant à la fin d'un flux.
### VALEUR DE RETOUR
Cette fonction retourne le caractère équivalent transformé en majuscule, si le caractère passé en paramètre était une minuscule. Si le caractère passé n'était pas une minuscule, alors la fonction retourne le caractère inchangé. Le résultat doit bien entendu être considéré en tant que unsigned char, néanmoins la fonction peut -1 si EOF a été fournit en paramètre.


## 15. TOLOWER
Cette fonction permet de convertir une lettre majuscule à une lettre minuscule. Rappel : les fonctions de cette librairie ne traitent que les caractères purs ASCII. Les lettres accentuées ne seront donc pas considérées comme des caractères alpha-numériques.
### PARAMÈTRE
- character : le caractère à convertir. Il est sur-typé par int car la fonction peut aussi accepter la valeur -1 (EOF - End Of File) correspondant à la fin d'un flux.
### VALEUR DE RETOUR
Cette fonction retourne le caractère équivalent transformé en minuscule, si le caractère passé en paramètre était une majuscule. Si le caractère passé n'était pas une majuscule, alors la fonction retourne le caractère inchangé. Le résultat doit bien entendu être considéré en tant que unsigned char, néanmoins la fonction peut -1 si EOF a été fournit en paramètre.


## 16. STRRCHR
Cette fonction recherche la dernière occurence du caractère passé en second paramètre dans la chaîne de caractère spécifiée via le premier caractère.
La fonction [strrchr] est proche de la fonction [strchr]. La différence réside dans le fait que [strchr] renvoie la position de la première occurrence du caractère recherché alors que [strrchr] renvoie la dernière occurence (recherche par la droite)
### PARAMÈTRE
- string : la chaîne de caractères dans laquelle effectuer la recherche.
- searchedChar : le caractère recherché.


## 17. STRNCMP
Cette fonction permet de comparer deux chaînes de caractères et de savoir si la premières est inférieure, égale ou supérieur à la seconde. Cette comparaison sera faites dans l'ordre lexicographique (en tenant compte des valeurs ASCII des différents caractères comparées).
Néanmoins la comparaison se fera au maximum sur les length premiers caractères.
### PARAMÈTRE
- first : la première chaîne de caractères à comparer
- second : la seconde chaîne de caractères à comparer.
- length : le nombre maximal (un entier non signé) de caractère à comparer.
### VALEUR DE RETOUR
Soit les deux chaînes sont égales : dans ce cas, une valeur nulle sera retournée.
Soit la première chaîne est plus petite que la seconde : dans ce cas, une valeur négative sera retournée.
Soit la première chaîne est plus grande que la seconde : dans ce derniers cas, une valeur n-positive sera renvoyée.


## 13. STRLCPY
Copie les size premiers caractères de la chaînes src dans la chaine dst.
### PARAMÈTRE
- src : la chaîne de caractères à copier.
- dst : la chaîne de caractères qui recevra la copie de la chaîne src.
- size : le nombre de caractères à copier.
### VALEUR DE RETOUR
Retourne la taille de la chaîne src.


## 14. STRLCAT
La fonction concatène les deux chaînes de caractères.  Elle ajoute les caractères de la chaîne source à la fin de la chaîne destination. 
### PARAMÈTRE
- dst : la chaîne de caractères qui recevra la concaténation.
- src : la chaîne de caractères à concaténer.
- size : taille de la chaîne final créer.
### VALEUR DE RETOUR
Renvoie la taille total de la chaîne que la fonction essai de créer, c'est à dire la taille initial de la chaîne destination plus la la taille de la chaîne source.


## 15. STRNSTR 
La fonction localise la première occurence de la chaine de caractères to_find dans la chaîne src, mais seulement len caractères sont recherchées. Les caractères qui apparaissent après un '\0' ne sont pas cherché. 
### PARAMÈTRE
- str : La chaîne de caractères dans laquelle on va faire notre recherche.
- to_find : La chaîne de caractères à chercher.
- len : nombre de caractère à chercher.
### VALEUR DE RETOUR
Si to_find est une chaîne vide, la chaîne str est renvoyé.  Si to_find n'apparait nul part dans str alors NULL sera retourné. Sinon un pointeur sur le premier caractère de la première occurence du to_find sera renvoyé.


## 16. ATOI
Cette fonction permet de transformer une chaîne de caractères, représentant une valeur entière, en une valeur numérique de type int. Le terme d'atoi est un acronyme signifiant : ASCII to integer.
### PARAMÈTRE
- theString : ce paramètre contient la chaîne de caractères à convertir en une donnée de type int.
### VALEUR DE RETOUR
Si la chaîne à convertir ne contient pas une donnée numérique entière, la valeur 0 vous sera retournée. Sinon, une valeur de type int équivalente à la chaîne passée en paramètre vous sera retournée.


## 17. CALLOC
Cette fonction alloue un bloc de mémoire en initialisant tous ces octets à la valeur 0. Bien que relativement proche de la fonction malloc, deux aspects les différencient :
- L'initialisation : calloc met tous les octets du bloc à la valeur 0 alors que malloc ne modifie pas la zone de mémoire.
- Les paramètres d'appels : calloc requière deux paramètres (le nombre d'éléments consécutifs à allouer et la taille d'un élément) alors que malloc attend la taille totale du bloc à allouer.
### PARAMÈTRE
- elementCount: permet de spécifier le nombre d'éléments consécutifs à réserver dans le bloc de mémoire.
- elementSize : permet de fixer la taille (en nombre d'octets) d'un élément.
Au total, la zone de mémoire allouée occupera donc `elementCount` * `elementSize` octets.
Dans le cas où le bloc de mémoire ne pourrait vous être réservé (plus de mémoire disponible, par exemple), le pointer NULL vous sera retourné.
### VALEUR DE RETOUR
Si tout ce passe bien, la fonction vous renvoie un pointeur sur la zone nouvellement allouée. Attention, ce pointeur est de type pointeur générique (void *) : si nécessaire, il est donc de votre responsabilité de "caster" votre pointeur vers un autre type (du moins si vous souhaitez ne pas avoir de warning affiché pas le compilateur, ce que je vous recommande vivement).


## 17. STRDUP
Cette fonction permet de dupliquer une chaîne de caractères.
la fonction strdup alloue une nouvelle zone de mémoire via la fonction malloc afin d'y copier la chaîne de caractères initiale. Il est donc impératif de libérer cette zone de mémoire après utilisation via la fonction free.
### PARAMÈTRE
- source : permet de définir l'adresse de la chaîne de caractères à dupliquer.
### VALEUR DE RETOUR
S'il y a suffisamment de mémoire pour produire la nouvelle chaîne, la fonction renvoie l'adresse de la chaîne dupliquée. Dans le cas contraire, un pointeur nul vous sera retourné.


# PART 2 - Fonction supplémentaires

## 1. SUBSTR
La fonction alloue avec malloc et retourne une chaine de caractères issue de la chaine 's'. Cette nouvelle chaine commence à l'index 'start' et a pour taille maximal 'len'. 
### PARAMÈTRES
- s : la chaîne de caractères de laquelle extraire la nouvelle chaîne.
- start : L'index de début de la nouvelle chaîne dans la chaîne 's'.
- len : La taille maximale de la nouvelle chaîne.
### VALEUR DE RETOUR
La nouvelle chaîne de caractères 
Ou NULL si l'allocation échoue.

## 2. STRJOIN
Alloue avec malloc et retourne une nouvelle chaine, résultant de la concaténation de s1 et s2.
### PARAMÈTRES
- s1 : La chaine de caractères préfixe.
- s2 : La chaine de caractère suffixe.
### VALEUR DE RETOUR
La nouvelle chaine de caractère, qui est la concaténation des deux chaines. 

## 3. STRTRIM
Alloue  et retourne une copie de la chaine de caractères donnée en argument, sans les caractères spécifiés dans le set donné en argument au début et à la fin de la chaine de caractères.
### PARAMÈTRES
- s1: La chaine de caractère à trimmer
- s2: Le set de reference de caractères à trimmer
### VALEUR DE RETOUR
La chaine de caractère trimmée. NULL si l'allocation échoue.


## 4. SPLIT
Alloue et retourne un tableau de chaine de caracteres obtenu en séparant s à l'aide du cactère c, utilisé comme délimitaur. Le tableau doit être terminé par NULL.
### PARAMÈTRES
- s: La chaine de caractère à découper
- c: Lecarctère délimitant
### VALEUR DE RETOUR
Le tableau de nouvelle chaines de caractères, résultant du découpage. NULL si l'allocation échoue.

## 5. ITOA
Alloue avec malloc et retourne une chaine de caractères représentant l’integer reçu en argument. Les nombres négatifs doivent être gérés.
### PARAMÈTRES
- n: L'integer à convertir
### VALEUR DE RETOUR
La chaine de caractères représentant l’int. NULL si l’allocation échoue.

## 6. STRMAPI
Applique la fonction f à chaque caractère de la chaine de caractères passée en argument pour créer une nouvelle chaine de caractères avec malloc résultant des applications successives de f.
### PARAMÈTRES
- s: La chaine de caractère sur laquelle itérer
- f: La fonction à appliquer à chaque  caractère
### VALEUR DE RETOUR
La chaine de caractère résultant des applications successives de f. Retourne NULL si l'allocation échoue.

## 7. PUTCHAR_FD
Écrit le caractère c sur le file descriptor donné.
### PARAMÈTRES
- c : Le carctère à écrire
- fd: Le file descriptor sur lequel écrire
### VALEUR DE RETOUR
Aucune.


## 8. PUTSTR_FD
Écrit le chaine caractère c sur le file descriptor donné.
### PARAMÈTRES
- s: La chaine de caractères à écrire
- fd: Le file descriptor sur lequel écrire
### VALEUR DE RETOUR
Aucune.

## 9. PUTENDL_FD
Écrit le chaine caractère c sur le file descriptor donné, suivie d'un retrour a la ligne.
### PARAMÈTRES
- s: La chaine de caractères à écrire
- fd: Le file descriptor sur lequel écrire
### VALEUR DE RETOUR
Aucune.

## 10. PUTNBR
Écrit l’integer n sur le file descriptor donné
### PARAMÈTRES
- n: L'integer à écrire
- fd: le file descriptor sur lequel écrire
### VALEUR DE RETOUR
Aucune.

# PART 3 - Fonction bonus

## 1. LST_NEW
Alloue avec malloc et renvoie un nouvel élément. la variable content est initialisée à l’aide de la valeur du paramètre content. La variable next est initialisée à NULL.
### PARAMÈTRES
- Le contenu du nouvel élément
### VALEUR DE RETOUR
Le nouvel élément

## 2. LST_ADD_FRONT
Ajoute l'élément new au début de la liste
### PARAMÈTRES
- *alst*: L'adresse du pointeur vers le premier élément de la liste
- *new*: L'adresse du pointeur vers l'élémnet à rajouter à la liste
### VALEUR DE RETOUR
aucune

## 3. LST_SIZE
Compte le nombre d'élément de la liste
### PARAMÈTRES
- Le début de la liste
### VALEUR DE RETOUR
taille de la liste

## 4. LST_LAST
Renvoie le dernier élément de la liste.
### PARAMÈTRES
- Le début de la liste
### VALEUR DE RETOUR
Dernier élément de la liste

## 5. LST_ADD_BACK
Ajoute l’élément new à la fin de la liste.
### PARAMÈTRES
- *alst*: L'adresse du pointeur vers le premier élément de la liste
- *new*: L'adresse du pointeur vers l'élément à rjouter à la liste
### VALEUR DE RETOUR
aucune


## 6. LST_DELONE
Libère la mémoire de l’élément passé en argument en utilisant la fonction del puis avec free. La mémoire de next ne doit pas être free.
### PARAMÈTRES
- *lst*: l'élément à free
- *(del)* : l'adresse de la fonction permettant de supprimer le contenu de l'élément
### VALEUR DE RETOUR
aucune


## 7. LST_CLEAR
Supprime et libère la mémoire de l’élément passé en paramètre, et de tous les élements qui suivent, à l’aide de del et de free. Enfin, le pointeur initial doit être mis à NULL.
### PARAMÈTRES
- *lst*: l'adresse du pointeur vers un élément
- *del*: l'adresse de la fonction permettant de supprimer le contenu d'un élément
### VALEUR DE RETOUR
aucune

## 8. LST_ITER
Description Itère sur la list lst et applique la fonction f au contenu chaque élément.
### PARAMÈTRES
- *lst*: L'adresse du pointeur vers un élément
- *f*: L'adresse de la fonction à appliquer
### VALEUR DE RETOUR
aucune

## 8. LST_MAP
Itère sur la liste lst et applique la fonction f au contenu de chaque élément. Crée une nouvelle liste résultant des applications successives de *(f).* la fonction del est la pour détruire le contenu d un element si necessaire.
### PARAMÈTRES
- *lst*: L'adressedu pointeur vers un élément
- *del*: L'adresse de la fonction à appliquer
### VALEUR DE RETOUR
La nouvelle liste. NULL si l'allocation échoue.