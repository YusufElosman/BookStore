#ifndef yazarlar_H
#define yazarlar_H
#include <string>
using namespace std;
class yazarlar
{
public:
	void print() const;
	void setYazar(string isim);
	string getYazar();
	yazarlar();
	~yazarlar();
private:
	string yIsim;
};
#endif
