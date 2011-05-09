#ifndef hl7msg_h
#define hl7msg_h

#include <string>
#include <iostream>
#include <vector>

using std::string;

struct MSHmsg{
	string codeSymbols;					//2
	string senderApplication;			//3
	string senderOffice;					//4
	string receiverApplication;		//5
	string receiverOffice;				//6
	string dateTime;						//7
	string defense;						//8
	string messageType;					//9
	string messageId;						//10
	string processingType;				//11
	string standartVersion;				//12
	string MessageNumber;				//13
	string continuation;					//14
	string receiveConfirmation;		//15
	string processingConfirmation;	//16
	string countryId;						//17
	void print(){
		 std::cout	<< "codeSymbols=" << codeSymbols << "\n"
						<<", senderApplication=" << senderApplication << "\n"
						<<", senderOffice=" << senderOffice << "\n"
						<<", receiverApplication=" << receiverApplication << "\n"
						<<", receiverOffice=" << receiverOffice << "\n"
						<<", dateTime=" << dateTime << "\n"
						<<", defense=" << defense << "\n"
						<<", messageType=" << messageType << "\n"
						<<", messageId=" << messageId << "\n"
						<<", processingType=" << processingType << "\n"
						<<", standartVersion=" << standartVersion << "\n"
						<<", MessageNumber=" << MessageNumber << "\n"
						<<", continuation=" << continuation << "\n"
						<<", receiveConfirmation=" << receiveConfirmation << "\n"
						<<", processingConfirmation=" << processingConfirmation << "\n"
						<<", countryId=" << countryId << "\n";
	}
};

struct EVNTmsg{
	string evntTypeCode;					//1
	string dateTime;						//2
	string dateTimePlanedEvnt;			//3
	string evntReason;					//4
	string operatorId;					//5
	void print(){
		 std::cout	<< "evntTypeCode=" << evntTypeCode << "\n"
						<<", dateTime=" << dateTime << "\n"
						<<", dateTimePlanedEvnt=" << dateTimePlanedEvnt << "\n"
						<<", evntReason=" << evntReason << "\n"
						<<", operatorId=" << operatorId << "\n";
	}
};
struct MSAmsg{
	enum msglen{
		count = 6
	};
	string fields[count];
	
	void print(){
		for(int i = 0; i < count; ++i){
			std::cout << "field[" << i << "]=" << fields[i] << "\n";
		}
	}
	
/*
1	ACKNOWLEDGEMENT CODE				ID
2	MESSAGE CONTROL ID				ST
3	TEXT MESSAGE						ST
4	EXPECTED SEQUENCE NUMBER		NM
5	DELAYED ACKNOWLEDGEMENT TYPE	ID
6	ERROR CONDITION					CE
*/
};

struct PIDmsg{
	string segId;							//1
	string externalId;					//2
	string internalId;					//3
	string alternativeId;				//4
	string name;							//5
	string mothersMaidenName;			//6
	string birthDate;						//7
	string gender;							//8
	string pastName;						//9
	string race;							//10
	string address;						//11
	string areaCode;						//12
	string homePhoneNumber;				//13
	string workPhoneNumber;				//14
	string language;						//15
	string maritalStatus;				//16
	string worship;						//17
	string account;						//18
	string socialSecurityNumber;		//19
	string motherId;						//20
	string ethnicGroup;					//21
	string birthPlace;					//22
	string multipleBirths;				//23
	string birthOrder;					//24
	string citizenship;					//25
	string militaryVeteranStatus;		//26
	void print(){
		 std::cout	<< "segId=" << segId << "\n"
						<<", externalId=" << externalId << "\n"
						<<", internalId=" << internalId << "\n"
						<<", alternativeId=" << alternativeId << "\n"
						<<", name=" << name << "\n"
						<<", mothersMaidenName=" << mothersMaidenName << "\n"
						<<", birthDate=" << birthDate << "\n"
						<<", gender=" << gender << "\n"
						<<", pastName=" << pastName << "\n"
						<<", race=" << race << "\n"
						<<", address=" << address << "\n"
						<<", areaCode=" << areaCode << "\n"
						<<", homePhoneNumber=" << homePhoneNumber << "\n"
						<<", workPhoneNumber=" << workPhoneNumber << "\n"
						<<", language=" << language << "\n"
						<<", maritalStatus=" << maritalStatus << "\n"
						<<", worship=" << worship << "\n"
						<<", account=" << account << "\n"
						<<", socialSecurityNumber=" << socialSecurityNumber << "\n"
						<<", motherId=" << motherId << "\n"
						<<", ethnicGroup=" << ethnicGroup << "\n"
						<<", birthPlace=" << birthPlace << "\n"
						<<", multipleBirths=" << multipleBirths << "\n"
						<<", birthOrder=" << birthOrder << "\n"
						<<", citizenship=" << citizenship << "\n"
						<<", militaryVeteranStatus=" << militaryVeteranStatus << "\n";
	}
};

struct PV1msg{
	enum msglen{
		count = 52
	};
	string fields[count];
	
	void print(){
		for(int i = 0; i < count; ++i){
			std::cout << "field[" << i << "]=" << fields[i] << "\n";
		}
	}
/*
  PV1-1   SI      4  Set ID - PV1
  PV1-2   IS      1  Patient Class
  PV1-3   PL     80  Assigned Patient Location
  PV1-4   IS      2  Admission Type
  PV1-5   CX     20  Preadmit Number
  PV1-6   PL     80  Prior Patient Location
  PV1-7   XCN    60  Attending Doctor
  PV1-8   XCN    60  Referring Doctor
  PV1-9   XCN    60  Consulting Doctor
  PV1-10  IS      3  Hospital Service
  PV1-11  PL     80  Temporary Location
  PV1-12  IS      2  Preadmit Test Indicator
  PV1-13  IS      2  Readmission Indicator
  PV1-14  IS      3  Admit Source
  PV1-15  IS      2  Ambulatory Status
  PV1-16  IS      2  VIP Indicator
  PV1-17  XCN    60  Admitting Doctor
  PV1-18  IS      2  Patient Type
  PV1-19  CX     20  Visit Number
  PV1-20  CM     50  Financial Class
  PV1-21  IS      2  Charge Price Indicator
  PV1-22  IS      2  Courtesy Code
  PV1-23  IS      2  Credit Rating
  PV1-24  IS      2  Contract Code
  PV1-25  DT      8  Contract Effective Date
  PV1-26  NM     12  Contract Amount
  PV1-27  NM      3  Contract Period
  PV1-28  IS      2  Interest Code
  PV1-29  IS      1  Transfer to Bad Debt Code
  PV1-30  DT      8  Transfer to Bad Debt Date
  PV1-31  IS     10  Bad Debt Agency Code
  PV1-32  NM     12  Bad Debt Transfer Amount
  PV1-33  NM     12  Bad Debt Recovery Amount
  PV1-34  IS      1  Delete Account Indicator
  PV1-35  DT      8  Delete Account Date
  PV1-36  IS      3  Discharge Disposition
  PV1-37  CM     25  Discharged to Location
  PV1-38  IS      2  Diet Type
  PV1-39  IS      2  Servicing Facility
  PV1-40  IS      1  Bed Status
  PV1-41  IS      2  Account Status
  PV1-42  PL     80  Pending Location
  PV1-43  PL     80  Prior Temporary Location
  PV1-44  TS     26  Admit Date/Time
  PV1-45  TS     26  Discharge Date/Time
  PV1-46  NM     12  Current Patient Balance
  PV1-47  NM     12  Total Charges
  PV1-48  NM     12  Total Adjustments
  PV1-49  NM     12  Total Payments
  PV1-50  CX     20  Alternate Visit ID
  PV1-51  IS      1  Visit Indicator
  PV1-52  XCN    60  Other Healthcare Provider
*/
};

struct PD1msg{
	enum msglen{
		count = 12
	};
	string fields[count];
	
	void print(){
		for(int i = 0; i < count; ++i){
			std::cout << "field[" << i << "]=" << fields[i] << "\n";
		}
	}
/*
  PD1-1   IS      2  Living Dependency
  PD1-2   IS      2  Living Arrangement
  PD1-3   XON    90  Patient Primary Facility
  PD1-4   XCN    90  Patient Primary Care Provider Name & ID No.
  PD1-5   IS      2  Student Indicator
  PD1-6   IS      2  Handicap
  PD1-7   IS      2  Living Will
  PD1-8   IS      2  Organ Donor
  PD1-9   ID      2  Separate Bill
  PD1-10  CX      2  Duplicate Patient
  PD1-11  CE     80  Publicity Indicator
  PD1-12  ID      1  Protection Indicator
*/
};

struct ADTmsg{
	std::vector<string> msh;
	std::vector<string> evn;
	std::vector<string> pid;
	std::vector<string> pd1;
	std::vector<string> pv1;
	void printVector(std::vector<string> const &v, string const & vname){
		std::cout << " --- " << vname << " --- \n";
		for(int i = 0; i < v.size(); ++i){
			if (v[i].size()) {
				std::cout << "i=" << i << ", val=" << v[i] << "\n";
			}
		}
	}
	void print(){
		printVector(msh, "msh");
		printVector(evn, "evn");
		printVector(pid, "pid");
		printVector(pd1, "pd1");
		printVector(pv1, "pv1");
	}
};

#endif	//hl7msg_h

//