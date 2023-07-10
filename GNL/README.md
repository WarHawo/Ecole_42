# PROTOTYPE

```c
int get_next_line(int fd, char **line);
```

# PARAMÈTRES

- *fd*: Le file descriptor sur lequel lire
- *line*: La valeur de ce qui a été lu

# VALEUR DE RETOUR

 1: Une ligne a été lue

 0: La fin de fichier a été atteinte

-1: Une erreur est survenue

# DESCRIPTION

Une fonction qui retourne une ligne lue depuis un file descriptor, sans le retour à la ligne.