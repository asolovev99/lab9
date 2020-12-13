#include"list.h"
#include<stdlib.h>
//#include<stdio.h>

struct List
{
	void* data;
	List* next_element;
};

struct ListIterator 
{
	List* current_list_element;
};

void add(List* list, void* data)
{
	List* new_element = NULL;
	new_element = (List*)malloc(sizeof(List));
	new_element->data = data;
	new_element->next_element = list->next_element;

	if (list == NULL)
	{
		list = new_element;
	}
	else
	{
		list->next_element = new_element;
	}
}
void add_to_end(List* list, void* data)
{
	List* new_element = NULL;
	new_element = (List*)malloc(sizeof(List));
	new_element->data = data;
	new_element->next_element = NULL;

	if (list == NULL)
	{
		list = new_element;
	}
	else
	{
		while (list->next_element != NULL)
		{
			list = list->next_element;
		}

		list->next_element = new_element;
	}
}
void* get(List* list, int index) // 0 - ��������� ������
{
	if (list == NULL)
	{
		return NULL;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			list = list->next_element;
		}

		return list->data;
	}
}
void remove(List* list, int index)
{
	List* removal_element = NULL;

	if (list != NULL)
	{
		if (index == 0)
		{
			free(list);
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
			{
				list = list->next_element;
			}

			removal_element = list->next_element;
			list->next_element = list->next_element->next_element;
			free(removal_element);
		}
	}
}
int get_length(List* list)
{
	int index = 0;
	if (list == NULL)
	{
		return 0;
	}
	else
	{
		for (index = 0; list->next_element != NULL; index++)
		{
			list = list->next_element;
		}

		return index + 1;
	}
}
ListIterator* get_iterator(List* list)
{
	ListIterator* result = malloc(sizeof(ListIterator));

	result->current_list_element = list;

	return result;
}

void* get_value(ListIterator* iterator)
{
	if (iterator == NULL)
	{
		return NULL;
	}
	else if (iterator->current_list_element == NULL)
	{
		return NULL;
	}
	else
	{
		return iterator->current_list_element->data;
	}
}
int has_next(ListIterator* iterator)
{
	if (iterator == NULL)
	{
		return 0;
	}
	else if (iterator->current_list_element == NULL)
	{
		return 0;
	}
	else
	{
		if (iterator->current_list_element->next_element == NULL)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
void move_next(ListIterator* iterator)
{
	if (iterator != NULL)
	{
		if (iterator->current_list_element != NULL)
		{
			if (iterator->current_list_element->next_element != NULL)
			{
				iterator->current_list_element = iterator->current_list_element->next_element;
			}
		}
	}
}