#include "pch.h"
#include "../Project 5 Mymap/mymap.h"
#include <gtest/gtest.h>


//Testing Default Size
TEST(mymap, default_size) {

	mymap <int, string> s;
	EXPECT_EQ(s.Size(), 0);
}

//Testing proper insert of array data 
TEST(mymap, size) {
	mymap <int, int> map;
	int arr[] = { 2, 1, 3 };
	for (int i = 0; i < 3; i++) {
		map.put(arr[i], arr[i]);
	}
	EXPECT_EQ(map.Size(), 3);
}

//Testing if size stays the same with duplicate keys
TEST(mymap, duplicate_Keys) {
	mymap <int, int> map;
	int n = 10;
	int arr[] = { 30, 15, 50, 20, 25, 70, 20, 28, 40, 30 };
	int arr2[] = { 32, 16, 51, 21, 26, 71, 22, 29, 2, 1 };
	for (int i = 0; i < n; i++) {
		map.put(arr[i], arr2[i]);
	}

	EXPECT_EQ(map.Size(), 10);
}


//Testing proper input of integer and string data
TEST(mymap, string_size) {
	mymap <int, string> map;
	int num1 = 3;
	int num2 = 4;
	int num3 = 5;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(num1, name1);
	map.put(num2, name2);
	map.put(num3, name3);

	EXPECT_EQ(map.Size(), 3);
}

//Testing proper input of set and string data


//Testing proper input of double and string data
TEST(mymap, double_size) {
	mymap <double, string> map;
	double num1 = 3.0;
	double num2 = 4.0;
	double num3 = 5.0;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(num1, name1);
	map.put(num2, name2);
	map.put(num3, name3);

	EXPECT_EQ(map.Size(), 3);
}




//Testing contains functions with int data
TEST(mymap, int_contains) {
	mymap <int, int> map;
	int arr[] = { 2, 1, 3 };
	for (int i = 0; i < 3; i++) {
		map.put(arr[i], arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		EXPECT_TRUE(map.contains(arr[i]));
	}

}

//Testing contains function on string data
TEST(mymap, string_Contains) {
	mymap <string, int> map;
	int num1 = 3;
	int num2 = 4;
	int num3 = 5;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(name1, num1);
	map.put(name2, num2);
	map.put(name3, num3);

	
	EXPECT_TRUE(map.contains(name1));
	EXPECT_TRUE(map.contains(name2));
	EXPECT_TRUE(map.contains(name3));
}

//testing contains function on double dataa
TEST(mymap, double_contains) {
	mymap <double, string> map;
	double num1 = 3.0;
	double num2 = 4.0;
	double num3 = 5.0;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(num1, name1);
	map.put(num2, name2);
	map.put(num3, name3);


	EXPECT_TRUE(map.contains(num1));
	EXPECT_TRUE(map.contains(num2));
	EXPECT_TRUE(map.contains(num3));
}

//Testing get function on int data
TEST(mymap, int_get) {
	mymap <int, int> map;
	int arr[] = { 2, 1, 3 };
	for (int i = 0; i < 3; i++) {
		map.put(arr[i], arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(map.get(arr[i]), arr[i]);
		EXPECT_EQ(map.Size(), 3);
	}
}

//Testing get function on string data
TEST(mymap, string_get) {
	mymap <string, int> map;
	int num1 = 3;
	int num2 = 4;
	int num3 = 5;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(name1, num1);
	map.put(name2, num2);
	map.put(name3, num3);

	
	EXPECT_EQ(map.get(name1), num1);
	EXPECT_EQ(map.get(name2), num2);
	EXPECT_EQ(map.get(name3), num3);

	EXPECT_EQ(map.Size(), 3);
	
}


//Testing get function on double data
TEST(mymap, double_get) {
	mymap <double, string> map;
	double num1 = 3.0;
	double num2 = 4.0;
	double num3 = 5.0;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(num1, name1);
	map.put(num2, name2);
	map.put(num3, name3);


	EXPECT_EQ(map.get(num1), name1);
	EXPECT_EQ(map.get(num2), name2);
	EXPECT_EQ(map.get(num3), name3);

	EXPECT_EQ(map.Size(), 3);

}

//Testing toString output function on int data
TEST(mymap, int_toString) {
	mymap <int, int> map;
	int arr[] = { 2, 1, 3 };
	for (int i = 0; i < 3; i++) {
		map.put(arr[i], arr[i]);
	}
	string sol = "key: 1 value: 1\nkey: 2 value: 2\nkey: 3 value: 3\n";
	EXPECT_EQ(sol, map.toString());
}


//Testing toString output function on string data
TEST(mymap, string_toString) {
	mymap <string, int> map;
	int num1 = 3;
	int num2 = 4;
	int num3 = 5;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(name1, num1);
	map.put(name2, num2);
	map.put(name3, num3);

	string sol = "key: Cam value: 5\nkey: Julie value: 3\nkey: May value: 4\n";

	EXPECT_EQ(sol, map.toString());
}

//Testing toString output function on double data
TEST(mymap, double_toString) {
	mymap <double, string> map;
	double num1 = 3.3;
	double num2 = 4.1;
	double num3 = 5.2;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(num1, name1);
	map.put(num2, name2);
	map.put(num3, name3);

	string sol = "key: 3.3 value: Julie\nkey: 4.1 value: May\nkey: 5.2 value: Cam\n";

	EXPECT_EQ(sol, map.toString());
}

// netid: msiddi73
// Testing put with random char key (Testing Size and toString)




//Testing operator function on int data
TEST(mymap, int_Operator) {
	mymap <int, int> map;
	int arr[] = { 2, 1, 3 };
	for (int i = 0; i < 3; i++) {
		map.put(arr[i], arr[i]);
	}

	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(map[arr[i]], arr[i]);
		EXPECT_EQ(map.Size(), 3);
	}

}

//Testing operator function on string data
TEST(mymap, string_Operator) {
	mymap <string, int> map;
	int num1 = 3;
	int num2 = 4;
	int num3 = 5;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(name1, num1);
	map.put(name2, num2);
	map.put(name3, num3);

	EXPECT_EQ(map[name1], num1);
	EXPECT_EQ(map[name2], num2);
	EXPECT_EQ(map[name3], num3);
	EXPECT_EQ(map.Size(), 3);
}

//Testing operator function on double data
TEST(mymap, double_Operator) {
	mymap <double, string> map;
	double num1 = 3.3;
	double num2 = 4.1;
	double num3 = 5.2;
	string name1 = "Julie";
	string name2 = "May";
	string name3 = "Cam";

	map.put(num1, name1);
	map.put(num2, name2);
	map.put(num3, name3);

	EXPECT_EQ(map[num1], name1);
	EXPECT_EQ(map[num2], name2);
	EXPECT_EQ(map[num3], name3);
	EXPECT_EQ(map.Size(), 3);
}


//Testing operator function's ability to add new data not currently
//in initial container--testing int data

//Testing Iterator functions
TEST(mymap, iteratorfunctions) {
	mymap<int, int> map;
	int arr[] = { 2, 1, 3 };
	int order[] = { 1, 2, 3 };
	for (int i = 0; i < 3; i++) {
		map.put(arr[i], arr[i]);
	}
	int i = 0;
	for (auto key : map) {
		EXPECT_EQ(order[i++], key);
	}
}


//Testing Equal Operator test <int, int>
//Adapted from tkoope2 testing
TEST(mymap, smallint_equalOperator) {
	mymap<int, int> m;
	mymap<int, int> m2;
	
    int arr[] = {3, 7, 6, 9, 10};
    int arr2[] = {4, 2, 1, 5, 9};

	string mOriginal = "key: 3 value: 3\nkey: 6 value: 6\nkey: 7 value: 7\nkey: 9 value: 9\nkey: 10 value: 10\n";
	
	for (int i = 0; i < 5; i++) {
		m.put(arr[i], arr[i]);
	}

	for (int j = 0; j < 5; j++) {
		m2.put(arr2[j], arr2[j]);
	}

	m = m2;

	EXPECT_EQ(m.Size(), m2.Size());
	EXPECT_EQ(m2.toString(), m.toString());
}


//Test from tkoope2 plus my personal modifications
//Copy Operator test <int, int> on a bigger scale
TEST(mymap, int_equalOperator) {
	mymap<int, int> m;
	mymap<int, int> m2;

	//Populate 1 and 2
	int key, value, high, low, modOp;
	int arrSize = rand() % 100;

	string mOriginal = "key: 3 value: 3\nkey: 6 value: 6\nkey: 7 value: 7\nkey: 9 value: 9\nkey: 10 value: 10\n";

	//Populate m
	high = 500;
	low = 1;
	modOp = (high - (low + 1)) + low;
	for (int i = 0; i < arrSize; i++) {
		key = rand() % modOp;
		value = rand() % modOp;
		m.put(key, value);
	}

	//Populate m2
	high = 1000;
	low = 500;
	modOp = (high - (low + 1)) + low;
	for (int i = 0; i < arrSize; i++) {
		key = rand() % modOp;
		value = rand() % modOp;
		m2.put(key, value);
	}

	m = m2;

	EXPECT_EQ(m.Size(), m2.Size()) << "IIEquals; size difference\n";
	EXPECT_NE(mOriginal, m.toString()) << "m should not still equal original\n";
	EXPECT_EQ(m2.toString(), m.toString()) << "toString() !=\n" << "M:\n" << m.toString() << "\nM2:\n" << m2.toString() << endl;
}

//Testing Equal Operator test <int, int> with different sizes
TEST(mymap, int_differentSizes_equalOperator) {
	mymap<int, int> m;
	mymap<int, int> m2;

	int arr[] = { 3, 7, 6, 9, 10 };
	int arr2[] = { 4, 2, 1, 5, 9, 11, 12 };

	string mOriginal = "key: 3 value: 3\nkey: 6 value: 6\nkey: 7 value: 7\nkey: 9 value: 9\nkey: 10 value: 10\n";

	for (int i = 0; i < 5; i++) {
		m.put(arr[i], arr[i]);
	}

	for (int j = 0; j < 5; j++) {
		m2.put(arr2[j], arr2[j]);
	}

	m = m2;

	EXPECT_EQ(m.Size(), m2.Size()) << "IIEquals; size difference\n";
	EXPECT_NE(mOriginal, m.toString()) << "m should not still equal original\n";
	EXPECT_EQ(m2.toString(), m.toString()) << "toString() !=\n" << "M:\n" << m.toString() << "\nM2:\n" << m2.toString() << endl;
}

//tkoope2
//Copy Constructor
TEST(copyConstructor, IIConCopy) {
	mymap<int, int> m;
	map<int, int> correct;
	vector<int> keys;
	int key;
	int val;
	int arrSize = 15;
	int high = 500, low = 0;
	int modOp = (high - (low + 1)) + low;


	//Populate
	for (int i = 0; i < arrSize; i++) {
		key = rand() % modOp;
		val = rand() % modOp;

		keys.push_back(key);

		m.put(key, val);
		correct[key] = val;
	}

	EXPECT_EQ(m.Size(), correct.size()) << "mymap != map\n";

	mymap<int, int> m2 = m;
	EXPECT_EQ(m.toString(), m2.toString()) << "Copy operator formating off\n";
	EXPECT_EQ(m2.Size(), correct.size()) << "M2's size does not match correct's\n";

	//Both have the same return value on keys
	int compA;
	int compB;
	for (auto& k : keys) {
		compA = m2[k];
		compB = correct[k];
		EXPECT_EQ(compA, compB) << compA << " != " << compB << "\t Incorrect Copy Constructor\n";
	}
}


// ssulta24
// stress test combining all the tests above 
TEST(mymap, stressTest) {

	// create a mymap
	mymap<int, int> m;

	vector< int > arr;

	for (int i = 0; i < 10000; i++) {
		int num = rand() % 10000;
		// append num to arr 
		arr.push_back(num);
		m.put(i, num);
	}

	for (int i = 0; i < 10000; i++) {
		EXPECT_EQ(m[i], arr[i]);
	}

	for (int i = 0; i < 10000; i++) {
		EXPECT_EQ(m.contains(i), true);
	}

	for (int i = 0; i < 10000; i++) {
		EXPECT_EQ(m.get(i), arr[i]);
	}

}

// Testing put with random char key(Testing Size and toString)
TEST(Put, randomCharInt) {

	map<char, int> m;
	mymap <char, int> mymap;
	stringstream s;

	char randomKey = 0;
	int randomValue = 0;
	int randomSize = 0;
	string test;


	for (int i = 0; i < 35; i++) {

		test = "";
		s.str("");

		randomSize = 1 + (rand() % 50);

		for (int p = 0; p < randomSize; p++) {

			randomKey = rand() % 40; // get uppercase characthers
			randomValue = rand() % 100;

			m[randomKey] = randomValue;
			mymap.put(randomKey, randomValue);

		}

		for (auto const& x : m) {
			s << "key: " << x.first << " value: " << x.second << "\n";
		}

		test = mymap.toString();

		ASSERT_EQ(mymap.Size(), m.size());
		ASSERT_EQ(test, s.str());

		mymap.clear();
		m.clear();

	}

}