#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> id;  
    vector<string> name;  

    int n;
    cout << "How many students ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tempId;
        string tempName;

        cout << "\n fill up  student " << i + 1 << " ID: ";
        cin >> tempId;

        cout << " fill up student " << i + 1 << " Name: ";
        cin >> tempName;

        id.push_back(tempId);
        name.push_back(tempName);
    }

    cout << "\nStudent List\n";
    for (int i=0; i < n; i++)
    {
        cout << "ID: " << id[i]
             << "  Name: " << name[i] << endl;
    }

    return 0;
}
