#include "MiniDB.h"

int main()
{
    MiniDB dbupc;
    dbupc.reading("covid.csv", 's');
    dbupc.ShowValues();
    cin.get();
    return 0;
}