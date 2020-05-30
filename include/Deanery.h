#ifndef Deanery_H
#define Deanery_H

#include <vector>
#include "Group.h"
#include "Student.h"

class Deanery {
private:
	std::vector <Group> groups;
public:
	// constructors ------------------------------------------------------------------



	// methods -----------------------------------------------------------------------

	void createGroups();
	void createStudents();
	//std::vector <Group>& getGroupList();
	void initiateHeadChoice();
	void addRandomMarkAllStutents();
	void studentDismissal(int group, int id);
	void studentDismissalProgressless();
	void studentTransfer(int group, int id, int groupDestination);
	void statistics();
};

#endif