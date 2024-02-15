#include "search.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int * generate_table(int table_size) {
    int *tablica = new int[table_size];
    srand(time(NULL));
    for(int i = 0; i < table_size; i++) {
        int losowa = rand() % 100;
        tablica[i] = losowa;
    }
    return tablica;
}

void printTable(int table_size, int * table) {
    for (int i = 0; i < table_size; ++i) {
        cout << table[i] << " ";
    }
    cout << endl;
}

int * bubble_sort(int table_size, int * table) {
    for(int j = 0; j < table_size; j++) {
        for(int i = 0; i < table_size - 1; i++) {
            if (table[i] > table[i+1]) {
                int temp = table[i];
                table[i] = table[i+1];
                table[i+1] = temp;  
            }
        }
    }
    return table;
}

int * cocktail_sort(int table_size, int * table) {
    int bottom = 0;
    int top = table_size - 1;
    bool change = true;
    while(change == true) {
        change = false;
        for(int i = bottom; i < top; i++) {
            if(table[i] > table[i+1]) {
                int temp = table[i];
                table[i] = table[i+1];
                table[i+1] = temp;
                change = true;
            }
        }
        top = top - 1;
        for(int i = top; i > bottom; i--) {
            if(table[i] < table[i-1]) {
                int temp = table[i];
                table[i] = table[i-1];
                table[i-1] = temp;
                change = true;
            }
        }
        bottom = bottom + 1;
    }
    return table;
}

int * insert_sort(int table_size, int * table) {
    for(int i = 1; i < table_size; i++) {
        int inserted_element = table[i];
        int j = i - 1;
        while(j >= 0 && table[j] > inserted_element) {
            table[j + 1] = table[j];
            j = j - 1;
        }
        table[j + 1] = inserted_element;
    }
    return table;
}

void linear_search(int table_size, int * table, int searched) {
    for(int i = 0; i < table_size; i++) {
        if(searched == table[i]) {
            cout << "Liczba " << searched << " znajduje się pod indeksem " << i << endl;
            return;
        }
    }
    cout << "Nie znaleziono podanej liczby\n";
}

void linear_search_with_sentry(int table_size, int * table, int searched) {
    int* array = new int[table_size + 1];
    for(int i = 0; i < table_size; i++) {
        array[i] = table[i];
    }
    array[table_size] = -1;
    int i = 0;
    while(array[i] != -1) {
        if(searched == array[i]) {
            cout << "Liczba " << searched << " znajduje się pod indeksem " << i << endl;
            delete[] array;
            return;
        }
        i++;
    }
    cout << "Nie znaleziono podanej liczby\n";
    delete[] array;
}

int binary_search(int table_size, int * table, int searched) {
    int left = 0;
    int right = table_size - 1;
    int index;
    while(left <= right) {
        index = floor((left + right) / 2);
        if (table[index] < searched) {
            left = index + 1;
        } else if(table[index] > searched) {
            right = index - 1;
        } else {
            return index;
        }
    }
    return -1;
}

void quick_sort(int* table, int leftIndex, int rightIndex) {
    int i = leftIndex;
    int j = rightIndex;
    int pivot = table[leftIndex];
    while (i <= j) {
        while (table[i] < pivot) {
            i++;
        }
        while (table[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = table[i];
            table[i] = table[j];
            table[j] = temp;
            i++;
            j--;
        }
    }
    if (leftIndex < j) {
        quick_sort(table, leftIndex, j);
    }
    if (i < rightIndex) {
        quick_sort(table, i, rightIndex);
    }
}

void jump_search(int table_size, int* table, int searched) {
    int block = (int)(sqrt(table_size));
    int index = 0;
    while (table[min(block, table_size) - 1] < searched) {
        index = block;
        block += (int)(sqrt(table_size));
        if (index >= table_size) {
            cout << "Nie znaleziono podanej liczby\n";
            return;
        }
    }
    while (table[index] < searched) {
        index++;
        if (index == min(block, table_size)) {
            cout << "Nie znaleziono podanej liczby\n";
            return;
        }
    }
    if (table[index] == searched) {
        cout << "Znaleziono liczbę pod indeksem: " << index << endl;
    } else {
        cout << "Nie znaleziono podanej liczby\n";
    }
}
void interpolation_search(int table_size, int* table, int searched) {
    int left = 0;
    int right = table_size - 1;

    while (left <= right && searched >= table[left] && searched <= table[right]) {
        // Wzór interpolacyjny
        int pos = left + ((double)(right - left) / (table[right] - table[left])) * (searched - table[left]);

        if (table[pos] == searched) {
            cout << "Znaleziono liczbę pod indeksem: " << pos << endl;
            return;
        } 
        else if (table[pos] < searched) {
            left = pos + 1;
        } 
        else {
            right = pos - 1;
        }
    }
    cout << "Nie znaleziono podanej liczby\n";
}