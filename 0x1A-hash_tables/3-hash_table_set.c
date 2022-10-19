#include "hash_tables.h"
/**
 * hash_table_set - Function to add an element to a hash table.
 * @ht: The hash table to be used.
 * @key:  Element key. (!= NULL)
 * @value: The value to be added. (= NULL accepted)
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hn, *hn_current;
	unsigned long int index = key_index((const unsigned char *)key, ht->size);

	if (ht == NULL || key == NULL)
		return (0);
	hn = malloc(sizeof(hash_node_t));
	if (hn == NULL)
		return (0);
	hn->key = strdup(key);
	hn->value = strdup(value);
	hn->next = NULL;
	if (ht->array[index] == NULL)
		ht->array[index] = hn;
	else
	{
		hn_current = ht->array[index];
		if (strcmp(hn_current->key, key) == 0)
		{
			hn->next = hn_current->next;
			ht->array[index] = hn;
			free(hn_current->key);
			free(hn_current->value);
			free(hn_current);
			return (1);
		} while (hn_current->next != NULL && strcmp(hn_current->next->key, key) != 0)
			hn_current = hn_current->next;
		if (strcmp(hn_current->key, key) == 0)
		{
			hn->next = hn_current->next->next;
			free(hn_current->next->key);
			free(hn_current->next->value);
			free(hn_current->next);
			hn_current->next = hn;
		} else
		{
			hn->next = ht->array[index];
			ht->array[index] = hn;
		}
	} return (1);
}
