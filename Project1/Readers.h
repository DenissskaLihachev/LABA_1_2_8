#pragma once
#pragma once

#include "Nuzhnoe.h"

class DataPerson
{
protected:
	virtual void setName(string) = 0;
	virtual void setInfo(string) = 0;
	virtual void setRefPer(string) = 0;
	virtual void setReaderData(string, string, string) = 0;

	virtual string getName() = 0;
	virtual string getInfo() = 0;
	virtual string getRefPer() = 0;
	virtual string getReaderData() = 0;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class RegularReader : public DataPerson
{
protected:
	string FIO;
	string NumberTicket;
	string BookName;
public:
	RegularReader();
	RegularReader(string FIO, string NumberTicket, string BookName);
	void setName(string FIO)override { this->FIO = FIO; }
	void setInfo(string NumberTicket)override { this->NumberTicket = NumberTicket; }
	void setRefPer(string BookName)	override { this->BookName = BookName; }
	void setReaderData(string FIO, string NumberTicket, string BookName) override {
		this->FIO = FIO;
		this->NumberTicket = NumberTicket;
		this->BookName = BookName;
	}

	string getName()		override { return FIO; }
	string getInfo()		override { return NumberTicket; }
	string getRefPer()		override { return BookName; }
	string getReaderData()	override { return "ФИО: " + FIO + " Номер билета: " + NumberTicket + " Назание книги: " + BookName; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TemporaryReader : public DataPerson
{
protected:
	string CurrentTerm;
	string NumberOfBooksTaken;
	string BookName;
public:
	TemporaryReader();
	TemporaryReader(
		string CurrentTerm,
		string NumberOfBooksTaken,
		string BookName
	);
	void setName(string CurrentTerm)		override { this->CurrentTerm = CurrentTerm; };
	void setInfo(string NumberOfBooksTaken)		override { this->NumberOfBooksTaken = NumberOfBooksTaken; };
	void setRefPer(string BookName)	override { this->BookName = BookName; };
	void setReaderData(string CurrentTerm, string NumberOfBooksTaken, string BookName) override {
		this->CurrentTerm = CurrentTerm;
		this->NumberOfBooksTaken = NumberOfBooksTaken;
		this->BookName = BookName;
	}
	string getName()		override { return CurrentTerm; };
	string getInfo()		override { return NumberOfBooksTaken; };
	string getRefPer()		override { return BookName; };
	string getReaderData()	override {
		return "Срок сдачи книги: "
			+ CurrentTerm + " Количество взятых книг: "
			+ NumberOfBooksTaken + " Название текущей книги: " + BookName;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DataProduct
{
protected:
	string BookType;
	string typeOfProduct;
	string refoundPeriod;
	//string ReaderNumber;
	//string ReaderAddress;
	int numberOfBooks;
	int totalNumberOfBooks;
public:
	DataProduct();
	DataProduct(
		string BookType,
		string typeOfProduct,
		string refoundPeriod,
		//string ReaderNumber,
		//string ReaderAddress,
		int numberOfBooks,
		int totalNumberOfBooks
	);
	void setProductName(string BookType) { this->BookType = BookType; };
	void setTypeOfProduct(string typeOfProduct) { this->typeOfProduct = typeOfProduct; };
	void setPaymentDay(string refoundPeriod) { this->refoundPeriod = refoundPeriod; };
	//void setVendorINN(string ReaderNumber) { this->ReaderNumber = ReaderNumber; };
	//void setCompanyAddress(string ReaderAddress) { this->ReaderAddress = ReaderAddress; };
	void setNumberOfProduct(int numberOfBooks) { this->numberOfBooks = numberOfBooks; };
	void setSumOfProduct(int totalNumberOfBooks) { this->totalNumberOfBooks = totalNumberOfBooks; };

	string  getBookName() { return this->BookType; };
	string  getTypeOfBook() { return this->typeOfProduct; };
	string  getRefoundPeriod() { return this->refoundPeriod; };
	//string  getVendorINN() { return this->ReaderNumber; };
	//string  getCompanyAddress() { return this->ReaderAddress; };
	int		getNumberOfBooks() { return this->numberOfBooks; };
	int		getTotalNumberOfBooks() { return this->totalNumberOfBooks; };
	string	getDataProduct();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListBook : public TemporaryReader, public RegularReader, public DataProduct
{
public:
	ListBook* next;
	ListBook* prev;
	bool temporaryReader;
	ListBook();
	ListBook(
		ListBook* next,
		ListBook* prev,
		bool temporaryReader,
		string BookType,
		string typeOfBook,
		string refoundPeriod,
		//string ReaderNumber,
		//string ReaderAddress,
		int numberOfBooks,
		int totalNumberOfBooks,
		string FIO,
		string NumberTicket,
		string CurrentTerm,
		string NumberOfBooksTaken,
		string BookName
	);
	void nextItem();
	void prevItem();
	ostream& operator << (ostream& os);
	istream& operator >> (ostream& os);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListOfReaders
{
private:
	ListBook* reader = NULL;
	ListBook* head = NULL;
	ListBook* tail = NULL;
	//string ReaderNumber = { "88005553535" };
	//string ReaderAddress = { "622966, Калининградская область, город Кашира, пл. Балканская, 27" };
	void swapAndDelClients();
	void transform();
	void show();
public:
	void operator[]			(const int index);
	operator int() const;
	void addReaders();
	void sortReaders();
	void transformReaders();
	void delReaders();
	void showReaders();
	void searchReaders();
	void save();
	void load();
};