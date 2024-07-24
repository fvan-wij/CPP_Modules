#pragma once

class Base {
	public:
		Base();
		virtual ~Base();
};

Base*			generate();
void			identify(Base* p);
void			identify(Base& r);
