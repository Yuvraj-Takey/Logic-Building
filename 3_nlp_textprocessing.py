# -*- coding: utf-8 -*-
"""3_NLP_TextProcessing.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1w-417jGJcmHo7SfIw7LCrWbaGO0b6a3-

# <div class="alert alert-info"> Import the libraries </div>
***
"""

import pandas as pd
import nltk
import string
import re
from sklearn.feature_extraction.text import TfidfVectorizer

pd.set_option('display.max_colwidth', 100)

"""# <div class="alert alert-info"> Load the raw data </div>
***
"""

# Method 1
def GetDFMeth1(file):
    
    # load the file
    data = open(file).read()

    # extract X and Y values from raw text file
    xVal = data.replace('\t','\n').split('\n')[1::2]
    yVal = data.replace('\t','\n').split('\n')[0::2][:-1] # last empty entry should be ignore
    
    # create the dataframe
    df = pd.DataFrame({"data" : xVal, "label" : yVal})
    
    return df

# Method 2
def GetDFMeth2(file):
    
    # load the file with non-header data
    df = pd.read_csv(file, sep="\t", header=None)
    
    # provide the column names to header
    df.columns = ["label", "data"]
    
    return df

df = GetDFMeth2("Dataset/SMSSpamCollection.tsv")
df.head()

"""# <div class="alert alert-info"> Overview of Helper-Modules </div>
***
"""

print("String Punctuation \n\n-->\t",string.punctuation)
print("____"*30,"\n\n")

print("Stop Words \n\n-->\t",nltk.corpus.stopwords.words('english'))
print("____"*30,"\n\n")

"""# <div class="alert alert-info"> Text Processing </div>
***

***
- <font color=black; size=4px>*** Punctuation *** </font>

***
"""

# Remove all punctuals from each row
def removePunct(text):
    text = "".join([char for char in text if char not in string.punctuation])
    return text

df['rm_Punct'] = df['data'].apply(lambda text : removePunct(text))

# Printing
print("Result 1 --> ",df['data'][5565])
print("Result 2 --> ",df['rm_Punct'][5565],"\n","____"*30)
df.head(3)

"""***
- <font color=black; size=4px>*** Tokenization *** </font>
***
"""

def tokenization(text):
    
    text = re.split('\W+', text)

    return text

df['tokens'] = df['rm_Punct'].apply(lambda text : tokenization(text.lower()))

# Printing
print("Result 1 --> ",df['data'][5565])
print("Result 2 --> ",df['rm_Punct'][5565])
print("Result 3 --> ",df['tokens'][5565],"\n","____"*30)
df.head(3)

"""***
- <font color=black; size=4px>*** Stop Words *** </font>
***
"""

# get the stop words
stopWords = nltk.corpus.stopwords.words('english')

# remove all punctuation from stopwords
for index in range(len(stopWords)):
    stopWords[index] = stopWords[index].replace("'","")

def removeStopWords(text):
    
    # remove stop words
    text = [words for words in text if words not in stopWords]
    return text

df['rm_StopWords'] = df['tokens'].apply(lambda text : removeStopWords(text))

# Printing
print("Result 1 --> ",df['data'][5565])
print("Result 2 --> ",df['rm_Punct'][5565])
print("Result 3 --> ",df['tokens'][5565])
print("Result 4 --> ",df['rm_StopWords'][5565],"\n","____"*30)
df.head(3)

"""***
- <font color=black; size=4px> *** Stemming *** </font>

***
"""

# use stemming 
def useStemming(text):
    
    # create the stemming object
    ps = nltk.PorterStemmer()
    
    # stem the word
    text = [ps.stem(word) for word in text]
    
    return text

df['stemming'] = df['rm_StopWords'].apply(lambda text : useStemming(text))

# Printing
print("Result 1 --> ",df['rm_StopWords'][5565])
print("Result 2 --> ",df['stemming'][5565])
df.head(3)

"""***
- <font color=black; size=4px> *** Lemmatisation *** </font>

***
"""

def useLemmatize(text):
    
    # use the lemmatizer object
    wl = nltk.WordNetLemmatizer()
    
    # apply lemmatize to the word
    text = [wl.lemmatize(word) for word in text]
    
    return text

df['lemmatize'] = df['rm_StopWords'].apply(lambda text : useLemmatize(text))

# Printing
print("Result 1 --> ",df['rm_StopWords'][5565])
print("Result 2 --> ",df['stemming'][5565])
print("Result 3 --> ",df['lemmatize'][5565])
df.head(3)

"""***
# Continue ........
***

***
- <font color=black; size=4px> *** Vectorization *** </font>

***
"""

def combine(text):
    text = " ".join(text)
    return text

# get the object for vectorizer
vect = TfidfVectorizer()

# fit all the data for training with vectorizer 
xVal = vect.fit_transform(df['stemming'].apply(lambda text : combine(text)))

# display
print(xVal.shape)
print(vect.get_feature_names())

X_tfidf_df = pd.DataFrame(xVal.toarray())
X_tfidf_df.columns = vect.get_feature_names_out ()
X_tfidf_df.head()