from ast import operator
import csv
import random
import math


def loadDataset(filePath, trainingSet, testingSet, split):
    with open(filePath) as dataFile:
        dataset = list(csv.reader(dataFile))
        for i in range (1, len(dataset)-1):
            for j in range(1,5):
                dataset[i][j] = float(dataset[i][j])
                if random.random() < split:
                    trainingSet.append(dataset[i])
                else:
                    testingSet.append(dataset[i])

def eucideanDistance(instance1, instance2):
    distance = 0
    for i in range(1,len(instance1)-1):
        distance += pow((instance1[i]-instance2[i]),2)
    return math.sqrt(distance)

def getNeighbours(trainingSet, testInstance, k):
    distances = []
    for i in range(len(trainingSet)):
        dist = eucideanDistance(trainingSet[i], testInstance)
        distances.append((trainingSet[i], dist))
    distances.sort(key = lambda x : x[1])
    neighbours = []
    for i in range(k):
        neighbours.append(distances[i][0])
    return neighbours

def getResponse(neighbors):
    classVotes = {}
    for x in range(len(neighbors)):
        response = neighbors[x][-1]
        if response in classVotes:
           classVotes[response] += 1
        else:
           classVotes[response] = 1
    sortedVotes = sorted(classVotes.items(), key = lambda x : x[1] , reverse=True)
    return sortedVotes[0][0]

def getAccuracy(predictions):
    correct = 0
    for i in range(len(predictions)):
        if predictions[i][0] == predictions[i][1]:
           correct += 1
    return (correct/float(len(predictions))) * 100.0


def main():
    print('\n\n----------------------------------------------------------------------------')
    print(' STUDENT NAME : BIJAY REGMI      REGD. NO. : 210913032')
    print('----------------------------------------------------------------------------\n\n')
    #------------------------------------------------------------------------------------
    # PREPARING DATA
    #------------------------------------------------------------------------------------
    trainingSet = []
    testingSet = []
    split = 0.67
    loadDataset('Iris.csv',trainingSet , testingSet, split)
    print ('\nNumber of Training data : ' + str(len(trainingSet)))
    print ('Number of Test Data : ' + str(len(testingSet)))

    #------------------------------------------------------------------------------------
    # GENERATING PREDICTIONS(K=1)
    #------------------------------------------------------------------------------------
    predictions = []
    k = 1
    print('\n-----------------------------------------------')
    print(' GENERATING PREDICTIONS(K = ',k,')',sep='')
    print('-----------------------------------------------')
    for i in range(len(testingSet)):
        neighbours = getNeighbours(trainingSet, testingSet[i], k)
        result = getResponse(neighbours)
        predictions.append((testingSet[i][-1],result))
        print('Predicted = ' + result + ', Actual = ' + testingSet[i][-1])
    accuracy = getAccuracy(predictions)
    print('\nThe Accuracy is: ' + repr(accuracy) + '%')

    #------------------------------------------------------------------------------------
    # GENERATING PREDICTIONS(K=3)
    #------------------------------------------------------------------------------------
    predictions = []
    k = 3
    print('\n-----------------------------------------------')
    print(' GENERATING PREDICTIONS(K = ',k,')',sep='')
    print('-----------------------------------------------')
    for i in range(len(testingSet)):
        neighbours = getNeighbours(trainingSet, testingSet[i], k)
        result = getResponse(neighbours)
        predictions.append((testingSet[i][-1],result))
        print('Predicted = ' + result + ', Actual = ' + testingSet[i][-1])
    accuracy = getAccuracy(predictions)
    print('\nThe Accuracy is: ' + repr(accuracy) + '%')


    #------------------------------------------------------------------------------------
    # GENERATING PREDICTIONS(K=5)
    #------------------------------------------------------------------------------------
    predictions = []
    k = 5
    print('\n-----------------------------------------------')
    print(' GENERATING PREDICTIONS(K = ',k,')',sep='')
    print('-----------------------------------------------')
    for i in range(len(testingSet)):
        neighbours = getNeighbours(trainingSet, testingSet[i], k)
        result = getResponse(neighbours)
        predictions.append((testingSet[i][-1],result))
        print('Predicted = ' + result + ', Actual = ' + testingSet[i][-1])
    accuracy = getAccuracy(predictions)
    print('\nThe Accuracy is: ' + repr(accuracy) + '%')


    #------------------------------------------------------------------------------------
    # GENERATING PREDICTIONS(K=7)
    #------------------------------------------------------------------------------------
    predictions = []
    k = 7
    print('\n-----------------------------------------------')
    print(' GENERATING PREDICTIONS(K = ',k,')',sep='')
    print('-----------------------------------------------')
    for i in range(len(testingSet)):
        neighbours = getNeighbours(trainingSet, testingSet[i], k)
        result = getResponse(neighbours)
        predictions.append((testingSet[i][-1],result))
        print('Predicted = ' + result + ', Actual = ' + testingSet[i][-1])
    accuracy = getAccuracy(predictions)
    print('\nThe Accuracy is: ' + repr(accuracy) + '%\n\n')


main()