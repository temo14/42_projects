typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list temp;
	while(*begin_list)
	{
		if(cmp(begin_list->data, data_ref))
		{
			temp = *begin_list;
			begin_list = *begin_list.next;
			free(temp->data);
			free(temp);
		}
		*begin_list = *begin_list->next;
	}
}
