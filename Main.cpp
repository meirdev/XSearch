#include <iostream>
#include <getopt.h>

#include "Configuration.h"

#include "ThreadPool/ThreadPool.h"
#include "Search/RegularSearch/RegularSearch.h"
#include "Search/RegexSearch/RegexSearch.h"
#include "FileReader/Text/TextReader.h"
#include "Style/Ack/Ack.h"
#include "Runnable/Search.h"

Configuration* g_configuration;

int main(int argc, char** argv)
{
    std::string search;
    std::string files;

    if (argc == 1)
    {
        std::cout << "usage: ..." << std::endl;

        return 0;
    }

    if (argc > 1)
    {
        search = argv[1];
    }

    if (argc > 2)
    {
        files = argv[2];
    }
    else
    {
        files = ".";
    }

    g_configuration = Configuration::getInstance();

    g_configuration->m_reader     = new TextReader;
    g_configuration->m_search     = new RegularSearch;
    g_configuration->m_style      = new Ack;

    ThreadPool threadPool(16);

    g_configuration->m_threadPool = &threadPool;

    Search searchRunnable(search, files);

    searchRunnable.run();

    return 0;
}