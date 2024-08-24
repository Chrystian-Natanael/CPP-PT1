#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <cstdio>

class Contact {
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _darkest_secret;

public:
	Contact(void);
	~Contact(void);

	void setFirstName(const std::string first_name);


	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	std::string getDarkestSecret(void);
};

#endif