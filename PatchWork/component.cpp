class Component
{
  public:
    Component(std::string name, double salary)
          : m_fullName(name), m_valueSalary (salary) {}

    virtual void printSalary(int level) = 0;

    //Of course these data members should be private,
    //but I did not wish to "litter" this class with
    //superfluous functions-interfaces,
    //therefore I have left these data members of class to be public
    std::string            m_fullName;
    double                 m_valueSalary;
};
