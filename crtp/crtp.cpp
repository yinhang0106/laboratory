#include <iostream>

//struct Animal {
//    virtual void speak() = 0;
//    virtual ~Animal() = default;
//};
//
//struct Cat : Animal {
//    void speak() override {
//        std::cout << "Miao!" << std::endl;
//    }
//};
//
//
//struct Dog : Animal {
//    void speak() override {
//        std::cout << "Wang!" << std::endl;
//    }
//};

template <class T>
struct Animal {
    T* val;

    Animal() : val(new T{}) {}

    void speak() {
        val->speak();
    }

    ~Animal() { delete val; }
};

struct Cat : Animal<Cat> {
    void speak() {
        std::cout << "Miao!" << std::endl;
    }
};

struct Dog : Animal<Dog> {
    void speak() {
        std::cout << "Wang!" << std::endl;
    }
};


int main() {
//    Animal* cat = new Cat{};
//    Animal* dog = new Dog();
//
//    cat->speak();
//    dog->speak();
//
//    delete cat;
//    delete dog;

    auto cat = std::make_unique<Animal<Cat>>();
    cat->speak();

}