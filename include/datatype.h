//
// Created by roy on 18-11-5.
//

#ifndef CPPBLOG_DATATYPE_H
#define CPPBLOG_DATATYPE_H

#include <iostream>
#include <unordered_map>

#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>

struct article {
    article(){
        id = -1;
    };

    int id;
    std::string title;
    std::string keyword;
    std::string dummy_body;
    std::string real_body;
};


template <typename T, int count=1>
std::shared_ptr<T> shared_malloc() {
    std::shared_ptr<T> ptr(static_cast<T*>(malloc(sizeof(T) * count)), free);
    return ptr;
}


template <typename keyType, typename valueType>
class Cache {
public:
    valueType Read(keyType key);
    void Write(keyType key, valueType value);
    void Delete(keyType key);

    Cache() = default;
    Cache(const Cache&) = delete;
    Cache& operator = (const Cache&) = delete;

private:
    std::unordered_map<keyType, valueType> _mapCache;
    typedef boost::shared_lock<boost::shared_mutex> read_lock;
    typedef boost::unique_lock<boost::shared_mutex> write_lock;
    typedef boost::shared_mutex read_write_mutex;
    read_write_mutex _locker;
};

template <typename keyType, typename valueType>
valueType Cache<keyType, valueType>::Read(keyType key) {
    valueType value;
    read_lock rlock(_locker);
    typename std::unordered_map<keyType, valueType>::const_iterator result = _mapCache.find(key);
    if(result != _mapCache.end()) {
        value = result->second;
    }
    return value;
}

template <typename keyType, typename valueType>
void Cache<keyType, valueType>::Write(keyType key, valueType value) {
    write_lock rlock(_locker);
    if (_mapCache.find(key) != _mapCache.end()) {
        _mapCache.erase(key);
    }
    _mapCache.insert(std::make_pair(key, value));
}

template <typename keyType, typename valueType>
void Cache<keyType, valueType>::Delete(keyType key) {
    write_lock rlock(_locker);
    _mapCache.erase(key);
}

#endif //CPPBLOG_DATATYPE_H
