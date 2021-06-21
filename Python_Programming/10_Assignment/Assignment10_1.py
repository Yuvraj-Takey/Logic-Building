# ================================================================
# Design a machine learning model with play predictor dataset
# ================================================================
import os
import pandas as pd
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

# ==================
# get the dataset
# ==================
def getData():

    # input from user
    data = input("Enter the dataset file name : ")

    # read the data
    dataset = pd.read_csv(data)
    
    return dataset

# ==================
# Data preprocesing
# ==================
def preProcess(dataset):

    decorate = "\n"+"--"*50+"\n"

    # Drop the column
    dataset.drop(columns=['Unnamed: 0'], inplace=True)

    print(dataset.head(),decorate)
    print(dataset.info(),decorate)

    # Get the dictionary object
    encode = {}

    # encode the all columns
    for colName in dataset.columns:

        # get the encoder object
        encode[colName] = preprocessing.LabelEncoder()
        dataset[colName] = encode[colName].fit_transform(dataset[colName])

    # Get X and y values
    X = dataset.iloc[:,:-1].values
    y = dataset.iloc[:,-1].values

    
    return encode, X, y


# ============================================
# Build the model and fir the data into model
# ============================================
def trainModel(x,y):

    # value of the k in KNN model
    kValue = 3
    
    # Get the object of the model
    classifier = KNeighborsClassifier(n_neighbors = kValue)

    # fit the data into model
    classifier.fit(x,y)

    return classifier

# ======================================
# Test the model with given classifier
# ======================================
def testModel(classifier, x):

    # test the model
    yPred = classifier.predict(x)

    return yPred


# ======================================
# Evaluate the model
# ======================================
def checkAccuracy(classifier, X, y):

    # split the dataset into equal parts
    xtrain, xtest, ytrain, ytest = train_test_split(X,y,test_size=0.50,random_state=0)

    # test the model with splited data
    yPred = testModel(classifier, xtest)

    # return accuracy
    return (accuracy_score(yPred,ytest))

# ======================================
# Get the data from user
# ======================================
def userInput(dataEnc):

    # Get user data
    print("Enter the data (case-sensitive)")
    whInput = input("Enter the wether[Sunny, Overcast, Rainy] : ")
    teInput = input("Enter the wether[Hot, Mild, Cold] : ")

    # encode the data with proper encoder object
    whether = dataEnc["Wether"].transform([whInput])[0]
    tempert = dataEnc["Temperature"].transform([teInput])[0]
    xtest = [[whether,tempert]]

    return xtest

# ==================
# Entry Function
# ==================
def main():

    # invoke the method
    dataset = getData()
    
    # preprocess the data
    dataEnc, X, y = preProcess(dataset)

    # Get the model
    classifier = trainModel(X, y)

    # Test-Data
    #
    # Get the Raw test data from user...Encode them using dataEnc
    # and then merge it in a xtest
    #
    xtest = userInput(dataEnc)
    
    # test the model
    yPredict = testModel(classifier, xtest)

    # Print the result 
    print("\nThe predicted result is : ",dataEnc["Play"].inverse_transform(yPredict),"\n")

 
    # evaluate the model
    accuracy = checkAccuracy(classifier, X, y)

    print("Accuracy of the model is : ",accuracy*100,"%")


# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
