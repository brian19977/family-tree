#include "person.h"
#include <iostream>

std::ostream& operator<<(std::ostream& output, const Person& dude)
{
    output << dude.first_name() << " " << dude.last_name()
	<< "\nDate of birth: " << dude.birth_year() << "/" 
	<< dude.birth_month() << "/" << dude.birth_day();
    if(dude.death_year())
    {
	output << "\nDate of death: " << dude.death_year() << "/"
	<< dude.death_month() << "/" << dude.death_day();
    }
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
    if(spouse)
	spouse->spouse = this;
}

void Person::modify_spouse(Person *spouse) 
{
    if(this->spouse)
	this->spouse->spouse = nullptr;
    this->spouse = spouse;
    spouse->spouse = this;
}

void Person::remove_spouse()
{
    if(this->spouse)
	this->spouse->spouse = nullptr;
    this->spouse = nullptr;
}

void Person::add_child(Person *child)
{
    children.insert(child);
    if(this->gender == "Male")
	child->father = this;
    else
	child->mother = this;
}

void Person::remove_child(Person *child)
{
    children.erase(child);
    if(this->gender == "Male")
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
