#include<bits/stdc++.h>
#define N 10000
using namespace std;

/*
    rules-
    first m students will be alloted the teachers they go, and then it will be on basis of cpi and then it will be random alloted.
*/

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
    return (a.second < b.second); 
}


int main()
{
    cout<<endl<<endl<<"\t\tWELCOME TO MENTOR ALLOCATION PROGRAM"<<endl<<endl;
    int no_of_students, no_of_mentors, temp;
    cout<<"NUMBER OF STUDENTS ARE :- ";
    cin>>no_of_students;
    cout<<"NUMBER OF TEACHERS ARE :- ";
    cin>>no_of_mentors;
    cout<<endl;

    vector<pair<int,int> >cpiv; // cpiv is the vector of student's cpi
    vector<int> t[no_of_mentors+1],p[no_of_students+1]; 
    // t[] vector will be the index of student which will be selected by the teacher.
    // p[] is students pereference list.
    
    int selection[N]={0}; // wether a student is selected
    int MAX_LIMIT = no_of_students/no_of_mentors+1; // maximum a teacher can have

    cout<<"ENTER THE DATA OF STUDENTS IN THE ORDER THEY APPLY."<<endl<<endl;

    int pu,cgpa;
    // pu - NO. OF TEACHERS VISITED AND TEACHERS ID
    for (int i = 1; i <= no_of_students; ++i){
            cout<<"ENTER CPI OF "<<i<<"TH STUDENT :- ";
            cin>>cgpa;
            cpiv.push_back(make_pair(i,cgpa));
            cout<<"ENTER NO. OF TEACHERS VISITED :- ";
            cin>> pu;
            //enter in order of visit. value should be greater than 0.
            cout<<"INDEX OF TEACHERS VISITED :- ";
            for(int j=0;j<pu;++j){
                  cin>>temp;
                  p[i].push_back(temp);
            } 
            // allocation of first m students
            if(i<=no_of_mentors){   // 1st m students
                    for(auto z : p[i]){
                            if( t[z].size() < MAX_LIMIT){ 
                                t[z].push_back(i);
                                selection[i]=1;
                                break;
                            }
                            else continue;
                    }
            }
            cout<<endl;
    }
    sort(cpiv.begin(), cpiv.end(), sortbysec);

    cout<<"ENTER THE CUTOFF CPI FOR EACH TEACHER AFTER THE FIRST M STUDENTS"<<endl;
     
    int cutoff[no_of_mentors+1];

    for (int i = 1; i <= no_of_mentors; ++i){
         cin>>cutoff[i];    
    }
    cout<<endl;
    for (vector<pair<int ,int> >::reverse_iterator  i = cpiv.rbegin(); i != cpiv.rend(); ++i ){
            if(selection[i->first]==1) continue;    // if selected continue
            for(auto z : p[i->first]){
                    if( t[z].size() < MAX_LIMIT  && cutoff[z] <= i->second){   
                        t[z].push_back(i->first);
                        selection[i->first]=1;
                        break;
                    }
                    else continue;
            }
    }

    for(int i=1;i<=no_of_students;++i){
        if(selection[i]==1) continue;
        for(int j=1;j<=no_of_mentors;++j){
            if(t[j].size()<MAX_LIMIT){
                t[j].push_back(i);
                selection[i]=1;
                break;
            }
        }
    }

    cout<<"TEACHER'S INDEX\tALLOCATED STUDENTS"<<endl;
    for(int i=1;i<=no_of_mentors;++i){
        cout<<i<<"\t\t\t";
        for(auto v : t[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}
