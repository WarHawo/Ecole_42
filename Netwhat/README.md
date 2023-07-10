Adresse IP
Une adresse IP est un nombre codé sur 32 bits (32 ‘0’ ou ‘1’) qui représente un numéro unique de machine sur un réseau IP.

Une adresse IP est une suite de 4 octets

x.w.y.z

Exemple : 193.168.0.1

les adresses IP doivent être uniques sur un même réseau IP, mais peuvent cependant être redondantes sur des réseaux séparés. Sur le réseau Internet, qui est un réseau IP mondial, toutes les adresses IP doivent être uniques. C’est un peu comme une adresse postale : si vous voulez recevoir votre courrier, le numéro de votre maison, la rue et le code postal doivent former un triplet unique. 

Les adresses IP sont composées de deux parties: la partie « réseau » et la partie « numéro de machine ».  

La classes de l’adresse IP détermine quelle partie de l’adresse code le réseau et quelle partie code le numéro de machine (hôte). Il y a  5 classes d’adresse IP.

Les classes d’adresse IP
Nom	Masque de sous-réseau	Adresse réseau	Nombre de réseau	Plage premier octet
📕A	255.0.0.0	1.0.0.0 - 126.255.255.255	126	0 à 127
📕C	255.255.255.0	192.0.0.0 - 223.255.255.255	2097152	192 à 223
📕B	255.255.0.0	128.0.0.0 - 191.255.255.255	16384	128 à 191
📕D	240.0.0.0	224.0.0.0 - 239.255.255.255	Adresses uniques	224 à 239
📕E	Non défini	240.0.0.0 - 255.255.255	Adresses uniques	240 à 255


On n’utilise généralement pas la classe D et E. La classe par défaut est la classe C.

La classe avec le plus d’adresse hôtes disponible pas défaut est la classe A.

Adresse IP privé
Il existe 3 sortes d’adresse privé.

10.0.0.0 /8  (utilisé dans un lycée par exemple)
172.16.0.0 /12 
192.168.0.0 /16  (utilisé pour un réseau local par exemple)
Les masques de sous-réseau 
Les masques de sous réseau indique le nombre de bit à 1 d’une adresse IPv4. Ils sont utilisé pour identifié le sous réseau et le nombre de bit qui caractérise les hôtes. Tous les bits correspondant à la partie qui code le réseau et celle qui code le sous-réseau sont à 1 et les bits qui codent le numéro de machine sont des 0.

/8 : 1111 1111. 0000 0000. 0000 0000. 0000 0000

Exemple : adresse IP 192.168.1.2

Masque = 255.255.255.0

Les octets qui sont associées au 255 ne  vont pas changé et corresponde à l’adresse de sous-réseau.

Quand le masque est à 0 : on à la plage total pour géré l’adresse de l’hôte, il peut aller de 0 à 255. 

Calcul 
Calcule adresse réseau
L’adresse de sous-réseau est obtenue en faisant un ET binaire entre l’adresseIP et le masque de sous-réseau.

Le ET binaire : 1+0=0; 1+1=1;

 Exemple : 
IP =  150 . 10 . 10 . 10
M =  255. 255. 252. 0
L’adresse IP en binaire:    1001 0110 .0000 1010 .0000 1010 .0000 1010                  150.10.10.10

Masque de sous-réseau: 1111 1111   .1111  1111    .1111 1100    .0000 0000.            255.255.252.0

ET binaire.                         ————————————————————————-          ————————

Adresse de sous-réseau: 1001 0110  .0000 1010 .0000 1000 .0000 0000.              150.10.8.0

Calcule adresse broadcast / de diffusion
L’adresse de broadcast est obtenue en faisant un OU binaire entre l’adresse de sous-réseau et le masque de sous-réseau inversé.

Le OU binaire: 0+1=1; 1+1=1; 

Exemple :
IP = 150.10.10.10
M = 255.255.252.0
Adresse de sous réseau = 150.10.8.0


Adresse de sous-réseau: 1001 0110.0000 1010.0000 1000.0000 0000     150.10.8.0

Masque inversé:                0000 000.0000 0000.0000 0011.1111 1111           0.0.3.255

OU binaire                          —————————————————————-         —————-

Adresse broadcats:           1001 0110.000 1010.0000 1011.1111 1111.            150.10.11.255

Le modèle OSI
le modèle OSI est une norme qui préconise comment les ordinateurs devraient communiquer entre eux. Son objectif est de normaliser les communications pour garantir un maximum d’évolutivité et d’interopérabilité entre les ordinateus.

Le modèle OSi est une modèle en couches. Cela veut dire qu’il est découper en plusieurs morceaux appelés couches, qui ont chacune un rôle défini.


Le protocole TCP
Tcp qui signifie Transmission control Protocol est un des principes de la couche transport du modèle TCP/IP. Il permet, au niveau des applications, de gérer les données en provenance, ou à destination, de la couche inférieur.

TCP est un protocole oriente connexion. Il vérifie si les données sont bien réceptionnées.

TCP est plus fiable

TCP n’est pas orienté datagramme

 Le protocole UDP
UDP est orienté non connexion, transport de donnée sans vérification

UDP est plus rapide

UDP orienté transaction et fournit des datagrammes

Ping
Ping utilise ICMP

Trouver le local host 127.0.0.1



DHCP
DHCP permet de créer des un mécanismes de création d’adresse IP

DHCP utilise UDP

