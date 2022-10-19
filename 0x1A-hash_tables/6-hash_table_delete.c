#include "hash_tables.h"

/**
 * hash_table_delete - Delete the hash table.
 * @ht: Hash table.
 *
 * Return: Void.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *hn_current;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			hn_current = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = hn_current;
		}
	}
	free(ht->array);
	free(ht);
}
