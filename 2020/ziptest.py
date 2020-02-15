import pandas as pd

datatrain = pd.DataFrame([[1,'A','Yes'],[2,'B','No'],[3,'C','Yes'],[4,'A','No'],[5,'B','Yes']], columns=['id','letter','answer'])

datatest = pd.DataFrame([[1,'B','xx'],[2,'B','xx'],[3,'B','xx'], [3,'A','yy'], [3,'C','yy']], columns=['id','letter','answer'])


for (no_train, data_train), (no_test, data_test) in zip(datatrain.groupby('letter'), datatest.groupby('letter')):
    print(data_train.values)


