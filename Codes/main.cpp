/******************************
 *  Author  :   YangRongBao
 *  Date    :   2021.3
******************************/

#include <iostream>
#include <QCoreApplication>
#include <QFile>
#include <QIODevice>
#include <QString>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication YHTriangle(argc, argv);

    cout << "Please input your lines:";
    int inputLines;
    cin >> inputLines;
    if(inputLines <= 2 || inputLines > 68)
    {
        cout << "Over range!";
        return 0;
    }
    else
    {
        cout << "calculating" << endl;
        quint64 yhTriangle[inputLines][inputLines];
        yhTriangle[0][0] = 1;
        yhTriangle[1][0] = 1;
        yhTriangle[1][1] = 1;
        for(int i = 2; i < inputLines; ++i)
        {
            yhTriangle[i][0] = 1;
            for(int j = 1; j < i + 1; ++j)
            {
                yhTriangle[i][j] = yhTriangle[i - 1][j - 1] + yhTriangle[i - 1][j];
            }
            yhTriangle[i][i] = 1;
        }
        QFile file("triangle.txt");
        QTextStream inputStream(&file);
        if(!file.open(QIODevice::WriteOnly))
        {
            file.open(QIODevice::NewOnly);
        }
        file.close();
        if(file.open(QIODevice::WriteOnly))
        {
            for(int i = 0; i < inputLines; ++i)
            {
                for(int j = 0; j < i + 1; ++j)
                {
                    inputStream << yhTriangle[i][j] << " ";
                }
                inputStream << "\n";
            }
        }
        file.close();
        cout << "Result has been saved in \"triangle.txt\".";
    }

    return YHTriangle.exec();
}

