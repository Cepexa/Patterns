#pragma once
#include <iostream>

class BaseCache {
public:
    virtual bool has(const std::string& key) = 0;
    virtual std::string read(const std::string& key) = 0;
    virtual void write(const std::string& key, const std::string& value) = 0;
    virtual void _delete(const std::string& key) = 0;
};

class MemoryCache : public BaseCache {
public:
    bool has(const std::string& key) override {
        std::cout << "MemoryCache has " + key << std::endl;
        return true;
    }
    std::string read(const std::string& key) override {
        std::cout << "MemoryCache read " + key << std::endl;
        return key;
    }
    void write(const std::string& key, const std::string& value)override {
        std::cout << "MemoryCache write into " + key +" this " + value << std::endl;
    }
    void _delete(const std::string& key) override {
        std::cout << "MemoryCache delete " + key << std::endl;
    }
    };
class FileCache : public BaseCache {
public:
    bool has(const std::string& key) override {
        std::cout << "FileCache has " + key << std::endl;
        return true;
    }
    std::string read(const std::string& key) override {
        std::cout << "FileCache read " + key << std::endl;
        return key;
    }
    void write(const std::string& key, const std::string& value)override {
        std::cout << "FileCache write into " + key + " this " + value << std::endl;
    }
    void _delete(const std::string& key) override {
        std::cout << "FileCache delete " + key << std::endl;
    }
    };
class NullCache : public BaseCache {
public:
    bool has(const std::string& key) override {
        std::cout << "NullCache has " + key << std::endl;
        return true;
    }
    std::string read(const std::string& key) override {
        std::cout << "NullCache read " + key << std::endl;
        return key;
    }
    void write(const std::string& key, const std::string& value)override {
        std::cout << "NullCache write into " + key + " this " + value << std::endl;
    }
    void _delete(const std::string& key) override {
        std::cout << "NullCache delete " + key << std::endl;
    }
    };
class PoorManMemoryCache : public BaseCache {
public:
    bool has(const std::string& key) override {
        std::cout << "PoorManMemoryCache has " + key << std::endl;
        return true;
    }
    std::string read(const std::string& key) override {
        std::cout << "PoorManMemoryCache read " + key << std::endl;
        return key;
    }
    void write(const std::string& key, const std::string& value)override {
        std::cout << "PoorManMemoryCache write into " + key + " this " + value << std::endl;
    }
    void _delete(const std::string& key) override {
        std::cout << "PoorManMemoryCache delete " + key << std::endl;
    }
    };

// Класс для использования
class CacheApplier {
private:
    BaseCache* strategy;
public:
    void set_strategy(BaseCache* strategy) {
        this->strategy = strategy;
    }

    std::string read_from_cache(const std::string& key) {
        return strategy->read(key);
    }
    void write_from_cache(const std::string& key, const std::string& value) {
        strategy->write(key, value);
    }
    void delete_from_cache(const std::string& key) {
        strategy->_delete(key);
    } // Удалить из cache
};
int strategy() {

    CacheApplier cA;

    //cA.set_strategy(new NullCache);
    cA.set_strategy(new MemoryCache);
    // cA.set_strategy (new FileCache);
    // cA.set_strategy (new PoorManMemoryCache);
    cA.read_from_cache("file");
    cA.write_from_cache("file", "data");
    cA.delete_from_cache("file");
    return 0;
}


