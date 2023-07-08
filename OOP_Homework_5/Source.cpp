#include <iostream>
#include <vector>
#include <string>
using namespace std;

#pragma region First
/*template<typename T>
class Vector
{
public:
    void push(const T& element)
    {
        data.push_back(element);
    }

    Vector<T> sort()
    {
        Vector<T> sortedVector(*this);  // copy current vector
        sortedVector = sort(sortedVector);
        return sortedVector;
    }

    static Vector<T> sort(Vector<T> vector)
    {
        bool swapped;
        int n = vector.data.size();
        for (int i = 0; i < n - 1; ++i)
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (vector.data[j] > vector.data[j + 1])
                {
                    swap(vector.data[j], vector.data[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
        return vector;
    }

    void print()
    {
        for (const T& element : data)
            cout << element << " ";
        cout << endl;
    }
private:
    vector<T> data;
};*/
#pragma endregion

#pragma region Second
class User
{
public:
    int id;
    string firstName;
    string lastName;
    string phoneNumber;

    User(int id, const string& firstName, const string& lastName, const string& phoneNumber)
        : id(id), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber) {}
};

class Vector
{
public:
    void createUser(int id, const string& firstName, const string& lastName, const string& phoneNumber) 
    {
        User newUser(id, firstName, lastName, phoneNumber);
        data.push_back(newUser);
    }

    void displayUsers() 
    {
        for (const User& user : data)
            cout << "ID: " << user.id << ", Name: " << user.firstName << " " << user.lastName << ", Phone: " << user.phoneNumber << endl;
    }

    void updateUser(int id, const string& newPhoneNumber)
    {
        for (User& user : data)
        {
            if (user.id == id)
            {
                user.phoneNumber = newPhoneNumber;
                cout << "User with ID " << id << " updated successfully." << endl;
                return;
            }
        }
        cout << "User with ID " << id << " not found." << endl;
    }

    void deleteUser(int id)
    {
        for (auto it = data.begin(); it != data.end(); ++it) 
        {
            if (it->id == id) 
            {
                data.erase(it);
                cout << "User with ID " << id << " deleted successfully." << endl;
                return;
            }
        }
        cout << "User with ID " << id << " not found." << endl;
    }

    void sortById() 
    {
        for (size_t i = 0; i < data.size() - 1; ++i)
        {
            for (size_t j = 0; j < data.size() - i - 1; ++j)
            {
                if (data[j].id > data[j + 1].id)
                    swap(data[j], data[j + 1]);
            }
        }
        cout << "Users sorted by ID." << endl;
    }
private:
    vector<User> data;
};
#pragma endregion

int main() 
{
    // FIRST

    /*Vector<int> myVector;
    myVector.push(5);
    myVector.push(3);
    myVector.push(9);
    myVector.push(0);
    cout << "Original vector: ";
    myVector.print();
    Vector<int> sortedVector = myVector.sort();
    cout << "Sorted vector: ";
    sortedVector.print();*/

    // SECOND

    Vector userVector;

    userVector.createUser(2, "Ivan", "Tretiakov", "1234567890");
    userVector.createUser(3, "Ken", "Landy", "9876543210");
    userVector.createUser(1, "Norman", "Gerhert", "777777777777");

    cout << "Current Users: " << endl;
    userVector.displayUsers();
    cout << endl;

    userVector.updateUser(2, "888888888888");
    userVector.deleteUser(3);
    userVector.sortById();
    cout << "Users after sorting: " << endl;
    userVector.displayUsers();

    system("pause");

    return 0;
}
