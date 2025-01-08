class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        string temp="";
        int sizeOfTemp=0;
        int count=0;
        for(int i=0;i<words.size();i++){
            temp=words[i];
            sizeOfTemp=temp.size();
            for(int j=i+1;j<words.size();j++){
                    int wordSize=words[j].size();
                    if(sizeOfTemp <= wordSize){
                        int k=0;
                        bool prefixCheck=true;
                        bool suffixCheck=true;
                        while(k<temp.size()){
                            if(words[j][k]!=temp[k]){
                                prefixCheck=false;
                                break;
                            }k++;
                        }
                        k=words[j].size()-1;
                        int tempSize=sizeOfTemp-1;
                        while(prefixCheck && tempSize>=0){
                            if(words[j][k]!=temp[tempSize]){
                                suffixCheck=false;
                                break;
                            }
                            k--;
                            tempSize--;
                        }
                        if(prefixCheck && suffixCheck){
                            count++;
                        }
                    }
            }
        }
        return count;
    }
};