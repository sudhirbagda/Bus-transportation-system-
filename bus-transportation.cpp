#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;
struct date
{
    int dd;
    int mm;
    int yy;
    date() {}
    date(const date &dt)
    {
        dd = dt.dd;
        mm = dt.mm;
        yy = dt.yy;
    }
    void get_date(int d, int m, int y)
    {
        dd = d;
        mm = m;
        yy = y;
    }
    bool operator==(date &d)
    {
        if (dd == d.dd)
        {
            if (mm == d.mm)
            {
                if (yy == d.yy)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    bool operator>=(const date &d)
    {
        if (mm > d.mm)
            return true;
        else if (mm == d.mm)
            if (dd >= d.dd)
                return true;
            else
                false;
    }
}; // date structure
struct d_time
{
    int hour;
    int minute;
    void print()
    {
        cout << hour << ":" << (minute < 10 ? "0" : "") << minute;
    }
    void get_time(int h, int m)
    {
        hour = h;
        minute = m;
    }
    void addMinutes(int minutesToAdd)
    {
        minute += minutesToAdd;
        hour += minute / 60;
        minute %= 60;
        hour %= 24;
    }
}; // time structure
class passenger
{
public:
    string name;
    string email;
    string mobile_no;
    int age;
    char gender;
    int seat;
    int busNum;
    string source;
    string destination;
    int total_distance;
    date journey_date;
    d_time departure_time;
    bool payment;
    int fees;
    char path;
    passenger() {}
    passenger(const passenger &p)
    {
        seat = p.seat;
        busNum = p.busNum;
        source = p.source;
        destination = p.destination;
        total_distance = p.total_distance;
        journey_date = p.journey_date;
        departure_time = p.departure_time;
        payment = p.payment;
        fees = p.fees;
        name = p.name;
        email = p.email;
        mobile_no = p.mobile_no;
        age = p.age;
        gender = p.gender;
        journey_date = p.journey_date;
        path = p.path;
    }
    string show_name() { return name; }
    string show_email() { return email; }
    string show_mobile_no() { return mobile_no; }
    int show_age() { return age; }
    char show_gender() { return gender; }
    void get_pname(string name) { this->name = name; }
    void get_email(string email) { this->email = email; }
    void get_num(string str) { mobile_no = str; }
    void get_age(int age) { this->age = age; }
    void get_gender(char g) { gender = g; }
    void display()
    {
        cout << "\n\t NAME          : " << name << endl;
        cout << "\n\t SEAT          : " << seat << endl;
        cout << "\n\t JOURNEY FROM  : " << source << endl;
        cout << "\n\t JOURNEY TO    : " << destination << endl;
        cout << "\n\t JOURNEY DATE  : " << journey_date.dd << "-" << journey_date.mm << "-" << journey_date.yy << endl;
        cout << "\n\t TOTAL FARE    : " << fees << endl;
    }
};
class Bus
{
protected:
    string bus_number;

public:
    string array_seats[28];
    passenger p[28];
    static int totalP;
    string main_route[15];
    int main_route_km[15];
    d_time departure_time;
    string get_bus_num()
    {
        return bus_number;
    }
};
int Bus::totalP = 0;
class User
{
    string username;
    string password;
    string key;

public:
    User()
    {
        username = "USER1";
        password = "USER10702";
        key = "USER_NUMBER";
    }
    string &ShowUsername()
    {
        return username;
    }
    string &Showpassword()
    {
        return password;
    }
    string ShowKey()
    {
        return key;
    }
    friend bool verifyCredentials(User, const string &, const string &);
} user_obj; // end of class User
class date_wise_data
{
public:
    date Date;
    Bus buses[10];
};
union passenger_history
{
    int n;
    passenger *passengers;
};
bool verifyCredentials(User obj, const string &enteredUsername, const string &enteredPassword)
{
    string uname = obj.username;
    string upassword = obj.password;
    cout << enteredPassword << endl;
    return (enteredUsername == uname && enteredPassword == upassword);
} // check password  and name
bool verifyEmail(string &email)
{
    int atPos = email.find('@');
    if (atPos == string::npos || atPos == 0 || atPos == email.length() - 1)
    {
        return false;
    }
    int dotPos = email.find('.', atPos);
    if (dotPos == string::npos || dotPos == atPos + 1 || dotPos == email.length() - 1)
    {
        return false;
    }
    if (email.find(' ') != string::npos)
    {
        return false;
    }
    return true;
} // end of verifyEmail
bool verifyMonum(string str)
{
    if (str.length() != 10)
    {
        return false;
    }
    // Check if all characters in the string are digits
    for (char c : str)
    {
        if (!(isdigit(c)))
        {
            return false;
        }
        return true;
    }
} // end of verifyMonum
bool verifyGen(char ch)
{
    if (ch != 'M' && ch != 'F' && ch != 'O')
    {
        return false;
    }
    return true;
}
bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int daysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    }
}
void nextDay(int day, int month, int year, date &d)
{
    if (day < daysInMonth(month, year))
    {
        day++;
    }
    else
    {
        day = 1;
        if (month < 12)
        {
            month++;
        }
        else
        {
            month = 1;
            year++;
        }
    }
    d.dd = day;
    d.mm = month;
    d.yy = year;
}
int choose_bus(date_wise_data[], passenger &);                  //  for choose the bus
int calculate_distance(Bus &, string &, string &, passenger &); // to calculate the distance in km
int reserve(Bus &, Bus[], passenger &, passenger_history[]);    // for reservation
bool payment(passenger &, Bus[]);                               // for payment
int get_num();                                                  // for getting correct number
int view(date_wise_data[]);                                     // for view ticket
int cancel(date_wise_data[]);                                   // for cancel ticket
void history(passenger_history[]);                              // for check today's history
int main()
{
    User user;
    time_t now = time(0);               // get current calendar time
    tm *current_time = localtime(&now); // convert calender time to local time components
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    date_wise_data array_data[10];
    date_wise_data array_data_rev[10];
    array_data[0].Date.dd = 18;
    array_data[0].Date.mm = 5;
    array_data[0].Date.yy = 2024;
    array_data_rev[0].Date.dd = 18;
    array_data_rev[0].Date.mm = 5;
    array_data_rev[0].Date.yy = 2024;
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < 28; k++)
            {
                array_data[j].buses[i].array_seats[k] = to_string(k + 1);
                array_data_rev[j].buses[i].array_seats[k] = to_string(k + 1);
            }
        }
    }
    passenger temp_passenger;
    passenger_history PH[281];
    PH[0].n = 0;
    string main_route[10][15] = {{"NADIAD", "KHEDA", "AHMEDABAD", "SANAND", "VIRAMGAM", "DHRAGADHRA", "HALVAD", "MALIA", "SAMAKHIALI", "BHACHAU", "KUKMA", "MADHAPAR", "BHUJ", "KODAY", "MANDVI"},
                                 {"ANAND", "NADIAD", "KHEDA", "DHOLKA", "BAGODARA", "LIMBDI", "SAYLA", "CHOTILA", "RAJKOT", "DHROL", "JAMNAGAR", "KHAMBHALIA", "BHATIYA", "BARADIA", "DWARKA"},
                                 {"DAHOD", "LIMKHEDA", "SANTRODA", "GODHRA", "SHEHRA", "HALOL", "VADODARA", "VASAD", "BORSAD", "TARAPUR", "DHOLERA", "BHAVNAGAR", "TALAJA", "BORDA", "MAHUVA"},
                                 {"SURAT", "KAMREJ", "MOTI NARODI", "ANKLESHWAR", "BHARUCH", "VADODARA", "VASAD", "BORSAD", "TARAPUR", "LIMBDI", "SAYLA", "CHOTILA", "RAJKKOT", "VIRPUR", "JUNAGADH"},
                                 {"MANDVI", "MUNDRA", "BHUJ", "KUKMA", "KABRAU", "BHACHAU", "SAMAKHIALI", "MADIA", "DHROL", "JAMNAGAR", "TRAN PATIYA", "RANAVAVA", "DIGVIJAYGADH", "VIRPUR", "PORBANDAR"},
                                 {"HIMATNAGAR", "DALPUR", "GANDHINAGAR", "ADALAJ", "AHMEDABAD", "BAGODARA", "LIMBDI", "BODIA", "VADOD", "SAYLA", "DOLIYA", "CHOTILA", "RAJKOT", "DHROL", "JAMNAGR"},
                                 {"MEHSANA", "KADI", "VIRAMGAM", "SUREDRANAGAR", "CHOTILA", "RAJKOT", "GONDAL", "VIRPUR", "JETPUR", "JUNAGADH", "KESHOD", "KHORASA GIR", "SUPASI", "VERAVAL", "SOMNATH"},
                                 {"BHAVNAGAR", "DHOLERA", "TARAPUR", "BORSAD", "VASAD", "VADODARA", "JAROD", "HALOL", "KALOL", "VEJALPUR", "SHEHRA", "LUNAWADA", "MODASA", "BAJKOT", "ARAVALLI"},
                                 {"BHUJ", "MADHAPAR", "BHUJODI", "DHANETI", "NAVAGAM", "BHUJPAR", "KABRAU", "SIKARA", "BHACHAU", "VONDH", "MORBI", "VAKANER", "CHOTILA", "RAJKOT", "BOTAD"},
                                 {"NADIAD", "KHEDA", "BAREJA", "MANINAGAR", "AHMEDABAD", "CHANDKHEDA", "ADALAJ", "GANDHINAGAR", "KALOL", "MEVAD", "MEHSANA", "UNAVA", "UNJHA", "MANDOTRI", "PATAN"}};
    int main_route_km[10][15] = {{0, 21, 38, 80, 93, 38, 29, 28, 22, 18, 49, 7, 5, 0, 0},
                                 {0, 20, 22, 28, 33, 44, 34, 34, 46, 50, 40, 57, 48, 1, 0},
                                 {0, 30, 22, 20, 20, 39, 42, 24, 20, 11, 23, 65, 53, 21, 25},
                                 {0, 23, 17, 31, 12, 87, 24, 20, 11, 115, 34, 34, 46, 57, 47},
                                 {0, 49, 53, 13, 54, 13, 18, 42, 84, 40, 69, 35, 65, 124},
                                 {0, 20, 43, 10, 18, 59, 44, 8, 10, 17, 10, 34, 46, 50, 40},
                                 {0, 38, 40, 67, 46, 40, 18, 13, 32, 37, 32, 13, 124, 0, 0},
                                 {0, 62, 66, 36, 20, 23, 27, 18, 170, 34, 138, 22, 58, 250},
                                 {0, 5, 6, 17, 10, 9, 20, 8, 14, 20, 69, 27, 39, 46, 122},
                                 {0, 21, 17, 17, 5, 11, 7, 12, 19, 14, 40, 21, 6, 29, 0}};
    d_time bus_departure_time[10] = {{6, 450}, {8, 30}, {7, 0}, {8, 40}, {10, 0}, {3, 45}, {9, 0}, {9, 25}, {5, 35}, {7, 30}};
    string bus_num[15] = {"GJ-18-Z-9410", "GJ-18-Z-1259", "GJ-18-Z-8529", "GJ-18-Z-4109", "GJ-18-Z-7709", "GJ-18-Z-7001", "GJ-18-Z-9119", "GJ-18-Z-9859", "GJ-18-Z-4596", "GJ-18-Z-1277"};
    for (int p = 0; p < 10; p++)
    {
        if (p > 0)
        {
            nextDay(array_data[p - 1].Date.dd, array_data[p - 1].Date.mm, array_data[p - 1].Date.yy, array_data[p].Date);
            nextDay(array_data_rev[p - 1].Date.dd, array_data_rev[p - 1].Date.mm, array_data_rev[p - 1].Date.yy, array_data_rev[p].Date);
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                array_data[p].buses[i].main_route[j] = main_route[i][j];
                array_data[p].buses[i].main_route_km[j] = main_route_km[i][j];
                array_data[p].buses[i].departure_time = bus_departure_time[i];
                array_data[p].buses[i].get_bus_num() = bus_num[i];
                array_data_rev[p].buses[i].main_route[j] = main_route[i][j];
                array_data_rev[p].buses[i].main_route_km[j] = main_route_km[i][j];
                array_data_rev[p].buses[i].departure_time = bus_departure_time[i];
                array_data_rev[p].buses[i].get_bus_num() = bus_num[i];
            }
        }
    }
    system("color 03");
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t __        __  _____   __      ____   ___    __  __   _____" << endl;
    cout << "\t\t\t\t\t\t \\ \\      / / | ____| | |     / ___/ / _ \\  |  \\/  | | ____|" << endl;
    cout << "\t\t\t\t\t\t  \\ \\ /\\ / /  |  _|   | |    | |    | | | | | |\\/| | | _|  " << endl;
    cout << "\t\t\t\t\t\t   \\ V  V /   | |___  | |__  | |__  | |_| | | |  | | | |___ " << endl;
    cout << "\t\t\t\t\t\t    \\_/\\_/    |_____| |____|  \\____\\ \\___/  |_|  |_| |_____|" << endl;
    cout << "\n\n\t\t\t\t\t\t---------------------------------------------------------------" << endl;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n   PLEASE PRESS ANY KEY TO CONTINUE.....";
    if (getchar())
    {
        system("cls");
        time_t now = time(0);               // get current calendar time
        tm *current_time = localtime(&now); // convert calender time to local time components
        string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
        cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
        string ename, epassword;
        do
        {
            char ch;
            cout << "\n\n\t\t\t\t\t\t\t\tWELCOME TO THE LOGIN PAGE " << endl;
            cout << "\t\t\t\t\t\t\t\t--------------------------\n\n";
            cout << "\n\n\tNOTE :- USERNAME AND PASSWORD ARE CASE SENSETIVE. \n\n";
            cout << "\tENTER USER_NAME   :- ";
            cin >> ename;
            cin.ignore();
            cout << "\n\tENTER PASSWORD    :- ";
            while ((ch = getch()) != '\r' && epassword.length() < 50)
            {
                if (ch == '\b' && !epassword.empty())
                {
                    cout << "\b \b";
                    epassword.pop_back();
                }
                else
                {
                    cout << "*";
                    epassword.push_back(ch);
                }
            }
            if (!verifyCredentials(user, ename, epassword))
            {
                system("color 04");
                epassword.clear();
                cout << "\n\n\n\n\n\n";
                cout << "\t\t\t\t\t ______________________________________________________________________________ " << endl;
                cout << "\t\t\t\t\t|                                                                              |" << endl;
                cout << "\t\t\t\t\t| WARNING           :- PLEASE ENTER THE VALID USERNAME AND PASSWORD.......     |" << endl;
                cout << "\t\t\t\t\t|                                                                              |" << endl;
                cout << "\t\t\t\t\t| KEY               :- " << user.ShowKey() << "\t\t\t                       |" << endl;
                cout << "\t\t\t\t\t|______________________________________________________________________________|" << endl;
                Sleep(2000);
                system("color 03");
            }
            else
            {
                break;
            }
            system("cls");
        } while (!verifyCredentials(user, ename, epassword));
        system("cls");
        fstream record;
        record.open("data.txt", ios::in);
        if (!record)
        {
            cout << "\n\t\t\tNo Data is Present... ";
            record.close();
        }
        else
        {
            while (record >> temp_passenger.path >> temp_passenger.journey_date.dd >> temp_passenger.journey_date.mm >> temp_passenger.journey_date.yy >> temp_passenger.busNum >> temp_passenger.name >> temp_passenger.age >> temp_passenger.email >> temp_passenger.mobile_no >> temp_passenger.gender >> temp_passenger.source >> temp_passenger.destination >> temp_passenger.seat >> temp_passenger.total_distance)
            {
                if (temp_passenger.path == 'F')
                {
                    temp_passenger.departure_time = array_data[0].buses[temp_passenger.busNum].departure_time;
                    temp_passenger.fees = temp_passenger.total_distance * 2 + 5 + 28 + 3;
                    temp_passenger.payment = true;
                    for (int i = 0; i < 10; i++)
                    {
                        if (array_data[i].Date == temp_passenger.journey_date)
                        {
                            array_data[i].buses[temp_passenger.busNum].p[temp_passenger.seat] = temp_passenger;
                            array_data[i].buses[temp_passenger.busNum].array_seats[temp_passenger.seat] = "X";
                        }
                    }
                }
                else if (temp_passenger.path == 'R')
                {
                    temp_passenger.departure_time = array_data_rev[0].buses[temp_passenger.busNum].departure_time;
                    temp_passenger.fees = temp_passenger.total_distance * 2 + 5 + 28 + 3;
                    temp_passenger.payment = true;
                    for (int i = 0; i < 10; i++)
                    {
                        if (array_data_rev[i].Date == temp_passenger.journey_date)
                        {
                            array_data_rev[i].buses[temp_passenger.busNum].p[temp_passenger.seat] = temp_passenger;
                            array_data_rev[i].buses[temp_passenger.busNum].array_seats[temp_passenger.seat] = "X";
                        }
                    }
                }
            }
            record.close();
        }
        int num = 10;
        bool flag = true;
        while (flag)
        {
        loop:
            system("cls");
            num = get_num();
            system("cls");
            int i = -1, j = -1, k = -1;
            switch (num)
            {
            case 1:
                i = 123;
                i = choose_bus(array_data, temp_passenger);
                if (temp_passenger.path == 'R')
                {
                    int Ndate = 123;
                    for (int j = 0; j < 10; j++)
                    {
                        if (array_data_rev[j].Date == temp_passenger.journey_date)
                        {
                            Ndate = j;
                            break;
                        }
                    }
                    if (i == 123)
                    {
                        goto loop;
                    }
                    else
                    {
                        reserve(array_data_rev[Ndate].buses[i], array_data_rev[i].buses, temp_passenger, PH);
                    }
                    break;
                }
                else
                {
                    int Ndate;
                    for (int j = 0; j < 10; j++)
                    {
                        if (array_data[j].Date == temp_passenger.journey_date)
                        {
                            Ndate = j;
                        }
                    }
                    if (i == 123)
                    {
                        goto loop;
                    }
                    else
                    {
                        reserve(array_data[Ndate].buses[i], array_data[i].buses, temp_passenger, PH);
                    }
                    break;
                }
            case 2:
                char path;
                cout << "\n\n\t\t\t\t\t\t\t\t\t VIEW TICKET \n\t\t\t\t\t\t\t\t\t-------------" << endl;
                cout << "\n\n\t\tPATH                : ";
                cin >> path;
                cin.ignore();
                system("cls");
                if (path == 'F')
                {
                    j = view(array_data);
                    if (j == 0)
                    {
                        goto loop;
                    }
                    break;
                }
                else if (path == 'R')
                {
                    j = view(array_data_rev);
                    if (j == 0)
                    {
                        goto loop;
                    }
                    break;
                }
            case 3:
                cout << "\n\n\t\t\t\t\t\t\t\t\t CANCEL HISTORY \n\t\t\t\t\t\t\t\t\t----------------" << endl;
                cout << "\n\n\t\tPATH                : ";
                cin >> path;
                cin.ignore();
                system("cls");
                if (path == 'F')
                {
                    k = cancel(array_data);
                    if (k == 0)
                    {
                        goto loop;
                    }
                    system("cls");
                    break;
                }
                else if (path == 'R')
                {
                    k = cancel(array_data_rev);
                    if (k == 0)
                    {
                        goto loop;
                    }
                    system("cls");
                    break;
                }
            case 4:
                history(PH);
                system("cls");
                break;
            case 5:
                flag = false;
                break;
            }
        }
        system("cls");
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
        cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t _____  _   _      _      _   _    _  __   __   __   ___    _   _  " << endl;
        cout << "\t\t\t\t\t\t|_   _|| | | |    / \\    | \\ | |  | |/ /   \\ \\ / /  / _ \\  | | | |  " << endl;
        cout << "\t\t\t\t\t\t  | |  | |_| |   / _ \\   |  \\| |  | ' /     \\ V /  | | | | | | | |" << endl;
        cout << "\t\t\t\t\t\t  | |  |  _  |  / ___ \\  | |\\  |  | . \\      | |   | |_| | | |_| |   _   _   _   _  " << endl;
        cout << "\t\t\t\t\t\t  |_|  |_| |_| /_/   \\_\\ |_| \\_|  |_|\\_\\     |_|    \\___/  \\ ___ /  |_| |_| |_| |_|  " << endl;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        Sleep(5000);
        return 0;
    }
} // end of main function
int get_num()
{
    string userInput;
    int number;
    while (true)
    {
        time_t now = time(0);               // get current calendar time
        tm *current_time = localtime(&now); // convert calender time to local time components
        string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
        cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
        cout << "\n\t\t\t\t\t\t\t\t\t    MAIN MENU \n\t\t\t\t\t\t\t\t\t   ------------";
        cout << "\n\n";
        cout << "\t  NO.        INDEX                                                                                              \n"
             << endl;
        cout << "\t  1.         ONLINE RESERVATION                                                                                 \n"
             << endl;
        cout << "\t  2.         VIEW TICKET                                                                                        \n"
             << endl;
        cout << "\t  3.         CANCEL TICKET                                                                                      \n"
             << endl;
        cout << "\t  4.         CHECK HISTORY                                                                                      \n"
             << endl;
        cout << "\t  5.         LOGOUT                                                                                             \n"
             << endl;
        cout << "\n\n\tENTER YOUR CHOICE NUMBER.... ";
        cin >> userInput;
        cin.ignore();
        if (isdigit(userInput[0]))
        {
            number = std::stoi(userInput);
            if (number >= 1 && number <= 7)
            {
                system("cls");
                break;
            }
            else
            {
                cout << "\n\tPLEASE ENTER VALID NUMBER..." << endl;
                cout << "\n\tPRESS ANY KEY TO CONTINUE...";
                if (getchar())
                    system("cls");
            }
        }
        else
        {
            cout << "\n\tPLEASE ENTER VALID NUMBER..." << endl;
            cout << "\n\tPRESS ANY KEY TO CONTINUE...";
            if (getchar())
                system("cls");
        }
    }
    return number;
} // end of get num
int choose_bus(date_wise_data array_data[], passenger &temp_passenger)
{
loop:
    system("cls");
    time_t now = time(0);               // get current calendar time
    tm *current_time = localtime(&now); // convert calender time to local time components
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    date today_date;
    today_date.dd = current_time->tm_mday;
    today_date.mm = current_time->tm_mon + 1;
    cout << "\n\t\t\t\t\t\t\t\t\t BUS ADVANCE BOOKING ";
    cout << "\n\t\t\t\t\t\t\t\t\t---------------------" << endl;
    cout << "\n\t ENTER SOURCE        :- ";
    string entered_source;
    string entered_destination;
    cin >> entered_source;
    cin.ignore();
    cout << "\n\t ENTER DESTINATION   :- ";
    cin >> entered_destination;
    cin.ignore();
    date d_journey;
    cout << "\n\t NOTE : DATE FORMATE IS DD/MM/YY . ";
    cout << "\n\n\t ENTER DATE OF JOURNEY :-";
    cin >> d_journey.dd;
    cin >> d_journey.mm;
    cin >> d_journey.yy;
    if (d_journey.yy >= (current_time->tm_year + 1900))
    {
        int resultBuses[10][2] = {0};
        int x = 0;
        int Ndate = -1;
        for (int i = 0; i < 10; i++)
        {
            if ((array_data[i].Date == d_journey) && (d_journey >= today_date))
            {
                Ndate = i;
                break;
            }
        }
        int flag = 0;
        for (int i = 0; i < 10; i++)
        {
            if (d_journey.mm == (current_time->tm_mon + 1))
            {
                if (d_journey.dd >= (current_time->tm_mday))
                {
                    flag = 1;
                    break;
                }
            }
            else if (d_journey.mm > (current_time->tm_mon + 1))
            {
                flag = 1;
                break;
            }
        }
        if (Ndate != -1 && flag == 1)
        {
            int s_point = 0;
            temp_passenger.journey_date = d_journey;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (array_data[Ndate].buses[i].main_route[j] == entered_source)
                    {
                        s_point = j;
                        for (int k = 0; k < 15; k++)
                        {
                            if (array_data[Ndate].buses[i].main_route[k] == entered_destination)
                            {
                                resultBuses[x][0] = i;
                                resultBuses[x][1] = calculate_distance(array_data[Ndate].buses[i], entered_source, entered_destination, temp_passenger);
                                x++;
                            }
                        }
                    }
                }
            }
            cout << "\n\t -----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\n\t RESULT :- \n\n";
            if (x == 0)
            {
                system("color 04");
                cout << "\t THERE IS NO DIRECT BUS AVAILABLE FROM " << entered_source << " TO " << entered_destination << endl;
                Sleep(5000);
                system("color 03");
                cout << "\n\n";
                cout << "\n\t PRESS M FOR MAIN MENU & P FOR PREVIOUS MENU ... ";
                char c;
                cin >> c;
                cin.ignore();
                if (c == 'P')
                {
                    goto loop;
                }
                else
                {
                    return 123;
                }
            }
            else
            {
                cout << "\t TOTAL TRIPS AVAILABLE  :- " << x << "\n\n";
                cout << "\t DATE OF JOURNEY        :- " << temp_passenger.journey_date.dd << "-" << temp_passenger.journey_date.mm << "-" << temp_passenger.journey_date.yy << "\n\n";
                cout << left;
                cout << setw(21) << "\t NO." << setw(20) << "ORIGIN" << setw(20) << "DESTINATION "
                     << setw(20) << "DEPARTURE TIME " << setw(20) << "FARE(INR) " << setw(20) << "DISTANCE " << "\n\n";
                d_time temp_time;
                for (int j = 0; j < x; j++)
                {
                    int i = resultBuses[j][0];
                    cout << "\t ";
                    cout << setw(20) << j + 1;
                    cout << setw(19) << array_data[Ndate].buses[i].main_route[0] << setw(20) << array_data[Ndate].buses[i].main_route[14];
                    temp_time.get_time(array_data[Ndate].buses[i].departure_time.hour, array_data[Ndate].buses[i].departure_time.minute);
                    temp_time.addMinutes(calculate_distance(array_data[Ndate].buses[i], entered_source, entered_destination, temp_passenger) * 1.5 + 60);
                    cout << temp_time.hour << ":" << (temp_time.minute < 10 ? "0" : "") << temp_time.minute;
                    cout << setw(20) << "" << setw(20) << (calculate_distance(array_data[Ndate].buses[i], entered_source, entered_destination, temp_passenger)) * 2 << setw(20) << calculate_distance(array_data[Ndate].buses[i], entered_source, entered_destination, temp_passenger) << endl
                         << endl;
                }
                cout << "\n\n";
                cout << "\t DO YOU WANT TO PROCCED FURTHER Y/N ? ";
                char c;
                cin >> c;
                cin.ignore();
                if (c == 'Y')
                {
                loop1:
                    cout << "\n\t ENTER YOUR BUS CHOICE NUMBER....";
                    int ChoiceNum;
                    cin >> ChoiceNum;
                    if (ChoiceNum > 0 && ChoiceNum <= x)
                    {
                        temp_passenger.source = entered_source;
                        temp_passenger.destination = entered_destination;
                        temp_passenger.busNum = resultBuses[ChoiceNum - 1][0];
                        temp_passenger.total_distance = resultBuses[ChoiceNum - 1][1];
                        temp_passenger.departure_time.hour = temp_time.hour;
                        temp_passenger.departure_time.minute = temp_time.minute;
                        return resultBuses[ChoiceNum - 1][0];
                    }
                    else
                    {
                        system("color 04");
                        cout << "\n\t PLEASE ENTER VALID CHOICE NUMBER...  ";
                        Sleep(2000);
                        system("color 03");
                        goto loop1;
                    }
                }
                else
                {
                    cout << "\n\t PRESS M FOR MAIN MENU & P FOR PREVIOUS MENU ... ";
                    char c;
                    cin >> c;
                    if (c == 'P')
                    {
                        goto loop;
                    }
                    else
                    {
                        return 123;
                    }
                }
            }
        }
        else
        {
            system("color 04");
            cout << "\n\t PLEASE ENTER VALID DATE...";
            Sleep(5000);
            system("color 03");
            goto loop;
        }
    }
    else
    {
        system("color 04");
        cout << "\n\t PLEASE ENTER VALID DATE...";
        Sleep(1000);
        system("color 03");
        goto loop;
    }
} // end of reserve function
int calculate_distance(Bus &bus, string &source, string &destination, passenger &temp_passenger)
{
    int total_distance = 0;
    int startingL = -1;
    int endL = -1;
    for (int j = 0; j < 15; j++)
    {
        if (bus.main_route[j] == source)
        {
            startingL = j;
        }
        if (bus.main_route[j] == destination)
        {
            endL = j;
        }
    }
    if (startingL > endL)
    {
        for (int i = startingL; i >= endL; i--)
        {
            if (endL == 0)
                total_distance += bus.main_route_km[i];
            else
                total_distance += bus.main_route_km[i - 1];
        }
        temp_passenger.path = 'R';
        return total_distance;
    }
    else
    {
        for (int i = startingL + 1; i <= endL; i++)
        {
            temp_passenger.path = 'F';
            total_distance += bus.main_route_km[i];
        }
        return total_distance;
    }
} // end of calculate_distance
int reserve(Bus &bus, Bus array_bus[], passenger &temp_passenger, passenger_history PH[])
{
    system("cls");
    time_t now = time(0);               // get current calendar time
    tm *current_time = localtime(&now); // convert calender time to local time components
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\t\t\t\t\t\t\t LOWER SEAT " << endl;
    cout << "\t\t\t\t\t\t\t -----------" << endl;
    cout << "\t\t\t   ____________________________________________________________________________________" << endl;
    cout << "\t\t\t /        |          |          |          |          |          |          |          |" << endl;
    cout << "\t\t\t|_________|    " << setw(2) << bus.array_seats[0] << "    |   " << setw(2) << bus.array_seats[1] << "     |    " << setw(2) << bus.array_seats[2] << "    |    " << setw(2) << bus.array_seats[3] << "    |    " << setw(2) << bus.array_seats[4] << "    |    " << setw(2) << bus.array_seats[5] << "    |    " << setw(2) << bus.array_seats[6] << "    |" << endl;
    cout << "\t\t\t|         |__________|__________|__________|__________|__________|__________|__________|" << endl;
    cout << "\t\t\t|                                                                                      |" << endl;
    cout << "\t\t\t|          __________ __________ __________ __________ __________ __________ __________|" << endl;
    cout << "\t\t\t|         |          |          |          |          |          |          |          |" << endl;
    cout << "\t\t\t|         |    " << setw(2) << bus.array_seats[7] << "    |   " << setw(2) << bus.array_seats[8] << "     |    " << setw(2) << bus.array_seats[9] << "    |    " << setw(2) << bus.array_seats[10] << "    |    " << setw(2) << bus.array_seats[11] << "    |    " << setw(2) << bus.array_seats[12] << "    |    " << setw(2) << bus.array_seats[13] << "    |" << endl;
    cout << "\t\t\t \\________|__________|__________|__________|__________|__________|__________|__________|" << endl;
    cout << "\n\n\n\t\t\t\t\t\t\t UPPER SEAT " << endl;
    cout << "\t\t\t\t\t\t\t ----------" << endl;
    cout << "\t\t\t   ____________________________________________________________________________________" << endl;
    cout << "\t\t\t /        |          |          |          |          |          |          |          |" << endl;
    cout << "\t\t\t|         |    " << setw(2) << bus.array_seats[14] << "    |   " << setw(2) << bus.array_seats[15] << "     |    " << setw(2) << bus.array_seats[16] << "    |    " << setw(2) << bus.array_seats[17] << "    |    " << setw(2) << bus.array_seats[18] << "    |    " << setw(2) << bus.array_seats[19] << "    |    " << setw(2) << bus.array_seats[20] << "    |" << endl;
    cout << "\t\t\t|         |__________|__________|__________|__________|__________|__________|__________|" << endl;
    cout << "\t\t\t|                                                                                      |" << endl;
    cout << "\t\t\t|          __________ __________ __________ __________ __________ __________ __________|" << endl;
    cout << "\t\t\t|         |          |          |          |          |          |          |          |" << endl;
    cout << "\t\t\t|         |    " << setw(2) << bus.array_seats[21] << "    |   " << setw(2) << bus.array_seats[22] << "     |    " << setw(2) << bus.array_seats[23] << "    |    " << setw(2) << bus.array_seats[24] << "    |    " << setw(2) << bus.array_seats[25] << "    |    " << setw(2) << bus.array_seats[26] << "    |    " << setw(2) << bus.array_seats[27] << "    |" << endl;
    cout << "\t\t\t \\________|__________|__________|__________|__________|__________|__________|__________|" << endl;
    int seat_num;
    int flag = 1;
    while (flag)
    {
        cout << "\n\n\t ENTER SEAT NUMBER :- ";
        string str;
        cin >> str;
        if (isdigit(str[0]))
        {
            seat_num = stoi(str);
            if (bus.array_seats[seat_num - 1] != "X" && seat_num < 29 && seat_num > 0)
            {
                temp_passenger.seat = seat_num - 1;
                flag = 0;
            }
        }
        else
        {
            system("color 04");
            cout << "\n\t ENTER VALID NUMBER ... " << endl;
            Sleep(1000);
            system("color 03");
        }
    }
    system("cls");
    bus.totalP++;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\t\t\t\t\t\tPASSENGER DETAIL" << endl;
    cout << "\t\t\t\t\t\t----------------" << endl;
    cout << "\n\n\n";
    cout << "\t\tNAME           : ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "\n";
    temp_passenger.get_pname(name);
    int flag1 = 1;
    string email;
    while (flag1)
    {
        cout << "\t\tEMAIL          : ";
        cin >> email;
        if (!verifyEmail(email))
        {
            system("color 04");
            cout << "\n\t\tINVALID EMAIL...\n"
                 << endl;
            Sleep(5000);
            system("color 03");
        }
        else
        {
            flag1 = 0;
        }
    }
    temp_passenger.get_email(email);
    cout << "\n";
    string num;
    flag1 = 1;
    while (flag1)
    {
        cout << "\t\tMOBILE NUMBER  : ";
        cin >> num;
        cout << "\n";
        if (!verifyMonum(num))
        {
            system("color 04");
            cout << "\tINVALID MOBILE NUMBER...\n"
                 << endl;
            Sleep(5000);
            system("color 03");
        }
        else
        {
            flag1 = 0;
        }
    }
    temp_passenger.get_num(num);
    int age;
    cout << "\t\tAGE            : ";
    cin >> age;
    cout << "\n";
    temp_passenger.get_age(age);
    char ch;
    flag1 = 1;
    while (flag1)
    {
        cout << "\t\tGENDER (M/F/O) : ";
        cin >> ch;
        cout << "\n";
        if (!verifyGen(ch))
        {
            system("color 04");
            cout << "\tINVALID GENDER TYPE(M,F,O)\n"
                 << endl;
            Sleep(5000);
            system("color 03");
        }
        else
        {
            flag1 = 0;
        }
    }
    temp_passenger.get_gender(ch);
    cin.ignore();
    cout << "\n\n\t\tPRESS Y FOR PAYMENT....";
    char ch1;
    cin >> ch1;
    if (ch1 == 'Y')
    {
        if (payment(temp_passenger, array_bus))
        {
            stringstream ss;
            ss << temp_passenger.show_name();
            string file_name = ss.str() + ".txt";
            fstream outputFile(file_name, ios::out);
            if (!outputFile.is_open())
            {
                cout << "\n\t Error opening file !";
            }
            outputFile << "\n\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
            outputFile << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
            outputFile << "\n\t NAME          : " << temp_passenger.show_name() << endl;
            outputFile << "\n\t SEAT          : " << temp_passenger.seat + 1 << endl;
            outputFile << "\n\t JOURNEY FROM  : " << temp_passenger.source << endl;
            outputFile << "\n\t JOURNEY TO    : " << temp_passenger.destination << endl;
            outputFile << "\n\t JOURNEY DATE  : " << temp_passenger.journey_date.dd << "-" << temp_passenger.journey_date.mm << "-" << temp_passenger.journey_date.yy << endl;
            outputFile << "\n\t TOTAL FARE    : " << temp_passenger.fees << endl;
            outputFile << "\n\n";
            bus.p[temp_passenger.seat] = temp_passenger;
            (PH[0].n)++;
            PH[PH[0].n].passengers = &(bus.p[temp_passenger.seat]);
            bus.array_seats[temp_passenger.seat] = "X";
            outputFile.close();
            fstream Data("data.txt", ios::app | ios::out);
            Data << "\n"
                 << temp_passenger.path << " ";
            Data << temp_passenger.journey_date.dd << " ";
            Data << temp_passenger.journey_date.mm << " ";
            Data << temp_passenger.journey_date.yy << " ";
            Data << temp_passenger.busNum << " ";
            Data << temp_passenger.show_name() << " ";
            Data << temp_passenger.show_age() << " ";
            Data << temp_passenger.show_email() << " ";
            Data << temp_passenger.show_mobile_no() << " ";
            Data << temp_passenger.show_gender() << " ";
            Data << temp_passenger.source << " ";
            Data << temp_passenger.destination << " ";
            Data << temp_passenger.seat << " ";
            Data << temp_passenger.total_distance;
            Data.close();
        }
        else                               
        {
            system("cls");
            system("color 04");
            cout << "\n\n\n\n\n\n\t PAYMENT FAILED .... ";
            Sleep(2000);
            system("color 03");
        }
    }
    return 0;
} // end of reserve function
bool payment(passenger &temp_passenger, Bus array_bus[])
{
    system("cls");
    time_t now = time(0);               // get current calendar time
    tm *current_time = localtime(&now); // convert calender time to local time components
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\n\t\t\t\t\t\t\t RESERVATION VOUCHER  \n\t\t\t\t\t\t\t---------------------" << endl;
    cout << "\t   JOURNEY FROM    : " << array_bus[temp_passenger.busNum].main_route[0] << endl;
    cout << "\t   JOURNEY TO      : " << array_bus[temp_passenger.busNum].main_route[14] << endl;
    cout << "\t   DEPARTURE TIME  : ";
    temp_passenger.departure_time.print();
    cout << "\t   JOURNEY DATE    : " << temp_passenger.journey_date.dd << "-" << temp_passenger.journey_date.mm << "-" << temp_passenger.journey_date.yy << endl;
    cout << "\t   SEAT NO/S       : " << temp_passenger.seat + 1;
    cout << "\n\n\t\t\t\t\t\t\t PASSENGER INFORMATION  \n\t\t\t\t\t\t\t-----------------------" << endl;
    cout << "\t   NAME            : " << temp_passenger.show_name() << endl;
    cout << "\t   AGE             : " << temp_passenger.show_age() << endl;
    cout << "\t   EMAIL           : " << temp_passenger.show_email() << endl;
    cout << "\t   MOBILE NUMBER   : " << temp_passenger.show_mobile_no() << endl;
    cout << "\t   GENDER          : " << temp_passenger.show_gender() << endl;
    cout << "\t   SOURCE          : " << temp_passenger.source << endl;
    cout << "\t   DESTINATION     : " << temp_passenger.destination << endl;
    cout << "\n\t\t\t\t\t\t\t TOTAL FARE DETAILS    \n\t\t\t\t\t\t\t--------------------" << endl;
    cout << "\t   BASIC FARE      : " << (temp_passenger.total_distance) * 2 << endl;
    cout << "\t   RESERVATION FEE : 5 " << endl;
    cout << "\t   TOLL FEE        : 28 " << endl;
    cout << "\t   DISCOUNTS       : 3 " << endl;
    cout << "\n\t   TOTAL FARE      : " << ((temp_passenger.total_distance) * 2) + 5 + 28 - 3 << endl;
    temp_passenger.fees = ((temp_passenger.total_distance) * 2) + 5 + 28 - 3;
    (array_bus[temp_passenger.busNum].totalP)++;
    array_bus[temp_passenger.busNum].array_seats[temp_passenger.seat + 1] = "X";
    cout << "\n\n\n\t PAYMENT DONE ? Y/N ? ";
    string str;
    cin.ignore();
    getline(cin, str);
    if (str[0] == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
} // endl  of payment function
int view(date_wise_data array_data[])
{
loop:
    string vname;
    date entered_date;
    time_t now = time(0);               // get current calendar time
    tm *current_time = localtime(&now); // convert calender time to local time components
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\n\t\t\t\t\t\t\t\t\t VIEW TICKET \n\t\t\t\t\t\t\t\t\t-------------" << endl;
    cout << "\t\tNAME           : ";
    getline(cin, vname);
    int flag1 = 1;
    cout << "\n\t\tJOURNEY DATE     : ";
    cin >> entered_date.dd >> entered_date.mm >> entered_date.yy;
    string num;
    flag1 = 1;
    while (flag1)
    {
        cout << "\n\t\tMOBILE NUMBER  : ";
        cin >> num;
        cout << "\n";
        if (!verifyMonum(num))
        {
            system("color 04");
            cout << "\n\t\tInvalid mobile number. Please enter a valid mobile number.\n"
                 << endl;
            Sleep(2000);
            system("color 03");
        }
        else
        {
            flag1 = 0;
        }
    }
    int res0 = 123;
    int res1 = 123;
    int res2 = 123;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 28; k++)
            {
                if (array_data[i].buses[j].p[k].show_name() == vname)
                {
                    if (array_data[i].buses[j].p[k].show_mobile_no() == num)
                    {
                        if (array_data[i].buses[j].p[k].journey_date == entered_date)
                        {
                            res0 = i;
                            res1 = j;
                            res2 = k;
                        }
                    }
                }
            }
        }
    }
    system("cls");
    if (res0 == 123 && res1 == 123 && res2 == 123)
    {
        system("color 04");

        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
        cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
        cout << "\n\n\t\t\t\t\t\t\t\t\t VIEW TICKET \n\t\t\t\t\t\t\t\t\t-------------" << endl;
        cout << "\n\n\n\n\n\n\t NO DATA FOUND...";
        Sleep(2000);
        system("color 03");
        return 0;
    }
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\n\t\t\t\t\t\t\t RESERVATION VOUCHER  \n\t\t\t\t\t\t\t---------------------" << endl;
    cout << "\t   JOURNEY FROM    : " << array_data[res0].buses[res1].main_route[0] << endl;
    cout << "\t   JOURNEY TO      : " << array_data[res0].buses[res1].main_route[14] << endl;
    cout << "\t   DEPARTURE TIME  : ";
    array_data[res0].buses[res1].departure_time.print();
    cout << "\n\t   NO. OF SEATS    : " << 1 << endl;
    cout << "\t   JOURNEY DATE    : " << array_data[res0].buses[res1].p[res2].journey_date.dd << "-" << array_data[res0].buses[res1].p[res2].journey_date.mm << "-" << array_data[res0].buses[res1].p[res2].journey_date.yy << endl;
    cout << "\t   SEAT NO/S       : " << array_data[res0].buses[res1].p[res2].seat + 1;
    cout << "\n\n\t\t\t\t\t\t\t PASSENGER INFORMATION  \n\t\t\t\t\t\t\t-----------------------" << endl;
    cout << "\t   NAME            : " << array_data[res0].buses[res1].p[res2].show_name() << endl;
    cout << "\t   AGE             : " << array_data[res0].buses[res1].p[res2].show_age() << endl;
    cout << "\t   EMAIL           : " << array_data[res0].buses[res1].p[res2].show_email() << endl;
    cout << "\t   MOBILE NUMBER   : " << array_data[res0].buses[res1].p[res2].show_mobile_no() << endl;
    cout << "\t   GENDER          : " << array_data[res0].buses[res1].p[res2].show_gender() << endl;
    cout << "\t   SOURCE          : " << array_data[res0].buses[res1].p[res2].source << endl;
    cout << "\t   DESTINATION     : " << array_data[res0].buses[res1].p[res2].destination << endl;
    cout << "\n\t\t\t\t\t\t\t TOTAL FARE DETAILS    \n\t\t\t\t\t\t\t--------------------" << endl;
    cout << "\t   BASIC FARE      : " << (array_data[res0].buses[res1].p[res2].total_distance) * 2 << endl;
    cout << "\t   RESERVATION FEE : 5 " << endl;
    cout << "\t   TOLL FEE        : 28 " << endl;
    cout << "\t   DISCOUNTS       : 3 " << endl;
    cout << "\n\t   TOTAL FARE      : " << ((array_data[res0].buses[res1].p[res2].total_distance) * 2) + 5 + 28 - 3 << endl;
    cout << "\n\n\t PRESS B FOR BACK AND V VIEW TICKET .....";
    char ch;
    cin >> ch;
    cin.ignore();
    if (ch == 'V')
    {
        goto loop;
    }
    else
    {
        return 0;
    }
} // end of view function
int cancel(date_wise_data array_data[])
{
    string vname;
    date journey_date;
    time_t now = time(0);               // get current calendar time
    tm *current_time = localtime(&now); // convert calender time to local time components
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\n\t\t\t\t\t\t\t\t\t CANCEL HISTORY \n\t\t\t\t\t\t\t\t\t----------------" << endl;
    cout << "\t\tNAME           : ";
    getline(cin, vname);
    int flag1 = 1;
    string num;
    date entered_date;
    cout << "\n\t\tJOURNEY DATE   : ";
    cin >> entered_date.dd >> entered_date.mm >> entered_date.yy;
    cout << "\n";
    flag1 = 1;
    while (flag1)
    {
        cout << "\t\tMOBILE NUMBER  : ";
        cin >> num;
        cout << "\n";
        if (!verifyMonum(num))
        {
            system("color 04");
            cout << "\tInvalid mobile number. Please enter a valid mobile number.\n"
                 << endl;
            Sleep(5000);
            system("color 03");
        }
        else
        {
            flag1 = 0;
        }
    }
    int res0 = 123;
    int res1 = 123;
    int res2 = 123;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 28; k++)
            {
                if (array_data[i].buses[j].p[k].show_name() == vname && array_data[i].buses[j].p[k].show_mobile_no() == num && array_data[i].buses[j].p[k].journey_date == entered_date)
                {
                    res0 = i;
                    res1 = j;
                    res2 = k;
                }
            }
        }
    }
    if (res1 != 123 && res2 != 123)
    {
        fstream record("data.txt", ios::in | ios::out);
        passenger temp_passenger;
        fstream tempFile("temp.txt", ios::app | ios::out);
        record.clear();
        record.seekg(0);
        fstream cancel_file("cancel.txt", ios::app | ios::out);
        while (record >> temp_passenger.path >> temp_passenger.journey_date.dd >> temp_passenger.journey_date.mm >> temp_passenger.journey_date.yy >> temp_passenger.busNum >> temp_passenger.name >> temp_passenger.age >> temp_passenger.email >> temp_passenger.mobile_no >> temp_passenger.gender >> temp_passenger.source >> temp_passenger.destination >> temp_passenger.seat >> temp_passenger.total_distance)
        {
            if (!(array_data[res0].buses[res1].p[res2].path == temp_passenger.path && array_data[res0].buses[res1].p[res2].journey_date == temp_passenger.journey_date && array_data[res0].buses[res1].p[res2].busNum == temp_passenger.busNum && array_data[res0].buses[res1].p[res2].show_name() == temp_passenger.name && temp_passenger.mobile_no == temp_passenger.mobile_no))
            {
                tempFile << temp_passenger.path << " " << temp_passenger.journey_date.dd << " " << temp_passenger.journey_date.mm << " " << temp_passenger.journey_date.yy << " " << temp_passenger.busNum << " " << temp_passenger.name << " " << temp_passenger.age << " " << temp_passenger.email << " " << temp_passenger.mobile_no << " " << temp_passenger.gender << " " << temp_passenger.source << " " << temp_passenger.destination << " " << temp_passenger.seat << " " << temp_passenger.total_distance << endl;
            }
            else
            {
                cancel_file << temp_passenger.path << " " << temp_passenger.journey_date.dd << " " << temp_passenger.journey_date.mm << " " << temp_passenger.journey_date.yy << " " << temp_passenger.busNum << " " << temp_passenger.name << " " << temp_passenger.age << " " << temp_passenger.email << " " << temp_passenger.mobile_no << " " << temp_passenger.gender << " " << temp_passenger.source << " " << temp_passenger.destination << " " << temp_passenger.seat << " " << temp_passenger.total_distance << endl;
            }
        }
        record.close();
        tempFile.close();
        cancel_file.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
        array_data[res0].buses[res1].array_seats[array_data[res0].buses[res1].p[res2].seat] = array_data[res0].buses[res1].p[res2].seat + 1;
        array_data[res0].buses[res1].p[res2].seat = 0;
        array_data[res0].buses[res1].p[res2].busNum = 0;
        array_data[res0].buses[res1].p[res2].source = '\0';
        array_data[res0].buses[res1].p[res2].destination = '\0';
        array_data[res0].buses[res1].p[res2].journey_date.get_date(0, 0, 0);
        array_data[res0].buses[res1].p[res2].departure_time.get_time(0, 0);
        array_data[res0].buses[res1].p[res2].payment = false;
        array_data[res0].buses[res1].p[res2].fees = 0;
        array_data[res0].buses[res1].p[res2].get_age(0);
        array_data[res0].buses[res1].p[res2].get_email(" ");
        array_data[res0].buses[res1].p[res2].get_pname(" ");
        array_data[res0].buses[res1].p[res2].get_gender('0');
        array_data[res0].buses[res1].p[res2].get_num("0");
        array_data[res0].buses[res1].totalP--;
        cout << "\n\t\t DATA SUCCESSFULLY REMOVED..." << endl;
        Sleep(4000);
    }
    else
    {
        system("color 04");
        cout << "\n\n\t NO DATA FOUND ... " << endl;
        Sleep(4000);
        system("cls");
        system("color 03");
        return 0;
    }
}
void history(passenger_history ph[])
{
    system("cls");
    time_t now = time(0);               // get current calendar time
    tm *current_time = localtime(&now); // convert calender time to local time components
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec;
    cout << "  " << (current_time->tm_mday) << '-' << (current_time->tm_mon + 1) << '-' << current_time->tm_year + 1900 << "  " << days[current_time->tm_wday];
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t HISTORY " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t---------" << endl;
    for (int i = 1; i <= ph[0].n; i++)
    {
        (ph[i].passengers)->display();
        cout << "\n";
    }
    if (ph[0].n == 0)
    {
        system("cls");
        system("color 04");
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t HISTORY " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t---------" << endl;
        cout << "\n\n\n\t NO DATA FOUND...";
        Sleep(2500);
        system("color 03");
    }
    Sleep(2500);
}
