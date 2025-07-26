#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <algorithm>
#include<string.h>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <shlobj.h> // For SHGetFolderPathA
#include <direct.h> // For _mkdir
#include <sys/stat.h> // For stat
#include <errno.h> // For errno

// Link legacy stdio definitions library to provide missing symbols
#pragma comment(lib, "legacy_stdio_definitions.lib")

using namespace std;

# include "iGraphics.h"
int mposx,  mposy,i=0,speed=10,r=0,jy=50,j=0,mh=240,dj=0,f1=0,fc=0,f2=0,s_life=200,p_f=0;
int pos[100];
int slice=70,width=1350/slice;
#define scw 1350;
#define sch 510;
#define sspd 14;
#define gspd 14;

int h=1,u=0,cond_e=0,sh=0,w=0,m1=1,b2=0,sc=0,over=0,play=1,rec1=0,obs=0,at=0,e_g_max=1150,e_g=e_g_max,e_s=0,ab1=((rand()%10)+(rand()%10)+1330),ac1=rand(),ac2=rand(),ac3=rand(),ac4=rand(),ac5=rand(),ab2=((rand()%10)+(rand()%10)+1330),ab3=((rand()%10)+(rand()%10)+1330),ab4=((rand()%10)+(rand()%10)+1330),ab5=((rand()%10)+(rand()%10)+1330);

bool run=true,jump=false,down=false,jump1=false,d_jump=false,djjump=false,djdown=false,fight=false,dash=false,kick=false;
int run1=0,jump_c=0,in=0,d=6,w3=0,shg,e_i=0,idx=0,dg=0,s_d=0;

// Boss system variables
int boss_kill_count=0;           // Number of times boss has been killed
int boss_respawn_timer=0;        // Timer for boss respawn (in timer ticks)
bool boss_spawned=false;         // Whether boss is currently spawned
bool boss_should_spawn=false;    // Whether boss should spawn when timer expires
int boss_base_health=60;         // Base health for boss (3 web shots * 20 damage = 60)
int boss_health_pulse=0;         // Counter for health bar pulsing effect

double obj_x,e_max=250,e_life=e_max,s_max=1400,f_c=0,e_dead=1,in1=0,b3=false,music=0,rec_g=109,e_con=0,rec_e=109;


char sp [3][20]= {"char\\s1.bmp","char\\s2.bmp","char\\s3.bmp"};
char rn[][20]= {"char\\r1.bmp","char\\r2.bmp","char\\r3.bmp","char\\r4.bmp","char\\r5.bmp","char\\r6.bmp","char\\r7.bmp","char\\r8.bmp","char\\r9.bmp","char\\r10.bmp","char\\r11.bmp","char\\r12.bmp","char\\r13.bmp","char\\r14.bmp"};
char djmp[][20]= {"char\\j2.bmp","char\\j3.bmp","char\\j4.bmp","char\\j5.bmp","char\\j6.bmp","char\\j10.bmp","char\\j11.bmp","char\\j1.bmp"};
char jmp[][20]= {"char\\j1.bmp"};
char bg[][30]= {"bg\\b01.bmp",	"bg\\b02.bmp",	"bg\\b03.bmp",	"bg\\b04.bmp",	"bg\\b05.bmp",	"bg\\b06.bmp",	"bg\\b07.bmp",	"bg\\b08.bmp",	"bg\\b09.bmp",	"bg\\b10.bmp",	"bg\\b11.bmp",	"bg\\b12.bmp",	"bg\\b13.bmp",	"bg\\b14.bmp",	"bg\\b15.bmp",	"bg\\b16.bmp",	"bg\\b17.bmp",	"bg\\b18.bmp",	"bg\\b19.bmp",	"bg\\b20.bmp",	"bg\\b21.bmp",	"bg\\b22.bmp",	"bg\\b23.bmp",	"bg\\b24.bmp",	"bg\\b25.bmp",	"bg\\b26.bmp",	"bg\\b27.bmp",	"bg\\b28.bmp",	"bg\\b29.bmp",	"bg\\b30.bmp",	"bg\\b31.bmp",	"bg\\b32.bmp",	"bg\\b33.bmp",	"bg\\b34.bmp",	"bg\\b35.bmp",	"bg\\b36.bmp",	"bg\\b37.bmp",	"bg\\b38.bmp",	"bg\\b39.bmp",	"bg\\b40.bmp",	"bg\\b41.bmp",	"bg\\b42.bmp",	"bg\\b43.bmp",	"bg\\b44.bmp",	"bg\\b45.bmp",	"bg\\b46.bmp",	"bg\\b47.bmp",	"bg\\b48.bmp",	"bg\\b49.bmp",	"bg\\b50.bmp",	"bg\\b51.bmp",	"bg\\b52.bmp",	"bg\\b53.bmp",	"bg\\b54.bmp",	"bg\\b55.bmp",	"bg\\b56.bmp",	"bg\\b57.bmp",	"bg\\b58.bmp",	"bg\\b59.bmp",	"bg\\b60.bmp",	"bg\\b61.bmp",	"bg\\b62.bmp",	"bg\\b63.bmp",	"bg\\b64.bmp",	"bg\\b65.bmp",	"bg\\b66.bmp",	"bg\\b67.bmp",	"bg\\b68.bmp",	"bg\\b69.bmp",	"bg\\b70.bmp",	"bg\\b01.bmp",	"bg\\b02.bmp",	"bg\\b03.bmp",	"bg\\b04.bmp",	"bg\\b05.bmp",	"bg\\b06.bmp",	"bg\\b07.bmp",	"bg\\b08.bmp",	"bg\\b09.bmp",	"bg\\b10.bmp",	"bg\\b11.bmp",	"bg\\b12.bmp",	"bg\\b13.bmp",	"bg\\b14.bmp",	"bg\\b15.bmp",	"bg\\b16.bmp",	"bg\\b17.bmp",	"bg\\b18.bmp",	"bg\\b19.bmp",	"bg\\b20.bmp",	"bg\\b21.bmp",	"bg\\b22.bmp",	"bg\\b23.bmp",	"bg\\b24.bmp",	"bg\\b25.bmp",	"bg\\b26.bmp",	"bg\\b27.bmp",	"bg\\b28.bmp",	"bg\\b29.bmp",	"bg\\b30.bmp",	"bg\\b31.bmp",	"bg\\b32.bmp",	"bg\\b33.bmp",	"bg\\b34.bmp",	"bg\\b35.bmp",	"bg\\b36.bmp","bg\\b37.bmp",	"bg\\b38.bmp",	"bg\\b39.bmp",	"bg\\b40.bmp",	"bg\\b41.bmp",	"bg\\b42.bmp",	"bg\\b43.bmp",	"bg\\b44.bmp",	"bg\\b45.bmp",	"bg\\b46.bmp",	"bg\\b47.bmp",	"bg\\b48.bmp",	"bg\\b49.bmp",	"bg\\b50.bmp",	"bg\\b51.bmp",	"bg\\b52.bmp",	"bg\\b53.bmp",	"bg\\b54.bmp",	"bg\\b55.bmp",	"bg\\b56.bmp",	"bg\\b57.bmp",	"bg\\b58.bmp",	"bg\\b59.bmp",	"bg\\b60.bmp",	"bg\\b61.bmp",	"bg\\b62.bmp",	"bg\\b63.bmp",	"bg\\b64.bmp",	"bg\\b65.bmp",	"bg\\b66.bmp",	"bg\\b67.bmp",	"bg\\b68.bmp",	"bg\\b69.bmp",	"bg\\b70.bmp"};
char f[][20]= {"char\\f1.bmp","char\\f2.bmp","char\\f3.bmp","char\\f4.bmp","char\\f5.bmp","char\\f6.bmp","char\\f7.bmp","char\\f8.bmp"};
char k[][20]= {"char\\k1.bmp"};
char m[][20]= {"menu\\m1.bmp","menu\\b1.bmp","menu\\b2.bmp","menu\\b3.bmp","menu\\b4.bmp","menu\\b5.bmp"};
char web[][20]={"web/w1.bmp","web/w2.bmp","web/sh.bmp" };
char e_id[][20]={	"electro\\b02.bmp",	"electro\\b03.bmp",	"electro\\b04.bmp",	"electro\\b05.bmp",	"electro\\b06.bmp",	"electro\\b07.bmp",	"electro\\b08.bmp",	"electro\\b09.bmp",	"electro\\b10.bmp",	"electro\\b11.bmp",	"electro\\b12.bmp",	"electro\\b13.bmp",	"electro\\b14.bmp",	"electro\\b15.bmp"};
char user[][20]={"name\\n2.bmp"};
char ob[][20]={"obs\\b01.bmp","obs\\b02.bmp","obs\\b03.bmp","obs\\b04.bmp","obs\\b05.bmp","obs\\b06.bmp"};
char e_a[][20]={"electro\\a1.bmp","electro\\a2.bmp","electro\\a3.bmp","electro\\a4.bmp","electro\\a5.bmp","electro\\a6.bmp","electro\\a11.bmp","electro\\a12.bmp","electro\\a13.bmp","electro\\a14.bmp","electro\\a15.bmp","electro\\a10.bmp","electro\\a9.bmp","electro\\a8.bmp","electro\\a16.bmp",};
char dmg[][20]={"dmg\\b01.bmp","dmg\\b02.bmp","dmg\\b03.bmp","dmg\\b04.bmp","dmg\\b05.bmp","dmg\\b06.bmp","dmg\\b07.bmp",} ;
char s_dd[][20]={"dd\\d1.bmp","dd\\d2.bmp","dd\\d3.bmp","dd\\d4.bmp","dd\\d5.bmp","dd\\d6.bmp","dd\\d7.bmp"};
char health[][20]={"health\\b01.bmp","health\\b02.bmp"};
char n[10];
 char s[1000];
 FILE *rec;
 
// Helper function to check if directory exists
bool directoryExists(const char* path) {
    struct stat info;
    if (stat(path, &info) != 0) {
        return false; // Cannot access path
    }
    return (info.st_mode & S_IFDIR) != 0; // Check if it's a directory
}

// Helper function to create directory recursively
bool createDirectoryRecursive(const std::string& path) {
    size_t pos = 0;
    bool success = true;
    
    while ((pos = path.find_first_of("\\/", pos)) != std::string::npos) {
        std::string subdir = path.substr(0, pos++);
        if (!subdir.empty() && !directoryExists(subdir.c_str())) {
            if (_mkdir(subdir.c_str()) != 0 && errno != EEXIST) {
                return false;
            }
        }
    }
    
    // Create the final directory
    if (!directoryExists(path.c_str())) {
        if (_mkdir(path.c_str()) != 0 && errno != EEXIST) {
            return false;
        }
    }
    
    return true;
}

// Improved function to get user-writable data file path
std::string getDataFilePath() {
    char appdata[MAX_PATH];
    HRESULT result = SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, appdata);
    
    if (FAILED(result)) {
        // Fallback to current directory if APPDATA fails
        return "data.txt";
    }
    
    std::string folder = std::string(appdata) + "\\Spiderman";
    
    // Create directory with better error handling
    if (!createDirectoryRecursive(folder)) {
        // If folder creation fails, try alternative locations
        
        // Try Documents folder
        char documents[MAX_PATH];
        if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, 0, documents))) {
            folder = std::string(documents) + "\\Spiderman";
            if (createDirectoryRecursive(folder)) {
                return folder + "\\data.txt";
            }
        }
        
        // Last resort: use current directory
        return "data.txt";
    }
    
    return folder + "\\data.txt";
}

// Function to clear the leaderboard file
void clearLeaderboard() {
    std::string filepath = getDataFilePath();
    FILE *fp = fopen(filepath.c_str(), "w");
    if (fp) {
        fclose(fp);
    } else {
        char errorMsg[512];
        sprintf(errorMsg, "Failed to clear leaderboard file at: %s\nError: %s", filepath.c_str(), strerror(errno));
        MessageBoxA(0, errorMsg, "File Error", MB_ICONERROR);
    }
}

 /*
	function iDraw() is called again and again by the system.
*/

	void resetGameState(); // Forward declaration

 	void record()
{
    std::string filepath = getDataFilePath();
    rec = fopen(filepath.c_str(), "a");
    if (!rec) {
        char errorMsg[512];
        sprintf(errorMsg, "Failed to open data file for writing at: %s\nError: %s\n\nPlease check if the directory exists and you have write permissions.", filepath.c_str(), strerror(errno));
        MessageBoxA(0, errorMsg, "File Error", MB_ICONERROR);
        return;
    }
    fputs(n, rec);
    fprintf(rec, " ");
    fputs(s, rec);
    fprintf(rec, "\n");
    idx = 0;
    fclose(rec);
    
    // Leaderboard sorting logic (unchanged)
    char x[100];
    char y[100];
    int z[100];
    string l[100];
    int v[100];
    int idx[100];
    int ix = 0;
    int k = 0;
    rec = fopen(filepath.c_str(), "r");
    if (!rec) {
        char errorMsg[512];
        sprintf(errorMsg, "Failed to open data file for reading at: %s\nError: %s", filepath.c_str(), strerror(errno));
        MessageBoxA(0, errorMsg, "File Error", MB_ICONERROR);
        return;
    }
    while (fscanf(rec, "%s %s", x, y) != EOF)
    {
        l[k] = x;
        z[k] = atoi(y);
        v[k] = atoi(y);
        k++;
    }
    k--;
    fclose(rec);
    int a;
    for (int p = 0; p <= k; ++p) {
        for (int o = p + 1; o <= k; ++o) {
            if (z[p] < z[o]) {
                a = z[p];
                z[p] = z[o];
                z[o] = a;
            }
        }
    }
    rec = fopen(filepath.c_str(), "w");
    if (!rec) {
        char errorMsg[512];
        sprintf(errorMsg, "Failed to open data file for writing at: %s\nError: %s", filepath.c_str(), strerror(errno));
        MessageBoxA(0, errorMsg, "File Error", MB_ICONERROR);
        return;
    }
    for (int o = 0; o <= k; o++)
    {
        for (int p = 0; p <= k; p++)
        {
            if (z[o] == v[p])
            {
                idx[ix] = p;
                ix++;
                break;
            }
        }
    }
    ix--;
    for (int p = 0; p <= ix; p++)
    {
        sprintf(s, "%d", z[p]);
        fprintf(rec, "%s", l[idx[p]].c_str());
        fprintf(rec, " ");
        fputs(s, rec);
        fprintf(rec, "\n");
    }
    fclose(rec);
    // Now reset game state as if 'q' was pressed
    resetGameState();
}
	


void iDraw()
{
    //place your drawing codes here
	
    iClear();
    if(over)
	{
		
		
		iShowBMP(0,0,s_dd[6]);

		iShowBMP2(speed,80,s_dd[s_d],16777215);
		iShowBMP2(35,400,health[0],16777215);
		iText(390,250,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1080,400,"Press 'P' to save Score",GLUT_BITMAP_TIMES_ROMAN_24);
		
		iShowBMP2(700,70,ob[5],16777215);
		if(s_d>=6)
		
		over=0;
		play=0;
		
		
		

	}
	else if(play){
		
			

    if(m1)
    {
		
		
        iShowBMP(0,0,m[0]);
        iShowBMP2(150,300,m[1],0);

        iShowBMP2(97,150,m[2],0);
		iShowBMP2(97,40,m[4],0);
    }
    else if(b2)
    {
        iShowBMP(0,0,m[3]);
        // Draw leaderboard background
        iSetColor(30, 30, 60); // dark blue
        iFilledRectangle(30, 80, 500, 420);
        // Draw leaderboard title
        iSetColor(255, 215, 0);
        iText(200, 470, "Leaderboard", GLUT_BITMAP_HELVETICA_18);
        // Draw table headers
        iSetColor(200, 200, 255);
        iText(60, 430, "Rank", GLUT_BITMAP_HELVETICA_12);
        iText(140, 430, "Name", GLUT_BITMAP_HELVETICA_12);
        iText(320, 430, "Score", GLUT_BITMAP_HELVETICA_12);
        // Draw leaderboard entries
        std::string filepath = getDataFilePath();
        rec=fopen(filepath.c_str(),"r");
        if (!rec) {
            // If file doesn't exist or can't be opened, just show empty leaderboard
            iSetColor(255,255,255);
            iText(200, 350, "No scores recorded yet", GLUT_BITMAP_HELVETICA_12);
        } else {
            char t[100],r[100];
            int h_y=400;
            int rank = 1;
            while(fscanf(rec,"%s %s",t,r)!=EOF && rank <= 8)
            {
                // Alternate row color
                if(rank % 2 == 0) {
                    iSetColor(40, 40, 80);
                    iFilledRectangle(35, h_y-10, 490, 35);
                }
                iSetColor(255,255,255);
                char rankStr[10];
                sprintf(rankStr, "%d", rank);
                iText(60, h_y, rankStr, GLUT_BITMAP_HELVETICA_12);
                iText(140, h_y, t, GLUT_BITMAP_HELVETICA_12);
                iText(320, h_y, r, GLUT_BITMAP_HELVETICA_12);
                h_y -= 40;
                rank++;
            }
            fclose(rec);
        }
        // Draw the clear leaderboard button on the right
        int btn_w = 200, btn_h = 40;
        int btn_x = 330, btn_y = 120; // right side of the leaderboard box
        iSetColor(200, 50, 50);
        iFilledRectangle(btn_x, btn_y, btn_w, btn_h);
        iSetColor(255,255,255);
        iText(btn_x + 30, btn_y + 12, "Clear Leaderboard", GLUT_BITMAP_HELVETICA_18);
    }
	else if(b3)
	{
		iShowBMP(0,0,m[5]);
	}
	else if(u)
	{
		
		iShowBMP(0,0,user[0]);
		iSetColor(255,255,255);
		iFilledRectangle(425,253,505,37);
		iSetColor(0,0,255);
		
		iText(550,262,n,GLUT_BITMAP_TIMES_ROMAN_24);
		
		
		
			
		
	
		
	}
		

   else
    {
        for(int m=0; m<slice; m++)
        {

            iShowBMP(pos[m],0,bg[m]);//1315


        }


		iShowBMP2(35,400,health[0],16777215);
		iSetColor(77,222,18);
		if(rec_g<=0)
		{
			rec_g=0;
			iFilledRectangle(83,421,rec_g,14);
		}
		iFilledRectangle(83,421,rec_g,14);
		
		// Enhanced Boss Health Bar
		if(e_con && e_life > 0)
		{
			// Boss health bar dimensions and position
			int boss_bar_x = 950;
			int boss_bar_y = 450;
			int boss_bar_width = 320;
			int boss_bar_height = 25;
			int boss_bar_border = 3;
			
			// Calculate health percentage
			double health_percentage = (double)e_life / (double)e_max;
			
			// Draw boss name label with pulsing effect for low health
			if(health_percentage <= 0.3 && (boss_health_pulse / 10) % 2 == 0) {
				iSetColor(255, 100, 100); // Pulsing red for low health
			} else {
				iSetColor(255, 255, 255); // Normal white
			}
			char boss_label[50];
			sprintf(boss_label, "ELECTRO - LEVEL %d", boss_kill_count + 1);
			iText(boss_bar_x, boss_bar_y + boss_bar_height + 10, boss_label, GLUT_BITMAP_HELVETICA_12);
			
			// Draw health bar background (dark frame) with pulsing for low health
			if(health_percentage <= 0.3 && (boss_health_pulse / 10) % 2 == 0) {
				iSetColor(80, 40, 40); // Pulsing darker red border for low health
			} else {
				iSetColor(40, 40, 40); // Normal dark border
			}
			iFilledRectangle(boss_bar_x - boss_bar_border, boss_bar_y - boss_bar_border, 
							boss_bar_width + (boss_bar_border * 2), boss_bar_height + (boss_bar_border * 2));
			
			// Draw health bar background (inner black)
			iSetColor(0, 0, 0);
			iFilledRectangle(boss_bar_x, boss_bar_y, boss_bar_width, boss_bar_height);
			
			// Calculate current bar width
			int current_bar_width = (int)(boss_bar_width * health_percentage);
			
			// Determine health bar color based on health percentage with pulsing effect
			if(health_percentage > 0.6) {
				iSetColor(77, 222, 18); // Green for high health
			} else if(health_percentage > 0.3) {
				iSetColor(255, 165, 0); // Orange for medium health
			} else {
				// Red with pulsing effect for low health
				if((boss_health_pulse / 5) % 2 == 0) {
					iSetColor(255, 100, 100); // Bright red
				} else {
					iSetColor(200, 50, 50); // Darker red
				}
			}
			
			// Draw the actual health bar
			if(current_bar_width > 0) {
				iFilledRectangle(boss_bar_x, boss_bar_y, current_bar_width, boss_bar_height);
			}
			
			// Draw health bar border/outline
			iSetColor(200, 200, 200);
			iRectangle(boss_bar_x, boss_bar_y, boss_bar_width, boss_bar_height);
			
			// Draw health text with color based on health
			if(health_percentage <= 0.3) {
				iSetColor(255, 100, 100); // Red text for low health
			} else {
				iSetColor(255, 255, 255); // White text for normal health
			}
			char health_text[50];
			sprintf(health_text, "%d / %d", (int)e_life, (int)e_max);
			iText(boss_bar_x + boss_bar_width + 10, boss_bar_y + 8, health_text, GLUT_BITMAP_HELVETICA_12);
			
			// Draw segmented health bar lines for visual appeal
			iSetColor(100, 100, 100);
			for(int i = 1; i < 10; i++) {
				int segment_x = boss_bar_x + (boss_bar_width * i / 10);
				iLine(segment_x, boss_bar_y, segment_x, boss_bar_y + boss_bar_height);
			}
		}
		
		// Reset e_con when boss dies
		if(e_life <= 0 && e_con) {
			e_con = 0;
		}
			

        if(in==0)
        {
            int n=0;

            for(int m=0; m<slice; m++)
            {
                iShowBMP(n,0,bg[m]);
                n+=width;
            }
            iShowBMP2(0,80,sp[i],16777215);
			
			iShowBMP2(35,400,health[0],16777215);
			iSetColor(77,222,18);
			iFilledRectangle(83,421,109,14);
			

        }
		


		if(!u && !m1 && in)
		{
			iSetColor(255,255,255);
			iText(580,431,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(672,431,s,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
        if(kick)
        {
            iShowBMP2(speed,jy,k[0],16777215);
            //ki++;

        }
		if(w)
		{
			
			iShowBMP2(speed,80,web[w3],16777215);
			run=true;
			shg=speed;
			

		}
		if(sh )
		{
			
			iShowBMP2(shg+130,160,web[2],16777215);
		}
		if( cond_e && e_dead)
		{
			iShowBMP2(1200,80,e_id[e_i],16777215);
			e_con=1;
			e_life=e_max;
		  //cout << e_i;
		}
		
		// Show boss health bar when boss is active (spawned but not dead)
		if(boss_spawned && e_life > 0)
		{
			e_con = 1;
		}
		
		if(!cond_e && e_life){
			if(shg>=890 && shg<=1120 && sh)
			{
				e_life-=20;
				// Calculate health bar reduction proportional to max health
				rec_e -= (int)(109.0 * 20.0 / e_max);
				s_max=1090;
				sh=false; // Prevent multiple hits from same web shot
				// Only allow one hit per web shot
				if(e_life<=0)
				{
					e_life=0;
					e_dead=1;
					boss_spawned=false;
					boss_kill_count++;
					boss_should_spawn=true;
					boss_respawn_timer=10000; // 10 seconds respawn delay (in milliseconds)
					in1=0;
				}
				//cout << e_life;
				//iShowBMP2(1130,160,web[2],16777215);
				
			}
			if(p_f && speed>=1130 && speed <= 1250 )
			{
				e_life-=30;
				// Calculate health bar reduction proportional to max health
				rec_e -= (int)(109.0 * 30.0 / e_max);
				if(e_life<=0)
				{
					e_life=0;
					e_dead=1;
					boss_spawned=false;
					boss_kill_count++;
					boss_should_spawn=true;
					boss_respawn_timer=10000; // 10 seconds respawn delay (in milliseconds)
					in1=0;
				}
				p_f=false;
				//cout<<e_life;
			}

		}
		
		if(sc>=2)
		{
			
			    
				iShowBMP2(ab1,70,ob[ac1%5],16777215);
				
				iShowBMP2(ab2,70,ob[ac2%5],16777215);
				

				
				if((speed-20)<=ab1 && (speed+20)>=ab1 && jy<=100)
				{
					
					if(dg<=6)
						run=true;
						iShowBMP2(speed,80,dmg[dg],16777215);
					s_life-=10;
					rec_g-=6;
					if(s_life<=0)
						over=1;
					//cout <<s_life<<endl;
				}
				if((speed-10)<=ab2 && (speed+10)>=ab2 && jy<=100)
				{
					
					if(dg<=6)
						run=true;
						iShowBMP2(speed,80,dmg[dg],16777215);
					s_life-=10;
					rec_g-=6;
					if(s_life<=0)
						over=1;
					//cout <<s_life<<endl;
				}
				if(jy<=140 && (e_g<=speed+50 && e_g>= speed-50) && e_life)
		{
			if(dg<=6)
						run=true;
					 iShowBMP2(speed,80,dmg[dg],16777215);
			s_life-=20;
			rec_g-=11;
			if(s_life<=0)
				over=1;
		}
		}
		
		if(!cond_e && e_life && in1 )
		{
			iShowBMP2(1200,80,e_a[at],16777215);
		}
		if(e_s && e_life)
		{
			iShowBMP2(e_g,140,e_a[14],16777215);
		}
		
        if(in!=0 && dash)
        {

            iShowBMP2(speed,80,f[d],16777215);
			run=true;

        }

        if(fight && in!=0 && f2==1)
        {
			run=true;
            if(f1>=0)

                iShowBMP2(speed,80,f[f1],16777215);
			




        }
        if(fight && in!=0 && f2==2)
        {
			run=true;
            iShowBMP2(speed,80,f[f1],16777215);
        }
        if(jump && in!=0)
        {



            run=true;


            if(d_jump)
            {
                jump1=false;
                down=false;
                iShowBMP2(speed,jy,djmp[dj],16777215);
            }
            else
            {
                if(!kick)

                    iShowBMP2(speed,jy,jmp[j],16777215);
            }

        }
        if(!run)
        {



            iShowBMP2(speed,80,rn[r],16777215);
		}
		}
		}
			






}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		
        if(mx>=155 && mx <=391 && my >= 305 && my <= 406 && !b2 && !b3)
        {
			
			
            m1=false;
            b2=false;
            in =0;
            u=true;
            speed=10;
			h=false;
        }
        else if(mx >=124 && mx <= 430 && my >=183 && my <= 259 && h && !b3)
        {
            b2=true;
            m1=false;
			rec1=true;
        }
		else if(mx>=145 && mx<=398 && my>=82 && my<=154 && h  )
		{
			b3=true;
			m1=false;
			rec1=true;
			b2=false;
		}
		//cout<<mx<<" "<<my<<" ";
		if(u && mx >=471 && mx <= 648 && my>=184 && my <= 219 && idx>0)
		{
			//record();
			u=false;
			PlaySound("bgm\\bgm2.wav",NULL,SND_LOOP| SND_ASYNC);
			
		}
		cout << mx <<" "<< my<<" ";
		


    }
    // Detect click on clear leaderboard button (right side)
    if(b2) {
        int btn_w = 200, btn_h = 40;
        int btn_x = 330, btn_y = 120;
        if(mx >= btn_x && mx <= btn_x + btn_w && my >= btn_y && my <= btn_y + btn_h) {
            clearLeaderboard();
        }
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
    //place your code here

    mposx = mx;
    mposy = my;
    if(mx== 2) {}       /*Something to do with mx*/
    else if(my== 2) {}  /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == '0')
    {
        if(jump_c>0)
        {
            jump1=false;
            down=false;
            d_jump=true;
            djjump=true;
        }
    }
	if(key=='w' && in && !jump && !sh)
	{
		w=true;
		run=true;
	}
    if(key=='f' && !jump)
    {

        fight=true;
        run=true;
        if(f2>2)
            f2=0;
        else
            f2++;
		if(sc>=5 && e_life)
			p_f=true;
    }
    if(key == 'd' && !jump && in)
    {
        run=true;
        dash=true;
    }
    if(key == 'f' && jump && !d_jump)
    {
        run=true;
        kick=true;
        down=false;
        jump1=false;
    }
    if(key == 'q' )
	{
        resetGameState();
	}
	
	if(u && key!=' ' && key!='\r')
	{
		b2=false;
		n [idx]=key;
		if(key=='\b')
		{
			if(idx==0)
			{
				idx=0;
			}
			else
			{
				idx--;
			}
		}
		else
			idx++;
	}
	if(u && key=='\r' && idx>0)
	{
		u=false;
		PlaySound("bgm\\bgm2.wav",NULL,SND_LOOP| SND_ASYNC);
	}
	if(key=='p' && !u )
	{
		record();
	}
	
	// Manual boss spawn for testing (key 'b')
	if(key=='b' && !u && !m1 && in)
	{
		if(!boss_spawned && boss_respawn_timer == 0)
		{
			e_max = boss_base_health + (boss_kill_count * 40);
			e_life = e_max;
			cond_e = true;
			boss_spawned = true;
			boss_should_spawn = false;
			e_dead = 0;
			e_con = 1;
			rec_e = 109;
		}
	}
	
	// Debug: Show data file path (key 'i' for info)
	if(key=='i' && (u || m1))
	{
		std::string dataPath = getDataFilePath();
		char infoMsg[512];
		sprintf(infoMsg, "Game data will be stored at:\n%s\n\nIf you encounter 'Failed to open data.txt' errors, this location may not be writable.\n\nTry running the game as administrator if the problem persists.", dataPath.c_str());
		MessageBoxA(0, infoMsg, "Spiderman - Data File Location", MB_ICONINFORMATION);
	}
	
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_RIGHT && !over)
    {
        run=false;
        speed+=20;
        if(speed>=1240)
            speed=1240;
        in++;
    }
    if(key == GLUT_KEY_LEFT && !over)
    {
        speed-=20;
        if(speed<=0)
            speed=0;
    }
    if(key==GLUT_KEY_UP && in!=0 && !fight && !over)
    {
        jump_c++;
        jump=true;
        jump1=true;
        run=false;
    }
    //place your codes for other keys here
}

void Run()
{
    if(in==0)
    {
        i++;
        if(i>2)
            i=0;
    }
}
void change1()
{
    if(!run)
    {
        r++;
        if(r>13)
            r=2;
    }
}
void Jump()
{
    if(jump1)
    {
        jy+=24; // was 30, slower jump up
        if(jy>=mh)
        {
            down=true;
            jump1=false;
        }
    }
    if(down)
    {
        if(GLUT_KEY_UP)
        {
            jump1=false;
        }
        jy-=26; // was 33, slower fall
        if(jy<=100)
        {
            jy=80;
            jump=false;
            down=false;
            jump_c=0;
            run=false;
        }
    }
}
void doubleJump()
{
    if(djjump)
    {
        jy+=24; // was 30, slower double jump up
        if(jy>=mh+100)
        {
            djdown=true;
            djjump=false;
        }
    }
    if(djdown)
    {
        if(GLUT_KEY_UP )
        {
            djjump=false;
        }
        jy-=26; // was 33, slower double jump fall
        dj++;
        if(dj>8)
            dj=7;
        if(jy<=80)
        {
            jy=80;
            jump=false;
            djdown=false;
            d_jump=false;
            jump_c=0;
            dj=0;
            run=false;
        }
    }
}
void bgPos()
{
    int m;
    for(m=0; m<slice; m++)
    {
        pos[m]-=width;
        if(pos[m]<0)
            pos[m]=(slice*width)-width;
    }
}
void position()
{
    int m,n;
    for(m=0,n=0; m<slice; m++)
    {
        pos[m]=n;
        n+=width;
    }
}
void fight1()
{
    if(fight && f2==1)
    {
        if(fc==0)
        {
            fc++;
            f1=0;
        }
        else
            ++f1;
    }
    if(f1>1 && f2==1 )
    {
        fight=false;
        fc=0;
        f1=2;
        if(in!=0)
            run=false;
    }
}
void fight2()
{
    if(fight && f2==2)
    {
        if(fc==0)
        {
            f1=2;
            fc++;
        }
        else
            f1++;
    }
    if(f1>5 && f2==2)
    {
        fight=false;
        fc=0;
        f2=0;
        f1=0;
        run=false;
    }
}
void fdash()
{
    if(dash)
    {
        d++;
        if(d==7)
            speed=speed+100;
    }
    if(d>7 && dash)
    {
        dash=false;
        run=false;
        d=6;
    }
}
void webs()
{
	if(w)
	w3++;
	
	if(w3>=2)
	{
		w3=0;
		w=false;
		run=false;
		sh=true;
	}
}
void shoot()
{
	if (sh){
	shg+=150;
	}
	if(shg>s_max)
	{
		sh=false;
		shg=speed;
	}
}
void e_idl()
{
	if(cond_e)
	e_i++;
	if(e_i>=14)
	{
		cond_e=false;
		e_dead=0;
		e_i=0;
		in1=1;
	}
}
void obstackle()
{
	if(sc>=2)
	ab1-=19;
	ab2-=19;
	
	if(ab1<-10)
	{
		int x2=rand();
		int x3=rand();
		ab1=(x3%100)+(x2%1000)+1332;
		ac1=rand();
	}
	if(ab2<-10)
	{
		int y2=rand();
		int y3=rand();
		int y4=rand();
		ab2=(y4%100)+(y3%100)+(y2%100)+1332;
		ac2=rand();
	}
}
void e_attack()
{
	if(!cond_e && in1 )
		at++;
	if(at>=7)
		e_s=true;
	if(at>=13)
	{
		at=0;
	}
}
void e_shoot()
{
	if(e_s)
	e_g-=75;
	if(e_g<=0 )
	{
		e_g=e_g_max;
		e_s=false;
	}
}
void score()
{
    if(!u && !m1 && in)
    {
        sc++;
        
        // Boss spawning logic - boss appears at score 5 (reduced for easier testing)
        if(sc >= 5 && !boss_spawned && !boss_should_spawn && boss_respawn_timer == 0)
        {
            // Calculate boss health based on kill count
            // First boss: 3 web shots (60 health)
            // Second boss: 5 web shots (100 health) 
            // Third boss: 7 web shots (140 health), etc.
            e_max = boss_base_health + (boss_kill_count * 40);
            e_life = e_max;
            cond_e = true;
            boss_spawned = true;
            boss_should_spawn = false;
            e_dead = 0;
            e_con = 1; // Explicitly set e_con to show health bar
            // Reset enemy health bar display proportional to new max health
            rec_e = 109;
        }
        
        sprintf(s,"%d",sc);
    }
}
void s_dead()
{
	if(over)
		s_d++;
	if(s_d>=6)
		s_d=5;
}
void damage()
{
	dg++;
	if(dg>=6 && sc>=2)
	{
		dg=0;
		run=false;
	}
}
void obstackle1()
{
	ab1=(rand()%10)+1332;
	ac1=rand();
}
void sound()
{
	if(music)
	{
	music=0;
	}
}
void fkick()
{
    if(kick)
    {
        kick=false;	
        down=true;	
        run=false;
    }
}

void doubleJumpMotion()
{
    if(djjump)
    {
        dj++;
        if(dj>8)
            dj=7;
    }
}

void bossRespawn()
{
    if(boss_should_spawn && boss_respawn_timer > 0)
    {
        boss_respawn_timer -= 100; // Decrease timer by 100ms each call
        
        if(boss_respawn_timer <= 0)
        {
            // Respawn boss with increased health
            e_max = boss_base_health + (boss_kill_count * 40);
            e_life = e_max;
            cond_e = true;
            boss_spawned = true;
            boss_should_spawn = false;
            e_dead = 0;
            boss_respawn_timer = 0;
            e_con = 1; // Explicitly set e_con to show health bar
            // Reset enemy health bar display
            rec_e = 109;
        }
    }
}

void bossHealthPulse()
{
    // Update the boss health pulse counter for visual effects
    boss_health_pulse++;
    if(boss_health_pulse > 100) {
        boss_health_pulse = 0;
    }
}

// Add a global variable to track if the clear leaderboard button is pressed
int main()
{
    //place your own initialization codes here.
    position();
    
    // Test and display data file location for debugging
    std::string dataPath = getDataFilePath();
    char infoMsg[512];
    sprintf(infoMsg, "Game data will be stored at:\n%s\n\nIf you encounter file errors, please ensure this location is writable.", dataPath.c_str());
    
    // Show this message only in debug mode or if needed
    // MessageBoxA(0, infoMsg, "Spiderman - Data Location", MB_ICONINFORMATION);
    
	PlaySound("bgm\\bgm.wav",NULL,SND_LOOP| SND_ASYNC);
	
    iSetTimer(10,sound);
	iSetTimer(130,shoot); // was 100, now slower shooting
	iSetTimer(90,e_shoot);
    iSetTimer(300,fkick);
    iSetTimer(40,obstackle);
    iSetTimer(150,webs);
    iSetTimer(130,fight1); // was 100, now slower fight1
	iSetTimer(0,damage);
    iSetTimer(300,fdash);
	iSetTimer(300,s_dead);
    iSetTimer(70,fight2); // was 50, now slower fight2
    iSetTimer(40,bgPos);
    iSetTimer(80,e_idl);
	iSetTimer(100,e_attack);
    iSetTimer(40,doubleJump); // was 0, now slower double jump
    iSetTimer(110,doubleJumpMotion); // was 90, now slower double jump motion
    iSetTimer(40,Jump); // was 0, now slower jump
    iSetTimer(62,change1);
    iSetTimer(400,Run);
	iSetTimer(1000,score);
	iSetTimer(100,bossRespawn); // Boss respawn timer
	iSetTimer(50,bossHealthPulse); // Boss health pulse effect

    iInitialize(1330, 510, "Spiderman");

    return 0;
}

void resetGameState() {
    // Reset menu states
    m1=true;
    u=false;
    h=true;
    b2=false;
    b3=false;

    // Reset all gameplay state variables to their initial values
    speed=10;
    jy=50;  // Reset to initial jump y position
    i=0;
    r=0;
    j=0;
    dj=0;
    f1=0;
    fc=0;
    f2=0;
    s_life=200;
    p_f=0;
    sc=0;
    over=0;
    play=1;
    in=0;

    // Reset boolean flags
    run=true;
    jump=false;
    down=false;
    jump1=false;
    d_jump=false;
    djjump=false;
    djdown=false;
    fight=false;
    dash=false;
    kick=false;

    // Reset other counters and indices
    run1=0;
    jump_c=0;
    d=6;
    w3=0;
    shg=0;
    e_i=0;
    idx=0;
    dg=0;
    s_d=0;

    // Reset enemy and shooting related variables
    cond_e=0;
    sh=0;
    w=0;
    rec1=0;
    obs=0;
    at=0;
    e_g=e_g_max;
    e_s=0;
    e_life=e_max;
    rec_g=109;
    e_con=0;
    rec_e=109;
    e_dead=1;
    in1=0;
    music=0;

    // Reset boss system variables
    boss_kill_count=0;
    boss_respawn_timer=0;
    boss_spawned=false;
    boss_should_spawn=false;
    boss_health_pulse=0;
    e_max=250; // Reset to original boss health

    // Reset obstacle positions
    ab1=((rand()%10)+(rand()%10)+1330);
    ac1=rand();
    ac2=rand();
    ac3=rand();
    ac4=rand();
    ac5=rand();
    ab2=((rand()%10)+(rand()%10)+1330);
    ab3=((rand()%10)+(rand()%10)+1330);
    ab4=((rand()%10)+(rand()%10)+1330);
    ab5=((rand()%10)+(rand()%10)+1330);

    // Reset background positions manually
    int m_pos, n_pos;
    for(m_pos=0, n_pos=0; m_pos<slice; m_pos++)
    {
        pos[m_pos]=n_pos;
        n_pos+=width;
    }

    // Clear the name input buffer
    for(int i_reset=0; i_reset<10; i_reset++)
    {
        n[i_reset] = '\0';
    }

    // Reset the score string
    sprintf(s, "0");
}
