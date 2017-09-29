clear
close all

I=imread('im6.jpg');
I=rgb2gray(I);
A=edge(I,'sobel');

figure
imshow(A)