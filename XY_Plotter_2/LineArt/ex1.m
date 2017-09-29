clear
close all
warning off;
%I=imread('line2.jpeg');
%I=imread('b.jpg');
I=imread('im1.png');
imshow(I);

if (length(size(I))==3)
    A=rgb2gray(I);
else
    A=I;
end

for i=1:size(I,1)
    for j=1:size(I,2)
        if I(i,j)==0
            I(i,j)=255;
        end
    end
       
end


figure
imshow(A)
for i=1:size(I,1)
    for j=1:size(I,2)
        if I(i,j)>=128
            A(i,j)=255;
        else
            A(i,j)=0;
        end
    end
       
end


figure
imshow(A)
A=255-A;
A=im2bw(A, 0.5) 
c=erode(A,'thin',15);
c=uint8(c)*255;
c=255-c;
figure
imshow(c);
% [L, img] = findLine(c);
% counter=1;
% lineList{counter}=L;

% while (~isempty(L))
%     [L, img] = findLine(img);
%     counter=counter+1;
%     lineList{counter}=L;
% end
img=c;
findEndPointState=1;
counter=1;
L=0;
while (~isempty(L))
    if findEndPointState==1
       [L, imgTemp] = findLine(img,[]);
       findEndPointState=0;
    else
        i=i-1;
        [L1, img] = findLine(img,L(size(L,1),:)); 
        lineList{counter}=L1*20; % scale factor
        counter=counter+1;
        findEndPointState=1;
    end
end
figure
simulation(lineList)
c=0;
%%%%%%%%%%%%%%%%%%%%% Bezier Approximation %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% for i=1:length(lineList)  
%     MxAllowSqD=2000; % Max. allowed Square Distance between original and fitted data
%     if size(lineList{i},1)>=4
%         Mat = lineList{i};
%         ei= size(Mat,1);
%         ibi=[1;ei]; %first and last point
% 
%         [p0mat,p1mat,p2mat,p3mat,fbi]=bzapproxu(Mat,MxAllowSqD,ibi);  
% 
%         [MatI]=BezierInterpCPMatSegVec(p0mat,p1mat,p2mat,p3mat,fbi);
%         lineList{i}=MatI;
%         c=c+1;
%     end
% end
% figure
% simulation(lineList)
