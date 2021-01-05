    #include <iostream>
    #include <direct.h>
    #include <string>
    #include <ctime>

using namespace std;
void CreateDataBase()
{
        string myDir = "DataBase";
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
        strTime = to_string(5+pTime->tm_hour) + "_" + to_string(30+pTime->tm_min) + "_" + to_string(pTime->tm_sec);
        myDir += strTime;
        const char* timeFolder = myDir.c_str();
        mkdir(timeFolder);

        cout<< "Successfully! Here's your link: " <<myDir;
    }
    int main()
    {
        CreateDataBase();

        return 0;
    }

// string str = "D:/Fresh/DauTranPrj/MyData/employee/Mydata/nooPhuocThinh";
// int main()
// {
// 	time_t curr_time;
// 	curr_time = time(NULL);

// 	char *tm = ctime(&curr_time);
// 	cout << "Today is : " << tm;
	
// 	return 0;
// }