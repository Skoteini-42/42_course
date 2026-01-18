#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	private:

	const std::string	_name;
	unsigned int		_grade;

	public:

	Bureaucrat();
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	void	incrementGrade();
	void	decrementGrade();

	const std::string&	Bureaucrat::getName() const;
	unsigned int		Bureaucrat::getGrade() const;

	// Inheriting from std::exception: virtual destructor and virtual: const char* what() const throw()
	// throw() guarantees that the function itself will not throw any exceptions
	class	GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureaucrat);