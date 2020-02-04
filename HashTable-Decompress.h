/*
OGUZHAN BERBEROGLU 24001
CS300 HW2
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include <string>
using namespace std;

template<class V, class K>
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

template<class V, class K>
class Dictionary
{
public:
	Dictionary(); // constructor; initiliaze the first 256 ASCII characters and add them to vector
	~Dictionary();
	void add(K key, V value); // add (key,val) if key doesn’t exist. Otherwise dic[key] = val
	K get(V value); // returns val = dic[key]
	bool isValueExist(V val); // returns true if key is already present
	int hash(K key); // compute hash and return int index for vector<V>

private:
	HashNode<V,K>dic[4096];
	int size;
};

template<class V, class K>
Dictionary<V,K>::Dictionary() // initiliazed 256 ASCII characters and added
{
	size = 4096;
	for (int i = 0; i < 256; i++) {
		char ch = i;
		string s(1, ch);
		add(s, i);
	}
}
template<class V, class K>
void Dictionary<V, K>::add(K key, V value) // add (key,val) if key doesn’t exist. Otherwise dic[key] = val
{
	HashNode<V,K> temp;
	int in = hash(key); // hashed value = in
	temp.key = key;
	temp.value = value;
	while (in < size && dic[in].index != -1 && dic[in].key != key) // index uptaded
		in++;
	temp.index = in;
	dic[in] = temp; // assigned
}
template<class V, class K>
int Dictionary<V, K>::hash(K key) // hash
{
	int ind = 0;
	for (int i = 0; i < key.length(); i++) // hash with length
		ind += key[i];
	//int ind = key * 13 + 37;
	if (ind < 0)
		ind = ind + size;
	ind %= size;
	return ind;
}


template<class V, class K>
K Dictionary<V, K>::get(V value) // returns val = dic[key]
{
	for (int i = 0; i < size-1; i++){
		if (dic[i].value == value)
			return dic[i].key;
	} return NULL;
}

template<class V, class K>
bool Dictionary<V, K>::isValueExist(V val) // returns true if key is already present
{
	for (int i = 0; i < size-1; i++) {
		if (dic[i].value == val)
			return true;
	} return false;
}
template<class V, class K>
Dictionary<V, K>::~Dictionary()
{}
#endif // !HASHTABLE_H
