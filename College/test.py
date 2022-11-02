import numpy as np
import pandas as pd
df=pd.DataFrame({'Bob': ['I liked it.', 'It was awful.'], 
              'Sue': ['Pretty good.', 'Bland.']},
             index=['Product A', 'Product B'])
sr=pd.Series([1, 2, 3, 4, 5])
print(df)
print(sr)
