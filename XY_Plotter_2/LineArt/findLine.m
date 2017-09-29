function [L,c]=findLine(c,endPoint)
m=size(c,1);
n=size(c,2);

L=[];

for i=1:m
    for j=1:n
        if c(i,j)==0;
            flag=1;
            if isempty(endPoint)
                currentPosition=[i,j];
            else
                currentPosition=endPoint;
            end
            
            L=[L;[currentPosition(1),currentPosition(2)]];
            c(currentPosition(1),currentPosition(2))=255;
            while (flag==1)
                if (inrange(currentPosition(1)+1,1,m) && inrange(currentPosition(2),1,n) && c(currentPosition(1)+1,currentPosition(2))==0)
                    currentPosition=[currentPosition(1)+1,currentPosition(2)];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                elseif (inrange(currentPosition(1)+1,1,m) && inrange(currentPosition(2)+1,1,n) && c(currentPosition(1)+1,currentPosition(2)+1)==0)
                    currentPosition=[currentPosition(1)+1,currentPosition(2)+1];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                elseif (inrange(currentPosition(1),1,m) && inrange(currentPosition(2)+1,1,n) && c(currentPosition(1),currentPosition(2)+1)==0)
                    currentPosition=[currentPosition(1),currentPosition(2)+1];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                elseif (inrange(currentPosition(1)-1,1,m) && inrange(currentPosition(2)+1,1,n) && c(currentPosition(1)-1,currentPosition(2)+1)==0)
                    currentPosition=[currentPosition(1)-1,currentPosition(2)+1];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                elseif (inrange(currentPosition(1)-1,1,m) && inrange(currentPosition(2),1,n) && c(currentPosition(1)-1,currentPosition(2))==0)
                    currentPosition=[currentPosition(1)-1,currentPosition(2)];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                elseif (inrange(currentPosition(1)-1,1,m) && inrange(currentPosition(2)-1,1,n) && c(currentPosition(1)-1,currentPosition(2)-1)==0)
                    currentPosition=[currentPosition(1)-1,currentPosition(2)-1];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                elseif (inrange(currentPosition(1),1,m) && inrange(currentPosition(2)-1,1,n) && c(currentPosition(1),currentPosition(2)-1)==0)
                    currentPosition=[currentPosition(1),currentPosition(2)-1];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                elseif (inrange(currentPosition(1)+1,1,m) && inrange(currentPosition(2)-1,1,n) && c(currentPosition(1)+1,currentPosition(2)-1)==0)
                    currentPosition=[currentPosition(1)+1,currentPosition(2)-1];
                    L=[L;[currentPosition(1),currentPosition(2)]];
                    c(currentPosition(1),currentPosition(2))=255;
                else
                    flag=0;
                end
            end
            return;
        end
    end
end
                    
                    
                