#pragma once
#include <string>
#include <ctime>

// Class: Logger
// A class for logging messages to the debug console.
class Logger {
public:
   /**
    * Default constructor for Logger.
    */
    // Constructor: Logger
    // Default constructor.
    Logger() {}

    /* Function: error
       Log a message as an error.

       Parameters:
          err - A message to log.
    */
    void error(std::string err);
   
    /* Function: warning
       Log a message as a warning.

       Parameters:
          warn - A message to log.
    */
    void warning(std::string warn);
	
    /* Function: info
       Log a message as info.

       Parameters:
          inf - A message to log.
    */
    void info(std::string inf);
	

    /* Function: plaintext
       Log a message as it is given.

       Parameters:
          pt - A message to log.
    */
    void plaintext(std::string pt);
};

