#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

template<typename T>
class Memento
{
    private:
        T state;

    public:
        Memento(const T& state) : state(state) {}
    
        string getState() const
        {
            return state;
        }
};
