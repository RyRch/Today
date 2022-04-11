#include "../icl/proto.h"
#include <stdlib.h>

p_s *create_node(char *task, int index, int status)
{
    p_s *node = malloc(sizeof(p_s));

    node->task = ft_strdup(task);
    node->index = index;
    node->status = status;
    node->next = NULL;
    return node;
}

p_s *str_to_list(char **arr)
{
    p_s *list = malloc(sizeof(p_s));
    p_s *tmp = NULL;
    int index = 0;
    int status = 0;

    status = atoi(&arr[0][0]);
    index = atoi(&arr[0][2]);
    tmp = create_node(arr[1], index, status);
    list = tmp;
    for (int i = 2; arr[i] != NULL; i++) {
        if (i % 2 == 0) {
            status = atoi(&arr[i][0]);
            index = atoi(&arr[i][2]);
            tmp = create_node(arr[i + 1], index, status);
            tmp->next = list;
            list = tmp;
        } 
    }
    return list;
}

char *list_to_str(p_s *list)
{
    p_s *tmp = list;
    char *str = malloc(sizeof(char) * 10000);
    char t[BUFSIZ] = {0};

    str[0] = 0;
    while (tmp != NULL) {
        ft_itoa(tmp->status, t);
        ft_strcat(str, t);
        ft_strcat(str, ".");
        ft_itoa(tmp->index, t);
        ft_strcat(str, t);
        ft_strcat(str, ":");
        ft_strcat(str, tmp->task);
        ft_strcat(str, "\n"); 
        tmp = tmp->next;
    }
    return str;
}

void sort_index(p_s *head)
{
    p_s *tmp = head;

    for (int i = 0; tmp != NULL; i++) {
        tmp->index = i;
        tmp = tmp->next;
    }
}

void print_list(p_s *head)
{
    p_s *tmp = head;

    while (tmp != NULL) {
        printf("node[index] = %d\n", tmp->index);
        printf("node[status] = %d\n", tmp->status);
        printf("node[task] = %s\n\n", tmp->task);
        tmp = tmp->next;
    }
}
