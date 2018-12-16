#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define compareFunc( a, b) (difftime((a).time ,(b).time) >0?true:(difftime((a).time ,(b).time) <0?false:((a.priority <b.priority)?true:false)))

template<class ObjType>
class heap{
	//this is a minheap
	vector<ObjType>vec;
	
	public:
		heap()
		{
			
		}
		~heap(){;}
		int parent(int child)
		{
			return child>0?(child-1)/2:-1;
		}
		int left(int parent)
		{
			return 2*parent+1;
		}
		int right(int parent)
		{
			return 2*parent+2;
		}
		
		
 void insert(ObjType value)
	{
		vec.push_back(value);
		insert_balance(vec.size()-1);
	
	};
 void insert_balance(int node)
	{
		int p = parent(node);
		if(p>=0&& compareFunc(vec.at(p), vec.at(node)))
		{
			ObjType temp = vec.at(node);
			vec.at(node) = vec.at(p);
			vec.at(p) = temp;
			insert_balance(p);
		}
	}
ObjType get_root()
	{
		if(vec.size() ==0)return {} ;
		 else return vec.front();
	}
bool isEmpty()
{
           return (vec.size() >0);
}
 int size()
{
           return vec.size();
}
ObjType popOut()
	{
        ObjType temp = get_root();
        delete_root();
        return temp;
	}
void delete_root()
	{
		if(vec.size() ==0)
		{
			cout<< "Empty heap\n";
		}
		
		else
		{
			vec.front() = vec.back();
			vec.pop_back();
			delete_balance(0);
		}
	}
 void delete_balance(int node)
	{
		int l = left(node);
		int r = right(node);
		int child = l;
		
		if(l<vec.size() && r<vec.size() && compareFunc(vec.at(l) , vec.at(r)))
		{
			child = r;
		}
		if(child <vec.size()&& compareFunc( vec.at(node) , vec.at(child)))
		{
			ObjType temp = vec.at(child);
			vec.at(child) = vec.at(node);
			vec.at(node) = temp;
			delete_balance(child);
		}
	}
	
virtual void print_heap(){
	
	size_t size = vec.size();
	
	for(int i=0;i<size;++i)
	std::cout << vec.at(i).name <<"   "<<vec.at(i).time <<"  "<< vec.at(i).priority <<"  "<<'\n';

	cout<<endl;
}
};