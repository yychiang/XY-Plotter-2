function simulation(lineList)


for i=1:length(lineList)
    points=lineList{i};
    
    X=points(:,1);
    Y=points(:,2);
    line(X,Y);
    %axis([0,18000,0,18000]);
    axis equal;
    hold on
end

