# Game of the Amazons

![Screenshot](game_screen.png)

Gra
----
Aplikacja została napisana w języku Java z wykorzystaniem biblioiteki JavaFX

Jak użyć
-----
Aby uruchomić aplikacje należy:
1. Ściągnąć projekt.
2. Zainstalować środowisko programistyczne IntelliJ (link do pobrania programu w sekcji "Przydatne linki")
3. W IntelliJ otworzyć projekt (wskazać w wyborze na folder GowinPlewaGra)
4. Dodać bibliotekę javafx.
   1. Ściągnąć bibliotekę javafx (https://gluonhq.com/products/javafx/ Release 17) 
   2. W IntelliJ `File -> Project structure-> libraries`. 
   3. Dodając bibliotekę należy pamiętać o wskazaniu na folder `/lib` i dodaniu jej do projektu.
5. Jeżeli SDK nie jest ustawiony należy go ustawić `File -> Project structure-> Project`. Projekt korzystał z Oracle OpenJDK version 17.0.1 (link do pobrania w sekcji "Przydatne linki")
6. W  `Run -> "Edit configuration"`  należy dodać nową konfigurację (Application) 
   1. Główna klasa to: AmazonApp 
   2. Modify options -> `Add VM options` utworzy nowe pole w które należy wpisać 
   `--module-path ${PATH_TO_FX} --add-modules javafx.controls,javafx.fxml`, gdzie ${PATH_TO_FX} to ścieżka do biblioteki javafx (należy wskazać na folder /lib)
7. Uruchomić grę

Jak grać
-----
Ruchy wykonuje naprzemiennie gracz biały/czarny. Po przsunieciu pionka nalezy postawic blokade na możliwym polu. Gra konczy sie w momencie gdy gracz nie moze wykonac juz zadnego ruchu

Przydatne linki:
-----
-Srodowisko: https://www.jetbrains.com/idea/download/

-SDK: https://jdk.java.net/17/
