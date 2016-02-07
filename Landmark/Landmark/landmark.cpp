#include <iostream>
#include <string>
using namespace std;

//Your declarations and implementations would go here
class Landmark{
public:
    Landmark(string n){
        m_name = n;
    }
    virtual string color() const{
        return "yellow";
    }
    virtual string icon() const = 0;
    string name() const {
        return m_name;
    }
    virtual ~Landmark(){ }

private:
    string m_name;
};

class Hotel: public Landmark{
public:
    Hotel(string n)
    :Landmark(n){ }
    
    virtual string icon() const{
        return "bed";
    }
    virtual ~Hotel(){
        cout << "Destroying the hotel " << name() <<".\n";
    };
};

class Restaurant: public Landmark{
public:
    Restaurant(string n, int c)
    :Landmark(n){
        m_capacity = c;
    }
    virtual string icon() const{
        return m_capacity>=40? "large knife/fork": "small knife/fork";
    }
    virtual string color() const{
        return "blue";
    }
    virtual ~Restaurant(){
        cout << "Destroying the restaurant " << name()<<".\n";
    };
private:
    int m_capacity;

};

class Hospital:public Landmark{
public:
    Hospital(string n)
    :Landmark(n){ }

    virtual string icon() const{
        return "H";
    }
    virtual string color() const{
        return "blue";
    }
    virtual ~Hospital(){
        cout << "Destroying the hospital " << name()<<".\n";
    }

    
};

void display(const Landmark* lm)
{
    cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
    << lm->name() << "." << endl;
}

int main()
{
    Landmark* landmarks[4];
    landmarks[0] = new Hotel("Westwood Rest Good");
    // Restaurants have a name and seating capacity.  Restaurants with a
    // capacity under 40 have a small knife/fork icon; those with a capacity
    // 40 or over have a large knife/fork icon.
    landmarks[1] = new Restaurant("Bruin Bite", 30);
    landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
    landmarks[3] = new Hospital("UCLA Medical Center");
    
    cout << "Here are the landmarks." << endl;
    for (int k = 0; k < 4; k++)
        display(landmarks[k]);
    
    // Clean up the landmarks before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete landmarks[k];
}