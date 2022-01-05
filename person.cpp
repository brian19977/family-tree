#include "person.h"
#include <iostream>

std::ostream& operator<<(std::ostream& output, const Person& dude)
{
    output << dude.first_name() << " " << dude.last_name()
        << "\nDate of birth: " << dude.birth_year() << "/" 
        << dude.birth_month() << "/" << dude.birth_day();
    if(dude.death_year() != 0)
    {
        output << "\nDate of death: " << dude.death_year() << "/"
            << dude.death_month() << "/" << dude.death_day();
    }
    return output;
}

Person::Person(string fname = "", string lname = "", string gen = "", 
    int byear = 0, int bmonth = 0, int bday = 0, 
    int dyear = 0, int dmonth = 0, int dday = 0, 
    Person *f = nullptr, Person *m = nullptr, int id = 0)
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

void Person::modify_id(int id)
{
    if(id)
        this->id = id;
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

void Person::remove_parents(bool f, bool m)
{
    if(f)
        father = nullptr;
    if(m)
        mother = nullptr;
}

void Person::modify_dates(int byear, int bmonth, int bday, int dyear, int dmonth, int dday)
{
    birthyear = byear;
    birthmonth = bmonth;
    birthday = bday;
    deathyear = dyear;
    deathmonth = dmonth;
    deathday = dday;
}

void Person::add_spouse(Person *spouse) 
{ 
    this->spouse = spouse;
    if(spouse)
	    spouse->spouse = this;
}

void Person::modify_spouse(Person *spouse) 
{
    if(this->spouse)
    {
    	this->spouse->spouse = nullptr;
        this->spouse = spouse;
        spouse->spouse = this;
    }
}

void Person::remove_spouse()
{
    if(this->spouse)
    	this->spouse->spouse = nullptr;
    this->spouse = nullptr;
}

void Person::add_child(Person *child)
{
    children.insert(pair<int, Person *>(child->id_(),child));
    if(this->gender == "Male")
	    child->father = this;
    else
	    child->mother = this;
}

void Person::remove_child(int id)
{
    Person child = children[id];
    children.erase(id);
    if(child->gender == "Male")
	    child->father = nullptr;
    else
	    child->mother = nullptr;
}

void Person::add_sibling(Person *sibling)
{
    siblings.insert(sibling);
    sibling->siblings.insert(this);
}

void Person::remove_sibling(Person *sibling)
{
    siblings.erase(sibling);
    sibling->siblings.erase(this);
}
