#ifndef CONCRETEGROWTHMEDIATOR_H
#define CONCRETEGROWTHMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

//#include "StaffMember.h"
#include "Plant.h"
#include "StaffMember.h"

class StaffMember;

/**
 * @class ConcreteGrowthMediator
 * @brief Mediator class that manages interactions between StaffMember objects and Plants.
 *
 * This class maintains a list of staff members and provides methods to add, remove, 
 * and notify them about changes or updates related to plants.
 */
class ConcreteGrowthMediator
{
private:
    /// List of staff members managed by this mediator
    vector<StaffMember *> staffMembers;

public:
    /**
     * @brief Constructs a ConcreteGrowthMediator object.
     */
    ConcreteGrowthMediator();

    /**
     * @brief Destructor for ConcreteGrowthMediator.
     */
    ~ConcreteGrowthMediator();

    /**
     * @brief Adds a staff member to the mediator.
     * @param bob Pointer to the StaffMember to add.
     * @return True if the staff member was successfully added, false if already exists.
     */
    bool addStaffMember(StaffMember* bob);

    /**
     * @brief Removes a staff member from the mediator.
     * @param bob Pointer to the StaffMember to remove.
     * @return True if the staff member was successfully removed, false if not found.
     */
    bool removeStaffMember(StaffMember* bob);

    /**
     * @brief Notifies all staff members about an update to a plant.
     * @param plant Pointer to the Plant that triggered the notification.
     */
    void notify(Plant* plant);
};

#endif
