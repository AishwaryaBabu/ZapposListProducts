#include<iostream>
#include"list.h"
#include<vector>
using namespace std;

ListItem::ListItem(int productID, float productPrice, int colorID)
{
    productID_ = productID;
    productPrice_ = productPrice;
    colorID_ = colorID;
}

int ListItem::getProductID()
{
    return productID_;
}

void ListItem::setProductID(int productID)
{   
    productID_ = productID;
}

float ListItem::getProductPrice()
{
    return productPrice_;
}

void ListItem::setProductPrice(float productPrice)
{
    productPrice_ = productPrice;
}

int ListItem::getProductColorID()
{
    return colorID_;
}

void ListItem::setProductColorID(int colorID)
{
    colorID_ = colorID;
}


void List::calculatePriceList(List& firstList, List& secondList )
{

    float temp;
    for(int i = 0; i < firstList.getSize(); i++)
    {
        for(int j = 0; j < secondList.getSize(); j++)
        {
            temp = firstList.getPrice(i) + secondList.getPrice(j);
            priceList_.push_back(temp);
            vector<ListItem> tempList;
            tempList.push_back(firstList.getProduct(i, 0));
            for(int k = 0; k < secondList.getNumItems(); k++)
            {
                tempList.push_back(secondList.getProduct(j, k));   
            }
            productList_.push_back(tempList);
        }
    }
}

void List::setSize(int size)
{
    productList_.resize(size);
}

int List::getSize()
{
    return productList_.size();
}   

float List::getPrice(int index)
{
    return priceList_[index];
}

int List::getNumItems()
{
    return numItems_;
}

void List::setNumItems(int numItems)
{
    numItems_ = numItems;
}

void List::addToList(int i, ListItem newItem, float price)
{
    productList_[i].push_back(newItem);
    priceList_.push_back(price);
}

ListItem List::getProduct(int i, int j)
{
    return productList_[i][j];
}

void List::displayList()
{
    for(int i = 0; i < productList_.size(); i++)
    {
        for(int j = 0; j < productList_[i].size(); j++)
        {
            cout<<productList_[i][j].getProductID()<<"+"<<productList_[i][j].getProductColorID()<<"+"<<productList_[i][j].getProductPrice()<<" ";
        }
        cout<<endl;
    }

}


