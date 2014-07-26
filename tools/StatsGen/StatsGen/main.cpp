#include <cstdio>
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "argvparser.h"
#include "htmlscripts.h"
#include "ChartGen.h"
#include "StringTokenizer.h"

using namespace std;
using namespace boost::filesystem;
using namespace CommandLineProcessing;

struct Problem{
    string name;
    string dir;
    bool hasStats;
    string type;
    string levels;
    string bestTime;
	string averageTime;
    string startTime;
    string endTime;
};

vector<Problem>pList;
string stateFileExt = ".st";

void listOfTriedProblems(path dir) {
    directory_iterator end_itr; // default construction yields past-the-end
    
    bool isAProblem = true;
    Problem p;
    p.hasStats = false;
    for ( directory_iterator itr( dir); itr != end_itr; ++itr ) {
        if ( is_directory(itr->status()) ) {
            //std::cout<<"Dir: "<<itr->path().leaf()<<std::endl;
            listOfTriedProblems(itr->path());
            isAProblem = false; //if current dir have other dir then current dir is not a problem dir
        }
        else {
            string fileName = itr->path().leaf().string();
            
            int pos = fileName.rfind(stateFileExt);
            p.name = dir.filename().string();
            p.dir = dir.parent_path().string();
            //std::cout<<"File: "<<p.name<<"/"<<dir.parent_path().string()<<std::endl;
            if (pos+stateFileExt.length()==fileName.length() && p.hasStats==false) {
                p.hasStats = true;
            }
        }
    }
    if (isAProblem) {
        pList.push_back(p);
    }
    //std::cout<<"End of: "<<dir.filename()<<std::endl;
}

string generateHtml() {
    string html = "<html><head><title>Problem state</title>"+javaScript+javaScript2+style+"</head><body>";
    html += "<img src=\"daypie.gif\" style=\"border:1px dashed black\"/>  <img src=\"monthpie.gif\" style=\"border:1px dashed black\" />";
    html += "<img src=\"levelbar.gif\" style=\"border:1px dashed black\"/> <img src=\"averageTimeBar.gif\" style=\"border:1px dashed black\">";
    html += "<table class=\"sortable\">";
    html += "<tr><th>NO.</th><th>Name</th><th>Type</th><th>Level</th><th>Quickest</th><th>Average Time</th><th>Your Time</th><th>Date</th></tr>\n";
    char buff[10];
    int count=1;
    double weekDays[7]={0.0}, monthOfYear[12]={0.0}, lvlCount[6]={0.0}, lvlTime[6]={0.0};
    for (int i=0; i<pList.size(); i++) {
        if (pList[i].hasStats) {
            sprintf(buff, "%d", count++);
            html +="<tr>";
            html += "<td>";
            html += buff;
            html += "&nbsp;</td>";
            html += "<td>"+pList[i].name+"&nbsp;</td>";
            html += "<td>"+pList[i].type+"&nbsp;</td>";
            html += "<td>"+pList[i].levels+"&nbsp;</td>";
            html += "<td>"+pList[i].bestTime+"&nbsp;</td>";
			html += "<td>" + pList[i].averageTime + "&nbsp;</td>";
            string levelStr;
            int levelInd=0;
            StringTokenizer stok(pList[i].levels, "& ");
			try {
				levelStr = stok.nextToken();
			}
			catch (NoSuchElementException ex) {
			}
            //levelStr = String::toUpperCase(levelStr);
            if (levelStr=="D2L1") {
                levelInd=0;
            } else if (levelStr=="D2L2") {
                levelInd=1;
            } else if (levelStr=="D2L3") {
                levelInd=2;
            } else if (levelStr=="D1L1") {
                levelInd=3;
            } else if (levelStr=="D1L2") {
                levelInd=4;
            } else if (levelStr=="D1L3") {
                levelInd=5;
            }
            boost::posix_time::ptime st(boost::posix_time::time_from_string(pList[i].startTime));
            int dayNum = st.date().day_of_week().as_number();
            weekDays[dayNum]++;
            int monthNum = st.date().month().as_number();
            monthOfYear[monthNum-1]++;
            if (pList[i].endTime.empty()) {
                html += "<td>In Progress</td>";
            } else {
                lvlCount[levelInd]++;
                boost::posix_time::ptime et(boost::posix_time::time_from_string(pList[i].endTime));
                boost::posix_time::time_duration duration = et - st;
                lvlTime[levelInd] += duration.total_seconds();
                html += "<td>"+boost::posix_time::to_simple_string(duration)+"</td>";
            }
            html +="<td>"+to_iso_extended_string(st)+"</td>";
            html +="</tr>";
        }
    }

    html += "</table></body></html>";
    DisLin disLin;
    disLin.drawDayPie(weekDays);
    disLin.drawMonthPie(monthOfYear);
    disLin.drawLvl(lvlCount, "levelbar.gif", "Level Count", "Levels ->", "Count ->");

    for (int i=0; i<6; i++) {
        if (lvlTime[i]<1e-7) {
            continue;
        }
        lvlTime[i] /= lvlCount[i];
        lvlTime[i] /= 60.0;
        
    }
    disLin.drawLvl(lvlTime, "averageTimeBar.gif", "Average Time", "Levels ->", "Minutes ->");
	//*/
    return html;
}

int main(int ac, char* av[]) {
    ArgvParser cmd;
    // init
    cmd.setIntroductoryDescription("Generate info state of solved/tired problem");

    cmd.setHelpOption("h", "help", "Print this help page");

    cmd.defineOption("dir", "Root directory", ArgvParser::OptionRequiresValue);
    cmd.defineOptionAlternative("dir","d");
    
    // finally parse and handle return codes (display help etc...)
    int result = cmd.parse(ac, av);

    if (result != ArgvParser::NoParserError) {
        std::cout << cmd.parseErrorDescription(result);
        exit(1);
    }
    string rootDir="./";
    //root dir
    if (cmd.foundOption("d")) {
        rootDir = cmd.optionValue("d");
    }

    path dir_path( rootDir );
    listOfTriedProblems(dir_path);
    std::cout<< "Total Tried Problem found: "<<pList.size()<<std::endl;
    char inp[150];
    for (int i=0; i<pList.size(); i++) {
        if (!pList[i].hasStats) {
            std::cout<<"Problem \""<<pList[i].name<<"\" does not have any state file.\n"
                <<"Do you want to create it? y/n: ";
            char ch;
            std::cin>>ch;
            if (ch=='y' || ch=='Y') {
                string cmd = string("Otocoder.exe -w n -d ")+pList[i].dir+" "+pList[i].name;
                cout<<cmd<<endl;
                system(cmd.c_str());
                pList[i].hasStats = true; //lets hope previous operation was a success
            }
        }
        int j=0;
        if (pList[i].hasStats) {
            std::ifstream ifs((pList[i].dir+"/"+pList[i].name+"/"+pList[i].name+stateFileExt).c_str(), std::ios_base::in);
            while(ifs.getline(inp, 150)) {
                if (j==1) {
                    pList[i].type = inp;
                } else if (j==2) {
                    pList[i].levels = inp;
                } else if(j==3) {
                    pList[i].bestTime = inp;
				} else if (j == 4) {
					pList[i].averageTime = inp;
				} else if (j==5) {
                    pList[i].startTime = inp;
                } else if (j==6) {
                    pList[i].endTime = inp;
                }
                j++;
            }
            ifs.close();
        }
    }
    std::ofstream ofs((rootDir+"/State.html").c_str(), std::ios_base::out);
    ofs<<generateHtml();
    ofs.close();
}
