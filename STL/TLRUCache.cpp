/*
 * TLRUCache.cpp
 *
 *  Created on: Aug 8, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<map>
#include<list>
#include<utility>

template <typename Key, typename Data>
class LRUCache{
public:
	typedef typename std::list<Key>::reverse_iterator LIST_REV_ITR;
	typedef typename std::list<Key>::iterator LIST_ITR;
	typedef typename std::pair<LIST_ITR, Data> PAIR;
	typedef typename std::map<Key, PAIR>::iterator MAP_ITR;


private:
	std::list<Key> mList;
	std::map<Key, PAIR> mMap;
	PAIR mPair;
	unsigned long long mSize;
	unsigned long long mCapacity;
	bool mDeleteUserData;

public:
	TLRUCacheNew(unsigned long long capacity, bool deleteUserData) :  mCapacity(capacity), mDeleteUserData(deleteUserData){
		mSize = 0;
	}

	/*bool find(Key key, MAP_ITR &itr){
		itr = mMap.find(key);
		if(itr != mMap.end()){
			return true;
		}else{
			std::cout << std::endl << "Entry not found in map while adding" << std::endl;
			return false;
		}
	}*/
	void Print(){
		for(MAP_ITR itr = mMap.begin(); itr != mMap.end(); itr++){
			std::cout << itr->first << " => "<< (itr->second.second->str) << " " ;
		}
		std::cout << std::endl;
	}

	void PrintList(){
		for(LIST_ITR itr = mList.begin(); itr != mList.end(); itr++)
			std::cout << *itr <<  " " ;
	}

	bool Insert(Key key, Data value){
		///Add entry to map and list
		mList.push_back(key);
		LIST_REV_ITR ritr = mList.rbegin();
		LIST_ITR itr = --ritr.base();
		mMap.insert(std::make_pair(key, std::make_pair(itr, value) ));
		/*
		LIST_ITR itr = --(mList.end());
		//std::pair<LIST_ITR, Data> data;
		mMap.insert(std::make_pair(key, std::make_pair(itr, value) ));
		*/
		mSize++;
	}
	bool Find(Key key, Data &value){
		MAP_ITR mapItr = mMap.find(key);
		if(mapItr != mMap.end()){
			value = mapItr->second.second;
			return true;
		}
		return false;
	}

	bool Add(Key key, Data value){
		Data temp = NULL;

		MAP_ITR mapItr = mMap.find(key);
		if(mapItr != mMap.end()){
			std::cout << "Found entry " << std::endl ;
			Remove(key);
			//std::cout << "Removed Found entry " << std::endl ;
			Insert(key, value);
		//	std::cout << "Inserted Found entry " << std::endl ;
			return true;
		}
		if(mSize >= mCapacity){
			//Remove logic remove the oldest entry from list
			LIST_ITR itr =  mList.begin();
			//Remove from map
			mapItr = mMap.find(*itr);
			if(mapItr != mMap.end()){
				Data temp = NULL;
				temp = mapItr->second.second ;
				mMap.erase(mapItr);
				if(temp && mDeleteUserData)
					delete temp;
			}else{
				std::cout << std::endl << "Entry not found in map while adding" << std::endl;
			}
			//Remove from list
			mList.pop_front();
			mSize--;
		}
		//Add entry to map and list
		Insert(key, value);

		return true;
	}

	bool Update(Key &key){
		typename std::map<Key,PAIR>::itetator mapItr = mMap.find(key);
		if(mapItr != mMap.end()){
		}
	}
	bool Remove(Key &key){
		MAP_ITR mapItr = mMap.find(key);
		if(mapItr != mMap.end()){
			Data temp = NULL;
			temp = mapItr->second.second ;
			mMap.erase(mapItr);
			if(temp && mDeleteUserData)
				delete temp;
			//Delete entry from list
			mList.erase(mapItr->second.first);
			mSize--;
		}else{
			std::cout << std::endl << "Entry not found in map while removing" << std::endl;
		}
	}

};

struct Test{
	int x;
	std::string str;
	Test(int x, std::string str) : x(x), str(str){}
};

int main(){
	unsigned long long cap = 100;
	bool b = false;
	LRUCache<int, Test*> _Cahce(cap, b);
	Test *tt = new Test(1,"aa");
	for(int i = 0; i< 10; i++){
		_Cahce.Add(i, tt);
	}

	for(int i = 5; i < 9; i++)
		_Cahce.Remove(i);

	for(int i = 10; i< 20; i++){
		_Cahce.Add(i, tt);
	}


	_Cahce.Print();
	_Cahce.PrintList();

	return 0;
}

