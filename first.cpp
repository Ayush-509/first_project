#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
map <string, vector<string> > users;
class reg_u{
    protected:
        string name,username,dob,password,phone_no,pin_code;
    public:
        reg_u(){}
        reg_u(string a,string b,string c,string d,string e,string f){
            name = a;
            username = b;
            dob = c;
            phone_no = d;
            pin_code = e;
            password = f;
            vector <string> l;
            l.push_back(password);
            l.push_back(name);
            l.push_back(dob);
            l.push_back(phone_no);
            l.push_back(pin_code);
            users[username] = l;
            cout<<"User registered successfully"<<endl<<endl;
        }
        void display(){
            cout<<"Displaying details of user"<<endl<<endl;
            cout<<"Name of user : "<<name<<endl;
            cout<<"DOB of user : "<<dob<<endl;
            cout<<"Phone number of user : "<<phone_no<<endl;
            cout<<"Pin-Code of user : "<<pin_code<<endl<<endl;
        }
};

class login_u : public reg_u{
    protected:
        string check_username,check_password;
        int c = 0;    
    public:
        login_u(){
            cout<<endl<<"Enter username : ";
            cin>> check_username;
            cout<<"Enter password : ";
            cin>> check_password;
            map <string,vector<string>> :: iterator i;
            for (i = users.begin() ; i != users.end() ; i ++){
                if ((i->first) == check_username && ((i->second)[0]) == check_password){
                    c = 1;
                }
            }
        }
        void display(void){
            map <string,vector<string>> :: iterator i;
            for (i = users.begin() ; i != users.end() ; i ++){
                if ((i->first) == check_username && ((i->second)[0]) == check_password){
                    cout<<endl<<"User logged in"<<endl;
                    cout<<"Displaying details of user"<<endl;
                    cout<<"Name of user : "<<((i->second)[1])<<endl;
                    cout<<"DOB of user : "<<((i->second)[2])<<endl;
                    cout<<"Phone number of user : "<<((i->second)[3])<<endl;
                    cout<<"Pin-Code of user : "<<((i->second)[4])<<endl;
                }
            }
            if (c == 0){
                cout<<"User not found, to register the user, press 1"<<endl<<endl;
            }
        }
        void check(void){
            if (c == 1){
                cout<<endl<<"User exists"<<endl<<endl;
            }
            else{
                cout<<endl<<"User does not exists"<<endl<<endl;
            }
        }
        void remove(void){
            if (c == 1){
                users.erase(check_username);
                cout<<"User deleted"<<endl<<endl;
            }
            else{
                cout<<"User does not exists"<<endl<<endl;
            }
        }  
};



int main(){
    
    while (true) {
        int c;
        cout<<"Enter your choice"<<endl;
        cout<<"1.Register user"<<endl;
        cout<<"2.Login user"<<endl;
        cout<<"3.Show user list"<<endl;
        cout<<"4.Search user"<<endl;
        cout<<"5.Delete user"<<endl;
        cout<<"6.Exit"<<endl;
        cin>>c;
        if (c == 1){
            string n,u,d,p,pc,ps;
            cout<<"Enter name of user : ";
            cin>>n;
            cout<<"Enter username : ";
            cin>>u;
            cout<<"Enter dob of user : ";
            cin>>d;
            cout<<"Enter phone number of user : ";
            cin>>p;
            cout<<"Enter pin-code of user : ";
            cin>>pc;
            cout<<"Enter password : ";
            cin>>ps;
            reg_u a(n,u,d,p,pc,ps);
        }
        else if (c==2){
            login_u b;
            b.display();
        }
        else if (c==3){
            cout<<"The list of users are as follows : "<<endl<<endl;
            map <string,vector<string>> :: iterator i;
            for (i = users.begin() ; i != users.end() ; i ++){
                cout<<i->first<<endl;
            }
        }
        else if (c==4){
            login_u c;
            c.check();
        }
        else if (c==5){
            login_u d;
            d.remove();
            cout<<endl;
        }
        else {
            break;
        }
    }
    cout<<endl<<"Thank You for visiting"<<endl;
    return 0;
}