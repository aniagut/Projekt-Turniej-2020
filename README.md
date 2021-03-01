# Projekt-Turniej-2020
Projekt realizowany w ramach przedmiotu Algorytmy Grafowe.

## Treść zadania
Książę Bitomruk jest zapalonym szachistą. Aby uczcić jego pasję przed koronacją postanowiono przeprowadzić wielki turniej szachowy. Turniej ma polegać na tym, że każdy zawodnik zagra z każdym innym i ten, który pokona najwięcej osób zwycięży (formalnie każda potyczka składa się z serii gier, żeby każdy w parze zagrał tyle samo razy białymi co czarnymi, ale to nie znaczenia dla naszego zadania). Oczywiście organizatorzy turnieju założyli, że Bitomruk wygra, ale oszacowane wyniki gier wskazują, że najwyraźniej książe ma w sobie więcej pasji niż talentu. Jako że Wielki Turniej Koronacyjny został już ogłoszony, organizatorzy postanowili przekupić część graczy, żeby Bitomruk jednak wygrał. Na podstawie analizy poprzednich gier wyznaczyli dla każdych dwóch graczy kto zapewne wygra oraz ustalili cenę za odwrócenie tego wyniki. Niestety mają już dość ograniczony budżet i chcą na łapówki wydać jak najmniej pieniędzy. Twoim zdaniem jest napisać program, który sprawdzi, czy przy ich budżecie możliwe jest zapewnienie Bitomrukowi zwycięstwa. Na szczęście zasady zostały ustalone tak, że jeśli turniej zakończy się remisem (czyli kilku zawodników wygra tyle samo gier) i wśród remisujących znajdzie się Bitomruk, to i tak on właśnie wygrywa.

## Dane wejściowe
Plik wejściowy (który ma być wczytywany ze standardowego wejścia) w pierwszej linii zawiera liczbę T mówiącą ile jest zestawów danych (każdy pojedynczy zestaw opisuje jeden turniej). W kolejnych linijkach znajdują się opisy turniejów w następującym formacie:

W pierwszej linii znajduje się liczba B, będąca budżetem organizatorów turnieju.

W drugiej linii znajduje się liczba n zawodników. Zawodnicy są numerowani od 0 do n-1, książe Bitomruk ma numer 0 (co według niektórych dobrze odpowiada jego osobowości).

W kolejnych n*(n-1)/2 liniach znajdują się czwórki liczb x, y, w, b, oznaczające, że gdy x gra przeciwko y to zwycięża w (gdzie w jest albo równe x albo y), ale płacąc b można wynik tego spotkania odwrócić. Każda para x, y występuje w opisie turnieju dokładnie raz.

Przykładowy plik wejściowy może być postaci:

3
5
3
0 1 0 0
1 2 2 5
0 2 2 3
10
4
0 1 1 5
0 3 0 0
0 2 2 14
1 2 2 3
1 3 1 8
2 3 2 1
1
4
0 1 1 5
0 3 0 0
0 2 2 14
1 2 2 3
1 3 1 8
2 3 2 1

W pliku tym mamy trzy turnieje. Żeby Bitomruk wygrał pierwszy, należy przekupić 2-kę, żeby przegrał z 0-em, co kosztuje 3, czyli tyle ile mamy budżetu. W drugim turnieju również można doprowadzić do zwycięstwa Bitomruka:

początkowo gracz 0 ma 1 punkt (tj. 1 wygrany mecz), gracz 1 ma 2 punkty, gracz 2 ma 3 punkty, a gracz 3 ma 0 punktów.

zmieniamy wynik gry gracza 0 z graczem 1 (na korzyść gracza 0, więc gracz 0 ma 2 punkty a gracz 1 ma 1 punkt), koszt 5.

zmieniamy wynik gry gracza 1 z graczem 2 (na korzyść 1, więc obaj mają po 2 punkty), koszt 3.

gracz 0 (Bitomruk) wygrywa na mocy zasady rozstrzygania remisów a łączny koszt to 8, co nie przekracza budżetu 10.

W trzecim turnieju (który jest taki sam jak drugi, poza mniejszym budżetem) Bitomruk nie może wygrać bo budżet jest za mały.

## Format danych wyjściowych
Wynik działania programu należy wypisać na standardowe wyjście w następującym formacie:

w każdej kolejnej linijce powinno być słowo “TAK” jeśli da się doprowadzić do zwycięśtwa Bitomruka i “NIE” jeśli się nie da.
Dla pliku wejściowego powyżej poprawnym wyjściem jest:

TAK
TAK
NIE

Źródło: https://faliszew.github.io/algograf/2020.project1




