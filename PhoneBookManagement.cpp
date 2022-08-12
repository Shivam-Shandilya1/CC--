#include <bits/stdc++.h>
using namespace std;

// Phone Book Data Element
class Data
{
private: 
    string name;
    string number;

public:
    Data()
    {
        name = "";
        number = "";
    }
    Data(string a, string b)
    {
        name = a;
        number = b;
    }
    string &getName()
    {
        return name;
    }
    string &getNumber()
    {
        return number;
    }
    void setName(string &a)
    {
        name = a;
    }
    void setNumber(string &a)
    {
        number = a;
    }
};

// Node
class Node
{
private:
    Data elem;
    Node *next;
    Node *prev;
    friend class DoubleLinkedList;
};

// Doubly Linked List
class DoubleLinkedList
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void add(bool, string, string);
    bool checkDuplicate(string s, string n);
    void modify();
    void remove(bool, int, string str);
    void search();
    void print();
    void isEmpty();
    void numberOfContacts();

private:
    Node *head;
};

// Success Message Function
void success()
{
    cout << endl;
    cout << "Contact list is successfully updated!! Desired changes has been made!!" << endl;
    cout << endl;
    return;
}

// Constructor
DoubleLinkedList::DoubleLinkedList() : head(NULL) {}

// Destructor
DoubleLinkedList::~DoubleLinkedList()
{
}

// Check Duplicate
bool DoubleLinkedList::checkDuplicate(string s, string n)
{
    Node *temp = head;
    while (temp != NULL)
    {
        string name = (temp->elem).getName();
        string number = (temp->elem).getNumber();
        if (name == s)
        {
            cout << endl;
            cout << "Contact with similar name already exists." << endl;
            return true;
        }
        if (number == n)
        {
            cout << endl;
            cout << "Contact with similar number already exists." << endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Validate the number
// bool validateNumber(string &str)
// {
//     bool ans = true;
//     for (char const &c : str)
//     {
//         if (std::isdigit(c) == 0)
//         {
//             ans = false;
//             break;
//         }
//     }
//     if (str.size() != 10)
//         ans = false;
//     if (ans == false)
//         cout << "Invalid Number!! A number must be 10 digits long containting 0-9 digits." << endl;

//     return ans;
// }
// Add Contact
void DoubleLinkedList ::add(bool modify, string a, string b)
{
    string nam, no;
    if (!modify)
    {
        cout << "Enter Name:\t";
        cin.ignore();
        getline(cin, nam);
        cout << "Enter Number:\t";
        cin >> no;
        transform(nam.begin(), nam.end(), nam.begin(), ::toupper);
        // if (validateNumber(no) == false)
            // return;
    }
    if (modify)
        nam = a, no = b;
    if (checkDuplicate(nam, no) == true)
    {
        cout << "Contact Already exists with that Name/Number.Wanna Update?" << endl;
        return;
    }
    Node *newNode = new Node();
    newNode->elem.setName(nam);
    newNode->elem.setNumber(no);

    Node *temp = head;

    // Insertion
    if (head == NULL)
    {
        // At head
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        // In between
        string s1;
        Node *tempLast = temp;
        while (temp != NULL)
        {
            s1 = temp->elem.getName();
            if (s1 > nam)
            {
                if (temp->prev != NULL)
                    temp->prev->next = newNode;
                else
                    head = newNode;
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev = newNode;
                if (!modify)
                    success();
                return;
            }
            temp = temp->next;
            if (temp != NULL)
                tempLast = temp;
        }
        // At end
        temp = tempLast;
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
    }
    if (!modify)
        success();
}

// Modify Contact
void DoubleLinkedList ::modify()
{
    int choice;
    while (true)
    {
        cout << "Choose Your Approach for Modification:-" << endl;
        cout << "1): Modify By Name" << endl;
        cout << "2): Modify By Number" << endl;
        cout << "3): Back to Main Menu" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Please Enter the name of the contact: \t";
            break;
        }
        else if (choice == 2)
        {
            cout << "Please Enter the number of the contact: \t";
            break;
        }
        else if (choice == 3)
        {
            return;
        }
        else
        {
            cout << "Invalid choice. Please try again" << endl;
            cout << endl;
            continue;
        }
    }
    string s;
    cin.ignore();
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    // if (choice == 2)
    // {
    //     if (validateNumber(s) == false)
    //         return;
    // }
    bool found = false;
    Node *temp = head;
    while (temp != NULL)
    {
        string name = (temp->elem).getName();
        string number = (temp->elem).getNumber();
        if (choice == 1)
        {
            if (name == s)
            {
                cout << "Contact Found!!" << endl;
                cout << "Name\t" << s << endl;
                cout << "Number\t" << number << endl;
                found = true;
                break;
            }
        }
        else if (choice == 2)
        {
            if (number == s)
            {
                cout << endl;
                cout << "Contact Found!!" << endl;
                cout << "Name\t" << name << endl;
                cout << "Number\t" << number << endl;
                found = true;
                break;
            }
        }
        temp = temp->next;
    }
    if (!found)
    {
        if (choice == 1)
            cout << "Contact with name " << s << " does not exist.Wanna ADD?" << endl;
        if (choice == 2)
            cout << "Contact with number " << s << " does not exist.Wanna ADD?" << endl;
        return;
    }
    else
    {

        string name, num;
        cout << "Enter new Name:\t";
        // cin.ignore();
        getline(cin, name);
        cout << "Enter new Number:\t";
        cin >> num;

        transform(name.begin(), name.end(), name.begin(), ::toupper);
        // if (validateNumber(s) == false)
        //     return;
        remove(true, choice, s);
        add(true, name, num);
        success();
    }
}
// Delete Contact
void DoubleLinkedList ::remove(bool modify, int ch, string str)
{
    int choice;
    string s;
    if (!modify)
    {

        while (true)
        {
            cout << "How do you want to Delete the contact? Choose one option" << endl;
            cout << "Enter 1: Delete By Name" << endl;
            cout << "Enter 2: Delete By Number" << endl;
            cout << "Enter 3: Back to Main Menu" << endl;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Please Enter the name of the contact: \t";
                break;
            }
            else if (choice == 2)
            {
                cout << "Please Enter the number of the contact: \t";
                break;
            }
            else if (choice == 3)
                return;
            else
            {
                cout << "Invalid choice. Please try again" << endl;
                cout << endl;
                continue;
            }
        }
        cin.ignore();
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    Node *temp = head;
    if (modify)
    {
        choice = ch;
        s = str;
    }
    while (temp != NULL)
    {
        string name = (temp->elem).getName();
        string number = temp->elem.getNumber();
        if (choice == 1)
        {
            if (name == s)
            {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                delete temp;
                if (!modify)
                    success();
                return;
            }
        }
        else if (choice == 2)
        {
            if (number == s)
            {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                delete temp;
                if (!modify)
                    success();
                return;
            }
        }
        temp = temp->next;
    }
    if (choice == 1)
        cout << "Contact with name " << s << " does not exist." << endl;
    if (choice == 2)
        cout << "Contact with number " << s << " does not exist." << endl;
    return;
}

// Search Contact
void DoubleLinkedList ::search()
{
    int choice;
    while (true)
    {
        cout << "How do you want to search the contact? Choose one option:-" << endl;
        cout << "1): Search By Name" << endl;
        cout << "2): Search By Number" << endl;
        cout << "3): Back to Main Menu" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Please Enter the name of the contact: \t";
            break;
        }
        else if (choice == 2)
        {
            cout << "Please Enter the number of the contact: \t";
            break;
        }
        else if (choice == 3)
            return;
        else
        {
            cout << "Invalid choice. Please try again" << endl;
            cout << endl;
            continue;
        }
    }
    string s;
    cin.ignore();
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    // if (choice == 2)
    //     if (validateNumber(s) == false)
    //         return;

    Node *temp = head;
    while (temp != NULL)
    {
        string name = (temp->elem).getName();
        string number = temp->elem.getNumber();
        if (choice == 1)
        {
            if (name == s)
            {
                cout << "Contact Found!!" << endl;
                cout << "Name\t" << s << endl;
                cout << "Number\t" << number << endl;
                return;
            }
        }
        else if (choice == 2)
        {
            if (number == s)
            {
                cout << endl;
                cout << "Contact Found!!" << endl;
                cout << "Name\t" << name << endl;
                cout << "Number\t" << number << endl;
                return;
            }
        }
        temp = temp->next;
    }
    if (choice == 1)
        cout<<"Contact Not Found By Name: "<< s <<"\nTry to Search with Number.\nOtherwise, Add a new Contact."<<endl;
    if (choice == 2)
        cout<<"Contact Not Found By Number: "<< s <<"\nTry to Search with Name.\nOtherwise, Add a new Contact."<<endl;
    return;
}

// Print Contact List
void DoubleLinkedList::print()
{
    Node *temp = head;
    cout << "Name\t\t\t\tNumber" << endl;
    while (temp != NULL)
    {
        string name = (temp->elem).getName();
        string number = (temp->elem).getNumber();
        cout << name << "\t\t\t\t" << number << endl;
        temp = temp->next;
    }
    cout << endl;
    cout << "Your contact list is successfully printed!!" << endl;
}

// IsEmpty()
void DoubleLinkedList::isEmpty()
{
    if (head == NULL)
        cout << "No Contact Found!! Your PhoneBook is Empty" << endl;
    else
        cout << "Contacts Found!! Your PhoneBook is NOT Empty" << endl;
    return;
}

// Total Number of Contacts
void DoubleLinkedList::numberOfContacts()
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt == 1)
        cout << "Total " << cnt << " contact is present in your contact list." << endl;
    else
        cout << "Total " << cnt << " contacts are present in your contact list." << endl;
}

void instructions()
{
    cout << endl;
    cout << "We offer the following services" << endl;
    cout << "Enter 1: Add Contact" << endl;
    cout << "Enter 2: Modify Contact" << endl;
    cout << "Enter 3: Delete Contact" << endl;
    cout << "Enter 4: Search Contact" << endl;
    cout << "Enter 5: Print Contact List" << endl;
    cout << "Enter 6: Check if PhoneBook is empty" << endl;
    cout << "Enter 7: Total number of Contacts present in PhoneBook" << endl;
    cout << "Enter 8: Print Instructions Again" << endl;
    cout << "Enter 0: End the program" << endl;

    return;
}

int main()
{
    DoubleLinkedList contactList;
    cout << endl
         << endl;
    cout << "Hi!, I am SVS Tech Bot. I am programmed to serve you as a PhoneBook." << endl;
    char sol = '*';
    

    while (sol!='0')
    {
        instructions();
        cout << endl;
        cout << "Please choose one of the options: ";
        cin >> sol;
        cout << endl;
        switch(sol)
        {
            case '1': contactList.add(false, "", ""); break;
            case '2': contactList.modify(); break;
            case '3': contactList.remove(false, -1, ""); break;
            case '4': contactList.search(); break;
            case '5': contactList.print(); break;
            case '6': contactList.isEmpty(); break;
            case '7': contactList.numberOfContacts(); break;
            case '8': break;
            case '0':{
            cout << "Thank for using me. I hope you liked me!" << endl;
            cout << "Bye!" << endl;
            break;
            }
            default:
            { 
            cout << "You pressed the wrong key. Please try again." << endl;
            cout << "You are back in Main Menu!!" << endl;
            break;
            }
        }

    }

    return 0;
}