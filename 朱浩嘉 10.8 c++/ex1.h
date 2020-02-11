#include<string>

using namespace std;
class Instructor
{
public:
	explicit Instructor( std::string );
	void setInstructorName( std::string );
	std::string getInstructorName() const;
	void displayMessage() const;
private:
	std::string instructorName;
};