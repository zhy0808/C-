#include "string.h"

int main()
{
	/*zhy::string s1("123456789");
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	zhy::string s2(s1);
	cout << s2[1] << endl;
	zhy::string s3;
	s3 = s2;
	zhy::string s4;
	s4 = "12345";
	cout << s4[2] << endl;
	
	s4.push_back('1');
	s4.append("zhy");
	s4 += 'v';
	s4 += "zhy200108";
	cout << s4.c_str() << endl;*/

	/*bit::string s1("12345");
	bit::string s2(s1);*/


	/*zhy::string s1("12345");
	zhy::string s2(s1);
	s2.push_back('a');
	s2.append("bcd");
	cout << s2.c_str() << endl;
	auto it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << endl;
		it++;
	}
	s2 = "hello world";
	cout << s2.c_str() << endl;
	cout << s2[3] << endl;*/

	//zhy::string s1("12345");
	//s1 += "12345";
	////s1.resize(-1,'a');
	//cout << s1.c_str() << endl << s1.size() << endl;
	/*zhy::string s2;
	s2 += s1;
	cout << s2.size() << endl;
	cout << s2.c_str() << endl;*/

	zhy::string s1;
	s1.insert(0, "123");
	s1 += "1234";
	cout << s1 << endl;
	/*s1.insert(6, "my ");
	cout << s1.c_str() << endl;*/
	/*cout << s1.find('o', 3) << endl;
	cout << s1.find("wor", 4) << endl;*/
	/*s1.erase(14,1);
	cout << s1.c_str() << endl;
	cout << s1 << endl;
	zhy::string s2(s1);*/
	//s2 += 'k';
	/*cout << (s1 < s2) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 != s2) << endl;*/
	

	system("pause");
	return 0;
}

