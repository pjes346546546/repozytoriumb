#ifndef SEARCH_HPP
#define SEARCH_HPP

int * generate_table(int table_size);

void printTable(int table_size, int * table);

int * bubble_sort(int table_size, int * table);

int * cocktail_sort(int table_size, int * table);

void linear_search(int table_size, int * table, int searched);

void linear_search_with_sentry(int table_size, int * table, int searched);

int binary_search(int table_size, int * table, int searched);

int * insert_sort(int table_size, int * table);

void quick_sort(int* table, int leftIndex, int rightIndex);

void jump_search(int table_size, int* table, int searched);

void interpolation_search(int table_size, int* table, int searched);


#endif /* SEARCH_HPP */
