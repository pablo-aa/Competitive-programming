// General functions to manipulate strings

// find function
int i = str.find("aa");
i = pos ou -1

// find multiples strings
while(i!=string::npos){
	i = str.find("aa", i);
}

// replace function
str.replace(index, (int)size_of_erased, "content");
"paablo".replace(1, 2, "a"); // = Pablo

// string concatenation
string a = "pabl"
a+="o" or a+='o' or a.pb('o')