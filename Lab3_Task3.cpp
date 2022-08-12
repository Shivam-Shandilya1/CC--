#include <bits/stdc++.h>
using namespace std;

template <typename DataType>
class List
{
    private:
        // Total length of list, to be initialized in the constructor
        int length;

        // Position of the cursor
        int cursorPosition;

        // Total number of elements that are currently in the list
        int numberOfElements;

        // The list in the form of a vector. You can also use an array here
        vector<DataType> array;

        vector<DataType> PrefixSumArray;

    public:
        // Constructor
        List(int listSize);
        void insert(const DataType &newDataItem);
        void remove();
        void replace(const DataType &newDataItem);
        void clear();
        bool isEmpty();
        bool isFull();
        void gotoBeginning();
        void gotoEnd();
        bool gotoNext();
        bool gotoPrior();
        DataType getCursor();
        void showStructure();
        void createPrefixSumArray();
        DataType subArraySum(int left, int right);
};

// Notice how we specify the template parameter since List is a class Template
template <typename DataType>
List<DataType>::List(int listSize)
{
    // easy way to set the size of a vector in C++. All values get inilized to zero.
    array.resize(listSize);

    // setting the length variable to the length of the array
    length = listSize;

    // setting the cursor position to -1 because there are no elements in the list yet.
    cursorPosition = -1;

    // currently there are no elements in the list
    numberOfElements = 0;
}

template <typename DataType>
void List<DataType>::insert(const DataType &newDataItem)
{
    // shifting all the necessary elements to the right
    for (int i = numberOfElements - 1; i > cursorPosition; i--)
        array[i + 1] = array[i];

    array[cursorPosition + 1] = newDataItem;
    cursorPosition++;
    numberOfElements++;
}

template <typename DataType>
void List<DataType>::remove()
{
    // shifting required elements to the left
    for (int i = cursorPosition; i < numberOfElements - 1; i++)
        array[i] = array[i + 1];

    if (cursorPosition == numberOfElements - 1)
        cursorPosition = 0;
    else
        cursorPosition++;
    numberOfElements--;
}

template <typename DataType>
void List<DataType>::replace(const DataType &newDataItem)
{
    array[cursorPosition] = newDataItem;
}

template <typename DataType>
void List<DataType>::clear()
{
    // easy way to clear vectors in C++
    array.clear();

    // however, this sets the size to 0, so we reset the size
    array.resize(length);
}

template <typename DataType>
bool List<DataType>::isEmpty()
{
    return numberOfElements == 0;
}

template <typename DataType>
bool List<DataType>::isFull()
{
    return numberOfElements == length;
}

template <typename DataType>
void List<DataType>::gotoBeginning()
{
    cursorPosition = 0;
}

template <typename DataType>
void List<DataType>::gotoEnd()
{
    cursorPosition = numberOfElements - 1;
}

template <typename DataType>
bool List<DataType>::gotoNext()
{
    if (cursorPosition == numberOfElements - 1)
        return false;

    else
    {
        cursorPosition++;
        return true;
    }
}

template <typename DataType>
bool List<DataType>::gotoPrior()
{
    if (cursorPosition == 0)
        return false;

    else
    {
        cursorPosition--;
        return true;
    }
}

template <typename DataType>
DataType List<DataType>::getCursor()
{
    return array[cursorPosition];
}

template <typename DataType>
void List<DataType>::showStructure()
{
    if (numberOfElements == 0)
    {
        cout << "Empty List\n";
        return;
    }

    else
    {
        // note that this only works for data types compatible with std::cout
        cout << "The number of elements in the list is " << numberOfElements << endl;
        for (int i = 0; i < numberOfElements; i++)
            cout << array[i] << endl;
    }
}

template <typename DataType>
void List<DataType>::createPrefixSumArray()
{
    DataType sum=0;
    for(int i=0;i<length;i++)
    {
        sum+=array[i];
        PrefixSumArray.push_back(sum);
    }
}

template <typename DataType>
DataType List<DataType>::subArraySum(int left, int right)
{
    if(left!=1)
        return PrefixSumArray[right-1]-PrefixSumArray[left-2];
    else    
        return PrefixSumArray[right-1];
}

int main() 
{
    List<int> tempList(5);
    tempList.insert(6);
    tempList.insert(1);
    tempList.insert(4);
    tempList.insert(8);
    tempList.insert(3);
    tempList.createPrefixSumArray();
    cout<<tempList.subArraySum(1, 3)<<endl;
    cout<<tempList.subArraySum(1, 5)<<endl;
    cout<<tempList.subArraySum(4, 5)<<endl;
    cout<<tempList.subArraySum(1, 1)<<endl;
    cout<<tempList.subArraySum(2, 4)<<endl;
}