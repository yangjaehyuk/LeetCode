class Solution {
public:
    string intToRoman(int num) {
        char str1[7]={'I','V','X','L','C','D','M'};
        string str2[6]={"IV","IX","XL","XC","CD","CM"};
        string ans;
        int container1[7]={1,5,10,50,100,500,1000};
        int container2[6]={4,9,40,90,400,900};
        map<int,string> arr;
        for(int i=0;i<7;i++){
            arr[container1[i]]=str1[i];
        }
        for(int i=0;i<6;i++){
            arr[container2[i]]=str2[i];
        }
        while(true){
            if(num==0) break;
            
            if(num>=1000){
                ans+=arr[1000];
                num-=1000;
            }
            else if(num>=900){
                ans+=arr[900];
                num-=900;
            }
            else if(num>=500){
                ans+=arr[500];
                num-=500;
            }
            else if(num>=400){
                ans+=arr[400];
                num-=400;
            }
            else if(num>=100){
                ans+=arr[100];
                num-=100;
            }
            else if(num>=90){
                ans+=arr[90];
                num-=90;
            }
            else if(num>=50){
                ans+=arr[50];
                num-=50;
            }
            else if(num>=40){
                ans+=arr[40];
                num-=40;
            }
            else if(num>=10){
                ans+=arr[10];
                num-=10;
            }
            else if(num>=9){
                ans+=arr[9];
                num-=9;
            }
            else if(num>=5){
                ans+=arr[5];
                num-=5;
            }
            else if(num>=4){
                ans+=arr[4];
                num-=4;
            }
            else if(num>=1){
                ans+=arr[1];
                num-=1;
            }
        }
        return ans;
    }
};