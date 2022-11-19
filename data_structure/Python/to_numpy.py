import pandas as pd

data = pd.read_csv("a.csv")
data.dropna(inplace = True)
  
# creating series form weight column
gfg = pd.Series(data['Height'])
  
# using to_numpy() function
print(gfg.to_numpy())