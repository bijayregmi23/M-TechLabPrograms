import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.cluster import KMeans
import sklearn.metrics as sm
import pandas as pd
import numpy as np

iris = datasets.load_iris()
X  = pd.DataFrame(iris.data)
X.columns = ['Sepal_Length','Sepal_Width','Petal_Length','Petal_Width']
Y = pd.DataFrame(iris.target)
Y.columns = ['Targets']

model = KMeans(n_clusters = 3)
model.fit(X)
model.labels_
plt.figure(figsize=(14,7))

colormap = np.array(['red','lime','black'])
plt.subplot(1,2,1)
plt.scatter(X.Petal_Length,X.Petal_Width,c = colormap[Y.Targets],s=40)
plt.title('Real Classification')

plt.subplot(1,2,2)
plt.scatter(X.Petal_Length,X.Petal_Width,c=colormap[model.labels_],s=40)

plt.figure(figsize=(14,7))

predY = np.choose(model.labels_,[0,1,2]).astype(np.int64)
print(predY)

plt.subplot(1,2,1)
plt.scatter(X.Petal_Length,X.Petal_Width,c=colormap[Y.Targets],s=40)
plt.title('Real Classification')

plt.subplot(1,2,2)
plt.scatter(X.Petal_Length,X.Petal_Width,c=colormap[predY],s=40)
plt.title('KMeans Classification')	
print('The accuracy score of KMeans:',sm.accuracy_score(Y,model.labels_))
print('The accuracy score of KMeans:',sm.confusion_matrix(Y,model.labels_))

from sklearn import preprocessing
scalar = preprocessing.StandardScaler()
scalar.fit(X)
xsa=scalar.transform(X)
xs = pd.DataFrame(xsa,columns=X.columns)
	
from sklearn.mixture import GaussianMixture
gmm = GaussianMixture(n_components=3)
gmm.fit(xs)

y_cluster_gmm = gmm.predict(xs)

plt.subplot=(2,2,3)
plt.scatter(X.Petal_Length,X.Petal_Width,c=colormap[y_cluster_gmm],s=40)
plt.title('GMM Classification')

print('The accuracy score of KMeans:',sm.accuracy_score(Y,y_cluster_gmm))
print('The accuracy score of KMeans:',sm.confusion_matrix(Y,y_cluster_gmm))





