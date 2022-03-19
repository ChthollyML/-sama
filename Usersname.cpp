#include "Usersname.h"
#include<sstream>
Usersname::Usersname()
{
}

Usersname::Usersname(const std::string& username, const std::string& passwords)
	:username(username),passwords(passwords)
{
}
std::string Usersname::formatInfols()
{
	std::stringstream ss;
	ss << username <<'#' <<passwords << std::endl;
	return ss.str();
}
