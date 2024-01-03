// NOTE: maaf kak, aku belum bisa tampilin grafiknya, ada error yg aku masih bingung cara ngatasinnya gimana.

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#include "Matrix.h"
#include "Swerve.h"
#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

float v_xFunction(float time){
    return 48*cos(time)*sin(time)*sin(time);
};

float v_yFunction(float time){
    return 4*sin(4*time) + 6*sin(3*time) + 10*sin(2*time) -13*sin(time);
};

float omegaFunction(float time){
    return 0;
};

float resultan(float compX, float compY){
    float a;
    a = pow(compX,2) + pow(compY, 2);
    return pow(a,0.5);
};

int main() {
    Swerve object1;
    vector<float> xs;
    vector<float> ys;
    vector<float> v1;
    vector<float> v2;
    vector<float> v3;
    vector<float> v4;
    vector<float> t;

    for (int i = 0; i <= 630; i++){
        float k;
        k = float(i)/float(100);
        object1.set_v_x(v_xFunction(k));
        object1.set_v_y(v_yFunction(k));
        object1.set_omega(omegaFunction(k));
        object1.velocityCommand(v_xFunction(k),v_yFunction(k),omegaFunction(k));
        object1.updatePose(k);

        xs.push_back(object1.x);
        ys.push_back(object1.y);
        v1.push_back(resultan(object1.v_1x,object1.v_1y));
        v2.push_back(resultan(object1.v_2x,object1.v_2y));
        v3.push_back(resultan(object1.v_3x,object1.v_3y));
        v4.push_back(resultan(object1.v_4x,object1.v_4y));
        t.push_back(k);
    }

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    // Pembuatan grafik
    DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);
    // Simpan grafik dalam format PNG
    vector<double> *pngdata = ConvertToPNG(imageReference->image);
    WriteToFile(pngdata, "grafik_y_terhadap_x.png"); // simpan nama file "grafik_y_terhadap_x"
    DeleteImage(imageReference->image);
    FreeAllocations();

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    // Pembuatan grafik
    DrawScatterPlot(imageReference, 600, 400, &t, &v1, errorMessage);
    // Simpan grafik dalam format PNG
    vector<double> *pngdata = ConvertToPNG(imageReference->image);
    WriteToFile(pngdata, "grafik_v1_terhadap_time.png"); // simpan nama file "grafik_v1_terhadap_time"
    DeleteImage(imageReference->image);
    FreeAllocations();

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    // Pembuatan grafik
    DrawScatterPlot(imageReference, 600, 400, &t, &v2, errorMessage);
    // Simpan grafik dalam format PNG
    vector<double> *pngdata = ConvertToPNG(imageReference->image);
    WriteToFile(pngdata, "grafik_v2_terhadap_time.png"); // simpan nama file "grafik_v2_terhadap_time"
    DeleteImage(imageReference->image);
    FreeAllocations();

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    // Pembuatan grafik
    DrawScatterPlot(imageReference, 600, 400, &t, &v3, errorMessage);
    // Simpan grafik dalam format PNG
    vector<double> *pngdata = ConvertToPNG(imageReference->image);
    WriteToFile(pngdata, "grafik_v3_terhadap_time.png"); // simpan nama file "grafik_v3_terhadap_time"
    DeleteImage(imageReference->image);
    FreeAllocations();

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    // Pembuatan grafik
    DrawScatterPlot(imageReference, 600, 400, &t, &v4, errorMessage);
    // Simpan grafik dalam format PNG
    vector<double> *pngdata = ConvertToPNG(imageReference->image);
    WriteToFile(pngdata, "grafik_v4_terhadap_time.png"); // simpan nama file "grafik_v4_terhadap_time"
    DeleteImage(imageReference->image);
    FreeAllocations();

    return 0;
}
