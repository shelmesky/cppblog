//
// Created by roy on 18-11-5.
//

#ifndef CPPBLOG_DATATYPE_H
#define CPPBLOG_DATATYPE_H

#include <iostream>
#include <unordered_map>

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


template <typename keyType, typename valueType>
class Cache {
public:
    valueType Read(keyType key);
    void Write(keyType key, valueType value);

private:
    std::unordered_map<keyType, valueType> _mapCache;
};

template <typename keyType, typename valueType>
valueType Cache<keyType, valueType>::Read(keyType key) {
    valueType value;
    typename std::unordered_map<keyType, valueType>::const_iterator result = _mapCache.find(key);
    if(result != _mapCache.end()) {
        value = result->second;
    }
    return value;
}

template <typename keyType, typename valueType>
void Cache<keyType, valueType>::Write(keyType key, valueType value) {
    if (_mapCache.find(key) != _mapCache.end()) {
        _mapCache.erase(key);
    }
    _mapCache.insert(std::make_pair(key, value));
}

#endif //CPPBLOG_DATATYPE_H
