#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:

		int			index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

		static std::string getInput(const std::string& prompt);
		static std::string truncateField(const std::string& field);
	
	public:

		Contact();
		
		static	Contact createContact(int index);
		void	setIndex(int idx);
		void	printSearchLine() const;
		void	printContact() const;
};

#endif