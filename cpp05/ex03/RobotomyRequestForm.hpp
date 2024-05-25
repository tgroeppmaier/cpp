#include "AForm.hpp"
#include <string>

using std::string;

class RobotomyRequestForm : public AForm {
    private:
        string m_target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        void execute(Bureaucrat const & executor) const;

        string getTarget() const;
        void setTarget(const string& target);
};