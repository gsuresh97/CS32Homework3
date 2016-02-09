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
