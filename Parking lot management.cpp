#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <unistd.h>

using namespace std;
void printCentered(const std::string &text)
{
    int terminalWidth = 110;
    int padding = (terminalWidth - text.length()) / 2;

    for (int i = 0; i < padding; i++)
    {
        std::cout << " ";
    }
    cout << text << endl;
}
void loading()
{
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    printCentered("Loading.....Please Wait For a While!");
    cout<<"\t\t\t\t\t\t\t\t\t"<<flush;
    for (int i=0; i<4; i++)
    {
        sleep(1);
        cout << "." <<flush;
    }
    system("cls");
}
struct Node
{
    string data;
    Node* next;
    Node(string value)
    {
        data = value;
        next = nullptr;
    }
};

int main()
{
    bool nice=false;
    int row,col,ticket,total=0;
    cout<<endl<<endl<<endl;
    printCentered("WELCOME TO SUMYAH MONIR'S PARKING LOT MANAGEMENT SYSTEM");
    cout<<endl<<endl<<endl;
    printCentered("Enter the number of rows in your Parking Lot: ");
    cout<<"\t\t\t\t\t\t\t\t";
    cin>>row;
    cout<<endl<<endl;
    printCentered("Enter the number of columns in your Parking Lot: ");
    cout<<"\t\t\t\t\t\t\t\t";
    cin>>col;
    cout<<endl<<endl;
    printCentered("Set the entry fee(tk): ");
    cout<<"\t\t\t\t\t\t\t\t";
    cin>>ticket;
    loading();
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    printCentered("The Parking Lot is "+to_string(row)+"x"+to_string(col));
    Node* head=nullptr;
    int car_waiting=0;
    vector<stack<string>>parking(col);
    stack<string>temp;
    string Size=to_string(row*col);
    queue<string>token;

    for(int i=1; i<=row*col; i++)
    {
        string tempo=to_string(i);
        string S=string((Size.size()-tempo.size()),'0')+tempo;
        token.push(S);
    }
    string doo ((col*(Size.size()+3))+1,'-');
    int cont=0;

    while(1)
    {
        vector<vector<string>>serial(col,vector<string>(row,string(Size.size(),' ')));
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        for(int i=0; i<col; i++)
        {
            temp=parking[i];
            while(!temp.empty())
            {
                serial[i][temp.size()-1]=temp.top();
                temp.pop();
            }
        }
        cout<<doo<<endl;
        for(int j=0; j<row; j++)
        {
            cout<<"|";
            for(int i=0; i<col; i++)
            {
                cout<<string((Size.size()+2),' ')<<"|";
            }
            cout<<"\n|";
            for(int i=0; i<col; i++)
            {
                cout<<" "<<serial[i][j]<<" "<<"|";
            }
            cout<<"\n|";
            for(int i=0; i<col; i++)
            {
                cout<<string(Size.size()+2,' ')<<"|";
            }
            cout<<endl<<endl;
        }
        int p;
there:
        cout<<"Choose next action:\n1.Enter a car\n2.Exit a car\n3.Details\n4.Exit\n";
        cin>>p;
        vector <string>List;
        int slot=0;
        if(p==1)
        {
            car_waiting++;
        }
        else if(p==2)
        {
            string t;
            cout<<"Enter the token of the car which wants to exit: ";
            cin>>t;
            bool flag = true;
            for (int i = 0; i < col && flag; i++)
            {
                for (int j = 0; j < row && flag; j++)
                {
                    if (serial[i][j] == t) flag = false;
                }
            }
            if (flag)
            {
                printCentered("The Token " +t + " doesn't exist.");
                goto there;
            }
            Node* Visiter = head;
            if (head == nullptr)
            {
                head = new Node(t);
            }
            else
            {
                while (Visiter->next != nullptr)
                {
                    Visiter = Visiter->next;
                }
                Visiter->next = new Node(t);
            }
            bool con = true;

            while (con)
            {
                con = false;
                Visiter = head;
                Node* prev = nullptr;

                while (Visiter != nullptr)
                {
                    bool found = false;

                    for (int i = 0; i < col; i++)
                    {
                        if (!parking[i].empty() && Visiter->data == parking[i].top())
                        {
                            if (prev == nullptr)
                            {
                                head = Visiter->next;
                                delete Visiter;
                                Visiter = head;
                            }
                            else
                            {
                                prev->next = Visiter->next;
                                delete Visiter;
                                Visiter = prev->next;
                            }
                            List.push_back(parking[i].top());
                            token.push(parking[i].top());
                            parking[i].pop();
                            serial[i][parking[i].size()]=string(Size.size(),' ');
                            found = true;
                            con = true;
                            nice=true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        prev = Visiter;
                        Visiter = Visiter->next;
                    }
                }
            }
        }
        else if(p==3)
        {

            for (int i = 0; i < col ; i++)
            {
                for (int j = 0; j < row ; j++)
                {
                    if (serial[i][j] != string(Size.size(),' '))slot++;
                }
            }
        }
        else if(p==4)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl;
            printCentered("Total Cars Entered: "+to_string(total)+"  Total Earning: "+to_string(total*ticket)+"tk");
            cout<<endl<<endl<<endl;
            printCentered("------------------Thank you------------------");
            cout<<endl<<endl<<endl<<endl<<endl<<endl;
            break;
        }
        else
        {
            printCentered("Not a valid option");
            goto there;
        }
        system("cls");
        cout<<endl<<endl<<endl<<endl;
        if(p==3)
        {
            printCentered("Filled Slots: "+to_string(slot));
            printCentered("Empty Slots: "+to_string((col*row)-slot));
        }
        if(List.size()!=0)
        {
            string ex="Exited Tokens: ";
            for (const string& token : List)
            {
                ex+= token+", ";
            }
            printCentered(ex);
        }
        else printCentered("No Car Exited.");
        if(head==nullptr)printCentered("No car is wanting to exit.");
        else
        {
            string ex="The Cars waiting to exit ";
            Node* Visiter=head;
            while(Visiter!=nullptr)
            {
                ex+=Visiter->data+", ";
                Visiter=Visiter->next;
            }
            printCentered(ex);
        }
        List.clear();
        if(car_waiting)
        {
            if(nice)
            {
                cout<<doo<<endl;

                for(int j=0; j<row; j++)
                {
                    cout<<"|";
                    for(int i=0; i<col; i++)
                    {
                        cout<<string((Size.size()+2),' ')<<"|";
                    }
                    cout<<"\n|";
                    for(int i=0; i<col; i++)
                    {
                        cout<<" "<<serial[i][j]<<" "<<"|";
                    }
                    cout<<"\n|";
                    for(int i=0; i<col; i++)
                    {
                        cout<<string(Size.size()+2,' ')<<"|";
                    }
                    cout<<endl<<endl;
                }
                nice=false;
            }
            for(int j=0; j<row && car_waiting; j++)
            {
                for(int i=0; i<col && car_waiting; i++)
                {
                    if(serial[i][j]==string(Size.size(),' '))
                    {
                        parking[i].push(token.front());
                        List.push_back(token.front());
                        token.pop();
                        car_waiting--;
                        total++;
                    }
                }
            }
            if(List.size()!=0)
            {
                string ex = "The New Vehicle with token ";
                for(string h:List)ex+=h+", ";
                ex+="entered";
                printCentered(ex);
            }
            else printCentered("No Vehicle entered.");
            List.clear();
        }
        if(car_waiting!=0)printCentered("The parking lot is full! and "+to_string(car_waiting)+" new cars are waiting in queue.");
        else printCentered("No New Cars to enter!");
        printCentered("Total Cars Entered: "+to_string(total)+"  Total Earning: "+to_string(total*ticket)+"tk");
    }
    return 0;
}

