
#ifndef BAZADATEJOC_H
#define BAZADATEJOC_H
#include <memory>
#include <vector>

template <typename T>
class BazaDateJoc {
private:
    std::vector<std::shared_ptr<T>> items;
    BazaDateJoc() = default;
    explicit BazaDateJoc(const std::vector<std::shared_ptr<T>>& items) : items(items) {}
    static std::shared_ptr<BazaDateJoc<T>> instance;
public:
    static std::shared_ptr<BazaDateJoc<T>> getInstance() {
        if (instance == nullptr) {
            instance = std::shared_ptr<BazaDateJoc<T>>(new BazaDateJoc<T>());
        }
        return instance;
    }



    static std::shared_ptr<BazaDateJoc<T>> createInstance(const std::vector<std::shared_ptr<T>>& initialItems) {
        instance = std::shared_ptr<BazaDateJoc<T>>(new BazaDateJoc<T>(initialItems));
        return instance;
    }

    void adaugaItem(const std::shared_ptr<T>& item) {
        items.push_back(item);
    }

    const std::vector<std::shared_ptr<T>>& getItems() const {
        return items;
    }
};

template <typename T>
std::shared_ptr<BazaDateJoc<T>> BazaDateJoc<T>::instance = nullptr;

template <typename T>
class BuilderBazaDateJoc {
private:
    std::vector<std::shared_ptr<T>> items;
public:
    BuilderBazaDateJoc& adaugaItem(const std::shared_ptr<T>& item) {
        items.push_back(item);
        return *this;
    }

    std::shared_ptr<BazaDateJoc<T>> build() {
        return BazaDateJoc<T>::createInstance(items);
    }
};

#endif