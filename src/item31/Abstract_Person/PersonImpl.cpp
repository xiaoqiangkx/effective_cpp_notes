#include "PersonImpl.h"


Date::Date(const std::string& d): date(d) {}
std::string Date::get() const { return date; }

PersonImpl::PersonImpl(const std::string& date): d(date) {}
std::string PersonImpl::get_date() const { return d.get(); }
