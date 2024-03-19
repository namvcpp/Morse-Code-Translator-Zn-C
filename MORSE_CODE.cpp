/*

	This program is Morse Code Translator Zn-C. It can help you translate morse code to sentence or sentence to morse code.
    Copyright (C) 2022  Nam Cong Van

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    
*/

#include <bits/stdc++.h>

using namespace std;

string arr_morse_code[60] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-."};
string arr_morse_mean[60] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@"};
int n = 54;

string find_morse_mean(string str)
{
    for(int i = 0 ; i < n ; ++ i)
    {
        if(str == arr_morse_code[i])
        {
            return arr_morse_mean[i];
        }
    }
    return "#";
}

string find_morse_code(string str)
{
    for(int i = 0 ; i < n ; ++ i)
    {

        if(str == arr_morse_mean[i])
        {
            return arr_morse_code[i];
        }
    }
    return "#";
}

string convert_to_morse(string str)
{
    string res, word;
    for(int i = 0 ; i < str.size() ; ++ i)
    {
    	string p;
    	p += str[i];
        if(p == " ")
        {
            res += word;
            res += "/ ";
            word = "";
        }
        else
        {
            word += find_morse_code(p) + " ";
        }
    }
    return res + word;
}

string convert_to_sentence(string str)
{
    string res, letter;
    for(int i = 0 ; i < str.size() ; ++ i)
    {
    	string p;
    	p += str[i];
        if(p == " ")
        {
            res += find_morse_mean(letter);
            letter = "";
        }
        else if(p == "/")
        {
            res += " ";
            ++ i;
        }
        else
        {
            letter += p;
        }
    }
    return res + find_morse_mean(letter);
}

void instruction(){
	cout << "This program is Morse Code Translator Zn-C. It can translate \nfrom morse code to sentence or from sentence to morse code.\n\n";
    cout << "Copyright (C) 2022  Nam Cong Van\n\n";

    cout << "This program is free software: you can redistribute it and/or modify\n";
    cout << "it under the terms of the GNU General Public License as published by\n";
    cout << "the Free Software Foundation, either version 3 of the License, or\n";
    cout << "(at your option) any later version.\n\n";

    cout << "This program is distributed in the hope that it will be useful,\n";
    cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
    cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
    cout << "GNU General Public License for more details.\n\n";

    cout << "You should have received a copy of the GNU General Public License\n";
    cout << "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";
	cout << "\n``````````````````````````````````````````````````````````````````````\n";
}

string upperCase(string s)
{
	string res;
	for(int i = 0 ; i < s.size() ; ++ i)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			res += char(int(s[i]) - 32);
		}
		else
		{
			res += s[i];
		}
	}
	return res;
}

int main()
{
	instruction();
    while(true)
    {
    	cout << "Choose one option you want to translate:\n";
		cout << "(M)orse to sentence\n";
		cout << "(S)entence to morse\n";
		cout << "\n";
    	string option;
    	getline(cin, option);
    	option = upperCase(option);
    	if(option == "M" || option == "MORSE TO SENTENCE")
    	{
    		cout << "\nPlease enter your Morse code:\n";
    		string s;
    		getline(cin, s);
    		s = upperCase(s);
    		cout << "\nSentence:\n" << convert_to_sentence(s) << "\n";
    		cout << "\nDo you want to exit? Press (C)ontinue if you still want to translate, press (E)xit to stop the program\n";
    		string is_exit;
    		while(true)
			{
				getline(cin, is_exit);
				is_exit = upperCase(is_exit);
	    		if(is_exit == "E" || is_exit == "EXIT")
	    		{
	    			cout << "\nBye, have a good day!";
	    			return 0;
				}
				else if(is_exit == "C" || is_exit == "CONTINUE")
				{
					cout << "\n``````````````````````````````````````````````````````````````````````\n";
					break;
				}
				else {
					cout << "Please enter again!\n";
				}
			}
		}
		else if(option == "S" || option == "SENTENCE TO MORSE")
		{
			cout << "\nPlease enter your sentence:\n";
    		string s;
    		getline(cin, s);
    		s = upperCase(s);
    		cout << "\nMorse code:\n" << convert_to_morse(s) << "\n";
    		cout << "\nDo you want to exit? Press (C)ontinue if you still want to translate, press (E)xit to stop the program\n";
    		string is_exit;
    		while(true)
			{
				getline(cin, is_exit);
				is_exit = upperCase(is_exit);
	    		if(is_exit == "E" || is_exit == "EXIT")
	    		{
	    			cout << "\nBye, have a good day!";
	    			return 0;
				}
				else if(is_exit == "C" || is_exit == "CONTINUE")
				{
					cout << "\n``````````````````````````````````````````````````````````````````````\n";
					break;
				}
				else {
					cout << "Please enter again!\n";
				}
			}
		}
		else
		{
			cout << "\nThere only two option, please choose again!\n";
			cout << "\n``````````````````````````````````````````````````````````````````````\n";
		}
	}
    return 0;
}