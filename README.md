# Arithmétique modulaire

Implémentation de l'arithmétique modulaire pour les entiers et les polynômes.

## Librairie

Le répertoire `lib` contient le code de la librairie statique `libmod`. Pour compiler la librairie depuis la racine :
```
make lib/libmod.a
```

### Arithmétiques

Quatre arithmétiques différentes sont implémentées :

- [x] `integer` : arithmétique d'entiers
- [x] `modint` : arithmétique d’entiers modulo un entier m
- [x] `modpoly` : arithmétique de polynômes à coefficients dans Z/mZ
- [x] `modpolyp` : arithmétique de polynômes modulo un polynôme P

La librairie contient aussi :
- [x] `extendedGcdInt` : algorithme d’Euclide étendu pour les entiers
- [x] `extendedGcdPoly` : algorithme d'Euclide étendu pour les polynômes à coefficients dans Z/mZ

La librairie définit les quatre types suivants :
- `integer` : entier de 32 bits
- `modulus` : entier modulo de 32 bits
- `polynomial` : polynôme d'entiers
- `degree` : degré d'un polynôme

### Séries formelles

Les fichiers `fps` définissent des fonctions pour manipuler les séries formelles.
Le type `fps` permet de définir une série formelle tronquée, et `prec` renseigne sa précision.

### Arbres de polynômes

Les fichiers `polytree` définissent les arbres de polynômes permettant l'implémentation des algorithmes rapides d'évaluation multipoint et d'interpolation.

## Exemples

Le répertoire `examples` contient des exemples d'utilisation de la librairie `libmod`.
- Pour compiler un exemple :
```
cd examples
make example1.out
```
- Pour compiler tous les exemples :
```
cd examples
make
```
Le README du répertoire `examples` montre le rôle de chaque exemple.

## Exécutables

Le répertoire `src` contient les fonctions principales pour générer des exécutables utilisant la librairie `libmod`.

### Compilation

- Pour compiler tous les exécutables :
```
make
```
- Pour compiler l'exécutable **extendedGcdInt.out** :
```
cd src
make ../extendedGcdInt.out
```
Protocole similaire pour tous les exécutables ci-dessous.

Les exécutables créés se trouvent à la racine du répertoire.

### Description

Voici la liste des exécutables :

- **extendedGcdInt.out** : algorithme d'Euclide étendu pour les entiers. Exemple ([source](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example)) :
```
== Extended Euclidean algorithm for integers ==
a = 240
b = 46
== Iteration 0 ==
(r, u, v) = (240, 1, 0)
== Iteration 1 ==
(r, u, v) = (46, 0, 1)
== Iteration 2 ==
(r, u, v) = (10, 1, -5)
== Iteration 3 ==
(r, u, v) = (6, -4, 21)
== Iteration 4 ==
(r, u, v) = (4, 5, -26)
== Result ==
(r, u, v) = (2, -9, 47)
```

- **extendedGcdPoly.out** : algorithme d'Euclide étendu pour les polynômes à coefficients dans Z/mZ. Exemple ([source](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example_2)) :
```
== Extended Euclidean algorithm for polynomials ==
Degree of A: 8
A[0] = 1
A[1] = 1
A[2] = 0
A[3] = 1
A[4] = 1
A[5] = 0
A[6] = 0
A[7] = 0
A[8] = 1
Degree of B: 6
B[0] = 1
B[1] = 1
B[2] = 0
B[3] = 0
B[4] = 1
B[5] = 0
B[6] = 1
Modulus: 2
A = X^8 + X^4 + X^3 + X + 1
B = X^6 + X^4 + X + 1
== Iteration 0 ==
R = X^8 + X^4 + X^3 + X + 1
U = 1
V = 0
== Iteration 1 ==
R = X^6 + X^4 + X + 1
U = 0
V = 1
== Iteration 2 ==
R = X^2
U = 1
V = X^2 + 1
== Iteration 3 ==
R = X + 1
U = X^4 + X^2
V = X^6 + X^2 + 1
== Result ==
R = 1
U = X^5 + X^4 + X^3 + X^2 + 1
V = X^7 + X^6 + X^3 + X
```

- **evalPoly.out** : évaluation d'un polynôme en un point dans Z/mZ. Exemple :
```
== Polynomial evaluation ==
Degree of P: 3
P[0] = 4
P[1] = 1
P[2] = 2
P[3] = 1
Modulus: 7
P = X^3 + 2 X^2 + X + 4
X = 2
P(2) = 1
```

- **multipointEvalPoly.out** : évaluation multipoint d'un polynôme dans Z/mZ. Exemple :
```
== Polynomial multipoint evaluation ==
Degree of P: 3
P[0] = 4
P[1] = 1
P[2] = 2
P[3] = 1
Modulus: 7
P = X^3 + 2 X^2 + X + 4
n = 4
x0 = 2
x1 = 5
x2 = 3
x3 = 4
== Result ==
P(2) = 1
P(5) = 2
P(3) = 3
P(4) = 6
```

- **euclideanDivisionPoly.out** : division euclidienne de polynômes à coefficients dans Z/mZ. Exemple :
```
== Euclidean division of polynomials ==
Degree of P: 4
P[0] = 9
P[1] = 1
P[2] = 4
P[3] = 7
P[4] = 1
Degree of D: 3
D[0] = 2
D[1] = 1
D[2] = 1
D[3] = 10
Modulus: 11
P = X^4 + 7 X^3 + 4 X^2 + X + 9
D = 10 X^3 + X^2 + X + 2
== Results ==
Q = 10 X + 3
R = 2 X^2 + 3
```

- **interpolationPoly.out** : interpolation de Lagrange dans Z/mZ. Exemple :
```
== Polynomial interpolation ==
Modulus: 7
n = 4
x0 = 2
y0 = 1
x1 = 5
y1 = 2
x2 = 3
y2 = 3
x3 = 4
y3 = 6
Lagrange polynomial:
L = X^3 + 2 X^2 + X + 4
Verification:
L(2) = 1
L(5) = 2
L(3) = 3
L(4) = 6
```

## Algorithmes

Voici la liste des algorithmes implémentés (ou à faire) :

- [x] [Algorithme d'Euclide étendu](https://fr.wikipedia.org/wiki/Algorithme_d%27Euclide_%C3%A9tendu) (pour les entiers et les polynômes)
- [x] [Méthode de Ruffini-Horner](https://fr.wikipedia.org/wiki/M%C3%A9thode_de_Ruffini-Horner)
- [x] Évaluation multipoint rapide
- [x] [Interpolation lagrangienne](https://fr.wikipedia.org/wiki/Interpolation_lagrangienne)
- [ ] Interpolation rapide
- [ ] [Algorithme de Wiedemann](https://en.wikipedia.org/wiki/Block_Wiedemann_algorithm)
- [ ] [Algorithme de remontée de Hensel](https://fr.wikipedia.org/wiki/Lemme_de_Hensel)

## Documentation

La documentation peut être générée par `doxygen` avec la commande :
```
make docs
```
Il suffit ensuite d'aller à l'adresse `docs/html/index.html`.

Pour supprimer la documentation :
```
make cleandocs
```

## Auteur

[Quentin Deschamps](mailto:quentindeschamps18@gmail.com)
