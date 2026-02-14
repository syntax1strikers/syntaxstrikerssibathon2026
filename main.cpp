#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

static string to_lowercase(string s){
    for(char &ch : s){
        if(ch >= 'A' && ch <= 'Z') ch = char(ch + 32);
    }
    return s;
}

static string normalizeYN(string s){
    s = to_lowercase(s);
    if(s=="y"||s=="yes") return "yes";
    if(s=="n"||s=="no")  return "no";
    if(s=="idk"||s=="skip"||s=="unknown") return "unknown";
    return s;
}

struct Person{
    string name;
    unordered_map<string, bool> fact;
};

struct Question{
    string key;
    string prompt;
    bool is_general;
};

vector<Person> people;
vector<Question> questions;

static void add_person(const string &name, initializer_list<pair<string,bool>> facts){
    Person p;
    p.name = name;
    for(const auto &kv : facts) p.fact[kv.first] = kv.second;
    people.push_back(std::move(p));
}

static void init_questions(){
    questions = {
        {"is_male",   "Is your celebrity male? (y/n): ", true},
        {"is_singer", "Are they primarily known as a singer? (y/n): ", true},
        {"worked_in_india", "Have they worked in India / Indian projects? (y/n): ", true},

        {"worked_in_coke_studio", "Have they worked in Coke Studio? (y/n): ", false},
        {"wears_glasses", "Do they often wear glasses? (y/n): ", false},
        {"married", "Are they married? (y/n): ", false},

        {"song_tajdare_haram", "Is their signature song 'Tajdar-e-Haram'? (y/n): ", false},
        {"song_dil_diyan_gallan", "Is their signature song 'Dil Diyan Gallan'? (y/n): ", false},
        {"song_tera_woh_pyar", "Is their signature song 'Tera Woh Pyar'? (y/n): ", false},
        {"song_provinces_pakistan", "Are they famous for songs about all provinces of Pakistan? (y/n): ", false},

        {"drama_humsafar", "Is their signature drama 'Humsafar'? (y/n): ", false},
        {"drama_mere_pas_tum_ho", "Is their signature drama 'Mere Paas Tum Ho'? (y/n): ", false},
        {"drama_khaani", "Is their signature drama 'Khaani'? (y/n): ", false},
        {"drama_sher", "Is their signature drama 'Sher'? (y/n): ", false},
        {"drama_khuda_aur_mohabbat", "Is their signature drama 'Khuda Aur Mohabbat'? (y/n): ", false},
        {"drama_pyare_afzal", "Is their signature drama 'Pyare Afzal'? (y/n): ", false},
        {"drama_yaqeen_ka_safar", "Is their signature drama 'Yaqeen Ka Safar'? (y/n): ", false},
        {"drama_kabhi_main_kabhi_tum", "Is their signature drama 'Kabhi Main Kabhi Tum'? (y/n): ", false},
        {"drama_ishq_murshid", "Is their signature drama 'Ishq Murshid'? (y/n): ", false},
        {"drama_baaghi", "Is their signature drama 'Baaghi'? (y/n): ", false},

        {"drama_tere_bin", "Is their signature drama 'Tere Bin'? (y/n): ", false},
        {"drama_sinf_e_ahan", "Have they worked in the drama 'Sinf-e-Aahan'? (y/n): ", false},
        {"best_couple_wahaj", "Are they famous as an on-screen couple with Wahaj Ali? (y/n): ", false},

        {"is_cricketer", "Are they known as a cricketer? (y/n): ", true},
        {"retired", "Are they retired? (y/n): ", false},
        {"ex_husband_of_sania", "Are they the ex-husband of Sania Mirza? (y/n): ", false},
        {"married_to_sana_javed", "Are they married to Sana Javed? (y/n): ", false},
        {"son_in_law_shaheen", "Is their son-in-law Shaheen Afridi? (y/n): ", false},
        {"nickname_lala_boom_boom", "Are they known as 'Lala / Boom Boom'? (y/n): ", false},
        {"pathan", "Are they Pathan? (y/n): ", false},
        {"ex_captain_pakistan", "Were they an ex-captain of Pakistan? (y/n): ", false},
        {"meme_with_hania", "Are they famous for a meme-relationship with Hania Amir? (y/n): ", false},
        {"trolled_weak_english", "Are they trolled for weak English? (y/n): ", false},
        {"clean_shaved", "Are they known for being clean-shaved? (y/n): ", false},
        {"rumoured_with_urvashi", "Were they rumoured to be in a relationship with Urvashi Rautela? (y/n): ", false},

        {"married_to_shoaib_malik", "Are they married to Shoaib Malik? (y/n): ", false},
        {"ex_husband_umair_jaiswal", "Were they previously married to Umair Jaiswal? (y/n): ", false},

        {"is_influencer", "Are they an influencer / content creator? (y/n): ", true},
        {"makes_instagram_reels", "Do they make Instagram reels? (y/n): ", false},
        {"wears_abaya", "Do they wear an abaya in their videos? (y/n): ", false},
        {"dialogue_hum_mazhabi_gharane", "Are they known for the dialogue 'Hum Mazhabi Gharane Se Hain'? (y/n): ", false},
        {"dialogue_ouch_ouch", "Are they known for saying 'Ouch Ouch' in videos? (y/n): ", false},

        {"worked_with_shah_rukh", "Have they worked with Shah Rukh Khan? (y/n): ", false},
        {"best_couple_fawad", "Are they best known as an on-screen couple with Fawad Khan? (y/n): ", false},
        {"married_to_danish", "Are they married to Danish Taimoor? (y/n): ", false},
        {"husband_of_ayeza", "Are they Ayeza Khan's husband? (y/n): ", false},
        {"rel_with_sajal", "Were they in a relationship with Sajal Aly? (y/n): ", false},
        {"rel_with_asim", "Were they in a relationship with Asim Azhar? (y/n): ", false},
        {"engaged_meerub", "Were they engaged to Meerub Ali? (y/n): ", false},
        {"married_ahad_then_divorced", "Were they married to Ahad Raza Mir (and later divorced)? (y/n): ", false},

        {"serious_roles", "Are they mainly known for serious roles? (y/n): ", false},
        {"strong_female_roles", "Are they known for strong female personality roles? (y/n): ", false},

        {"movie_creature_3d", "Did they work in the Indian movie 'Creature 3D'? (y/n): ", false},
        {"movie_maula_jutt", "Were they in the movie 'Maula Jatt'? (y/n): ", false},
        {"movie_jawani_phir_nahi_ani", "Were they in 'Jawani Phir Nahi Ani'? (y/n): ", false},
        {"movie_mere_brother_ki_dulhan", "Did they work in 'Mere Brother Ki Dulhan'? (y/n): ", false},
        {"movie_hindi_medium", "Did they work in the movie 'Hindi Medium'? (y/n): ", false},
    };
}

static void init_people(){
    people.clear();

    add_person("Atif Aslam", {
        {"is_male", true},{"is_singer", true},{"worked_in_india", true},
        {"worked_in_coke_studio", true},{"song_tajdare_haram", true},{"song_dil_diyan_gallan", true},
        {"married", true}
    });

    add_person("Mahira Khan", {
        {"is_male", false},{"is_singer", false},{"worked_in_india", true},
        {"drama_humsafar", true},{"worked_with_shah_rukh", true},{"best_couple_fawad", true},
        {"married", true}
    });

    add_person("Ayeza Khan", {
        {"is_male", false},{"is_singer", false},{"worked_in_india", false},
        {"drama_mere_pas_tum_ho", true},{"drama_pyare_afzal", true},{"married_to_danish", true},
        {"married", true}
    });

    add_person("Feroz Khan", {
        {"is_male", true},{"is_singer", false},{"worked_in_india", false},
        {"drama_khaani", true},{"drama_khuda_aur_mohabbat", true},{"serious_roles", true},{"rel_with_sajal", true},
        {"married", true}
    });

    add_person("Danish Taimoor", {
        {"is_male", true},{"is_singer", false},{"worked_in_india", false},
        {"drama_sher", true},{"serious_roles", true},{"husband_of_ayeza", true},
        {"married", true}
    });

    add_person("Imran Abbas", {
        {"is_male", true},{"is_singer", false},{"worked_in_india", true},
        {"drama_khuda_aur_mohabbat", true},{"movie_creature_3d", true},
        {"married", false}
    });

    add_person("Hamza Ali Abbasi", {
        {"is_male", true},{"is_singer", false},{"worked_in_india", false},
        {"drama_pyare_afzal", true},{"movie_maula_jutt", true},{"movie_jawani_phir_nahi_ani", true},
        {"married", true}
    });

    add_person("Sajal Aly", {
        {"is_male", false},{"is_singer", false},{"worked_in_india", false},
        {"drama_yaqeen_ka_safar", true},{"married_ahad_then_divorced", true},
        {"married", false}
    });

    add_person("Asim Azhar", {
        {"is_male", true},{"is_singer", true},{"worked_in_india", true},
        {"worked_in_coke_studio", true},{"song_tera_woh_pyar", true},{"wears_glasses", true},{"engaged_meerub", true},
        {"married", false}
    });

    add_person("Hania Amir", {
        {"is_male", false},{"is_singer", false},{"worked_in_india", false},
        {"drama_kabhi_main_kabhi_tum", true},{"rel_with_asim", true},
        {"married", false}
    });

    add_person("Bilal Abbas", {
        {"is_male", true},{"is_singer", false},{"worked_in_india", false},
        {"drama_ishq_murshid", true},
        {"married", false}
    });

    add_person("Ali Zafar", {
        {"is_male", true},{"is_singer", true},{"worked_in_india", true},
        {"song_provinces_pakistan", true},{"movie_mere_brother_ki_dulhan", true},
        {"married", false}
    });

    add_person("Saba Qamar", {
        {"is_male", false},{"is_singer", false},{"worked_in_india", true},
        {"drama_baaghi", true},{"strong_female_roles", true},{"movie_hindi_medium", true},
        {"married", false}
    });

    add_person("Yumna Zaidi", {
        {"is_male", false},{"is_singer", false},{"worked_in_india", false},
        {"drama_tere_bin", true},{"drama_sinf_e_ahan", true},{"best_couple_wahaj", true},
        {"married", false}
    });

    add_person("Shoaib Malik", {
        {"is_male", true},{"is_cricketer", true},{"retired", true},
        {"ex_husband_of_sania", true},{"married_to_sana_javed", true},
        {"married", true}
    });

    add_person("Shahid Afridi", {
        {"is_male", true},{"is_cricketer", true},{"retired", true},
        {"son_in_law_shaheen", true},{"nickname_lala_boom_boom", true},{"pathan", true},
        {"married", true}
    });

    add_person("Babar Azam", {
        {"is_male", true},{"is_cricketer", true},{"ex_captain_pakistan", true},{"meme_with_hania", true},{"trolled_weak_english", true},
        {"married", false}
    });

    add_person("Naseem Shah", {
        {"is_male", true},{"is_cricketer", true},{"clean_shaved", true},{"rumoured_with_urvashi", true},
        {"married", false}
    });

    add_person("Sana Javed", {
        {"is_male", false},{"is_singer", false},{"worked_in_india", false},
        {"drama_khaani", true},{"ex_husband_umair_jaiswal", true},{"married_to_shoaib_malik", true},
        {"married", true}
    });

    add_person("Sparrow", {
        {"is_male", true},{"is_influencer", true},
        {"makes_instagram_reels", true},{"wears_abaya", true},{"dialogue_hum_mazhabi_gharane", true},{"dialogue_ouch_ouch", true},
        {"married", false}
    });
}
