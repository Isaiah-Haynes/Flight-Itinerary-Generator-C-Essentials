//
//  ECAirport.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECAirport_h
#define ECAirport_h

#include <string>
#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <iostream>



// ****************************************************************************
// Airport: start/end point of a flight

class ECAirport 
{
public:
    // by default, airport is operating (except in default constructor)
    ECAirport(); 
    ECAirport(const std::string &nameAP, const std::string &codeIATA);
    ECAirport(const ECAirport &rhs);
    
    // Get the name of the airport
    std::string GetName() const;
    
    // Get IATA code
    std::string GetCode() const;
    
    // Operating status: is it operating normally?
    bool IsOperating() const;
    
    // Set operating status
    void SetOperating(bool f);
    
private:
    std::string name;
    std::string codeIATA;
    bool operating;
};

// ****************************************************************************
// Airport info: access airport information
// Use singleton pattern

// need to figure out how to use singleton pattern. . .
class ECAirportInfo
{
public:
    // instance
    static ECAirportInfo& Instance();

    virtual ~ECAirportInfo();
    
    // Create a new airport in the system
    void CreateAirport(const std::string &name, const std::string &code);
    
    // Get airport by code
    // Throw exception (std::string) if there is no airport with the code
    ECAirport &GetAirport(const std::string &code) const;
    
    // Set distance (in miles) between airports
    void SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist);

    // Get Distance (in miles) between two airports
    double GetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code) const;

    // Get flight time between airports
    // virtual int GetFlightTime(const std::string &ap1Code, const std::string &ap2Code) const;


    // more to add...
    
private:
    std::set<ECAirport *> airports;
    std::map<std::pair<std::string, std::string>, double> distances;
    
    ECAirportInfo() {};
};


#endif /* ECAirport_h */

