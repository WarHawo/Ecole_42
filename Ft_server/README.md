# FT_SERVER

Ce sujet à pour but de nous faire découvrir l'administration système en nous sensibilisant à l'importance de l'utilisation de scripts pour automatiser les taches. Nous allons utiliser la technologie "Docker" afin d'installer un serveur web web complet, qui sera capable de faire tourner plusieurs services, tel qu'un Wordpress, Phpmyadmin ainsi qu'une base de donné.

---

## Qu'est qu'un serveur web ?

Un serveur web est un serveur informatique qui permet de stocker ou de publier des pages web sur internet ou sur intranet et généralement écrite en HTML.

Le client, généralement un Navigateur web, fait une demande de page web au serveur web  qui lui envoie en réponse la page demandé. Le protocole de communication HTTP permet au serveur web de communiqué avec le client.

Le serveur web peut être logiciel ou matériel ou bien une combinaison des deux. Au niveau matériel est un serveur web est un ordinateur qui stocke des fichiers constituant un site web. Par exemple les documents HTML, les feuilles de style CCS, les images et les fichiers Javascript. 

Au niveau logiciel les composants sont différents en fonction de la nature du serveur web. 

On parle de serveur web static lorsque  le serveur web envoie les fichiers hébergés tel quel vers le client. Le serveur web static contient un OS comme windows ou Linux et un serveur http. Le serveur HTTP ou deamon HTTP est le logiciel qui prend en charge les requêtes client serveur du protocole http le plus connues et apache. 

Le serveur web dynamique inclue quand a lui en plus de l'OS et du serveur HTTP une base de donnée comme MySql qui va stocker les données et un langage de scripte comme le PHP par exemple. Le rôle de ce dernier est d'interpréter les demandes du client et de les traduire ensuite en HTML. On parle donc de serveurs web dynamique quand les fichiers hébergés sont mis à jours avant d'être envoyé aux clients via HTTP.

## Qu'est ce Docker ?

La virtualisation par conteneur se base sur la virtualisation linux LXC = LinuX Containers. Il s'agit d'une méthode de cloisonnement au niveau de l'OS. Le principe est de faire tourner des environnements Linux isolés les un des autres dans un conteneur partageant le même noyau. contrairement au machine virtuel traditionnel un conteneur n'inclue pas d'OS puisque qu'il s'appuie sur les fonctionnalité de l'OS de la machine haute. Les conteneurs accède alors à l'OS hôte de manière totalement isolé les uns des autres.  

Le conteur virtualise l'environnement d'exécution, comme le processeur la mémoire vive ou le système de fichier, et ne virtualise donc pas la machine. C'est pour cela que l'on parle de conteneur et non de machine virtuel. 

LXC repose principalement sur deux fonctionnalité du noyau Linux, La première est la fonctionnalité des C-Groupes :  control groups. C'est ce qui permet d' isolé et de limité l'utilisation des ressource. 

Ensuite la fonctionnalité de  cloisonnement des espaces de nommage (namespace en anglais ) permet d'empêcher qu'un groupe puisse voir les ressources des autres groupes.

La virtualisation par conteneurs est aussi caractérisée par la couche intermédiaire du contrôleur. Le contrôleur gère un ensemble de fonctionnalité pour les conteneurs. En premiers lieu, il y a évidemment les interactions des conteneurs avec l'OS. Ensuite la sécurité par la gestions de privilèges et de ressources. La scalabilité c'est-à-dire la duplication et la suppression des conteneurs. L'accessibilité des conteneurs à travers la gestion des API et CLI. La portabilité : c'est-à-dire la migration à froid ou à chaud de conteneurs. Enfin, il est à noté que le contrôleur peut simuler des environnements différents de celui de l'OS hôte.

### conteneur vs machine virtuelle

Une machine virtuelle ou Vm recrée intégralement un serveur c'est-à-dire avec un OS complet, ses pilotes, ses fichiers binaires ou bibliothèques ainsi que l'application elle-même. Comme le conteneur n'embarque pas d'OS il est beaucoup plus léger que la VM. Le conteneur est donc plus facile à migrer/télécharger et est plus rapides à sauvegarder/restaurer. La virtualisation par conteneur permet aussi aux serveurs d'héberger beaucoup plus de conteneurs que s'il s'agissait de VM.

Docker est donc une technologie de virtualisation par conteneurs reposant sur LXC de linux. Il permet de créer des conteneurs qui vont uniquement contenir des applications avec leurs dépendances. Les conteneurs docker permettent d'embarquer des applications afin de les exécuter au sein de l'OS hôte mais de manière virtuellement isolée.

## LES CONTENEURS

Historiquement, quand on avait besoin de serveurs il fallait acheter des serveurs physique avec une quantité définie de CPU, de mémoire RAM ou de stockage sur le disque. Or on avait souvent besoin d'avoir de la puissance supplémentaire pendant des périodes de forte charge (fête de Noël par exemple). Ainsi il fallait acheter plus de serveurs pour répondre aux pics d'utilisation. Une solution a donc était créer pour résoudre se problème : la machine virtuelle 

### Qu'est ce qu'une machine virtuelle ?

Lorsque qu'on appelle une machine virtuelle on fait de la virtualisation lourde. En effet, on recrée un systeme complet dans le systme hôte pour qu'il ait ses propres ressources. 

- definitions
    
    un hyperviseur est une plateforme de virtualisation qui permet à plusieurs systèmes d'exploitation de travailler sur une même machine physique en même temps. 
    
    un Os : système d'exploitation c'est un ensemble de programmes qui dirige l'utilisation des ressource d'un ordi. C'est un intermédiaire entre les logiciels d'application est le matériel 
    

L'isolation avec le système hôte est donc total mais cela apporte plusieurs contrainte :

- Une machine virtuelle prend du temps a démarrer ;
- Une machine virtuelle réserve les ressources (CPU/RAM) sur le système hôte.

Mais cette solution présente aussi plusieurs avantage :

- Une machine virtuelle est totalement isolée du système hôte ;
- les ressources attribuées à une machine virtuelle lui sont totalemnt réservées.
- on peut installer différent OS (Linux, Windows, BSD, ect ..)

Il arrive très souvent que l'application que la machine virtuelle fait rourner ne consomme qu'une parie des ressources dispo sur la VM (gaspillage de ressources). C'est pour ça qu'est né un nouveau système de virtualisation plus léger : les conteneur

## Qu'est-ce-qu'un conteneur ?

Un conteneur Linux est un processus ou un eemble de processur isolés du reste du système, tout en étant légers.

Le conteneur permet de faire une virtualisation légère, c'est-à-dire qu'il ne virtualise pas les ressources, il ne crée qu'une isolation des processus. Le conteneurs partage donc les ressources avec le système hôte.

Les avantages des conteneurs :

- permet de réserver que les resource nécessaire. On peut allouer 16 Go de RAM à notre conteneur, mais celui-ci n'utilise que 2 Go, le reste ne sera pas vérouiller contrairement au VM
- démarrage rapide : vu qu'il n'y a pas de virtualisation des ressources mais juste une isilation de celle-ci

Les conteneurs permettent de réduire les coûts, d'augmenter la densité d'infrastructure, tout en améliorant le cycle de déploiement. 

## Installer docker

```bash
sudo apt-get install docker.io
```

## Lister les conteneurs

```bash
docker ps
```

## Lancer un conteneur

Pour lancer un conteneur, il y a par default le docker hub qui est installer. Il a une image de base qui est installer qui s'appelle Alpine et c'est l'image la plus légers. Par défaut on est connecter au Docker Hub.

```bash
docker run alpine:latest
```

Mais si on fait juste un *docker run* et ensuite un docker ps le ps ne vas rien afficher car on a créer une image mais on ne lui a rien demander de faire. Si on fait un *docker ps -a* on verras que l'image auras été créer mais qu'elle a un statut **Exit (0)**. Cela se passe car on a rien demandé à l'image de faire.

## Comment faire pour garder une image en fonction ?

```bash
docker run -di --name Nom_Conteneur Image_utilisé:Version
docker run -di --name Hawa alpine:lastes /* destach interactive */
```

ps : par default Docker fournit un nom à notre conteneur c'est pour cela qu'on utilise le *—name* pour le définir nous même

# Se connecté un conteneur

```bash
docker exec -ti Hawa sh
```

On veut se connecter au shell du conteneur Hawa.


#Correction 
```c
sudo nginx -s stop
```

```c
sudo docker build -t nom .
```

```c
sudo docker run -it --env AUTOINDEX=on -p 443:443 -p 80:80 --name test nom
```