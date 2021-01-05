    #include <iostream>
    #include <direct.h>
    #include <string>
    #include <ctime>

using namespace std;
    int main()
    {
        string myDir = "D:/Fresh/DauTranPrj/MyData/employee/";
        string strLocalDay;
        string strTime;

        //Create a days
        time_t now =time(0);
        tm *pTime = localtime(&now);
        strLocalDay = to_string(1900 + pTime->tm_year)+ "_" + to_string(1 + pTime->tm_mon) + "_" + to_string(pTime->tm_mday);

        myDir += strLocalDay;

        strTime = to_string(5+pTime->tm_hour) + "_" + to_string(30+pTime->tm_min) + "_" + to_string(pTime->tm_sec);

        myDir += "/" + strTime;



        const char* s = myDir.c_str();
        mkdir(s);
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