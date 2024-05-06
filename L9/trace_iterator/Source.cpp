#include "common.h"

int main()
{
    TraceValidator validator("traces");

    for (auto [fname, content] : validator)
    {
        cout << fname << endl;
        for (auto [hash, content] : content)
        {
            if (content.count > 100)
                cout << "\t" << hex << hash << " " << content.name << " " << content.count << endl;
        }
    }

    return 0;
}

