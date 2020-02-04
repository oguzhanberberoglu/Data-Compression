/*
OGUZHAN BERBEROGLU 24001
CS300 HW2
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include <string>
using namespace std;

template< class K, class V>
struct HashNode
{
	K key;
	V value;
	int index; // private vector index of Dictionary
	HashNode()
	{
		index = -1;
	}
};

template< class K, class V>
class Dictionary
{
public:
	Dictionary(); // constructor; initiliaze the first 256 ASCII characters and add them to vector
	~Dictionary();
	void add(K key, V val); // add (key,val) if key doesn’t exist. Otherwise dic[key] = val
	V get(K key); // returns val = dic[key]
	bool isKeyExist(K key); // returns true if key is already present
	int hash(K key); // compute hash and return int index for vector<V>

private:
	HashNode<K,V>dic[4096];
	int size;
};

template< class K, class V>
Dictionary<K,V>::Dictionary() // initiliazed 256 ASCII characters and added
{
	size = 4096;
	for (int i = 0; i < 256; i++){
		char ch = i;
		string s(1, ch);
		add(s, i);
	}
}
template< class K, class V>
void Dictionary<K, V>::add(K key, V val) // add (key,val) if key doesn’t exist. Otherwise dic[key] = val
{
	HashNode<K, V> temp;
	int in = hash(key); // hashed value = in
	temp.key = key;
	temp.value = val;
	while (in < size && dic[in].index != -1 && dic[in].key != key) // index uptaded
		in++;
	temp.index = in;
	dic[in] = temp; // assigned
}
template< class K, class V>
int Dictionary<K,V>::hash (K key) // hash
{
	int ind = 0;
	for (int i = 0; i < key.length(); i++) // hash with length
		ind += key[i];
	if (ind < 0)
		ind = ind + size;	
	ind %= size;
	return ind;
}


template< class K, class V>
V Dictionary<K,V>::get(K key) // returns val = dic[key]
{
	int i= hash(key);
	while (i < (size - 1) && dic[i].key != key)
		i++;
	V val = dic[i].value;
	return val;
}

template< class K, class V>
bool Dictionary<K,V>::isKeyExist(K key) // returns true if key is already present
{
	for (int i = 0; i < size; i++){
		if (dic[i].key == key)
			return true;
	}
	return false;
}
template< class K, class V>
Dictionary<K, V>::~Dictionary()
{}
#endif // !HASHTABLE_H
