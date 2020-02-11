#include<iostream>
#include<string>
using namespace std;

int main()
{
    for (int i = 1; i <= 12; i++)
    {
        cout << "On the ";
        switch(i)
        {
            case 1:
            cout << "first";
            break;
            case 2:
            cout << "second";
            break;
            case 3:
            cout << "third";
            break;
            case 4:
            cout << "fourth";
            break;
            case 5:
            cout << "fifth";
            break;
            case 6:
            cout << "sixth";
            break;
            case 7:
            cout << "seventh";
            break;
            case 8:
            cout << "eighth";
            break;
            case 9:
            cout << "ninth";
            break;
            case 10:
            cout << "tenth";
            break;
            case 11:
            cout << "eleventh";
            break;
            case 12:
            cout << "twelfth";
            break;
        }
        cout << " day of Christmas" << endl;
        cout << "my true love sent to me:" << endl;
        if (i != 1)
        {
            for (int k = i; k>0; k--)
            {
                switch(k)
                {
                    case 12:
                    cout << "12 Drummers Drumming" << endl;
                    break;
                    case 11:
                    cout << "Eleven Pipers Piping" << endl;
                    break;
                    case 10:
                    cout << "Ten Lords a Leaping" << endl;
                    break;
                    case 9:
                    cout << "Nine Ladies Dancing" << endl;
                    break;
                    case 8:
                    cout << "Eight Maids a Milking" << endl;
                    break;
                    case 7:
                    cout << "Seven Swans a Swimming" << endl;
                    break;
                    case 6:
                    cout << "Six Geese a Laying" << endl;
                    break;
                    case 5:
                    cout << "Five Golden Rings" << endl;
                    break;
                    case 4:
                    cout << "Four Calling Birds" << endl;
                    break;
                    case 3:
                    cout << "Three French Hens" << endl;
                    break;
                    case 2:
                    cout << "Two Turtle Doves" << endl;
                    break;
                    case 1:
                    cout << "and a Partridge in a Pear Tree" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "A Partridge in a Pear Tree" << endl;
        }
        cout << endl;
    }
}

// On the first day of Christmas
// my true love sent to me:
// A Partridge in a Pear Tree

// On the second day of Christmas
// my true love sent to me:
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the third day of Christmas
// my true love sent to me:
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the fourth day of Christmas
// my true love sent to me:
// Four Calling Birds*
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the fifth day of Christmas
// my true love sent to me:
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the sixth day of Christmas
// my true love sent to me:
// Six Geese a Laying
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the seventh day of Christmas
// my true love sent to me:
// Seven Swans a Swimming
// Six Geese a Laying
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the eighth day of Christmas
// my true love sent to me:
// Eight Maids a Milking
// Seven Swans a Swimming
// Six Geese a Laying
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the ninth day of Christmas
// my true love sent to me:
// Nine Ladies Dancing
// Eight Maids a Milking
// Seven Swans a Swimming
// Six Geese a Laying
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the tenth day of Christmas
// my true love sent to me:
// Ten Lords a Leaping
// Nine Ladies Dancing
// Eight Maids a Milking
// Seven Swans a Swimming
// Six Geese a Laying
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the eleventh day of Christmas
// my true love sent to me:
// Eleven Pipers Piping
// Ten Lords a Leaping
// Nine Ladies Dancing
// Eight Maids a Milking
// Seven Swans a Swimming
// Six Geese a Laying
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree

// On the twelfth day of Christmas
// my true love sent to me:
// 12 Drummers Drumming
// Eleven Pipers Piping
// Ten Lords a Leaping
// Nine Ladies Dancing
// Eight Maids a Milking
// Seven Swans a Swimming
// Six Geese a Laying
// Five Golden Rings
// Four Calling Birds
// Three French Hens
// Two Turtle Doves
// and a Partridge in a Pear Tree
