#include <stdio.h>
#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *curr = *begin_list;
	t_list *prev = NULL;
	t_list *tmp;
	
	while (curr)
	{
		if(cmp(curr->data, data_ref) == 0)
		{
			tmp = curr;
			if(prev == NULL)
				*begin_list = curr->next;
			else
				prev->next = curr->next;
			curr = curr->next;
			free(tmp);	
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

t_list *create_node(void *data)
{
	t_list *result = (t_list *)malloc(sizeof(t_list));
	result->data = data;
	result->next = NULL;
	return result;
}

void print_nodes(t_list *node)
{
	while(node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
}

int func(void *ptr1, void *ptr2)
{
	char *c = (char *)ptr1;
	char *c2 = (char *)ptr2;
	if(*c == *c2)
		return 0;

	return 1;
}

int main()
{
	t_list *first = create_node("Temo");
	t_list *second = create_node("Gaga");
	t_list *third = create_node("Temo1");

	first->next = second;
	second->next = third;

	print_nodes(first);
	ft_list_remove_if(&first, "Temo1", func);
	print_nodes(first);

	return (0);
}
