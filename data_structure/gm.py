import numpy as np
from pandas import Series
from pandas import DataFrame
import pandas as pd
import matplotlib.pyplot as plt
from math import e
#台中市人口變化
# source: https://blog.csdn.net/qq_30091945/article/details/54379922

def Identification_Algorithm(x):    #辨识算法
    B = np.array([[1]*2]*5)
    

    tmp = np.cumsum(x)

    for i in range(len(x)-1) :
        B[i][0] = (tmp[i] + tmp[i + 1]) * (-1.0) / 2

    Y = np. transpose (x[1:])
    BT = np.transpose(B)
    a = np.linalg.inv(np.dot(BT,B) )
    a = np.dot (a, BT)
    a = np.dot(a, Y)
    a = np.transpose(a)

    return a

#GM(1, 1)模型
def GM_Model(X0, a, tmp) :
    A = np.ones (len (X0))

    for i in range(len(A)) :
        A[i] = a[1]/a[0] + (X0[0] - a[1] / a[0]) * np.exp(a[0] * (tmp[i] - 1) * (-1))
    
    print('GM(1,1) Model 為: \nX(k) =',X0[0]-a[1]/a[0], '* exp(',-a[0],'(k-1)) + ',a[1]/a[0])

    XK = Series(A, index = pd.period_range('2000', '2005', freq ='A-DEC'))
    

    print ("GM(1,1)模型计算值为：")
    print (XK)
    return XK

def Return (XK):    
    # 顽测值还原
    tmp = np.ones (len(XK))
    for i in range(len(XK)) :
        if i == 0:
            tmp[i] = XK[i]
        else:
            tmp [i] = XK[i] - XK[i-1]
    X_Return = Series (tmp, index = pd.period_range('2000', '2005', freq = 'A-DEC'))

    print ('還原值為: \n')
    print (X_Return)
    return X_Return
    
def Predict(X0, a, k, r, st,item_num): #X0 = Series /a = matrix / k = index
    tmp = (X0[0]-a[1]/a[0]) * pow(e,-a[0]*(k - 1)) + (a[1] / a[0])
   
    result = tmp - r
    
    return result



if __name__ == "__main__":
    #初始化原始数据
    date = pd.period_range('2000', '2005', freq ='A-DEC')
    tmp = np. array([1, 2, 3, 4, 5, 6])
    
    data = np.array( [132,92,118,130,187,207])

    X0 = Series(data, index = date)
    X0_copy = Series (data, index = tmp)

    print('原始数据为：\n')
    print (X0)

    # 对原始数据惊醒一次累加
    X1 = np.cumsum (X0)
    print("原始数据累加为：")
    print(X1)

    # 辦识算法
    a = Identification_Algorithm (data)
    print("a矩阵为: ")
    print (a)

    #GM(1,1)模型
    XK = GM_Model(X0, a, tmp)

    #最後要還原預測項
    leng = XK.size - 1
    r = XK[leng]
    
    # 预测值还原
    X_Return = Return (XK)

    # 预测值即预测值精度表
    X_Compare1 = np. ones(len(X0) )
    X_Compare2 = np. ones(len(X0))

    for i in range(len(data)) :
        X_Compare1[i] = data[i] - X_Return[i]
        X_Compare2[i] = X_Compare1[i] / data[i] * 100

    Compare = {'GM' :XK, '1-AGO': np. cumsum (data) , 'Returnvalue':X_Return, 'Realityvalue':data, 'Error': X_Compare1, 'Relative(%)':X_Compare2}
    X_Compare = DataFrame (Compare, index = date)
    print("预测值即预测值精度表")
    print (X_Compare)

    #模型檢驗

    #殘差平方和
    error_square = np.dot (X_Compare, np. transpose (X_Compare) )
    #平均相對誤差
    error_avg = np.mean(error_square)

    S = 0
    #X0的關聯度
    for i in range(1, len(X0)-1,1):
        S += X0[i]-X0[0]+(XK[-1]-XK[0])/2
    S = np.abs (S)

    #XK的關聯度
    SK = 0
    for i in range(1, len(XK)-1,1):
        SK += XK[i]-XK[0]+(XK[-1]-XK[0]) /2
    SK = np.abs (SK)

    # |IS-SK|b
    S_Sub = 0
    for i in range(1, len(XK)-1,1):
        S_Sub += X0[i]-X0[0]-(XK[i]-XK[0])+((X0[-1]-X0[0])-(XK[i]-XK[0]))/2
    S_Sub = np.abs (S_Sub)

    T = (1 + S + SK) / (1 + S + SK + S_Sub)

    if T >= 0.9:
        print ("精度為一級")
        print ('可用GM(1,1)E\nX(k) = ' ,X0[0]-a[1]/a[0], 'exp(',-a[0], ' (k-1))' ,a[1]/a[0])
    elif T >= 0.8:
        print ("精度為二級")
        print('可以用GM(1,1)模型\nx(k)= ',X0[0] - a[1] / a[0],'exp(',-a [0],'(k-1))',a[1] / a[0])
    elif T >= 0.7:
            print ("精度為三級")
            print ('慎用GM(1,1)模型\nX(k) = ' ,X0[0]-a[1]/a[0], 'exp(',-a[0], ' (k-1))' ,a[1]/a[0])
    elif T >= 0.6:
            print ("精度為四級")
            print ('避免用GM(1,1)模型\nX(k) = ',X0[0]-a[1]/a[0], 'exp(', - a[0], ' (k-1))',a[1]/a[0])

    X2006 = Series(np.array([259.4489]), index=pd.period_range('2006', '2006', freq = 'A-DEC'))
    

    
    # k = index of the element 
    # G(1, 1) = v, Return(v) = answer
    X_Return = X_Return.append (X2006)


    B = pd.DataFrame([X0, X_Return], index= ['Original Data', 'Prediction Data'])
    B = np.transpose(B)
    print(B)
    B.plot()
    plt.title("2022/01 Taichung Population Prediction")
    plt.xlabel("Year/Month")
    plt.ylabel("Population(10K)")

    plt.show()


