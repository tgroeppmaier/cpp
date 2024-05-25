#include "AForm.hpp"
#include <string>

using std::string;

class PresidentialPardonForm : public AForm {
    private:
        string m_target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        void execute(Bureaucrat const & executor) const;

        string getTarget() const;
        void setTarget(const string& target);
};