#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include"list.h"
using namespace std;

void createFinalList(int N, float totalPrice, List& totalListFinal, vector<vector<ListItem> >&finalList)
{

    finalList.resize(1);
    for(int i = 0; i < N; i++)
    {
        finalList[0].push_back(totalListFinal.getProduct(0, i));
    }

    float diff = abs(totalPrice - totalListFinal.getPrice(0));

    for(int i = 1; i < totalListFinal.getSize(); i++)
    {
        vector<ListItem> tempList;
        //diff greater
        if(diff > abs(totalListFinal.getPrice(i)- totalPrice))
        {
/*            for(int j = 0; j < finalList.size(); j++)
            {   
                finalList.pop_back();
            }
*/
            finalList.clear();
            for(int k = 0; k < N; k++)
            {
                tempList.push_back(totalListFinal.getProduct(i, k));   
            }
            finalList.push_back(tempList);
            diff = abs(totalListFinal.getPrice(i)-totalPrice);
        }
        else if(diff == abs(totalListFinal.getPrice(i)- totalPrice))
        {
            for(int k = 0; k < N; k++)
            {
                tempList.push_back(totalListFinal.getProduct(i, k));   
            }

            finalList.push_back(tempList);
        }
       
    }   
}

void displayFinalList(int N, vector<vector<ListItem> >& finalList)
{
    for(int i = 0; i < finalList.size(); i++)
    {
        for(int j = 0; j < N; j++)
            cout<<finalList[i][j].getProductID()<<" "<<" "<<finalList[i][j].getProductColorID()<<" $"<<finalList[i][j].getProductPrice()<<" ;";
        cout<<endl;
    }
}   

void readInput(string inputFilename, vector<int>& productIds, vector<float>& priceArray,  vector<int>& colorIds, int& totalNumObjects)
{

    fstream fs;
    fs.open(inputFilename.c_str(), fstream::in);

    string input;
    getline(fs, input);

    fs.close();
    int found=0;
    int found1=0;
    int count = 0;

    found = input.find("currentResultCount");
    found1 = input.find("\"", found+21);
    totalNumObjects = atoi((input.substr(found+21, found1-found-21).c_str()));

    found = 0;
    found1 = 0;

    while(count < totalNumObjects)
    {
        found = input.find("price", found+1); 
        found1 = input.find("\"", found+9);
        priceArray.push_back(atoi((input.substr(found+9, found1-found-9)).c_str()));

        found = input.find("colorId", found+1);
        found1 = input.find("\"", found+10);
        colorIds.push_back(atoi((input.substr(found+10, found1-found-10)).c_str()));
 
        found = input.find("productId", found+1);
        found1 = input.find("\"", found+12);
        productIds.push_back(atoi(input.substr(found+12, found1-found-12).c_str()));
          
//        cout<<input.substr(found+11, found1-found-11).c_str()<<endl;
//        cout<<productIds[count]<<endl;
        count++;
    }

    

}


int main(int argc, char* argv[])
{

    vector<int> productIds;
    vector<float> priceArray;
    vector<int> colorIds;
    int totalNumObjects = 0;
//    int N = 3;
//    float totalPrice = 383;

    int N;
    cout<<"Enter the number of objects you wish to purchase: "<<endl;
    cin >> N;

    float totalPrice;
    cout<<"\nEnter the maximum cost: "<<endl;
    cin >> totalPrice;   

//change

    string inputFilename("data.json");
    readInput(inputFilename, productIds, priceArray, colorIds, totalNumObjects);
/*
    string inputFilename("inputFile.txt");
    fstream inputFile;

    string temp1;
    int temp2;
    float temp3;

    inputFile.open(inputFilename.c_str(), fstream::in);
    while(inputFile>>temp1>>temp2>>temp3)
    {
        productIds.push_back(temp1);
        colorIds.push_back(temp2);
        priceArray.push_back(temp3);
        totalNumObjects++;
    }
*/
//change till here

    vector<List> totalList;
    List firstList;
    firstList.setNumItems(1);
    firstList.setSize(totalNumObjects);
    for(int i = 0; i < totalNumObjects; i++)
    {
        ListItem newItem(productIds[i], priceArray[i], colorIds[i]);
        firstList.addToList(i, newItem, priceArray[i]);
    }
    totalList.push_back(firstList);

//    firstList.displayList();

    for(int i = 1; i < N; i++)
    {
        List nextList;    

        if(i == 1)
        {
            nextList.setNumItems(2);
            nextList.calculatePriceList(firstList, firstList);
            totalList.push_back(nextList);
            //          nextList.displayList();

        }
        else
        {
            nextList.setNumItems(i+1);
            nextList.calculatePriceList(firstList, totalList[i-1]);
            totalList.push_back(nextList);
        }
    }

    vector<vector<ListItem> > finalList;
    createFinalList(N, totalPrice, totalList[N-1], finalList); 
    displayFinalList(N, finalList);


    return 0;
}

