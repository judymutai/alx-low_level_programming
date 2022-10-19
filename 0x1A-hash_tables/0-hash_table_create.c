#include "hash_tables.h"

/**
 * hash_table_create - Hash function to create a new hash table
 * @size: Array size in hash table
 * Return: Hash table value pointer
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL || size == 0)
		return (NULL);
	ht->array = malloc(sizeof(void *) * size);
	if (ht->array == NULL)
		return (NULL);
	ht->size = size;
	return (ht);
}
