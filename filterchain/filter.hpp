#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <set>
using namespace std;
class Filter;
class FilterChain;


class Filter{
    protected:
        virtual void preHandler(string &request, string &response){
            cout<<"default preHandler"<<endl;
        }
        virtual void postHandler(string &request, string &response){
            cout<<"default postHandler"<<endl;
        }
    public:
        virtual void doFilter(string &request, string &response, FilterChain * chain);
};


class FilterChain{
    protected:
        vector<shared_ptr<Filter>> filters;
        int index=0;
    public:
        void doFilter(string &request, string &response);
        void addFilter(shared_ptr<Filter> filter){
            filters.push_back(filter);
        }
};




class SecureFilter:public Filter{
    protected:
        virtual void preHandler(string &request, string &response){
            cout<<"SecureFilter preHandler"<<endl;
            static set<char> blacklist={
                '|','&','<','>'
            };
            string new_request;
            for(auto c:request){
                if(blacklist.count(c)==0){
                    new_request+=c;
                }
            }
            request=new_request;
        }
};

class UpplerCaseFilter:public Filter{
    bool isLowerCase(char c){
        return c>='a' && c<='z';
    }
    protected:
        virtual void postHandler(string &request, string &response){
            cout<<"UpplerCaseFilter postHandler"<<endl;
            string new_response;
            for(auto c:response){
                if(isLowerCase(c)){
                    new_response+=c-'a'+'A';
                }
                else{
                    new_response+=c;
                }
            }
            response=new_response;
        }
};



void FilterChain::doFilter(string &request, string &response){
    if(index>=filters.size()){
        response = request;
        return;
    }
    filters[index++]->doFilter(request, response, this);
}



void Filter::doFilter(string &request, string &response, FilterChain * chain){
    preHandler(request, response);
    chain->doFilter(request, response);
    postHandler(request, response);
}
