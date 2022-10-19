#include "hash_tables.h"
/**
 * key_index - Function to generate index value of a key
 * @key: key to be used in indexing
 * @size: Is the size of the hash table array.
 * Return: Returns the index value generated
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hashvalue;

	hashvalue = hash_djb2(key);
	hashvalue %= size;
	return (hashvalue);
}
