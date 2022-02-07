# navy

## Protocole de communication

Pour envoyer des informations entre les 2 joueurs en utilisant uniquement les signaux `SIGUSR1` et `SIGUSR2`, nous avons utilisé un système binaire sur 4 ou 8 bits en fonction de l‘information envoyée.

Nous avons défini arbitrairement que la réception de `SIGUSR1` était représentée par un `0` et `SIGUSR2` par un `1`.  
Les positions contiennent 2 caractères prenant des valeurs de A à H et de 1 à 8, soit 8 valeurs possibles, il est donc possible de les représenter en 2 groupes de 3 bits allant de `000` pour A/1 à `111` pour H/8.

Cependant puisque nous avons des informations autres que les positions à transmettre, nous avons rajouté un bit de poids fort à chaque groupe pour indiquer que les bits suivant représentent une position (0) ou une information différente (1).  

C'est ainsi qu'on obtient une position envoyée sur 8 bits, par exemple:
```
A1 = 0 000 0 000
C4 = 0 010 0 011
H8 = 0 111 0 111
```

D'autres informations doivent être envoyées, comme un signal de connexion entre les joueurs au début de jeu, un signal pour informer le joueur qui attaque s'il a touché ou non un bateau....  

Puisque ces signaux sont peu nombreux, on peut largement les envoyer sur 3 bits + le bit de poids fort défini sur `1`, par exemple:
```
Connexion:  1 000
Tir réussi: 1 001
Tir raté:   1 010
```
