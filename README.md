# TP_Shell

## But:

Créer une console très simple qui exécute des commandes avec ou sans paramètre.

## Question 1 et 2:

Nous avons commencer par gérer l'exécution de commandes sans paramètres. Pour cela, nous utilisons la fonction fork() qui dédouble l'exécution du programme: une partie continue de gérer le Shell pendant que l'autre traite la commande entrée.

## Question 3:

Nous avons implémenté la posibilité de fermer le Shell en entrant la commande exit ou bien en appuyant sur ctrl+D.

## Question 4:

Il est maintenant possible d'arréter le traitement de la commande en écrivant, dans une autre console, kill "pid du fils" où le pid est affiché dans notre Shell.

## Question 5:

Nous calculons le temps d'exécution de la commande entrée. Il est affiché dans l'entête de la ligne qui suit l'exécution de la commande consernée dans le Shell.

## Question 6:

Maintenant, le Shell peut exécuter des commandes avec arguments.
