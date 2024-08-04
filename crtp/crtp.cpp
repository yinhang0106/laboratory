#include <iostream>

struct Animal {
    virtual void speak() = 0;
    virtual ~Animal() = default;
};

struct Cat : Animal {
    void speak() override {
        std::cout << "Miao!" << std::endl;
    }
};


struct Dog : Animal {
    void speak() override {
        std::cout << "Wang!" << std::endl;
    }
};

void say(Animal* _this) {
    _this->speak();
}

//template <class T>
//struct Animal {
//    void speak() {
//        static_cast<T *>(this)->impl();
//    }
//};
//
////template <class T>
////void speak(Animal<T>* _this) {
////    static_cast<T *>(_this)->impl();
////}
//
//struct Cat : Animal<Cat> {
//    void impl() {
//        std::cout << "Miao!" << std::endl;
//    }
//};
//
////struct CatImpl {
////
////    void speak() {
////        static_cast<CatImpl *>(this)->impl();
////    }
////
////    void impl() {
////        std::cout << "Miao!" << std::endl;
////    }
////};
//
//struct Dog : Animal<Dog> {
//    void impl() {
//        std::cout << "Wang!" << std::endl;
//    }
//};
//
////void say(auto animal) {
////    animal->speak();
////}
//
//template <class T>
//concept Speakable = requires(T* t) {
//    t->speak();
//};
//
//template <class T>
////requires requires(T* t) {
////    t->speak();
////}
//requires Speakable<T>
//void say(T* _this) {
//    _this->speak();
//}

int main() {
    Animal* cat = new Cat{};
    Animal* dog = new Dog();

    cat->speak();
    dog->speak();
//
//    delete cat;
//    delete dog;

//    auto a = new int{32};
//    say(a);

//    auto cat = new Animal<Cat>{};
//    cat->speak();
//
//    auto dog = new Animal<Dog>{};
//    dog->speak();
//
//    say(cat);
//    say(dog);

    bool ok;
    std::cin >> ok;
    say(ok ? cat : dog); // 错误：不兼容的类型之间不能三目

    delete cat;
    delete dog;

}