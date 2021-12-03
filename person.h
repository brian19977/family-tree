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
    inline string first_name() const { return firstname; }
    inline string last_name() const { return lastname; }

    inline int id_() const { return id; }

    void modify_gender(string gen);
    inline string gender_() const { return gender; }

    void modify_parents(Person *f, Person *m);

    void modify_dates(int byear, int bmonth, int bday, int dyear, int dmonth, int dday);
    inline int birth_year() const { return birthyear; }
    inline int birth_month() const { return birthmonth; }
    inline int birth_day() const { return birthday; }
    inline int death_year() const { return deathyear; }
    inline int death_month() const { return deathmonth; }
    inline int death_day() const { return deathday; }

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
    set<Person *> children;
    Person *father;
    Person *mother;
    set<Person *> siblings;
};
