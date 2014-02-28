


#ifndef LIST_H
#define LIST_H

#include<vector>
#include<string>
using namespace std;

/*
    Class ListItem contains relevant details of products
*/

class ListItem
{
    string productID_;
    float productPrice_;
    int colorID_;
    public:

    ListItem(string productID, float productPrice, int colorID);

    string getProductID();

    void setProductID(string productID);

    float getProductPrice();

    void setProductPrice(float productPrice);

    int getProductColorID();

    void setProductColorID(int colorID);
};

/*
    List is a list of (lists of 'N' items) and also stores the combined price of these 'N' items.
*/
class List
{
    int numItems_;
    vector<float> priceList_;
    vector<vector <ListItem> > productList_;

    public:

    void calculatePriceList(List& firstList, List& secondList );
    void setSize(int size);

    int getSize();

    float getPrice(int index);
    int getNumItems();
    void setNumItems(int numItems);
    void addToList(int i, ListItem newItem, float price);
    ListItem getProduct(int i, int j);
    void displayList();
};

#endif
