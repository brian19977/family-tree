#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Person {
public:
    Person() = default;

    Person(string firstname_, string lastname_, string gender_, 
        int birthyear_, int birthmonth_, int birthday_, 
        int deathyear_, int deathmonth_, int deathday_, 
        Person *father_, Person *mother_, int id_);    

    void modify_name(string firstname_, string lastname_);
    inline string firstname_() const { return firstname; }
    inline string lastname_() const { return lastname; }

    void modify_id(int id_);
    inline int id_() const { return id; }

    void modify_gender(string gen);
    inline string gender_() const { return gender; }

    void modify_parents(Person *f, Person *m);
    void Person::remove_parents(bool f, bool m);

    void modify_dates(int birthyear_, int birthmonth_, int birthday_, 
        int deathyear_, int deathmonth_, int deathday_);
 
    inline int birthyear_() const { return birthyear; }
    inline int birthmonth_() const { return birthmonth; }
    inline int birthday_() const { return birthday; }
    inline int deathyear_() const { return deathyear; }
    inline int deathmonth_() const { return deathmonth; }
    inline int deathday_() const { return deathday; }

    void add_spouse(Person *spouse);
    void modify_spouse(Person *spouse);
    void remove_spouse();

    void add_child(Person *child);
    void remove_child(Person *child);

    void add_sibling(Person *sibling);
    void remove_sibling(Person *sibling);

    friend ostream& operator<<(ostream& output, const Person& dude);

private:
    string firstname;
    string lastname;
    int birthyear;
    int birthmonth;
    int birthday;
    int deathyear;
    int deathmonth;
    int deathday;
    string gender;

    int id;

    Person *spouse;
    map<int, Person *> children;
    Person *father;
    Person *mother;
    map<int, Person *> siblings;
};
