/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.java;

import java.util.Arrays;

/**
 *
 * @author sowrov
 */
public class Main {
    static double[] SumMultipleArray(double[] ...arr) {
        double [] res = new double[arr.length];
        int i=0;
        for (double[] d: arr) {
            double sum=0;
            if (d!=null) { //Null check
                for (double v: d) {
                    sum += v;
                }
            }
            
            res[i++] = sum;
        }
        return res;
    }
    
    public static void main(String[] args) {
        double[] array_1 = {1.1, 3.3, 5.5, 7.7, 9.9, 11.11};
        double[] array_2 = {2.222, 4.444, 6.666, 8.888, 10.100, 12.122};
        double[] array_3 = {3.111, 3.222, 3.333, 3.444, 3.555, 3.666};
        double[] array_4 = {};
        double[] array_5 = null;
        double[] array_n = {12.444, 12.888, 13.332, 13.776, 14.22, 14.664};
        
        
        double[] res = SumMultipleArray(array_1, array_2, array_3, array_4, array_5, array_n);
        
        System.out.println(Arrays.toString(res));
    }
}
