#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

double history[100][2];
int historyIndex = 0;
int historyIndexMax = 0;

void lokasi(){
    cout << "LOKASI SAAT INI -> (" << fixed << setprecision(2) << history[historyIndex][0] << ", " << history[historyIndex][1] << ")\n";
};

void gerak(double x, double y){
    history[historyIndex+1][0] = history[historyIndex][0] + x;
    history[historyIndex+1][1] = history[historyIndex][1] + y;
    if (historyIndexMax == historyIndex)
    {
        historyIndexMax += 1;
    };
    historyIndex += 1;
    lokasi();
};

void gerak_2(double v, double t, double theta){
    history[historyIndex+1][0] = history[historyIndex][0] + v*t*cos(theta* M_PI / 180.0);
    history[historyIndex+1][1] = history[historyIndex][1] + v*t*sin(theta* M_PI / 180.0);
    if (historyIndexMax == historyIndex)
    {
        historyIndexMax += 1;
    };
    historyIndex += 1;
    lokasi();
};

void undo(){
    if (historyIndex == 0)
    {
        cout << "Tidak dapat undo!" << endl;
    } else
    {
        historyIndex -= 1;
        cout << "Undo berhasil" << endl;
    }; 
    lokasi();
};

void redo(){
    if (historyIndex < historyIndexMax)
    {
        historyIndex += 1;
        cout << "Redo berhasil" << endl;
    } else
    {
        cout << "Tidak dapat redo" << endl;
    };
    lokasi();
};

void save(){
    ofstream file("save.txt");
    if (file.is_open()){
        file << history[historyIndex][0] << " " << history[historyIndex][1];
        file.close();
        cout << "Save berhasil"<< endl;
    } else{
        cout << "Save gagal" << endl;
    };
};

void load(){
    ifstream file("save.txt");
    if (file.is_open()){
        file >> history[0][0] >> history[0][1];
        file.close();
        cout << "Load berhasil"<< endl;
    } else{
        cout << "Load gagal" << endl;
    }
};

int main()
{
    bool kondisi = true;
    while(kondisi){
        cout << "--------------------------------------------" << endl;
        cout << "       PILIH FUNGSI YANG DIINGINKAN         " << endl;
        cout << "--------------------------------------------" << endl;
        cout << "1. lokasi()                                 " << endl;
        cout << "2. gerak(double x, double y)                " << endl;
        cout << "3. gerak_2(double v, double t, double theta)" << endl;
        cout << "4. undo()                                   " << endl;
        cout << "5. redo()                                   " << endl;
        cout << "6. save()                                   " << endl;
        cout << "7. load()                                   " << endl;
        cout << "8. exit()                                   " << endl;
        cout << "--------------------------------------------" << endl;
        cout << "MASUKKAN NOMOR FUNGSI: ";

        int nomor;
        cin >> nomor;
        cout << "--------------------------------------------" << endl;

        if(nomor == 8){
            cout << "PROGRAM SELESAI" << endl;
            kondisi = false;
        }
        else if (nomor == 1)
        {
            lokasi();
        }
        else if (nomor == 2)
        {
            double x,y ;
            cout << "Masukkan nilai x (double): ";
            cin >> x ;
            
            cout << "Masukkan nilai y (double): ";
            cin >> y ;
            cout << "--------------------------------------------" << endl;

            gerak(x,y);
        }
        else if (nomor == 3)
        {
            double v,t,theta;
            cout << "Masukkan nilai v (double): ";
            cin >> v ;
            cout << "Masukkan nilai t (double): ";
            cin >> t ;
            cout << "Masukkan nilai theta (double): ";
            cin >> theta ;
            cout << "--------------------------------------------" << endl;   

            gerak_2(v,t,theta);
        }
        else if (nomor == 4){
            undo();
        }
        else if (nomor == 5){
            redo();
        }
        else if (nomor == 6){
            save();
        }
        else if (nomor == 7){
            load();
        };

        cout << "--------------------------------------------" << endl;
        cout << "\n\n";
    };
    return 0;
};


