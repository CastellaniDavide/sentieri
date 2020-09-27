/**
 * @file sentieri.cpp
 *
 * @version 01.01 2020-9-27
 *
 * @brief https://training.olinfo.it/#/task/sentieri/statement
 *
 * @ingroup sentieri
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

// Variabiles
int N, A, B, i, temp1, temp2;
vector< vector<int> > sentieri;
vector<int> value;
queue<int> todo;

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    /*
    8 5 9
    1 5
    3 5
    3 4
    4 6
    7 8

    1 2
    1 3
    2 3
    1 6
    5 6
    5 4
    4 8
    6 8
    6 7

    8 5 9 1 5 3 5 3 4 4 6 7 8 1 2 1 3 2 3 1 6 5 6 5 4 4 8 6 8 6 7
    */

    // Input
    cin >> N >> A >> B;
    sentieri.resize(A + B);
    value.resize(N);

    for(i = 0; i < A + B; ++i)
    {
        cin >> temp1 >> temp2;
        sentieri[i].push_back(temp1 - 1);
        sentieri[i].push_back(temp2 - 1);
        if(i < A)
            sentieri[i].push_back(0);
        else
            sentieri[i].push_back(1);
        //cout << sentieri[i][0] << "\t" << sentieri[i][1] << "\t" << sentieri[i][2] << endl;
    }

    for(i = 0; i < N; ++i)
        value[i] = INT_MAX;
    // Code
    // ...
    todo.push(0);
    value[0] = 0;
    while(!todo.empty())
    {
        for(i = 0; i < A + B; ++i)
        {
            if(sentieri[i][0] == todo.front() && value[sentieri[i][1]] > value[sentieri[i][0]] + 1)
            {
                value[sentieri[i][1]] = value[sentieri[i][0]] + 1;
                todo.push(sentieri[i][1]);
            }
            else if(sentieri[i][1] == todo.front() && value[sentieri[i][0]] > value[sentieri[i][1]] + 1)
            {
                value[sentieri[i][0]] = value[sentieri[i][1]] + 1;
                todo.push(sentieri[i][0]);
            }
        }
        todo.pop();
    }

    // Output
    cout << value[N-1] << endl;

    // End
    return 0;
}
