class Solution {
public:
    int countOfSubstrings(string str, int k) {
        // // map<string,bool> mp;
        // // mp["a"]=1;
        // // mp["e"]=1;
        // // mp["i"]=1;
        // // mp["o"]=1;
        // // mp["u"]=1;
        int countA=0;
        int countE=0;
        int countI=0;
        int countO=0;
        int countU=0;
        // for(int i=0;i<word.size();i++){
        //     if(word[i]=='a'){
        //         countA++;
        //     }
        //     else if(word[i]=='e'){
        //         countE++;
        //     }
        //     else if(word[i]=='i'){
        //         countI++;
        //     }
        //     else if(word[i]=='o'){
        //         countO++;
        //     }
        //     else if(word[i]=='u'){
        //         countU++;
        //     }
        // }

        // // return min(countA,min(countE,min(countI,min(countO,countU))));
        // cout<<countA<<" "<<countE<<" "<<countI<<" "<<countO<<" "<<countU;
        // return 0;
        int count=0;
        int kCount=0;
        for (int i = 0; i < str.length(); i++) {
        string subStr;
        kCount=0;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
            // subStr += str[j];
            if(str[j]=='a'){
                countA++;
            }
            else if(str[j]=='e'){
                countE++;
            }
            else if(str[j]=='i'){
                countI++;
            }
            else if(str[j]=='o'){
                countO++;
            }
            else if(str[j]=='u'){
                countU++;
            }
            else{
                kCount++;
            }
            if(kCount==k+1){
                break;
            }
            if(countA && countE && countI && countO && countU && kCount==k){
                count++;
                // countA=0;
                // countE=0;
                // countI=0;
                // countO=0;
                // countU=0;
                // break;
            }
        }
        countA=0;
        countE=0;
        countI=0;
        countO=0;
        countU=0;
        

    }
    return count;


    }
};