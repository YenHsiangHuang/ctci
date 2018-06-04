// Use built-in linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

class Animal
{
public:
    int timeStamp;
    virtual ~Animal() {};  // Make Animal polymorphic for dynamic_cast
    virtual void who() {
        printf("Animal\n");
    };
};

class Dog : public Animal
{
    virtual void who() {
        printf("Dog\n");
    };
};

class Cat : public Animal
{
    virtual void who() {
        printf("Cat\n");
    };
};

class AnimalQueue
{
public:
    void enQueue(Cat& newCat);
    void enQueue(Dog& newDog);
    Cat deQueue(Cat cat);
    Dog deQueue(Dog dog);
    Animal* deQueueAny();
    Cat deQueueCat();
    Dog deQueueDog();

private:
    int order = 0;
    vector<Cat> cats;
    vector<Dog> dogs;
};
void AnimalQueue::enQueue(Cat& newCat) {
    newCat.timeStamp = order++;
    cats.push_back(newCat);
}
void AnimalQueue::enQueue(Dog& newDog) {
    newDog.timeStamp = order++;
    dogs.push_back(newDog);
}

Cat AnimalQueue::deQueue(Cat cat) {
    for (auto c = cats.begin(); c != cats.end(); c++) {
        if ((*c).timeStamp == cat.timeStamp) {
            cats.erase(c);
            return *c;
        }
    }
    Cat nullCat;
    return nullCat;
}
Dog AnimalQueue::deQueue(Dog dog) {
    for (auto d = dogs.begin(); d != dogs.end(); d++) {
        if ((*d).timeStamp == dog.timeStamp) {
            dogs.erase(d);
            return *d;
        }
    }
    Dog nullDog;
    return nullDog;
}

Animal* AnimalQueue::deQueueAny() {
    if (cats.empty() && !dogs.empty()) {
        Dog* tmp = new Dog;
        *tmp = deQueueDog();
        Animal* res = tmp;
        delete tmp;
        return res;
    }
    if (dogs.empty() && !cats.empty()) {
        Cat* tmp = new Cat;
        *tmp = deQueueCat();
        Animal* res = tmp;
        delete tmp;
        return res;
    }

    if (dogs[0].timeStamp < cats[0].timeStamp) {
        Dog* tmp = new Dog;
        *tmp = deQueueDog();
        Animal* res = tmp;
        delete tmp;
        return res;
    } else {
        Cat* tmp = new Cat;
        *tmp = deQueueCat();
        Animal* res = tmp;
        delete tmp;
        return res;
    }
}

Cat AnimalQueue::deQueueCat() {
    Cat c;
    if (!cats.empty()) {
        c = cats[0];
        cats.erase(cats.begin());
    }
    return c;
}

Dog AnimalQueue::deQueueDog() {
    Dog d;
    if (!dogs.empty()) {
        d = dogs[0];
        dogs.erase(dogs.begin());
    }
    return d;
}

template <typename CheckType, typename InstanceType>
bool isInstanceOf(InstanceType &Instance) {
    return (dynamic_cast<CheckType *>(&Instance) != NULL);
}

int main()
{
    srand(time(nullptr));
    AnimalQueue aq;
    for (int i = 0; i < 20; i++) {
        if (rand()%2 == 0) {
            Cat cat;
            aq.enQueue(cat);
            printf("Cat ");
        } else {
            Dog dog;
            aq.enQueue(dog);
            printf("Dog ");
        }
    }
    printf("\n");

    for (int i = 0; i < 20; i++) {
        auto oldest = aq.deQueueAny();
        if (isInstanceOf<Cat, Animal>(*oldest)) printf("Cat ");;
        if (isInstanceOf<Dog, Animal>(*oldest)) printf("Dog ");;
    }
    printf("\n");




}
