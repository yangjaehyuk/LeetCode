class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for(int i=0;i<asteroids.size();i++){
            int a=asteroids[i];
            if(stack.size()==0){
                stack.push_back(a);
            }
            else{
                if(stack[stack.size()-1] * a > 0){
                    stack.push_back(a);
                }
                else{
                    if(stack[stack.size()-1]<0){
                        stack.push_back(a);
                    }
                    else{
                        int res=stack[stack.size()-1]+a;
                        if(res==0){
                            stack.pop_back();
                            continue;
                        }
                        else if(res<0){
                            while(true){
                                stack.pop_back();
                                stack.push_back(a);
                                if(stack.size()==1) break;
                                else{
                                    if(stack[stack.size()-2]*stack[stack.size()-1]>0){
                                    break;
                                    }
                                    else{
                                        if(stack[stack.size()-2]<0){
                                        break;
                                    }
                                    else{
                                        int tmp=stack[stack.size()-2]+stack[stack.size()-1];
                                        if(tmp>0){
                                            stack.pop_back();
                                            break;
                                        }
                                        else if(tmp==0){
                                            stack.pop_back();
                                            stack.pop_back();
                                            break;
                                        }
                                        else{
                                            stack.pop_back();
                                            stack.pop_back();
                                            stack.push_back(a);
                                        }
                                    }
                                    }
                                }
                            }
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
        }
    return stack;
    }
};