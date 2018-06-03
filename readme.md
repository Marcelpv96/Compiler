# Compiler &mu;C

## Introducció

Compilador realitzat per l'assignatura de Processadors de llenguatge de la Universitat de Lleida. Aquest compilador ha estat programat utilitzant bison per l'anàlisi sintàctic, i flex per l'anàlisi lexic.

## Funcionalitats implementades

-  Declaració de variables locals de qualsevol tipus.
-  Estructures de control bàsiques
    - If.. else
    - While
    - Do.. While
    - For
- Funcions.
- Declaració de variables globals.

## Instalació i ús

- Flex:
    > sudo apt install flex

- Bison:
    > sudo apt install bison

- gcc:
    > sudo apt install gcc

- g++:
    > sudo apt install g++

- Compilació:
  > make

- Execució:
    > ./mycc file.uc
