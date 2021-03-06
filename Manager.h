/*
* File:   Manager.h
* Author: Daria Tarasova
*
* Created on January 28, 2016, 7:26 PM
*/

#ifndef MANAGER_H
#define	MANAGER_H

#include "Employee.h"
#include <vector>
using namespace std;

class CManager : public CEmployee {
protected:
	//Employees managed by manager
	vector<CEmployee*> m_Group;
	string m_DepartmentName;

public:
	CManager(const string &firstName, const string &lastName,
		const unsigned short &salary, const tm &yearHired,
		const string &departName, const vector<CEmployee*> &group) :
		CEmployee(firstName, lastName, salary, yearHired) {
		m_Group = group;
		m_DepartmentName = departName;
	}
	//Default Constructor
	CManager() :CEmployee() {
		m_DepartmentName = "NA";
	}
	//Copy Constructor
	CManager(const CManager &CM) {
		if (this != &CM)
		{
			m_FirstName = CM.getFirstName();
			m_LastName = CM.getLastName();
			m_YearHired = CM.getYearHired();
			m_Salary = CM.getSalary();
			m_DepartmentName = CM.getDepartment();
			m_Group = CM.getGroup();
		}
	}
	//Assignment Operator
	CManager& operator=(const CManager &CM) {
		if (this != &CM)
		{
			m_FirstName = CM.getFirstName();
			m_LastName = CM.getLastName();
			m_YearHired = CM.getYearHired();
			m_Salary = CM.getSalary();
			m_DepartmentName = CM.getDepartment();
			m_Group = CM.getGroup();
		}
		return *this;
	}

	string getDepartment() const {
		return m_DepartmentName;
	}

	void setDepartment(const string departName) {
		m_DepartmentName = departName;
	}

	vector<CEmployee*> getGroup() const
	{
		return m_Group;
	}

	void setGroup(const vector<CEmployee*> group) {
		m_Group = group;
	}
	//Displays Manager Imformation and their subordinates' info
	virtual void DisplayEmployee() const {
		cout << m_FirstName << " " << m_LastName << "    Salary: " << m_Salary << ";    Hiring Year: " <<
			m_YearHired.tm_year << "     Department: " << m_DepartmentName << "    Subordinates: " << m_Group.size() <<endl;
		for (auto E : m_Group)
		{
			cout << "\tSubordinate:";
			E->DisplayEmployee();
		}
	}
};

#endif	/* MANAGER_H */