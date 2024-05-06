#include "common.h"

TraceValidator::TraceValidator(string s)
{
    Parse(s);
}

void TraceValidator::Parse(string s)
{
    WIN32_FIND_DATA data;
    HANDLE h = FindFirstFile((s+"/*").c_str(), &data);
    if (h != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (string(data.cFileName) == "." || string(data.cFileName) == "..") continue;
                else Parse(s + "/" + data.cFileName);
            }
            else
            {
                ifstream f(s + "/" + data.cFileName);
                //map<int, int> hitCount;

                while (f.good())
                {
                    char Line[4096];
                    f.getline(Line, 4096);
                    if (*(int*)Line == '    ')
                    {
                        string line = Line;
                        Content c;
                        int offset = line.substr(line.find(':')).find_last_of('_');
                        string hash = line.substr(line.find(':')).substr(offset);
                        hash = hash.substr(1,hash.find(']') - 1);
                        string name = line.substr(line.find(':')).substr(1, offset - 1);
                        
                        int sum = 0;
                        for (int i = 0; i < hash.size(); i++)
                            sum = sum * 16 + ((hash[i] < 'A') ? hash[i] - '0' : hash[i] - 'A' + 10);
                        c.hash = sum;
                        c.name = name;

                        //hitCount[sum]++;
                        this->data[s + "/" + data.cFileName][sum].count++;
                        this->data[s + "/" + data.cFileName][sum].name = name;
                        this->data[s + "/" + data.cFileName][sum].hash = sum;
                    }
                }
            }
        } while (FindNextFile(h, &data));
    }
}

TraceValidatorIterator::TraceValidatorIterator(map<string, map<int, Content>>::iterator it)
{
    this->it = it;
}

TraceValidatorIterator TraceValidator::begin()
{
    return TraceValidatorIterator(data.begin());
}

TraceValidatorIterator TraceValidator::end()
{
    return TraceValidatorIterator(data.end());
}

map<string, map<int, Content>>::iterator TraceValidatorIterator::operator->()
{
    return it;
}

pair<string, map<int, Content>> TraceValidatorIterator::operator*()
{
    return *it;
}

map<string, map<int, Content>>::iterator TraceValidatorIterator::operator++()
{
    return ++it;
}

bool TraceValidatorIterator::operator==(const TraceValidatorIterator& it)
{
    return this->it == it.it;
}

bool TraceValidatorIterator::operator!=(const TraceValidatorIterator& it)
{
    return this->it != it.it;
}