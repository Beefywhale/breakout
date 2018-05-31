#pragma once
#include <string>
#include <ctime>

<<<<<<< HEAD
/**
* @brief Logger.
*/
class Logger
{
public:
   /**
    * Default constructor for Logger.
    */
    Logger() {};
	
  /**
   * Print out an error message.
   * @param err An error to output to the debug console.
   */
	void error(std::string err);
   
   /**
    * Print out an warning message.
    * @param warn A warning to output to the debug console.
    */
    void warning(std::string warn);
	
   /**
    * Print out an info message.
    * @param inf An info message to output to the debug console.
    */
    void info(std::string inf);
	
   /**
    * Print out a message.
    * @param pt A message to output to the debug console.
    */
    void plaintext(std::string pt);
=======
class Logger
{
public:
	Logger();
	
	void error(std::string err);
	void warning(std::string err);
	void info(std::string inf);
	void plaintext(std::string pt);
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
};

