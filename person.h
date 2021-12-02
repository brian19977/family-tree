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
    Person(string fname, string lname, string gen, int byear, int bmonth, int bday, int dyear, int dmonth, int dday, Person *f, Person *m, int id);

    void modify_name(string fname, string lname);

    void modify_gender(string gen);

    void modify_parents(Person *f, Person *m);

    void modify_dates(int byear, int bmonth, int bday, int dyear, int dmonth, int dday);

    void add_spouse(Person *spouse);
    void modify_spouse(Person *spouse);
    void remove_spouse();

    void add_child(Person *child);
    void remove_child(Person *child);

    void add_sibling(Person *sibling);
    void remove_sibling(Person *sibling);

    friend ostream& operator<<(ostream& output, const Person& dude);

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
    set<Person *> children;
    Person *father;
    Person *mother;
    set<Person *> siblings;
};
