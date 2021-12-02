#include <iostream>
#include <vector>
#include "person.h"
#include <filesystem>
#include <exception>
#include <fstream>
#include <sstream>

int main() 
{
    if(!filesystem::exists("Family_Members"))
        throw runtime_error { "No Family_Members file." };

    ifstream family_members { "Family_Members" };
    if(!family_members)
        throw runtime_error { "Can't open Family_Members." };

    string buf;
    int count = 1;
    vector<Person *> people;

    getline(family_members, buf); // skip first "PERSON"

    while(getline(family_members, buf)) // this one gets the name
    {
        Person *temp = new Person("","","",0,0,0,0,0,0,nullptr,nullptr,count);
        
        temp->modify_name(
            buf.substr(0,buf.find(" ")),
            buf.substr(buf.find(" ")+1,buf.length())
            );
       
	// add gender
        getline(family_members, buf);
        temp->modify_gender(buf);

	// add dates
        getline(family_members, buf);
        stringstream dates(buf);
        string segment;
        vector<string> seglist;
        while(getline(dates, segment, ','))
            seglist.push_back(segment);
        vector<int> intdates;

        for(const auto& date : seglist)
            intdates.push_back(stoi(date));

        temp->modify_dates(intdates[0],intdates[1],intdates[2],
            intdates[3], intdates[4], intdates[5]);

	// skip family member connections for now
        while(getline(family_members, buf))
        {
            if(buf == "PERSON")
            {
                count++;
                break;
            }
        }
        people.push_back(temp);
    }

    for(const auto& person : people)
        cout << *person << endl;
}
