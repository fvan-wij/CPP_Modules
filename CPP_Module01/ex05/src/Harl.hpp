#pragma once
#include <string>

class Harl{

	public:
		Harl();
		~Harl();
		void	complain(std::string level);

	private:
		typedef struct _LevelFn {
			std::string 	level;
			void 			(Harl::*_pmf)();
		} _LevelFn;

		_LevelFn	_lvlFn[4];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};
