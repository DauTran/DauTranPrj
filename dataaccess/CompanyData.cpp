#include "CompanyData.h"

CompanyData::CompanyData()
{
        string myDir = "Backup data";
        string strLocalDay;
        string strTime;
        const char* dataFolder = myDir.c_str();
        mkdir(dataFolder);

        //Create a day folder
        time_t now =time(0);
        tm *pTime = localtime(&now);
        strLocalDay = "/" + to_string(1900 + pTime->tm_year) + "_" + to_string(1 + pTime->tm_mon) + "_" + to_string(pTime->tm_mday) + "/";
        myDir += strLocalDay;
        const char* daysFolder = myDir.c_str();
        mkdir(daysFolder);

        //Create a time folder
        strTime = to_string(pTime->tm_hour) + "_" + to_string(pTime->tm_min) + "_" +  "/"; //to_string(pTime->tm_sec) +
        myDir += strTime;
        const char* timeFolder = myDir.c_str();
        mkdir(timeFolder);

        mBackupLink = myDir;
}

string CompanyData::GetLink()
{
    return mBackupLink;
}


