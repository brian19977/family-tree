#include "tree.h"
#include <iostream>

ostream& operator<<(ostream& output, Person& dude)
{
    output << dude.firstname << " " << dude.lastname << "\n";
       // << "Date of birth: " << dude.birthyear << "/" 
       // << dude.birthmonth << "/" << dude.birthday << "\n";
    return output;
}

Person::Person(string fname, string lname, string gen, int byear, int bmonth, int bday, int dyear, int dmonth, int dday, Person *f, Person *m, int id)
{
    firstname = fname;
    lastname = lname;
    gender = gen;

    birthyear = byear;
    birthmonth = bmonth;
    birthday = bday;
    deathyear = dyear;
    deathmonth = dmonth;
    deathday = dday;

    father = f;
    mother = m;

    this->id = id;
}

void Person::modify_name(string fname, string lname)
{
    if(fname.length())
        firstname = fname;
    if(lname.length())
        lastname = lname;
}

void Person::modify_gender(string gen)
{
    if(gen.length())
        gender = gen;
}

void Person::modify_parents(Person *f, Person *m)
{
    if(f)
        father = f;
    if(m)
        mother = m;
}

void Person::modify_dates(int byear, int bmonth, int bday, int dyear, int dmonth, int dday)
{
    if(byear)
        birthyear = byear;
    if(bmonth)
        birthmonth = bmonth;
    if(bday)
        birthday = bday;
    if(dyear)
        deathyear = dyear;
    if(dmonth)
        deathmonth = dmonth;
    if(dday)
        deathday = dday;
}

void Person::add_spouse(Person *spouse) 
{ 
    this->spouse = spouse;
    spouse->spouse = this;
}

void Person::modify_spouse(Person *spouse) 
{ 
    this->spouse->spouse = nullptr;
    this->spouse = spouse;
    spouse->spouse = this;
}

void Person::remove_spouse()
{
    this->spouse->spouse = nullptr;
    this->spouse = nullptr;
}

void Person::add_child(Person *child)
{
    children.insert(child);
}

void Person::remove_child(Person *child)
{
    children.erase(child);
}

void Person::add_sibling(Person *sibling)
{
    siblings.insert(sibling);
}

void Person::remove_sibling(Person *sibling)
{
    siblings.erase(sibling);
}


