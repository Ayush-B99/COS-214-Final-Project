#include "../include/Manager.h"
#include "../include/Inventory.h"

Manager::Manager(const string& name, CommMediator* mediator, Inventory* inventory)
    : StaffMember(name, mediator, inventory) 
{
}

void Manager::handleCustomerQuery(Customer* customer, const string& query, Plant* plant)
{
    cout << getName() << " handling complex query from " << customer->getName() 
         << ": \"" << query << "\"" << endl;
    
    string response;
    Inventory* inventory = getInventory();  
    if (query.find("bulk") != string::npos || query.find("wholesale") != string::npos)
    {
        response = "I can help with bulk purchases! We offer discounts for orders over 20 plants.";
    }
    else if (query.find("rare") != string::npos || query.find("special") != string::npos)
    {
        response = "We can special order rare plants for you. It takes 2-3 weeks.";
    }
    else if (query.find("complaint") != string::npos)
    {
        response = "I apologize for any inconvenience. Let me make this right for you.";
    }
    else if ((query.find("inventory") != string::npos || query.find("stock") != string::npos) && inventory)
    {
        
        int totalPlants = getTotalPlantCount();
        response = "As manager, I can tell you we currently have " + to_string(totalPlants) + 
                  " plants in inventory across various species.";
    }
    else
    {
        response = "As manager, I'm here to ensure you have the best experience!";
    }
    
    respondToCustomer(customer, response, plant);
}

void Manager::handlePurchaseRequest(Customer* customer, const string& plantType, int quantity)
{
    cout << getName() << " processing special purchase: " << quantity << " " << plantType << "(s)" << endl;
    
    string response;
    Inventory* inventory = getInventory();  
    if (inventory)
    {
       
        vector<Plant*> availablePlants = inventory->getPlants(plantType);
        int availableCount = availablePlants.size();
        
        if (availableCount >= quantity)
        {
            if (quantity >= 10)
            {
                response = "I've approved your bulk order of " + to_string(quantity) + 
                          " " + plantType + " plants with a 15% discount!";
            }
            else
            {
                response = "I've processed your order for " + to_string(quantity) + 
                          " " + plantType + " plants. Thank you for your business!";
            }
            
           
        }
        else
        {
            if (availableCount > 0)
            {
                response = "We only have " + to_string(availableCount) + " " + plantType + 
                          " plants available. I can arrange a special order for the remaining " + 
                          to_string(quantity - availableCount) + " plants.";
            }
            else
            {
                response = "We're currently out of " + plantType + 
                          " plants, but I can place a special order that will arrive in 2-3 weeks.";
            }
        }
    }
    else
    {
        response = "Let me check our inventory system for you.";
    }
    
    respondToCustomer(customer, response);
}



void Manager::checkInventoryStatus()
{
    Inventory* inventory = getInventory();  
    if (!inventory)
    {
        cout << "Inventory system not available." << endl;
        return;
    }
    
    int totalPlants = getTotalPlantCount();
    cout << getName() << " checking inventory status: " << totalPlants << " total plants in stock." << endl;
    
    inventory->print();
}

int Manager::getTotalPlantCount()
{
    Inventory* inventory = getInventory();  
    if (!inventory) return 0;
    return inventory->getPlantCount();
}