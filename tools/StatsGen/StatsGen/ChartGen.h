#ifndef __CHARTGEN_H
#define __CHARTGEN_H
#include <iostream>
#include "discpp.h"
#include <string>

struct DisLin {
    int drawLvl (double *y2, std::string fileName, std::string titleStr, std::string xAxisName, std::string yAxisName)
    { 
        double xray[6]  = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0},
            y1ray[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

        double maxY=0;
        for (int i=0; i<6; i++) {
            if (y2[i]>maxY) {
                maxY = y2[i];
            }
        }
        Dislin g;
        g.setfil(fileName.c_str());
        g.filmod("delete");
        //g.setpag ("da4p");
        g.window(30, 30, 707, 500);
        g.metafl("gif");
        //g.metafl ("cons");

        g.imgfmt("RGB");
        g.disini ();
        g.pagfll(255);
        g.pagera ();
        g.hwfont ();

        g.titlin (titleStr.c_str(), 2);
        g.htitle (60);
        g.height(45);
        g.shdpat (16);
    
        g.axspos (400, 1800);
        g.setclr(0);
        g.barwth (0.3);
        g.bartyp ("3dvert");
        g.name (xAxisName.c_str(), "X");
        g.name (yAxisName.c_str(), "Y");

        g.mylab("D2L1", 2, "x");
        g.mylab("D2L2", 3, "x");
        g.mylab("D2L3", 4, "x");
        g.mylab("D1L1", 5, "x");
        g.mylab("D1L2", 6, "x");
        g.mylab("D1L3", 7, "x");
    
        g.labels ("delta", "bars");
        g.labpos ("outside", "bars");
        g.labclr (0, "bars");
        g.labels ("mylab", "X");
        g.graf   (0.0, 7.0, 0.0, 1.0, 0.0, maxY+7, 0.0, 10.0);
        g.title  ();
        g.chnbar("color");
        g.clrcyc (1, g.intrgb(0.5,0.5,0.5));
        g.clrcyc (2, g.intrgb(0.0, 0.9, 0.1));
        g.clrcyc (3, g.intrgb(0.0, 0.1, 0.8));
        g.clrcyc (4, g.intrgb(1.0, 0.95, 0.3));
        g.clrcyc (5, g.intrgb(1.0, 0.0, 0.0));
        g.clrcyc (6, g.intrgb(0.8, 0.0, 0.0));
        g.bars   (xray, y1ray, y2, 6);
        g.endgrf ();
  
        g.disfin ();
        return 0;
    }


    void drawDayPie(double *ray) {
        const char *ctit = "Week days";
        char cbuf[91];
        Dislin g;
        g.setfil("daypie.gif");
        g.filmod("delete");
        //g.setpag ("da4p");
        g.window(30,30, 707, 500); //1.4141414141414141414141414141414
        g.metafl("gif");
        //g.metafl ("cons");

        g.imgfmt("RGB");
        g.disini ();
        g.pagfll(255); //background color

        g.pagera ();
        g.hwfont();//font
        
        g.axslen (1400, 1400); //size
        g.axspos (700, 1800); //center
        g.titlin (ctit, 2);
        g.htitle(60); //title font height

        g.setrgb(0.0, 0.0, 0.0);
        g.height(45); //other font height
        g.legini (cbuf, 7, 9);
        g.leglin (cbuf, "Monday", 1);
        g.leglin (cbuf, "Tuesday", 2);
        g.leglin (cbuf, "Wednesday", 3);
        g.leglin (cbuf, "Thursday", 4);
        g.leglin (cbuf, "Friday", 5);
        g.leglin (cbuf, "Saturday", 6);
        g.leglin (cbuf, "Sunday", 7);
    
    
        g.chnpie ("colour");
        g.shdpat(16);
        g.clrcyc(4, 10);
        g.clrcyc(1, 70);

        g.labels("both", "pie");
        //g.labclr(0, "pie");
        g.labdig(-1, "data");
        g.labpos("external", "pie");
        g.pietyp ("3d");
        g.piegrf(cbuf, 1, ray, 7);
        g.title();
        g.endgrf();
        g.disfin();
    }


    void drawMonthPie(double *ray) {
        const char *ctit = "Month of year";
        char cbuf[37];
        Dislin g;
        g.setfil("monthpie.gif");
        g.filmod("delete");
        //g.setpag ("da4p");
        g.window(30,30, 707, 500); //1.4141414141414141414141414141414
        g.metafl("gif");
        //g.metafl ("cons");

        g.imgfmt("RGB");
        g.disini ();
        g.pagfll(255); //background color

        g.pagera ();
        g.hwfont();

        g.axslen (1400, 1400); //size
        g.axspos (700, 1800); //center
        g.titlin (ctit, 2);
        g.htitle(60); //title font height
        //g.chnpie ("both");
        g.chnpie ("colour");
        g.shdpat(16);
        g.height(45);
        g.legini (cbuf, 12, 3);
        g.leglin (cbuf, "Jan", 1);
        g.leglin (cbuf, "Feb", 2);
        g.leglin (cbuf, "Mar", 3);
        g.leglin (cbuf, "Apr", 4);
        g.leglin (cbuf, "May", 5);
        g.leglin (cbuf, "Jun", 6);
        g.leglin (cbuf, "Jul", 7);
        g.leglin (cbuf, "Aug", 8);
        g.leglin (cbuf, "Sep", 9);
        g.leglin (cbuf, "Oct", 10);
        g.leglin (cbuf, "Nov", 11);
        g.leglin (cbuf, "Dec", 12);
    
        /*for (int i=1; i<=12; i++) {
            g.patcyc (i, i);
        }*/
        g.clrcyc(1, 70);
        g.clrcyc(4, 20);
        g.clrcyc(9, 10);
        g.clrcyc(12, 110);
        g.setrgb(0., 0., 1.);

        g.labels("both", "pie");
        g.labdig(-1, "data");
        g.labpos("external", "pie");
        g.pietyp ("3d");
        g.piegrf(cbuf, 1, ray, 12);
        g.title();
        g.endgrf();
        g.disfin();
    }
};
/*int main ()
{ 
    double dayray[7] = {5, 7, 20, 11, 5, 9, 12};
    double monthray[12] = {5, 7, 20, 11, 5, 9, 12, 56, 22, 40, 32, 25};
    double levelCount[6] = {33, 15, 10, 5, 4, 3};
   // drawDayPie(dayray);
   // drawMonthPie(monthray);
    drawLvl(levelCount);
    return 0;
}
*/

#endif