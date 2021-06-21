# ==================================================
# Design a machine learning model with wine dataset
# ==================================================
import os
import pandas as pd
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import StandardScaler

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

    # print dataset information
    decorate = "\n"+"--"*50

    # check few rows in dataset
    print(dataset.head(5),decorate)

    # check the describe about dataset including mean, std, max value etc
    print(dataset.describe(),decorate)

    # check the type of data in each column, if object-type then encode
    print(dataset.info(),decorate)

    # get the X and y value
    X = dataset.iloc[:,1:].values
    y = dataset.iloc[:,0].values

    # encode the X features using standardScaller
    EncodeSca = StandardScaler()
    X = EncodeSca.fit_transform(X)

    return X, y


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
def evaluateModel(yPred, ytest):
    return (accuracy_score(yPred,ytest))

# ==================
# Entry Function
# ==================
def main():

    # invoke the method
    dataset = getData()
    
    # preprocess the data
    X, y = preProcess(dataset)

    # split the data
    xtrain, xtest, ytrain, ytest = train_test_split(X, y, test_size=0.30, random_state=0)

    # Get the model
    classifier = trainModel(xtrain, ytrain)
    
    # test the model
    yPredict = testModel(classifier, xtest)

    # evaluate the model
    accuracy = evaluateModel(yPredict, ytest)

    # Output
    print("Accuracy of the model is : ",accuracy * 100)

# ===========
# Starter
# ===========
if(__name__ == "__main__"):

    # Call to "entry point" function
    main()
