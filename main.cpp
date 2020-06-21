#include <iostream>
#include <vector>

class person
{
public:
	std::string m_name;
	explicit person(const std::string &name) : m_name(name)
	{
		std::cout << "created " << m_name << std::endl;		
	}
	
	~person()
	{
		std::cout << "destroyed " << m_name << std::endl;		
	}	
	
	person(const person &other) : m_name(other.m_name)
	{
		m_name += ".copied";
		std::cout << "copied " << other.m_name << " -> " << m_name << std::endl;
	}
	
	person(person &&other) noexcept : m_name(std::move(other.m_name))
	{
		m_name += ".moved";
		std::cout << "moved " << other.m_name << " -> " << m_name << std::endl;
	}	
		
	person& operator=(person &&other) noexcept = delete;
};


int main()
{
	std::vector<person> people;
	people.reserve(10);
	
	std::cout << "\ncopy bob (lvalue):" << std::endl;
	person bob{"bob"};
	people.emplace_back(bob);

	std::cout << "\nmove fred (lvalue):" << std::endl;
	person fred{"fred"};
	people.emplace_back(std::move(fred));

	std::cout << "\ntemp joe (rvalue):" << std::endl;
	people.emplace_back("joe");
	
	std::cout << "\nterminating:" << std::endl;
}
