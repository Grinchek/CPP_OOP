#pragma once
#include"Service.h"
#include<vector>
#include <conio.h>
class Post
{
private:
	vector<Service> accepted;
	vector<Service>  complited;
public:
	Post() :accepted(0), complited(0){ }
	void Accept();
};

