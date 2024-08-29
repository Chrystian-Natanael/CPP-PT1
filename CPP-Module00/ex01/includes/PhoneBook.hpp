#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <cctype>
# include <string>
# include <iomanip>
# include "../includes/Contact.hpp"
# include "../includes/Colors.hpp"

enum info {
	NAME = 1,
	PHONE,
	ANY
};

class PhoneBook {
private:
	Contact	listContacts[8];
	int		currIndex;
	int		numOfContacts;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContact(void);
};

#endif