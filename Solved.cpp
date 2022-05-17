#include <iostream>
#include <ctime>
using namespace std;

void detectOneBorderless(int myArray[][6]);
void defaultProblem();
int createArray(int number);

int main()
{
    int selection;
    cout << "*****************************************\n*\tPlease select\t\t\t*\n*\t1->Solve default problem\t*\n*\t2->Create array and solve\t*\n*****************************************" << endl;
    cin >> selection;
    switch (selection)
    {
    case 1:
        defaultProblem();
        break;
    case 2:
        int arrayLength;
        cout << "Please enter the number array" << endl;
        cin >> arrayLength;
        createArray(arrayLength);
        break;
    default:
        cout<<"Wrong select"<<endl;
        break;
    }
    return 0;
}
void defaultProblem()
{
    int problemArry[6][6] = {1, 0, 0, 0, 0, 0,
                               0, 1, 0, 1, 1, 1,
                               0, 0, 1, 0, 1, 0,
                               1, 1, 0, 0, 1, 0,
                               1, 0, 1, 1, 0, 0,
                               1, 0, 0, 0, 0, 1,};
    cout<<"Problem array="<<endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout<<problemArry[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<"Solved array="<<endl;
    detectOneBorderless(problemArry);
}
int createArray(int arrayLength)
{
    //Array create
    int myArray[arrayLength][arrayLength] = {0};
    srand(time(0));
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayLength; j++)
        {
            int randomNumber = rand() % 2;
            myArray[i][j] = randomNumber;
        }
    }
    cout<<"Created array=\n"<<endl;
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayLength; j++)
        {
            cout << myArray[i][j] << ",";
        }
        cout << endl;
    }
    cout<<endl;
    cout<<"Solved array"<<endl;
    //SOLVE
    int protectOnes[arrayLength][arrayLength] = {};
    // TOP Search
    for (int j = 0; j < arrayLength; j++)
    {
        if (myArray[j][0] == 1)
        {
            for (int i = 0; i < arrayLength; i++)
            {
                if (myArray[j][i] == 1)
                {
                    protectOnes[j][i] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    // Left Search
    for (int i = 0; i < arrayLength; i++)
    {
        if (myArray[0][i] == 1)
        {
            for (int j = 0; j < arrayLength; j++)
            {
                if (myArray[j][i] == 1)
                {
                    protectOnes[j][i] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    } 
    // Bottom Search
    for (int i = arrayLength-1; i > -1; i--)
    {
        if (myArray[arrayLength-1][i] == 1)
        {
            for (int j = arrayLength-1; j > -1; j--)
            {
                if (myArray[j][i] == 1)
                {
                    protectOnes[j][i] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    // Right Search
    for (int i = 0; i < arrayLength; i++)
    {
        if (myArray[i][arrayLength-1] == 1)
        {
            for (int j = arrayLength-1; j > -1; j--)
            {
                if (myArray[i][j] == 1)
                {
                    protectOnes[i][j] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    // Protect Search
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayLength; j++)
        {
            if (protectOnes[i][j] == 1)
            {
                // Left Search
                if (j > 0)
                {
                    for (int a = j; a > 0; a--)
                    {
                        if (myArray[i][a] == 1)
                        {
                            protectOnes[i][a] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // Right Search
                if (j < arrayLength)
                {
                    for (int a = j; a < arrayLength; a++)
                    {
                        if (myArray[i][a] == 1)
                        {
                            protectOnes[i][a] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // Top Search
                if (i > 0)
                {
                    for (int a = i; a > 0; a--)
                    {
                        if (myArray[a][j] == 1)
                        {
                            protectOnes[a][j] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // Bottom Search
                if (i < arrayLength)
                {
                    for (int a = i; a < arrayLength; a++)
                    {
                        if (myArray[a][j] == 1)
                        {
                            protectOnes[a][j] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    // Convert Zero
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayLength; j++)
        {
            if (protectOnes[i][j] != 1)
            {
                myArray[i][j] = 0;
            }
        }
    }
    // write screen
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = 0; j < arrayLength; j++)
        {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }




    return myArray[arrayLength][arrayLength];
}
void detectOneBorderless(int myArray[][6])
{
    int protectOnes[6][6] = {};
    // TOP Search
    for (int j = 0; j < 6; j++)
    {
        if (myArray[j][0] == 1)
        {
            for (int i = 0; i < 6; i++)
            {
                if (myArray[j][i] == 1)
                {
                    protectOnes[j][i] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    // Left Search
    for (int i = 0; i < 6; i++)
    {
        if (myArray[0][i] == 1)
        {
            for (int j = 0; j < 6; j++)
            {
                if (myArray[j][i] == 1)
                {
                    protectOnes[j][i] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    // Bottom Search
    for (int i = 5; i > -1; i--)
    {
        if (myArray[5][i] == 1)
        {
            for (int j = 5; j > -1; j--)
            {
                if (myArray[j][i] == 1)
                {
                    protectOnes[j][i] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    // Right Search
    for (int i = 0; i < 6; i++)
    {
        if (myArray[i][5] == 1)
        {
            for (int j = 5; j > -1; j--)
            {
                if (myArray[i][j] == 1)
                {
                    protectOnes[i][j] = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    // Protect Search
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (protectOnes[i][j] == 1)
            {
                // Left
                if (j > 0)
                {
                    for (int a = j; a > 0; a--)
                    {
                        if (myArray[i][a] == 1)
                        {
                            protectOnes[i][a] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // Right Search
                if (j < 6)
                {
                    for (int a = j; a < 6; a++)
                    {
                        if (myArray[i][a] == 1)
                        {
                            protectOnes[i][a] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // Top Search
                if (i > 0)
                {
                    for (int a = i; a > 0; a--)
                    {
                        if (myArray[a][j] == 1)
                        {
                            protectOnes[a][j] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // Bottom Search
                if (i < 6)
                {
                    for (int a = i; a < 6; a++)
                    {
                        if (myArray[a][j] == 1)
                        {
                            protectOnes[a][j] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    // Convert Zero
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (protectOnes[i][j] != 1)
            {
                myArray[i][j] = 0;
            }
        }
    }
    // write screen
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }
}