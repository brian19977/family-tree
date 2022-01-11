#include "person.h"

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

Person::Person(string firstname_ = "", string lastname_ = "", string gender_ = "", 
    int birthyear_ = 0, int birthmonth_ = 0, int birthday_ = 0, 
    int deathyear_ = 0, int deathmonth_ = 0, int deathday_ = 0, 
    Person *father_ = nullptr, Person *mother_ = nullptr, int id_ = 0)
{
    firstname = firstname_;
    lastname = lastname_;
    gender = gender_;

    birthyear = birthyear_;
    birthmonth = birthmonth_;
    birthday = birthday_;
    deathyear = deathyear_;
    deathmonth = deathmonth_;
    deathday = deathday_;

    father = father_;
    mother = mother_;

    id = id_
}

void Person::modify_name(string firstname_, string lastname_)
{
    if(firstname_.length())
        firstname = firstname_;
    if(lastname_.length())
        lastname = lastname_;
}

void Person::modify_id(int id_)
{
    if(id_)
        id = id_;
}

void Person::modify_gender(string gender_)
{
    if(gender_.length())
        gender = gender_;
}

void Person::modify_parents(Person *father_, Person *mother_)
{
    if(father_)
        father = father_;
    if(mother_)
        mother = mother_;
}

void Person::remove_parents(bool f, bool m)
{
    if(f)
        father = nullptr;
    if(m)
        mother = nullptr;
}

void modify_dates(int birthyear_, int birthmonth_, int birthday_,
    int deathyear_, int deathmonth_, int deathday_)
{
    birthyear = birthyear_;
    birthmonth = birthmonth_;
    birthday = birthday_;
    deathyear = deathyear_;
    deathmonth = deathmonth_;
    deathday = deathday_;
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
