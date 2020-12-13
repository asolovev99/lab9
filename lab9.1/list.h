#pragma once

typedef struct List List;

typedef struct ListIterator ListIterator;

void add(List* list, void* data);
void add_to_end(List* list, void* data);
void* get(List* list, int index);
void remove(List* list, int index);
int get_length(List* list);
ListIterator* get_iterator(List* list);

void* get_value(ListIterator* iterator);
int has_next(ListIterator* iterator);
void move_next(ListIterator* iterator);