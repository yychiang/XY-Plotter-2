
close all
 
hold on
figure
axis([0,1000,0,1000])
c=1;
for i=1:length(lineList)
i
    for j=2: size(lineList{i},1)
  c=c+1;
        line([lineList{i}(j-1,1),lineList{i}(j,1) ],[ lineList{i}(j-1,2), lineList{i}(j,2)]);
       
    end
M(c)=getframe;
    
end
%movie(M,1,100)

