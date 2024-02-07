#ifndef HARL_H_
#define HARL_H_

#include <string>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		void complain( std::string level );
};

#endif // HARL_H_