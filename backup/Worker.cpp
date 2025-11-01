#include "../include/Worker.h"
#include "../include/Inventory.h"

Worker::Worker(const string &name, CommMediator *mediator, Inventory *inventory)
    : StaffMember(name, mediator, inventory)
{
    // Staffmember handles mediator registration which happens automatically
    // Staffmember handles mediator registration which happens automatically
}

void Worker::handleCustomerQuery(Customer *customer, const string &query, Plant *plant)
{
    cout << getName() << " handling query from " << customer->getName()
         << ": \"" << query << "\"" << endl;


    string response;

    if (query.find("water") != string::npos || query.find("care") != string::npos)
    {
        response = "I can help with plant care! Most plants need watering once a week.";
        providePlantCareAdvice(customer, "general");
    }
 
    else if (query.find("price") != string::npos || query.find("cost") != string::npos)
    {
        response = "Let me check the prices for you. Our plants range from $5 to $50.";
    }
    else if (query.find("sunlight") != string::npos)
    {
        response = "Great question! Most plants need 4-6 hours of sunlight daily.";
    }
    else if (query.find("stock") != string::npos || query.find("available") != string::npos ||
             query.find("have") != string::npos)
    {
        // Handle stock inquiries using the actual inventory
        Inventory *inventory = getInventory();
        if (inventory)
        {
            // Try to extract plant type from query - USE ACTUAL FACTORY PLANT NAMES
            vector<string> factoryPlants = {"carnivorous", "tropical", "temperate", "succulent"};
            string foundPlant;
            for (const string &plantType : factoryPlants)
            {
                if (query.find(plantType) != string::npos)
                {
                    foundPlant = plantType;
                    break;
                }
            }

            if (!foundPlant.empty())
            {
                // Convert to actual inventory key names
                string inventoryKey = foundPlant;
                if (foundPlant == "carnivorous")
                    inventoryKey = "CarnivorousPlant";
                else if (foundPlant == "tropical")
                    inventoryKey = "TropicalPlant";
                else if (foundPlant == "temperate")
                    inventoryKey = "TemperatePlant";
                else if (foundPlant == "succulent")
                    inventoryKey = "SucculentPlant";

                int stockCount = getPlantStockCount(inventoryKey);
                if (stockCount > 0)
                {
                    response = "We have " + to_string(stockCount) + " " + foundPlant + " plants available!";
                }
                else
                {
                    response = "Sorry, we're currently out of " + foundPlant + " plants.";
                }
            }
            else
            {
                // No specific plant mentioned - give general inventory info
                response = "We have carnivorous, tropical, temperate, and succulent plants available!";
            }
        }
        else
        {
            response = "Let me check our inventory for you. We have many beautiful plants available!";
        }
    }
    else
    {
        response = "I'll be happy to help you with that!";
    }


    respondToCustomer(customer, response, plant);
}

void Worker::handlePurchaseRequest(Customer *customer, const string &plantType, int quantity)
{
    cout << getName() << " processing purchase: " << quantity << " " << plantType << "(s)" << endl;

    string response;
    Inventory *inventory = getInventory();
    if (inventory)
    {
        if (checkPlantAvailability(plantType, quantity))
        {

            response = "Great! We have " + to_string(quantity) + " " + plantType +
                       " plant(s) available. Your total is $" + to_string(quantity * 15) + ". Thank you!";
        }
        else
        {
            int available = getPlantStockCount(plantType);
            if (available > 0)
            {
                response = "Sorry, we only have " + to_string(available) +
                           " " + plantType + " plant(s) available. Would you like to purchase fewer?";
            }
            else
            {
                response = "Sorry, we're currently out of " + plantType + " plants. We expect more soon!";
            }
        }
    }
    else
    {
        response = "I need to check our inventory system. One moment please.";
    }

    respondToCustomer(customer, response);
}


void Worker::checkInventory(const string &plantType)
{
    cout << "    [" << getName() << " checking inventory for " << plantType << "]" << endl;
    Inventory *inventory = getInventory();
    if (inventory)
    {
        int stockCount = getPlantStockCount(plantType);
        cout << "    Current stock of " << plantType << ": " << stockCount << " plants" << endl;
    }
    else
    {
        cout << "    Inventory system not available" << endl;
    }
}

bool Worker::checkPlantAvailability(const string &plantType, int quantity)
{
    Inventory *inventory = getInventory();
    if (!inventory)
        return false;

    int available = getPlantStockCount(plantType);
    return available >= quantity;
}

int Worker::getPlantStockCount(const string &plantType)
{
    Inventory *inventory = getInventory();
    if (!inventory)
        return 0;

    vector<Plant *> plants = inventory->getPlants(plantType);
    return plants.size();
}

vector<string> Worker::getAvailablePlantTypes()
{
    vector<string> availableTypes;
    Inventory *inventory = getInventory();
    if (!inventory)
        return availableTypes;

    availableTypes = {"rose", "tulip", "orchid", "sunflower", "cactus", "fern"};
    return availableTypes;
}

void Worker::providePlantCareAdvice(Customer *customer, const string &plantType)
{
    cout << "    [" << getName() << " providing " << plantType << " care advice to " << customer->getName() << "]" << endl;
}