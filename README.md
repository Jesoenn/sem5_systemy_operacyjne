# Quicksort wielowątkowy
Umożliwia generowanie danych tablic oraz oraz testowanie algorytmu dla różnych konfiguracji.  

---

## Uruchamianie Windows
Program wymaga podania 7 argumentów.
```
so_projekt1.exe <dataType> <size> <sorting> <outputFile> <numbersFile> <pivot> <threads>
```
### Argumenty
- **`<dataType>`** – typ danych:
  - `0` – int
  - `1` – float
  - `2` – double
  - `3` – char

- **`<size>`** – liczba elementów do wygenerowania

- **`<sorting>`** – ułożenie elementów w tablicy przed rozpoczęciem sortowania.
  - `0` – losowe
  - `1` – niemalejące
  - `2` – nierosnące
  - `3` – niemalejące w 33%
  - `4` – niemalejące w 66%

- **`<outputFile>`** – plik, do którego zostaną zapisane wyniki algorytmu.

- **`<numbersFile>`** – plik z otrzymaną, posortowaną tablicą (`-` - brak pliku)

- **`<pivot>`** – wybór pivota:
  - `0` – lewy
  - `1` – prawy
  - `2` – środkowy
  - `3` – losowy

- **`<threads>`** – liczba wątków (minimum 1)
### Przykładowe uruchomienie
```
so_projekt1.exe 0 10000 0 wynik.txt - 2 1
```
Tablica o 10 000 elementach typu int, rozmieszczonych losowo, z wynikiem zapisanym do pliku `wynik.txt`, środkowego pivota oraz 1 wątku.
 
