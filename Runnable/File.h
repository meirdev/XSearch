#ifndef __RUNNABLE_FILE_H__
#define __RUNNABLE_FILE_H__

#include <string>

#include "ThreadPool/IRunnable.h"

class File : public IRunnable
{
public:
    File(const std::string& _search, const std::string& _file);
    void run();
private:
    std::string m_search;
    std::string m_file;
};

#endif // __THREAD_POOL_RUNNABLE_FILE_H__