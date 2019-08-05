#include <iostream>

using namespace std;
class Hotel
{
 public:
     string name_of_client;
     string city;
     string room;
     int phone_no;
     int no_of_days;
     int bill;
     int no_of_facilities;
     static int total_amount;


    Hotel(){
     phone_no=0;
     no_of_days=0;
      bill=0;
      no_of_facilities=0;
      }

     void get()
     {
         cout<<"Enter the name of client-";
         cin>>name_of_client;
         cout<<"Enter the phone no. of client-";
         cin>>phone_no;
         cout<<"Enter the city-";
         cin>>city;
         cout<<"---------------\n";

     }
      void addservice(int amt)
    {
        bill += amt;
        total_amount += amt;
        no_of_facilities++;
    }
      void setclientroom(int code)
    {
        if (code == 1)
        {
            room = "dlx";
            addservice(2000);
        }
        if (code == 2)
        {
            room = "normal";
            addservice(1000);
        }
    }

   static int getTotalfunds()
   {
       return total_amount;
   }
     string getname()
     {
         return name_of_client;
     }
     string getcity()
     {
         return city;
     }
     int getphone_no()
     {
         return phone_no;
     }
     int getdays()
     {
         return no_of_days;
     }
     int getbill()
     {
         return bill;
     }
     int getfacilities()
     {
         return no_of_facilities;
     }
     int getamount()
     {
         return total_amount;
     }
     string getroom()
      {
    return room;
      }
     void disp()
     {
         cout<<"Name of client:"<<name_of_client<<endl;
         cout<<"Name of city:"<<city<<endl;
         cout<<"Phone no.:"<<phone_no<<endl;
     }
};
     int Hotel::total_amount = 0;

int main()
{
    int choice=0;
    int count;
    int selected_customer=0;
    int total_customers=0;
    int largest_bill=0;
    Hotel arr[2];
    for(int i=0;i<2;i++)
    {
        arr[i].get();
    }
     do
    {
        cout << "0. Exit" << endl;
        cout << "1. Select Client" << endl;
        cout << "2. Get Clients From Patiala and Chandigarh And Name Starting with 'n'" << endl;
        cout << "3. Get Deluxe Room Customer Names" << endl;
        cout << "4. Total Funds collected today" << endl;
        cout << "5. Get client with largest Bill" << endl;
        cin >> choice;

    switch(choice)

  {
  case 1:
     cout << "S.no\tName\tCity\tPhone\tBill" << endl;
            for (int i = 0; i <2; i++)
            {
                cout << i + 1 << "\t" << arr[i].getname() << "\t" << arr[i].getcity() << "\t" << arr[i].getphone_no()<<"\t"<<arr[i].getbill() << endl;
            }
            cin >> selected_customer;
            selected_customer--;
             cout << "1. Allot Room to " << arr[selected_customer].getname() << endl;
            cout << "2. Add Lunch =Rs100" << endl;
            cout << "3. Add Breakfast =Rs100" << endl;
            cout << "4. Add Dinner =Rs100" << endl;
            cout << "5. Add Internet =Rs100" << endl;
            cout << "6. Add Laundary =Rs100" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1: // Allot Room;
                cout << "1. Deluxe Rs 2000 per day" << endl;
                cout << "2. Normal Rs 1000 per day" << endl;
                cin >> choice;
                 switch (choice)
                {
                case 1: // dlx code - 1;
                    arr[selected_customer].setclientroom(1);
                    cout << "Deluxe Room has been Added \n Bill = " << arr[selected_customer].getbill() << endl;
                    break;
                case 2: // Normal code - 2;
                    arr[selected_customer].setclientroom(2);
                    cout << "Normal Room has been Added \n Bill = " << arr[selected_customer].getbill() << endl;

                    break;
                }
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                arr[selected_customer].addservice(100);
            }

            break;

 case 2:
    for(int i=0;i<2;i++)
    {
    if((arr[i].getcity()=="pataiala" || arr[i].getcity()=="chd") && arr[i].getname()[0]=='n'|| arr[i].getname()[0]=='N' )
    arr[i].disp();
    }
    break;
  case 3: //Get Deluxe Room Cutomer Names
            for (int i = 0; i < 2; i++)
            {
                if (arr[i].getroom() == "dlx")
                {
                    cout << arr[i].getname() << "\t" << arr[i].getcity() << endl;
                }
            }
            break;
        case 4: //Total Funds collected today
            cout << "Total Funds: " << Hotel::getTotalfunds() << endl;
            break;
        case 5: // Get client with largest Bill
            count = 0;
            largest_bill = arr[0].getbill();
            for (int i = 0; i < 2; i++)
            {
                if (arr[i].getbill() > largest_bill)
                {
                    largest_bill = arr[i].getbill();
                    count++;
                }
            }
            cout << "Largest Bill: " << arr[count].getname() << "\tRs." << arr[count].getbill() << endl;
            break;
        }
  }
    while(choice!=0);
}




