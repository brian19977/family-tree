#include <iostream>
#include <iomanip>
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
    vector<Person> people;

    getline(family_members, buf); // skip first "PERSON"

    while(!family_members.eof())
    {
        Person temp;

        // get id
        getline(family_members, buf);
        temp.modify_id(stoi(buf));
        
    	// add name
	    getline(family_members, buf);
        temp.modify_name(
            buf.substr(0,buf.find(" ")),
            buf.substr(buf.find(" ")+1,buf.length())
            );
       
	    // add gender
        getline(family_members, buf);
        temp.modify_gender(buf);

	    // add dates
        getline(family_members, buf);
        stringstream dates(buf); // create a string stream using buf
        string segment;
        vector<string> seglist;
        vector<int> intdates;
        while(getline(dates, segment, ',')) // from the stream, 
                                            // read into string,
                                            // delimiting with char
            seglist.push_back(segment);

        for(const auto& date : seglist)     // cast each separate string
            intdates.push_back(stoi(date)); // to int

        temp.modify_dates(intdates[0],intdates[1],intdates[2],
            intdates[3], intdates[4], intdates[5]);

        // skip family member connections for now
        while(getline(family_members, buf))
        {
            if(buf == "PERSON")
                break;
        }
        people.push_back(temp);
    }

    // set ifstream to start of file
    family_members.clear();
    family_members.seekg(0, ios::beg);

    while(!family_members.eof())
    {
        // get id
        getline(family_members, buf);
        int curr_id;
        if(buf == "PERSON")
        {
            getline(family_members, buf);
            curr_id = stoi(buf);
        }

        // for the n+1th iteration
        if(family_members.eof())
            break;

        // get to relations
        while(getline(family_members, buf))
        {
            if(buf == "RELATIONS")
                break;
        }

        Person *fatherptr = nullptr;
        Person *motherptr = nullptr;
    
        getline(family_members, buf);
        if(buf != "null")
            fatherptr = &(people[stoi(buf)-1]);
        getline(family_members, buf);
        if(buf != "null")
            motherptr = &(people[stoi(buf)-1]);
        
        people[curr_id-1].modify_parents(fatherptr, motherptr);
    }

    for(const auto& person : people)
        cout << person << endl;

    
    
}
