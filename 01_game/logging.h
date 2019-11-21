#include <string>

void openLog(bool append);

void closeLog();

void logString(std::string logstr);

extern bool logging;
