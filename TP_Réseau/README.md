# TP_RESEAU

## Question 1
  Pour obtenir les informations de la ligne de commande, il suffit d'utiliser argc et argv.

## Question 2
On configure les structures addr_info et les arguments de getaddrinfo comme pour le TD3.

## Question 3
On crée un socket avec la fonction socket. On a ensuite utilisé connect pour tester la connection au serveur.
Or vu que dans les questions suivante on utilise une socket UDP, cela n'est pas necessaire

## Question 4
Pour envoyer des requête RRQ, on doit respecter l'architecture suivante: 01 + Nom du fichier + 0 + Mode + 0
On crée donc un buffer qu'on remplie de manière adéquate.
