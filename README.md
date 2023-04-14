Space shooter (name subject to change)
Gracz wcieli się w pilota statku kosmicznego przemierzającego odległe zakątki wszechświata. Jego zadaniem będzie wykonywanie pobocznych misji, polegających na zbieraniu konkretnych elementów, niszczeniu statków kosmitów, unikaniu deszczów meteorytów, a co jakiś czas pokonywaniu potężnych wrogich bossów.

Na ekranie widoczny będzie statek kosmiczny, którym gracz będzie się poruszać za pomocą strzałek. Wraz z upływem gry będzie on udoskonalany za pomocą części zbieranych w trakcie rozgrywki lub zamieniany na lepszy, kupiony za wirtualną kosmiczną walutę. Każdy ze statków będzie miał swoje charakterystyczne statystyki (takie jak punkty życia czy prędkość), a także własne ataki specjalne. W grze spotkamy wiele rodzajów wrogich statków, które także różnić się od siebie będą statystykami i różnymi metodami na zniszczenie statku gracza. Rozgrywka będzie więc urozmaicona, zgodna z prawem Bushnella: „Easy to learn, hard to master”.
[baza (gracz kupuje tam i ulepsza statki)]
[ataki na bazę]
[pytanie o sfml]



Podział na klasy:
- Game - jest to klasa główna, odpowiedzialna za zarządzanie grą. Znajdzie się w niej pętla umożliwiająca działanie programu oraz podstawowe metody umożliwiające przerwanie, zatrzymanie i wznowienie gry. Klasa ta będzie miała dostęp do wszystkich innych klas. Zajdzie tu więc dziedziczenie.
- Base - klasa bazowa, która będzie zawierać metody wspólne dla wszystkich obiektów, takie jak chociażby położenie na ekranie.
- Stats - klasa magazynująca statystyki gracza, takie jak punkty życia, punkty doświadczenia, zebrane monety czy części statku. Zajdzie w niej pełna enkapsulacja danych
- Player - klasa rysująca sprite gracza.
- Enemy - klasa odpowiedzialna za charakterystyki przeciwników. M.in. tutaj zajdzie enkapsulacja, aby chronić zmienne przed dostępem z zewnątrz.
- Sounds - W tej klasie zawierać się będą metody związane z odtwarzaniem plików dźwiękowych.
- Ship - Klasa ta będzie przechowywać statystyki konkretnych statków oraz ich ataki specjalne


Sposób komunikacji z użytkownikiem:
Komunikacja z użytkownikiem odbywać się będzie za pomocą graficznego interfejsu SMFL.
Do sterowania gracz używać będzie klawiatury.
Dodatkowo program zapisywać będzie aktualny stan gry w pliku tekstowym.
