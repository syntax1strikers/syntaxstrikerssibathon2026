#include <iostream>
#include <string>
using namespace std;

const int TOTAL=30;

string name[TOTAL],gender[TOTAL],hair[TOTAL],height[TOTAL],beard[TOTAL],personality[TOTAL],sportsperson[TOTAL],singer[TOTAL],married[TOTAL],glasses[TOTAL],kids[TOTAL],overseas[TOTAL],old[TOTAL],dramas[TOTAL],famous_drama[TOTAL],famous_song[TOTAL],nickname_arr[TOTAL];

struct Answers{
    string gender,hair,height,sportsperson,singer;
    string dramas,married,kids,overseas,old,glasses,personality,beard;
    string famous_drama,famous_song,nickname;
};

string to_lowercase(string s){
    for(size_t i=0;i<s.length();i++) if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
    return s;
}

string normalize_yes_no(string s){
    s=to_lowercase(s);
    if(s=="y"||s=="yes") return "yes";
    if(s=="n"||s=="no") return "no";
    return s;
}

void initialize_celebrities(){
    for(int i=0;i<TOTAL;i++){
        name[i]="";gender[i]="";hair[i]="";height[i]="";beard[i]="";personality[i]="";sportsperson[i]="";singer[i]="";married[i]="";glasses[i]="";kids[i]="";overseas[i]="";old[i]="";dramas[i]="";famous_drama[i]="";famous_song[i]="";nickname_arr[i]="";
    }
    name[0]="Atif Aslam";gender[0]="male";hair[0]="black";height[0]="average";beard[0]="yes";personality[0]="calm";sportsperson[0]="no";singer[0]="yes";married[0]="yes";glasses[0]="no";kids[0]="yes";overseas[0]="yes";old[0]="no";dramas[0]="no";famous_song[0]="tajdar-e-haram";nickname_arr[0]="atif";
    name[1]="Mahira Khan";gender[1]="female";hair[1]="brown";height[1]="tall";beard[1]="no";personality[1]="graceful";sportsperson[1]="no";singer[1]="no";married[1]="yes";glasses[1]="no";kids[1]="yes";overseas[1]="yes";old[1]="no";dramas[1]="yes";famous_drama[1]="humsafar";nickname_arr[1]="mahira";
    name[2]="Ali Zafar";gender[2]="male";hair[2]="black";height[2]="average";beard[2]="light";personality[2]="charming";sportsperson[2]="no";singer[2]="yes";married[2]="yes";glasses[2]="no";kids[2]="yes";overseas[2]="yes";old[2]="no";dramas[2]="yes";famous_song[2]="channo";nickname_arr[2]="ali";
    name[3]="Ayeza Khan";gender[3]="female";hair[3]="brown";height[3]="tall";beard[3]="no";personality[3]="confident";sportsperson[3]="no";singer[3]="no";married[3]="yes";glasses[3]="no";kids[3]="yes";overseas[3]="no";old[3]="no";dramas[3]="yes";famous_drama[3]="mere paas tum ho";nickname_arr[3]="ayeza";
    name[4]="Iqra Aziz";gender[4]="female";hair[4]="brown";height[4]="short";beard[4]="no";personality[4]="energetic";sportsperson[4]="no";singer[4]="no";married[4]="yes";glasses[4]="no";kids[4]="yes";overseas[4]="no";old[4]="no";dramas[4]="yes";famous_drama[4]="suno chanda";nickname_arr[4]="iqra";
    name[5]="Sajal Aly";gender[5]="female";hair[5]="brown";height[5]="average";beard[5]="no";personality[5]="serious";sportsperson[5]="no";singer[5]="no";married[5]="no";glasses[5]="no";kids[5]="no";overseas[5]="no";old[5]="no";dramas[5]="yes";famous_drama[5]="yeh dil mera";nickname_arr[5]="sajal";
    name[6]="Feroze Khan";gender[6]="male";hair[6]="black";height[6]="tall";beard[6]="yes";personality[6]="bold";sportsperson[6]="no";singer[6]="no";married[6]="no";glasses[6]="no";kids[6]="yes";overseas[6]="no";old[6]="no";dramas[6]="yes";famous_drama[6]="khaani";nickname_arr[6]="feroze";
    name[7]="Shahid Afridi";gender[7]="male";hair[7]="black";height[7]="tall";beard[7]="yes";personality[7]="aggressive";sportsperson[7]="yes";singer[7]="no";married[7]="yes";glasses[7]="no";kids[7]="yes";overseas[7]="yes";old[7]="yes";dramas[7]="no";nickname_arr[7]="lala";
    name[8]="Imran Abbas";gender[8]="male";hair[8]="black";height[8]="tall";beard[8]="no";personality[8]="romantic";sportsperson[8]="no";singer[8]="no";married[8]="no";glasses[8]="no";kids[8]="no";overseas[8]="no";old[8]="no";dramas[8]="yes";famous_drama[8]="khuda aur mohabbat";nickname_arr[8]="imran";
    name[9]="Mawra Hocane";gender[9]="female";hair[9]="brown";height[9]="average";beard[9]="no";personality[9]="elegant";sportsperson[9]="no";singer[9]="no";married[9]="no";glasses[9]="no";kids[9]="no";overseas[9]="yes";old[9]="no";dramas[9]="yes";famous_drama[9]="aangan";nickname_arr[9]="mawra";
    name[10]="Wahaj Ali";gender[10]="male";hair[10]="black";height[10]="average";beard[10]="yes";personality[10]="humble";sportsperson[10]="no";singer[10]="no";married[10]="yes";glasses[10]="no";kids[10]="yes";overseas[10]="no";old[10]="no";dramas[10]="yes";famous_drama[10]="tere bin";nickname_arr[10]="wahaj";
    name[11]="Bilal Abbas Khan";gender[11]="male";hair[11]="black";height[11]="tall";beard[11]="light";personality[11]="intense";sportsperson[11]="no";singer[11]="no";married[11]="no";glasses[11]="no";kids[11]="no";overseas[11]="no";old[11]="no";dramas[11]="yes";famous_drama[11]="cheekh";nickname_arr[11]="bilal";
    name[12]="Waseem Akram";gender[12]="male";hair[12]="black";height[12]="tall";beard[12]="no";personality[12]="professional";sportsperson[12]="yes";singer[12]="no";married[12]="yes";glasses[12]="no";kids[12]="yes";overseas[12]="yes";old[12]="yes";dramas[12]="no";nickname_arr[12]="wasim";
    name[13]="Babar Azam";gender[13]="male";hair[13]="black";height[13]="average";beard[13]="yes";personality[13]="calm";sportsperson[13]="yes";singer[13]="no";married[13]="no";glasses[13]="no";kids[13]="no";overseas[13]="yes";old[13]="no";dramas[13]="no";nickname_arr[13]="babar";
    name[14]="Shaheen Afridi";gender[14]="male";hair[14]="black";height[14]="tall";beard[14]="yes";personality[14]="energetic";sportsperson[14]="yes";singer[14]="no";married[14]="yes";glasses[14]="no";kids[14]="no";overseas[14]="yes";old[14]="no";dramas[14]="no";nickname_arr[14]="shaheen";
    name[15]="Fahad Mustafa";gender[15]="male";hair[15]="black";height[15]="average";beard[15]="yes";personality[15]="funny";sportsperson[15]="no";singer[15]="no";married[15]="yes";glasses[15]="no";kids[15]="yes";overseas[15]="no";old[15]="no";dramas[15]="yes";famous_drama[15]="jeeto pakistan";nickname_arr[15]="fahad";
    name[16]="Mehwish Hayat";gender[16]="female";hair[16]="brown";height[16]="tall";beard[16]="no";personality[16]="bold";sportsperson[16]="no";singer[16]="yes";married[16]="no";glasses[16]="no";kids[16]="no";overseas[16]="no";old[16]="no";dramas[16]="yes";famous_song[16]="billi";nickname_arr[16]="mehwish";
    name[17]="Fawad Khan";gender[17]="male";hair[17]="black";height[17]="tall";beard[17]="light";personality[17]="charming";sportsperson[17]="no";singer[17]="yes";married[17]="yes";glasses[17]="no";kids[17]="yes";overseas[17]="yes";old[17]="no";dramas[17]="yes";famous_drama[17]="humsafar";famous_song[17]="humsafar ost";nickname_arr[17]="fawad";
    name[18]="Hania Aamir";gender[18]="female";hair[18]="brown";height[18]="average";beard[18]="no";personality[18]="cheerful";sportsperson[18]="no";singer[18]="no";married[18]="no";glasses[18]="no";kids[18]="no";overseas[18]="no";old[18]="no";dramas[18]="yes";famous_drama[18]="mere humsafar";nickname_arr[18]="hania";
    name[19]="Yumna Zaidi";gender[19]="female";hair[19]="brown";height[19]="average";beard[19]="no";personality[19]="serious";sportsperson[19]="no";singer[19]="no";married[19]="no";glasses[19]="no";kids[19]="no";overseas[19]="no";old[19]="no";dramas[19]="yes";famous_drama[19]="bakhtawar";nickname_arr[19]="yumna";
    name[20]="Saba Qamar";gender[20]="female";hair[20]="brown";height[20]="average";beard[20]="no";personality[20]="strong";sportsperson[20]="no";singer[20]="no";married[20]="no";glasses[20]="no";kids[20]="no";overseas[20]="no";old[20]="no";dramas[20]="yes";famous_drama[20]="baaghi";nickname_arr[20]="saba";
    name[21]="Danish Taimoor";gender[21]="male";hair[21]="black";height[21]="tall";beard[21]="yes";personality[21]="confident";sportsperson[21]="no";singer[21]="no";married[21]="yes";glasses[21]="no";kids[21]="yes";overseas[21]="no";old[21]="no";dramas[21]="yes";famous_drama[21]="deewangi";nickname_arr[21]="danish";
    name[22]="Ayesha Omar";gender[22]="female";hair[22]="brown";height[22]="average";beard[22]="no";personality[22]="bold";sportsperson[22]="no";singer[22]="yes";married[22]="no";glasses[22]="no";kids[22]="no";overseas[22]="no";old[22]="no";dramas[22]="yes";famous_drama[22]="bulbulay";nickname_arr[22]="ayesha";
    name[23]="Usman Khalid Butt";gender[23]="male";hair[23]="black";height[23]="average";beard[23]="yes";personality[23]="intelligent";sportsperson[23]="no";singer[23]="no";married[23]="no";glasses[23]="yes";kids[23]="no";overseas[23]="no";old[23]="no";dramas[23]="yes";nickname_arr[23]="usman";
    name[24]="Nauman Ijaz";gender[24]="male";hair[24]="black";height[24]="tall";beard[24]="yes";personality[24]="serious";sportsperson[24]="no";singer[24]="no";married[24]="yes";glasses[24]="no";kids[24]="yes";overseas[24]="no";old[24]="yes";dramas[24]="yes";nickname_arr[24]="nauman";
    name[25]="Farhan Saeed";gender[25]="male";hair[25]="black";height[25]="average";beard[25]="light";personality[25]="romantic";sportsperson[25]="no";singer[25]="yes";married[25]="yes";glasses[25]="no";kids[25]="no";overseas[25]="no";old[25]="no";dramas[25]="yes";famous_song[25]="jal";nickname_arr[25]="farhan";
    name[26]="Asim Azhar";gender[26]="male";hair[26]="black";height[26]="average";beard[26]="light";personality[26]="young";sportsperson[26]="no";singer[26]="yes";married[26]="no";glasses[26]="no";kids[26]="no";overseas[26]="no";old[26]="no";dramas[26]="no";famous_song[26]="tere bina";nickname_arr[26]="asim";
    name[27]="Ahsan Khan";gender[27]="male";hair[27]="black";height[27]="tall";beard[27]="light";personality[27]="charming";sportsperson[27]="no";singer[27]="no";married[27]="yes";glasses[27]="no";kids[27]="yes";overseas[27]="no";old[27]="no";dramas[27]="yes";nickname_arr[27]="ahsan";
    name[28]="Adnan Siddiqui";gender[28]="male";hair[28]="black";height[28]="tall";beard[28]="yes";personality[28]="professional";sportsperson[28]="no";singer[28]="no";married[28]="yes";glasses[28]="no";kids[28]="yes";overseas[28]="yes";old[28]="yes";dramas[28]="yes";nickname_arr[28]="adnan";
    name[29]="Sanam Saeed";gender[29]="female";hair[29]="brown";height[29]="tall";beard[29]="no";personality[29]="strong";sportsperson[29]="no";singer[29]="no";married[29]="yes";glasses[29]="no";kids[29]="no";overseas[29]="yes";old[29]="no";dramas[29]="yes";famous_drama[29]="zindagi gulzar hai";nickname_arr[29]="sanam";
}

string best_value_from_candidates(const string &field,const Answers &ans,bool alive[],string arr[]){
    string best="";int bestc=0,total=0;
    for(int i=0;i<TOTAL;i++) if(alive[i]){
        bool ok=true;
        if(!ans.gender.empty()&&gender[i]!=ans.gender) ok=false;
        if(!ans.hair.empty()&&hair[i]!=ans.hair) ok=false;
        if(!ans.height.empty()&&height[i]!=ans.height) ok=false;
        if(!ans.sportsperson.empty()&&sportsperson[i]!=ans.sportsperson) ok=false;
        if(!ans.singer.empty()&&singer[i]!=ans.singer) ok=false;
        if(!ans.dramas.empty()&&!dramas[i].empty()&&dramas[i]!=ans.dramas) ok=false;
        if(!ans.married.empty()&&!married[i].empty()&&married[i]!=ans.married) ok=false;
        if(!ans.kids.empty()&&!kids[i].empty()&&kids[i]!=ans.kids) ok=false;
        if(!ans.overseas.empty()&&!overseas[i].empty()&&overseas[i]!=ans.overseas) ok=false;
        if(!ans.old.empty()&&!old[i].empty()&&old[i]!=ans.old) ok=false;
        if(!ans.glasses.empty()&&!glasses[i].empty()&&glasses[i]!=ans.glasses) ok=false;
        if(!ans.personality.empty()&&!personality[i].empty()&&personality[i]!=ans.personality) ok=false;
        if(!ans.beard.empty()&&!beard[i].empty()&&beard[i]!=ans.beard) ok=false;
        if(!ans.famous_drama.empty()&&!famous_drama[i].empty()&&famous_drama[i]!=ans.famous_drama) ok=false;
        if(!ans.famous_song.empty()&&!famous_song[i].empty()&&famous_song[i]!=ans.famous_song) ok=false;
        if(!ans.nickname.empty()&&!nickname_arr[i].empty()&&nickname_arr[i]!=ans.nickname) ok=false;
        if(!ok) continue;
        total++;
    }
    if(total<=1) return "";
    for(int i=0;i<TOTAL;i++) if(alive[i]){
        bool ok=true;
        if(!ans.gender.empty()&&gender[i]!=ans.gender) ok=false;
        if(!ans.hair.empty()&&hair[i]!=ans.hair) ok=false;
        if(!ans.height.empty()&&height[i]!=ans.height) ok=false;
        if(!ans.sportsperson.empty()&&sportsperson[i]!=ans.sportsperson) ok=false;
        if(!ans.singer.empty()&&singer[i]!=ans.singer) ok=false;
        if(!ans.dramas.empty()&&!dramas[i].empty()&&dramas[i]!=ans.dramas) ok=false;
        if(!ans.married.empty()&&!married[i].empty()&&married[i]!=ans.married) ok=false;
        if(!ans.kids.empty()&&!kids[i].empty()&&kids[i]!=ans.kids) ok=false;
        if(!ans.overseas.empty()&&!overseas[i].empty()&&overseas[i]!=ans.overseas) ok=false;
        if(!ans.old.empty()&&!old[i].empty()&&old[i]!=ans.old) ok=false;
        if(!ans.glasses.empty()&&!glasses[i].empty()&&glasses[i]!=ans.glasses) ok=false;
        if(!ans.personality.empty()&&!personality[i].empty()&&personality[i]!=ans.personality) ok=false;
        if(!ans.beard.empty()&&!beard[i].empty()&&beard[i]!=ans.beard) ok=false;
        if(!ans.famous_drama.empty()&&!famous_drama[i].empty()&&famous_drama[i]!=ans.famous_drama) ok=false;
        if(!ans.famous_song.empty()&&!famous_song[i].empty()&&famous_song[i]!=ans.famous_song) ok=false;
        if(!ans.nickname.empty()&&!nickname_arr[i].empty()&&nickname_arr[i]!=ans.nickname) ok=false;
        if(!ok) continue;
        string v=arr[i];
        if(v.empty()) continue;
        int c=0;
        for(int j=0;j<TOTAL;j++) if(alive[j]){
            bool ok2=true;
            if(!ans.gender.empty()&&gender[j]!=ans.gender) ok2=false;
            if(!ans.hair.empty()&&hair[j]!=ans.hair) ok2=false;
            if(!ans.height.empty()&&height[j]!=ans.height) ok2=false;
            if(!ans.sportsperson.empty()&&sportsperson[j]!=ans.sportsperson) ok2=false;
            if(!ans.singer.empty()&&singer[j]!=ans.singer) ok2=false;
            if(!ans.dramas.empty()&&!dramas[j].empty()&&dramas[j]!=ans.dramas) ok2=false;
            if(!ans.married.empty()&&!married[j].empty()&&married[j]!=ans.married) ok2=false;
            if(!ans.kids.empty()&&!kids[j].empty()&&kids[j]!=ans.kids) ok2=false;
            if(!ans.overseas.empty()&&!overseas[j].empty()&&overseas[j]!=ans.overseas) ok2=false;
            if(!ans.old.empty()&&!old[j].empty()&&old[j]!=ans.old) ok2=false;
            if(!ans.glasses.empty()&&!glasses[j].empty()&&glasses[j]!=ans.glasses) ok2=false;
            if(!ans.personality.empty()&&!personality[j].empty()&&personality[j]!=ans.personality) ok2=false;
            if(!ans.beard.empty()&&!beard[j].empty()&&beard[j]!=ans.beard) ok2=false;
            if(!ans.famous_drama.empty()&&!famous_drama[j].empty()&&famous_drama[j]!=ans.famous_drama) ok2=false;
            if(!ans.famous_song.empty()&&!famous_song[j].empty()&&famous_song[j]!=ans.famous_song) ok2=false;
            if(!ans.nickname.empty()&&!nickname_arr[j].empty()&&nickname_arr[j]!=ans.nickname) ok2=false;
            if(!ok2) continue;
            if(arr[j]==v) c++;
        }
        if(c>bestc&&c<total){bestc=c;best=v;}
    }
    return best;
}

bool consistent(int i,const Answers &ans){
    if(!ans.gender.empty()&&gender[i]!=ans.gender) return false;
    if(!ans.hair.empty()&&hair[i]!=ans.hair) return false;
    if(!ans.height.empty()&&height[i]!=ans.height) return false;
    if(!ans.sportsperson.empty()&&sportsperson[i]!=ans.sportsperson) return false;
    if(!ans.singer.empty()&&singer[i]!=ans.singer) return false;
    if(!ans.dramas.empty()&&!dramas[i].empty()&&dramas[i]!=ans.dramas) return false;
    if(!ans.married.empty()&&!married[i].empty()&&married[i]!=ans.married) return false;
    if(!ans.kids.empty()&&!kids[i].empty()&&kids[i]!=ans.kids) return false;
    if(!ans.overseas.empty()&&!overseas[i].empty()&&overseas[i]!=ans.overseas) return false;
    if(!ans.old.empty()&&!old[i].empty()&&old[i]!=ans.old) return false;
    if(!ans.glasses.empty()&&!glasses[i].empty()&&glasses[i]!=ans.glasses) return false;
    if(!ans.personality.empty()&&!personality[i].empty()&&personality[i]!=ans.personality) return false;
    if(!ans.beard.empty()&&!beard[i].empty()&&beard[i]!=ans.beard) return false;
    if(!ans.famous_drama.empty()&&!famous_drama[i].empty()&&ans.famous_drama!=famous_drama[i]) return false;
    if(!ans.famous_song.empty()&&!famous_song[i].empty()&&ans.famous_song!=famous_song[i]) return false;
    if(!ans.nickname.empty()&&!nickname_arr[i].empty()&&ans.nickname!=nickname_arr[i]) return false;
    return true;
}

int score_candidate(int i,const Answers &ans){
    int s=0;
    if(!ans.gender.empty()&&gender[i]==ans.gender) s+=20;
    if(!ans.hair.empty()&&hair[i]==ans.hair) s+=10;
    if(!ans.height.empty()&&height[i]==ans.height) s+=10;
    if(!ans.sportsperson.empty()&&sportsperson[i]==ans.sportsperson) s+=12;
    if(!ans.singer.empty()&&singer[i]==ans.singer) s+=12;
    if(!ans.dramas.empty()&&!dramas[i].empty()&&dramas[i]==ans.dramas) s+=8;
    if(!ans.married.empty()&&!married[i].empty()&&married[i]==ans.married) s+=4;
    if(!ans.kids.empty()&&!kids[i].empty()&&kids[i]==ans.kids) s+=4;
    if(!ans.overseas.empty()&&!overseas[i].empty()&&overseas[i]==ans.overseas) s+=4;
    if(!ans.old.empty()&&!old[i].empty()&&old[i]==ans.old) s+=4;
    if(!ans.glasses.empty()&&!glasses[i].empty()&&glasses[i]==ans.glasses) s+=4;
    if(!ans.personality.empty()&&!personality[i].empty()&&personality[i]==ans.personality) s+=3;
    if(!ans.beard.empty()&&!beard[i].empty()&&beard[i]==ans.beard) s+=3;
    if(!ans.famous_drama.empty()&&!famous_drama[i].empty()&&famous_drama[i]==ans.famous_drama) s+=18;
    if(!ans.famous_song.empty()&&!famous_song[i].empty()&&famous_song[i]==ans.famous_song) s+=14;
    if(!ans.nickname.empty()&&!nickname_arr[i].empty()&&nickname_arr[i]==ans.nickname) s+=12;
    return s;
}

int best_guess(const Answers &ans,bool alive[]){
    int best=-1,bs=-1;
    for(int i=0;i<TOTAL;i++){
        if(!alive[i]) continue;
        if(!consistent(i,ans)) continue;
        int sc=score_candidate(i,ans);
        if(sc>bs){bs=sc;best=i;}
    }
    if(best==-1){
        for(int i=0;i<TOTAL;i++) if(alive[i]) return i;
    }
    return best;
}

int count_candidates(const Answers &ans,bool alive[]){
    int c=0;
    for(int i=0;i<TOTAL;i++) if(alive[i]&&consistent(i,ans)) c++;
    return c;
}

bool ask_question(int q,Answers &ans,bool asked[],bool alive[]){
    if(asked[q]) return false;
    if(q==0){cout<<"Is the person male or female? ";cin>>ans.gender;ans.gender=to_lowercase(ans.gender);asked[q]=true;return true;}
    if(q==1){cout<<"Hair color (black/brown/blonde)? ";cin>>ans.hair;ans.hair=to_lowercase(ans.hair);asked[q]=true;return true;}
    if(q==2){cout<<"Height (tall/average/short)? ";cin>>ans.height;ans.height=to_lowercase(ans.height);asked[q]=true;return true;}
    if(q==3){cout<<"Is the person a sportsperson (yes/no)? ";cin>>ans.sportsperson;ans.sportsperson=normalize_yes_no(ans.sportsperson);asked[q]=true;return true;}
    if(q==4){cout<<"Is the person a singer (yes/no)? ";cin>>ans.singer;ans.singer=normalize_yes_no(ans.singer);asked[q]=true;return true;}
    if(q==5){cout<<"Has the person worked in dramas (yes/no)? ";cin>>ans.dramas;ans.dramas=normalize_yes_no(ans.dramas);asked[q]=true;return true;}
    if(q==6){cout<<"Is the person married (yes/no)? ";cin>>ans.married;ans.married=normalize_yes_no(ans.married);asked[q]=true;return true;}
    if(q==7){cout<<"Does the person have kids (yes/no)? ";cin>>ans.kids;ans.kids=normalize_yes_no(ans.kids);asked[q]=true;return true;}
    if(q==8){cout<<"Has the person worked overseas (yes/no)? ";cin>>ans.overseas;ans.overseas=normalize_yes_no(ans.overseas);asked[q]=true;return true;}
    if(q==9){cout<<"Is the person considered old (yes/no)? ";cin>>ans.old;ans.old=normalize_yes_no(ans.old);asked[q]=true;return true;}
    if(q==10){cout<<"Does the person wear glasses (yes/no)? ";cin>>ans.glasses;ans.glasses=normalize_yes_no(ans.glasses);asked[q]=true;return true;}
    if(q==11){cout<<"Personality (calm/bold/funny/serious/charming/confident/graceful/soft/energetic/strong/intelligent/professional/modern/young/humble/romantic/elegant/cheerful/intense/aggressive): ";cin>>ans.personality;ans.personality=to_lowercase(ans.personality);asked[q]=true;return true;}
    if(q==12){
        if(ans.gender!="male") return false;
        cout<<"Does he have a beard (yes/no/light)? ";
        cin>>ans.beard;ans.beard=to_lowercase(ans.beard);ans.beard=normalize_yes_no(ans.beard);asked[q]=true;return true;
    }
    if(q==13){
        if(ans.dramas!="yes") return false;
        string d=best_value_from_candidates("famous_drama",ans,alive,famous_drama);
        if(d.empty()) return false;
        cout<<"Has the person worked in "<<d<<" (yes/no): ";
        string x;cin>>x;x=normalize_yes_no(x);
        if(x=="yes") ans.famous_drama=d;
        asked[q]=true;return true;
    }
    if(q==14){
        if(ans.singer!="yes") return false;
        string s=best_value_from_candidates("famous_song",ans,alive,famous_song);
        if(s.empty()) return false;
        cout<<"Is the person known for the song "<<s<<" (yes/no): ";
        string x;cin>>x;x=normalize_yes_no(x);
        if(x=="yes") ans.famous_song=s;
        asked[q]=true;return true;
    }
    if(q==15){
        string n=best_value_from_candidates("nickname",ans,alive,nickname_arr);
        if(n.empty()) return false;
        cout<<"Is the person known by nickname "<<n<<" (yes/no): ";
        string x;cin>>x;x=normalize_yes_no(x);
        if(x=="yes") ans.nickname=n;
        asked[q]=true;return true;
    }
    return false;
}

void ask_next_five(Answers &ans,bool asked[],bool alive[]){
    int asked_now=0;
    for(int q=0;q<16&&asked_now<5;q++){
        if(ask_question(q,ans,asked,alive)) asked_now++;
    }
    if(asked_now<5){
        for(int q=0;q<16&&asked_now<5;q++){
            if(!asked[q]){
                if(q==10){cout<<"Does the person wear glasses (yes/no): ";cin>>ans.glasses;ans.glasses=normalize_yes_no(ans.glasses);asked[q]=true;asked_now++;continue;}
                if(q==9){cout<<"Is the person considered old (yes/no): ";cin>>ans.old;ans.old=normalize_yes_no(ans.old);asked[q]=true;asked_now++;continue;}
                if(q==8){cout<<"Has the person worked overseas (yes/no): ";cin>>ans.overseas;ans.overseas=normalize_yes_no(ans.overseas);asked[q]=true;asked_now++;continue;}
                if(q==7){cout<<"Does the person have kids (yes/no): ";cin>>ans.kids;ans.kids=normalize_yes_no(ans.kids);asked[q]=true;asked_now++;continue;}
                if(q==6){cout<<"Is the person married (yes/no): ";cin>>ans.married;ans.married=normalize_yes_no(ans.married);asked[q]=true;asked_now++;continue;}
                if(q==5){cout<<"Has the person worked in dramas (yes/no): ";cin>>ans.dramas;ans.dramas=normalize_yes_no(ans.dramas);asked[q]=true;asked_now++;continue;}
            }
        }
    }
}

int main(){
    initialize_celebrities();
    Answers ans;
    ans.gender="";ans.hair="";ans.height="";ans.sportsperson="";ans.singer="";
    ans.dramas="";ans.married="";ans.kids="";ans.overseas="";ans.old="";ans.glasses="";ans.personality="";ans.beard="";
    ans.famous_drama="";ans.famous_song="";ans.nickname="";

    bool alive[TOTAL];
    for(int i=0;i<TOTAL;i++) alive[i]=true;

    bool asked[16];
    for(int i=0;i<16;i++) asked[i]=false;

    while(true){
        ask_next_five(ans,asked,alive);
        int g=best_guess(ans,alive);
        cout<<"\nMy guess is: "<<name[g]<<"\nWas my guess correct? (yes/no): ";
        string yn;cin>>yn;yn=normalize_yes_no(yn);
        if(yn=="yes") break;
        alive[g]=false;
        if(count_candidates(ans,alive)<=1){
            int last=-1;
            for(int i=0;i<TOTAL;i++) if(alive[i]&&consistent(i,ans)) last=i;
            if(last==-1) for(int i=0;i<TOTAL;i++) if(alive[i]){last=i;break;}
            cout<<"\nMy guess is: "<<name[last]<<"\nWas my guess correct? (yes/no): ";
            cin>>yn;yn=normalize_yes_no(yn);
            if(yn=="yes") break;
            alive[last]=false;
        }
    }
    return 0;
}
