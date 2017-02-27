#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

/*structs*/
struct like{
string likers;
};
struct block{
string blocked;
};
struct post{
int id;
string text;
string pixel;
vector <like> l1;
};
struct followers{
string follower;
};
struct user{

/*convert a string to int*/
string name;
string comment;
vector <post> p1;
vector <followers> f1;
vector <block> b1;
};
int strtoint(string str){
int b = atoi(str.c_str());
return b;
}

/*calculation function for pixels*/
int strtopixel(string str){
    int div= str.find_first_of("x");
    string first = str.substr(0,div);
    string second = str.substr(div+1,str.length());
    int result = strtoint(first) * strtoint(second);
    return result;

}

/*main class-all void functions included here*/
class Twitter{
public:
    /*main vector*/
vector<user> v1;

/*functions*/
void addUser(string name,string comment,std::ofstream& os){
user users;
users.name= name;
users.comment=comment;
unsigned int off=0;
for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
           off=1;
        }
}
if(off==1)
{
     os<<"Err: The user "<<name<<" has already been created."<<endl;
     cout<<"Err: The user "<<name<<" has already been created."<<endl;
}
else{
    v1.push_back(users);
    os<<"User '"<<name<<"' has been created"<<endl;
    cout<<"User '"<<name<<"' has been created"<<endl;

}
off=0;
}
void addPost(string name,int id,string text,string pixel,std::ofstream& os){
post p;
p.id = id;
p.text = text;
p.pixel= pixel;
unsigned int ctr;
unsigned int len=0;

     for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
             ctr=i;
        }
        else{
            len++;
        }
    }
     if(len==v1.size())
    {
        os<<"Err: the user '"<<name<<"' could not be found!"<<endl;
         cout<<"Err: the user '"<<name<<"' could not be found!"<<endl;
    }
    else{
        v1[ctr].p1.push_back(p);
    }
}
void rePost(string reposter,string name,int id,std::ofstream& os){
 unsigned int ctr,ctr2,len=0,len2=0,len3=0,off2=0;
 for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
             ctr=i;
        }
        else{
            len++;
            }
    }
    if(len==v1.size())
    {
        os<<"Err: the user '"<<name<<"' could not be found!"<<endl;
        cout<<"Err: the user '"<<name<<"' could not be found!"<<endl;
    }
    else{
     for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name!=reposter)
        {
            len2++;
        }
    }

       if(len2==v1.size())
    {
         os<<"Err: the user '"<<reposter<<"' could not be found!"<<endl;
         cout<<"Err: the user '"<<reposter<<"' could not be found!"<<endl;
    }
    else{
        for(unsigned int i=0;i<v1[ctr].p1.size();i++)
    {
             if(v1[ctr].p1[i].id == id)
             {
                 ctr2=i;
             }
             else{
                len3++;
             }
    }
if(len3==v1[ctr].p1.size())
{
    os<<"Err: "<<name<<"'s post could not be found!"<<endl;
        cout<<"Err: "<<name<<"'s post could not be found!"<<endl;
}
else{
     for(unsigned int i=0;i<v1[ctr].b1.size();i++)
    {
        if(v1[ctr].b1[i].blocked==reposter)
        {
            off2=1;
        }
    }
      if(off2==1)
        {
            os<<"Err: the user '"<<name<<"' had blocked '"<<reposter<<"' . You cannot repost a post of '"<<name<<"' !"<<endl;
            cout<<"Err: the user '"<<name<<"' had blocked '"<<reposter<<"' . You cannot repost a post of '"<<name<<"' !"<<endl;
        }
        else{
        addPost(reposter,id,v1[ctr].p1[ctr2].text,v1[ctr].p1[ctr2].pixel,os);
        os<<reposter<<" has reposted "<<name<<"'s post"<<endl;
         cout<<reposter<<" has reposted "<<name<<"'s post"<<endl;
        }
}
    }
}
}
void viewUser(string name,std::ofstream& os){
    unsigned int ctr,len=0,fol=0;
     for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
             ctr=i;
        }
        else{
            len++;
        }

    }
    if(len==v1.size())
    {
        os<<"Err: the user '"<<name<<"' could not be found!"<<endl;
        cout<<"Err: the user '"<<name<<"' could not be found!"<<endl;
    }
    else{
            for(unsigned int i=0;i<v1.size();i++)
            {
                for(unsigned int j=0;j<v1[i].f1.size();j++)
                {
                    if(v1[i].f1[j].follower == name)
                    {
                        fol++;
                    }
                }
            }
        os<<endl;
         cout<<endl;
        os<<"------------------------------------------------"<<endl;
        cout<<"------------------------------------------------"<<endl;
        os<<name<< " following ["<<fol<<"] - blocked ["<<v1[ctr].b1.size()<<"] users - ["<<v1[ctr].p1.size()<<"] posts."<<endl;
         cout<<name<< " following ["<<fol<<"] - blocked ["<<v1[ctr].b1.size()<<"] users - ["<<v1[ctr].p1.size()<<"] posts."<<endl;
        os<<v1[ctr].comment<<endl;
        cout<<v1[ctr].comment<<endl;
        os<<"---------------------Tweets---------------------"<<endl;
        cout<<"---------------------Tweets---------------------"<<endl;
        for(unsigned int i=0;i<v1[ctr].p1.size();i++)
        {
            if(v1[ctr].p1[i].pixel == "null")
            {
                 os<<v1[ctr].p1[i].text<<" - Likes: "<<v1[ctr].p1[i].l1.size()<<endl;
                   cout<<v1[ctr].p1[i].text<<" - Likes: "<<v1[ctr].p1[i].l1.size()<<endl;

            }else{
                 os<<v1[ctr].p1[i].text<<" - TotalSize: ["<<strtopixel(v1[ctr].p1[i].pixel)<<" pixels] - Likes: "<<v1[ctr].p1[i].l1.size()<<endl;
                 cout<<v1[ctr].p1[i].text<<" - TotalSize: ["<<strtopixel(v1[ctr].p1[i].pixel)<<" pixels] - Likes: "<<v1[ctr].p1[i].l1.size()<<endl;
            }

        }
         os<<"------------------------------------------------"<<endl;
           cout<<"------------------------------------------------"<<endl;

    }

}
void blockUser(string name,string blockedp,std::ofstream& os){
block b;
     b.blocked = blockedp;
     unsigned int ctr,ctr2,off=0,len=0,len2=0;
      for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
             ctr=i;
        }
        else{
            len++;
        }
    }
    if(len==v1.size())
    {
        os<<"Err: the user '"<<name<<"' could not be found!"<<endl;
        cout<<"Err: the user '"<<name<<"' could not be found!"<<endl;
    }
    else{
     for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name!=blockedp)
        {
            len2++;
        }
    }
       if(len2==v1.size())
    {
         os<<"Err: the user '"<<blockedp<<"' could not be found!"<<endl;
         cout<<"Err: the user '"<<blockedp<<"' could not be found!"<<endl;
    }
    else{
  for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==blockedp)
        {
             ctr2=i;
        }
    }
       for(unsigned int i=0;i<v1[ctr].p1.size();i++)
       {
           for(unsigned int j=0;j<v1[ctr].p1[i].l1.size();j++)
           {
                if(v1[ctr].p1[i].l1[j].likers == blockedp)
                {
                     v1[ctr].p1[i].l1.erase(v1[ctr].p1[i].l1.begin()+j);
                }
           }
       }
for(unsigned int i=0;i<v1[ctr].f1.size();i++)
{
    if(v1[ctr].f1[i].follower==blockedp)
    {
        v1[ctr].f1.erase(v1[ctr].f1.begin() +i);
    }
}
 for(unsigned int i=0;i<v1[ctr].b1.size();i++)
    {
        if(v1[ctr].b1[i].blocked==blockedp)
        {
            off=1;
        }
    }
if(off==1)
{
    os<<"Err:" <<name<<" has already blocked "<<blockedp<<"!";
    cout<<"Err:" <<name<<" has already blocked "<<blockedp<<"!";
}
else{
    v1[ctr].b1.push_back(b);
    os<<name<< " has blocked " <<blockedp<<endl;
     cout<<name<< " has blocked " <<blockedp<<endl;
}
    }
}
}
void followUser(string follower,string name,std::ofstream& os){
if(follower==name)
{
    os<<"Err: "<<name<<" cannot follow itself"<<endl;
    cout<<"Err: "<<name<<" cannot follow itself"<<endl;
}
else{
followers f;
     f.follower = follower;
     unsigned int ctr,off=0,len=0,len2=0;
unsigned int off2=0;
      for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
             ctr=i;
        }
        else{
            len++;
        }

    }
    if(len==v1.size())
    {
        os<<"Err: the user '"<<name<<"' could not be found!"<<endl;
        cout<<"Err: the user '"<<name<<"' could not be found!"<<endl;
    }
    else{

     for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name!=follower)
        {
            len2++;
        }
    }

       if(len2==v1.size())
    {
         os<<"Err: the user '"<<follower<<"' could not be found!"<<endl;
         cout<<"Err: the user '"<<follower<<"' could not be found!"<<endl;
    }
    else{
           for(unsigned int i=0;i<v1[ctr].b1.size();i++)
    {
        if(v1[ctr].b1[i].blocked==follower)
        {
            off2=1;
        }
    }

        if(off2==1)
        {
            os<<"Err: the user '"<<name<<"' had blocked '"<<follower<<"'."<<endl;
            cout<<"Err: the user '"<<name<<"' had blocked '"<<follower<<"'."<<endl;
        }
        else{
             for(unsigned int i=0;i<v1[ctr].f1.size();i++)
    {
        if(v1[ctr].f1[i].follower==follower)
        {
            off=1;
        }
    }
if(off==1)
{
    os<<"Err:" <<follower<<" has already followed "<<name<<"!"<<endl;
     cout<<"Err:" <<follower<<" has already followed "<<name<<"!"<<endl;
}
else{
    v1[ctr].f1.push_back(f);
    os<<follower<< " followed " <<name<<endl;
      cout<<follower<< " followed " <<name<<endl;
}
        }
    }
    }
}
}
void likePost(string liker,string name,int id,std::ofstream& os){
    unsigned int len=0,ctr=0,ctr2=0,len2=0,off=0,len3=0,off2=0;
    like l;
    l.likers=liker;
 for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
             ctr=i;
        }
        else{
            len++;
        }
    }
     if(len==v1.size())
    {
        os<<"Err: the user '"<<name<<"' could not be found!"<<endl;
        cout<<"Err: the user '"<<name<<"' could not be found!"<<endl;
    }
    else{
          for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name!=liker)
        {
            len2++;
        }
    }

       if(len2==v1.size())
    {
         os<<"Err: the user '"<<liker<<"' could not be found!"<<endl;
         cout<<"Err: the user '"<<liker<<"' could not be found!"<<endl;
    }
        else{
               for(unsigned int i=0;i<v1[ctr].b1.size();i++)
    {
        if(v1[ctr].b1[i].blocked==liker)
        {
            off2=1;
        }
    }
      if(off2==1)
        {
            os<<"Err: the user '"<<name<<"' had blocked '"<<liker<<"' . You cannot like a post of '"<<name<<"' !"<<endl;
             cout<<"Err: the user '"<<name<<"' had blocked '"<<liker<<"' . You cannot like a post of '"<<name<<"' !"<<endl;

        }
        else{

            for(unsigned int i=0;i<v1[ctr].p1.size();i++)
    {
             if(v1[ctr].p1[i].id == id)
             {
                 ctr2=i;
             }
             else{
                len3++;
             }
    }


if(len3==v1[ctr].p1.size())
{
    os<<"Err: "<<name<<"'s post could not be found!"<<endl;
    cout<<"Err: "<<name<<"'s post could not be found!"<<endl;
}
else{


       for(unsigned int i=0;i<v1[ctr].p1[ctr2].l1.size();i++)
    {
        if(v1[ctr].p1[ctr2].l1[i].likers==liker)
        {
            off=1;
        }
    }

    if(off==1)
    {
        os<<"Err: "<<name<<"'s post had already been liked!"<<endl;
         cout<<"Err: "<<name<<"'s post had already been liked!"<<endl;
    }
    else{
         v1[ctr].p1[ctr2].l1.push_back(l);
        os<<liker<<" has liked "<<name<<"'s post"<<endl;
         cout<<liker<<" has liked "<<name<<"'s post"<<endl;


    }

}

    }
      }

        }



}
void unfollowUser(string unfollower,string name,std::ofstream& os){
    unsigned int len=0,ctr=0,len2=0,len3=0;
 for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name==name)
        {
             ctr=i;
        }
        else{
            len++;
        }
    }

       if(len==v1.size())
    {
        os<<"Err: the user '"<<name<<"' could not be found!"<<endl;
         cout<<"Err: the user '"<<name<<"' could not be found!"<<endl;
    }
    else{
for(unsigned int i=0;i<v1.size();i++)
    {
        if(v1[i].name!=unfollower)
        {
            len2++;
        }
    }

       if(len2==v1.size())
    {
         os<<"Err: the user '"<<unfollower<<"' could not be found!"<<endl;
         cout<<"Err: the user '"<<unfollower<<"' could not be found!"<<endl;
    }
    else{
for(unsigned int i=0;i<v1[ctr].f1.size();i++)
    {
        if(v1[ctr].f1[i].follower == unfollower){
            v1[ctr].f1.erase(v1[ctr].f1.begin()+i);
        os<<name<<" has been unfollowed by "<<unfollower<<endl;
         cout<<name<<" has been unfollowed by "<<unfollower<<endl;
        }
        else{
            len3++;
        }
    }
if(len3==v1[ctr].f1.size())
{
    os<<"Err: "<<name<< " has already been unfollowed by you! You cannot unfollow again."<<endl;
     cout<<"Err: "<<name<< " has already been unfollowed by you! You cannot unfollow again."<<endl;
}
    }
    }
}
};

/*main*/
int main()
{
    string line;
ifstream infile;
  Twitter t1;
   ofstream myfile;
  myfile.open("out.txt");
  infile.open("input.txt");
    while(!infile.eof()){
        getline(infile,line);
    string word[5];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 5){
        ssin >> word[i];
        ++i;
    }
	/*reading file*/
 if(word[0]=="AddUser")
     {
        t1.addUser(word[1],word[2],myfile);
     }
     if(word[0]=="FollowUser")
     {
         t1.followUser(word[1],word[2],myfile);
     }
    if(word[0]=="AddPost")
    {
        if(word[4].find("x") != std::string::npos && word[4].find('x') != 0)
        {
            t1.addPost(word[1],strtoint(word[2]),word[3],word[4],myfile);
        }
        else{
             t1.addPost(word[1],strtoint(word[2]),word[3],"null",myfile);
        }
    }
    if(word[0]=="LikePost")
    {
        t1.likePost(word[1],word[2],strtoint(word[3]),myfile);
    }
     if(word[0]=="UnfollowUser")
     {
           t1.unfollowUser(word[1],word[2],myfile);
     }
       if(word[0]=="BlockUser")
       {
           t1.blockUser(word[1],word[2],myfile);
       }
       if(word[0]=="ViewUser")
       {
            t1.viewUser(word[1],myfile);
       }
        if(word[0]=="Repost")
        {
            t1.rePost(word[1],word[2],strtoint(word[3]),myfile);
        }
    }
    getchar();
}

