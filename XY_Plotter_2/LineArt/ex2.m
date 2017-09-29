

%fid = fopen('exp.txt','w');
%        fprintf(fid,'penUp();\n');

 geoList={['Ua']};
        
for i=1:length(lineList)
%     fprintf(fid,'Line(%d,%d);\n',lineList{i}(1,1),lineList{i}(1,2));
    geoList{length(geoList)+1}=['Lx',int2str(lineList{i}(1,1)),'y',int2str(lineList{i}(1,2)),'a'];
%     fprintf(fid,'penDown();\n');
    geoList{length(geoList)+1}=['Da'];

    for j=2: size(lineList{i},1)
%       fprintf(fid,'Line(%d,%d);\n',lineList{i}(j,1),lineList{i}(j,2));
        geoList{length(geoList)+1}=['Lx',int2str(lineList{i}(j,1)),'y',int2str(lineList{i}(j,2)),'a'];
    end
%     fprintf(fid,'penUp();\n');
    geoList{length(geoList)+1}=['Ua'];

    
end
        
