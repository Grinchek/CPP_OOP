#pragma once
#include"Service.h"
#include<vector>
#include <conio.h>
#include<fstream>
class Post
{
private:
	vector<Service> accepted;
	vector<Service>  complited;
public:
	Post() :accepted(0), complited(0){ }
	void ShowAccepted();
	void ShowComplited();
	Date SetDate();
	Service Feel();
	void Accept(Service item);
	void Complit(Service item);
	void DeleteElement(vector<Service>& vec,int index);
	void EditElement(vector<Service>& vec, int index, Service elem);
	vector<int> SearchByName(vector<Service>& vec);
	int GetAcceptedSize();
	int GetComplitedSize();
	vector<Service>& GetAcceptedList();
	vector<Service> GetComplitedList();
	void GetFromFileAccept();
	void WrteToFileAccept();
	void GetFromFileCompl();
	void WrteToFileCompl();
};

