#include "AForm.hpp"
#include <string>

using std::string;

class ShrubberyCreationForm : public AForm {
    private:
        string m_target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(string m_target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        void execute(Bureaucrat const & executor) const;

        string getTarget() const;
        void setTarget(const string& target);

};