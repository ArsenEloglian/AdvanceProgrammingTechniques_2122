# Game of the Amazons

![Screenshot](game_screen.png)

Gra
----
Aplikacja została napisana w języku Java z wykorzystaniem biblioiteki JavaFX

Jak użyć
-----
Aby uruchomić aplikacje należy:
1. Pobrać repozytorium
2. Otworzyć projekt oraz dodać biblioteke JavaFX z (https://gluonhq.com/products/javafx/) do projektu
3. Ustwic VM options w `Run/Debug Configuration` : `--module-path ${PATH_TO_FX} --add-modules javafx.controls,javafx.fxml`
4. Uruchomić

Jak grać
-----
Ruchy wykonuje naprzemiennie gracz biały/czarny. Po przsunieciu pionka nalezy postawic blokade na możliwym polu. Gra konczy sie w momencie gdy gracz nie moze wykonac juz zadnego ruchu
