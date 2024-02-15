#include <iostream>
#include "search.hpp"

using namespace std;

int main() {
    cout << "Podaj wielkość tablicy: ";
    int table_size;
    cin >> table_size;

    int *generated = generate_table(table_size);
    cout << "Wygenerowana tablica:\n";
    printTable(table_size, generated);

    cout << "Napisz 1 aby wybrać sortowanie napisz 2 aby wybrać  wyszukiwanie\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "Napisz liczbe sortowania które chcesz uzyskać:\n";
  cout << "1 dla przez scalanie\n";
        cout << "2 dla bąbelkowego\n";
  cout << "3 dla przez wstawianie\n";
        cout << "4 dla koktajlowego\n";
        cout << "5 dla szybkiego\n";
        cin >> choice;

  switch (choice) {
    case 1: {
                  break;
            }
    case 2: {
                  bubble_sort(table_size, generated);
                  cout << "Posortowana tablica za pomocą sortowania bąbelkowego:\n";
                  printTable(table_size, generated);
                   break;
            }
    case 3: {
                  insert_sort(table_size, generated);
                  cout << "Posortowana tablica za pomocą sortowania przez wstawianie:\n";
                  printTable(table_size, generated);
                  break;
            }
    case 4: {
                  cocktail_sort(table_size, generated);
                  cout << "Posortowana tablica za pomocą sortowania koktajlowego:\n";
                  printTable(table_size, generated);
                  break;
            }
    case 5: {
                  quick_sort(generated, 0, table_size - 1);
                  cout << "Posortowana tablica za pomocą szybkiego sortowania:\n";
                  printTable(table_size, generated);
                  break;
            }
    default: {
                  cout << "Niepoprawny wybór\n";
                  break;
            }
        }
} else if (choice == 2) {
        cout << "Proszę wybrać cyfrę odpowiadającą wyszukiwaniu:\n";
        cout << "1 dla liniowego\n";
        cout << "2 dla liniowego z wartownikiem\n";
        cout << "3 dla skokowego\n";
        cout << "4 dla binarnego\n";
        cout << "5 dla interpolacyjnego\n";

        cin >> choice;
        cout << "Proszę podać wyszukiwaną liczbę: ";
        int searched;
        cin >> searched;

        switch (choice) {
            case 1: {
                linear_search(table_size, generated, searched);
                break;
            }
            case 2: {
                linear_search_with_sentry(table_size, generated, searched);
                break;
            }
            case 3: {
                jump_search(table_size, generated, searched);
                break;
            }
            case 4: {
                int result = binary_search(table_size, generated, searched);
                if (result != -1) {
                    cout << "Znaleziono liczbę pod indeksem: " << result << endl;
                } else {
                    cout << "Nie znaleziono podanej liczby\n";
                }
                break;
            }
            case 5: {
                
                break;
            }
            default: {
                cout << "Niepoprawny wybór\n";
                break;
            }
        }
    } else {
        cout << "Niepoprawny wybór\n";
    }

    delete[] generated;
    return 0;
}
