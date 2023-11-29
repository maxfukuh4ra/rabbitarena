#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

#include "History.h"
#include "globals.h"

using namespace std;


History::History(int nRows, int nCols)
{
    // constructor initializes private variables
    m_rows = nRows;
    m_cols = nCols;
    
    // initialize and make the entire grid into '.' as all rabbits start as unpoisoned
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
            m_grid[r][c] = 0;
    }
    
}

// called when a rabbit starts its turn poisoned but not dead, so adds count for that cell with ++
bool History::record(int r, int c)
{
    bool retvalue;
    
    if (r < 1 || r > m_rows || c > m_cols || c < 1)
        retvalue = false;
    else
    {
        m_grid[r-1][c-1]++;
        retvalue = true;
    } 
    return retvalue;
}

void History::display() const
{
    // clear the screen
    clearScreen();
    
    // convert the history grid as char instead of int with '.' and 'A' - 'Z'
    char displayedGrid[MAXROWS][MAXCOLS];
    
    // traverse through the 2D array of rows and cols
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
        {
            if (m_grid[r][c] == 0)
            {
                displayedGrid[r][c] = '.';
            }
            else if (m_grid[r][c] >= 1 && m_grid[r][c] <= 25)
            {
                displayedGrid[r][c] = m_grid[r][c] - 1 + 'A';
            }
            else if (m_grid[r][c] >= 26)
            {
                displayedGrid[r][c] = 'Z';
            }
        }
    }
    
    // display the history grid now as the converte char array
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
        {
            cout << displayedGrid[r][c];
        }
        cout << endl; // new line for each row after that column is done
    }
    
    // writes an empty line after history grid
    cout << endl;
}
